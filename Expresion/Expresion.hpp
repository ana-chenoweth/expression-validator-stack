#ifndef EXPRESION_HPP_INCLUDED
#define EXPRESION_HPP_INCLUDED
#include <iostream>

enum Operadores {
    SUMA = 1,
    RESTA = 1,
    MULTIPLICACION = 2,
    DIVISION = 2,
    EXPONENTE = 3,
    PARENTESIS_ABIERTO = 4
};

class Expresion{
public:
    Expresion();
    bool EsCadenaValida();

private:
    std::string expInfija;
    std::string expPosfija;
    bool esValida;
    void ConvertirPosfija();

    bool EsNumero(const char caracter);
    std::string SubCadenaNum(const std::string &cadena, int &i);
    bool EsOperadorBinario(const char caracter);
    
    bool EsAbierto(const char caracter);
    bool EsCerrado(const char caracter);
    bool EsPrecedente(const char caracter1, const char caracter2);

};
#endif // EXPRESION_HPP_INCLUDED
