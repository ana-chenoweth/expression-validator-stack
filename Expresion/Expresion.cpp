#include "Expresion.hpp"
#include <iostream>
#include <math.h>
#include <string>


Expresion::Expresion(): expInfija(""), expPosfija(""), esValida(false)
{

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