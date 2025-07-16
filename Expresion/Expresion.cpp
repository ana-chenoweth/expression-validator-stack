#include "Expresion.hpp"
#include <iostream>
#include <math.h>
#include <string>
#include "../Pila/Pila.hpp"

Expresion::Expresion(): expInfija(""), expPosfija(""), esValida(false)
{

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