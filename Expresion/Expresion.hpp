#ifndef EXPRESION_HPP_INCLUDED
#define EXPRESION_HPP_INCLUDED
#include <iostream>

class Expresion{
public:
    Expresion();

private:
    std::string expInfija;
    std::string expPosfija;
    bool esValida;
    bool EsNumero(const char caracter);
    bool EsOperadorBinario(const char caracter);
    bool EsAbierto(const char caracter);
    bool EsCerrado(const char caracter);

};
#endif // EXPRESION_HPP_INCLUDED
