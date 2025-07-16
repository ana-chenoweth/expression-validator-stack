#include "Expresion.hpp"
#include <iostream>
#include <math.h>
#include <string>
#include "../Pila/Pila.hpp"

Expresion::Expresion(): expInfija(""), expPosfija(""), esValida(false)
{

}
//******************************************************************
Expresion::Expresion(std::string expInfija)
{
    this->expInfija = expInfija;
    esValida = EsCadenaValida();
    ConvertirPosfija();
}
//*****************************************************************
void Expresion::Capturar()
{
    std::cin >> expInfija;
    esValida = EsCadenaValida();
    ConvertirPosfija();
}
//*******************************************************************************
bool Expresion::EsCadenaValida()
{

    Pila<char> pila;
    std::string cadena = expInfija;
    bool estamal = false;

    for(int i = 0; i<(int)expInfija.size(); i++){
        if(EsOperadorBinario(cadena[i]) || cadena[i] == '.' || cadena[i] == 'E'|| EsNumero(cadena[i])) continue;
        else if(EsAbierto(cadena[i])|| EsCerrado(cadena[i])){
            if(EsAbierto(cadena[i])){
                pila.Agregar(cadena[i]);
            }
            if(cadena[i] == ')' ){
                if(!pila.EstaVacia()){
                    if(pila.ObtenerTope()=='(') pila.Eliminar();
                    else estamal = true;
                }
            }
            if(cadena[i] == '}'){
                if(!pila.EstaVacia()){
                    if(pila.ObtenerTope()=='{') pila.Eliminar();
                    else estamal = true;
                }
            }
            if(cadena[i] == ']'){
                if(!pila.EstaVacia()){
                    if(pila.ObtenerTope()=='[') pila.Eliminar();
                    else estamal = true;
                }
            }
        }else{
            esValida = false;
            return false;
            }
        }


    if(pila.EstaVacia() && !estamal ){
        esValida = true;
        return true;
    }
    else{
        esValida = false;
        return false;
    }

}
//*****************************************************************************************
bool Expresion::EsNumero(const char caracter)
{
    return caracter == '0' || caracter == '1' || caracter == '2' || caracter == '3' || caracter == '4'
     || caracter == '5' || caracter == '6' || caracter == '7' || caracter == '8' || caracter == '9';
}
//****************************************************************************************
bool Expresion::EsOperadorBinario(const char caracter)
{
    return caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/' || caracter == '^';
}
//****************************************************************************************************
bool Expresion::EsAbierto(const char caracter){
    return caracter == '[' || caracter == '{' || caracter == '(';
}
//****************************************************************************************************
bool Expresion::EsCerrado(const char caracter){
    return caracter == ']' || caracter == '}' || caracter == ')';
}
//**************************************************************************************************
std::string Expresion::SubCadenaNum(const std::string &cadena, int &i){

    int indInicial = i;

    int estado = 0;

    bool seTerminoElNum = false;

    while(!seTerminoElNum){

        switch(estado){

            //No se ha leido nada

            case 0:

                if(cadena[i] == '.') estado = 2;

                else if(EsNumero(cadena[i])) estado = 1;

                else seTerminoElNum = true;

                break;

            //Se leyo un numero antes del punto

            case 1:

                if(cadena[i] == '.') estado = 2;

                else if(cadena[i] == 'e' || cadena[i] == 'E') estado = 4;

                else if(!EsNumero(cadena[i])) seTerminoElNum = true;

                break;

            //Se leyo un punto

            case 2:

                if(EsNumero(cadena[i])) estado = 3;

                else esValida = false;

                break;

            //Se leyo un numero despues del punto

            case 3:

                if(cadena[i] == 'e' || cadena[i] == 'E') estado = 4;

                else if(!EsNumero(cadena[i])) seTerminoElNum = true;

                break;

            //Se leyo una 'e' o 'E'

            case 4:

                if(cadena[i] == '+' || cadena[i] == '-') estado = 5;

                else seTerminoElNum = true;

                break;

            //Se leyo un '+' o '-' despues de una 'e' o 'E'

            case 5:

                if(EsNumero(cadena[i])) estado = 6;

                else seTerminoElNum = true;

                break;

            //algo

            case 6:

                if(!EsNumero(cadena[i])) seTerminoElNum = true;

                break;

        }

        i++;

    }

    i -= 2;

    if(estado == 1 || estado == 3 || estado == 6) {

        std::string cadenaRetorno = cadena.substr(indInicial,i-indInicial+1);

        return cadenaRetorno;

    }

    else throw "Ocurrio un error al extraer la subcadena";

}
//***********************************************************************************************
void Expresion::ConvertirPosfija()
{
    Pila<char> miPila;
    std::string expresion = expInfija;
    if(!esValida) throw "La expresion no es valida";

  for (int i = 0; i < (int)expInfija.size(); ++i) {
        char caracter = expInfija[i];
        // Si el caracter es un operador binario, par�ntesis de apertura o cierre
        if (EsOperadorBinario(caracter) || EsAbierto(caracter) || EsCerrado(caracter)) {
            if (EsCerrado(caracter)) {
                // Si es un par�ntesis de cierre, desapilar hasta encontrar el par�ntesis de apertura correspondiente
                while (!miPila.EstaVacia() && miPila.ObtenerTope() != '(' && miPila.ObtenerTope() != '[' && miPila.ObtenerTope() != '{') {
                    expPosfija += miPila.ObtenerTope();
                    miPila.Eliminar();
                }
                if (!miPila.EstaVacia()) miPila.Eliminar(); // Eliminar el par�ntesis de apertura correspondiente
            } else {
                // Si no es un par�ntesis de cierre, manejar la precedencia de operadores
                while (!miPila.EstaVacia() && miPila.ObtenerTope() != '(' && miPila.ObtenerTope() != '[' && miPila.ObtenerTope() != '{' && !EsPrecedente(caracter, miPila.ObtenerTope())) {
                    expPosfija += miPila.ObtenerTope();
                    miPila.Eliminar();
                }
                miPila.Agregar(caracter); // Agregar el operador actual a la pila
            }
        } else if (EsNumero(caracter) || caracter == '.') {
            // Si es un n�mero, agregarlo directamente a la expresi�n posfija
            if (expPosfija != "") {
                    if(EsNumero(expPosfija[expPosfija.size()-1])) expPosfija += ';';
            }
            expPosfija += SubCadenaNum(expInfija, i);
        } else {
            throw "Car�cter no v�lido al convertir a posfija";
            esValida = false;
        }
    }

    // Desapilar los operadores restantes
    while (!miPila.EstaVacia()) {
        expPosfija += miPila.ObtenerTope();
        miPila.Eliminar();
    }

}
//****************************************************************************************************
bool Expresion::EsPrecedente(const char caracter1, const char caracter2)
{
    int num1, num2;
    switch(caracter1)
        {
            case '+':
                num1 = SUMA;
                break;
            case '-':
                num1 = RESTA;
                break;
            case '*':
                num1 = MULTIPLICACION;
                break;
            case '/':
                num1 = DIVISION;
                break;
            case '^':
                num1 = EXPONENTE;
                break;
            default:
                num1 = PARENTESIS_ABIERTO;
                break;
        }
        switch(caracter2)
        {
            case '+':
                num2 = SUMA;
                break;
            case '-':
                num2 = RESTA;
                break;
            case '*':
                num2 = MULTIPLICACION;
                break;
            case '/':
                num2 = DIVISION;
                break;
            case '^':
                num2 = EXPONENTE;
                break;
            default:
                num1 = PARENTESIS_ABIERTO;
                break;
        }
    return num1>num2;
}