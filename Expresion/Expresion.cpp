#include "Expresion.hpp"
#include <iostream>
#include <math.h>
#include <string>

enum Operadores {
    SUMA = 1,
    RESTA = 1,
    MULTIPLICACION = 2,
    DIVISION = 2,
    EXPONENTE = 3,
    PARENTESIS_ABIERTO = 4
};

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