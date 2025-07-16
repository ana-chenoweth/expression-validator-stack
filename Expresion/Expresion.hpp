/**
 * \file Pila.hpp
 * \brief Implementaci&oacute;n de una plantilla de pila
 * \author Ana Laura Chenoweth Galaz, Manuel Busani Yanez
 * \date 7/03/2024
 */
#ifndef EXPRESION_HPP_INCLUDED
#define EXPRESION_HPP_INCLUDED
#include <iostream>
/** \class Expresion
 *  \brief Clase para evaluar expresiones matem&aacute;ticas.
 * <b>Permite evaluar expresiones matem&aacute;ticas b&aacutesicas en forma infija y posfija.</b>
 * <br>Soporta operaciones como suma, resta, multiplicaci&oacute;n, divisi&oacute;n y potenciaci&oacute;n.
 *
 *
 * \code Ejemplo.cpp
    #include <iostream>
    #include "Expresion.hpp"
    using namespace std;

    int main()
    {
        try{
        cout << "Clase Expresi\242n..." << endl;
        Expresion exp("{[(5+7)*6+4]/[(2-3)/4]}^2");
        double num = exp.EvaluarExpPosfija();
        cout << "\nResultado de la expresi\242n: " << num << endl;
        cout << "Expresion infija: ";
        exp.ImprimirInfija();
        cout << endl << "Expresion posfija: ";
        exp.ImprimirPosfija();

        cout << endl << endl << "Tambi\202n puedes ingresar una expresi\242n: ";
        Expresion exp2;
        exp2.Capturar();
        double num2 = exp2.EvaluarExpPosfija();
        cout << "\nResultado de la expresi\242n: " << num2 << endl;
        cout << "Expresion infija: ";
        exp2.ImprimirInfija();
        cout << endl << "Expresion posfija: ";
        exp2.ImprimirPosfija();
        cout << endl;

        }catch (const char* error) {
            cerr << "\nError: " << error << endl;
        } catch (...) {
            cerr << "\nError desconocido" << endl;
        }
        return 0;
    }

 * \endcode
 *
 \verbatim Salida:
    Clase Expresi&oacute;n...
    Resultado de la expresi&oacute;n: 92416
    Expresion infija: {[(5+7)*6+4]/[(2-3)/4]}^2
    Expresion posfija: 5;7+6*4+2;3-4//2^

    Tambi&eacute;n puedes ingresar una expresi&oacute;n: (2+3)^2

    Resultado de la expresi&oacute;n: 25
    Expresion infija: (2+3)^2
    Expresion posfija: 2;3+2^

  \endverbatim
 *
 */

/**
 * @brief Enumeraci&oacute;n que representa los diferentes operadores matem&aacute;ticos.
 *
 * Esta enumeraci&oacute;n define los distintos tipos de operadores matem&aacute;ticos utilizados en una expresi&oacute;n.
 * Cada operador tiene asignado un valor entero que representa su precedencia.
 *
 * Los operadores se clasifican seg&uacute;n su precedencia de la siguiente manera:
 * - SUMA y RESTA tienen la misma precedencia (nivel 1).
 * - MULTIPLICACION y DIVISION tienen la misma precedencia (nivel 2).
 * - EXPONENTE tiene la mayor precedencia (nivel 3).
 * - PARENTESIS_ABIERTO se utiliza para indicar el inicio de un grupo de operaciones.
 */
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
    /** \brief Constructor.
     *
     *  Crea un objeto de Expresion.
     *
     */
    Expresion();
    /** \brief Constructor.
     *
     * Crea un objeto de Expresion con la expresi&oacute;n infija especificada.
     * \param expInfija La expresi&oacute;n infija a evaluar.
     *
     * \pre La expresi&oacute;n infija ingresada debe ser v&aacute;lida.
     *
     * \exception const <b>char *</b> La expresi&oacute;n no puede ser creado si la expresi&oacute;n no es v&aacute;lida.
     *
     */
    Expresion(std::string expInfija);
    /**
     * \brief Captura una expresi&oacute;n infija desde la entrada est&aacute;ndar.
     */
    void Capturar();
    /**
     * \brief Imprime la expresi&oacute;n infija en la salida est&aacute;ndar.
     */
    void ImprimirInfija();
    /**
     * \brief Imprime la expresi&oacute;n posfija en la salida est&aacute;ndar.
     */
    void ImprimirPosfija();
     /**
     * \brief Calcula el resultado de la expresi&oacute;n posfija.
     * \return El resultado de la expresi&oacute;n posfija.
     * \exception const <b>char *</b> Si la expresi&oacute;n posfija es inv&aacute;lida.
     * \exception const <b>char *</b> Si no se ha capturo correctamente la expresion.
     * \exception const <b>char *</b> No hay suficientes operandos para la operacion.
     * \exception const <b>char *</b> No es posible dividir entre 0
     * \exception const <b>char *</b> No es posible realizar ra&iacute;ces pares de n&uacute;meros negativos
     */
    double EvaluarExpPosfija();
    /**
     * \brief Verifica si la expresi&oacute;n infija es una cadena v&aacute;lida.
     *
     * Comprueba si la expresi&oacute;n infija contiene &uacute;nicamente caracteres v&aacute;lidos,
     * incluyendo operadores binarios, n&uacute;meros, puntos decimales y notaci&oacute;n cient&iacute;fica.
     * Adem&aacute;s, verifica el balance de par&eacute;ntesis, corchetes y llaves en la expresi&oacute;n.
     * \return true si la cadena es v&aacute;lida, false en caso contrario.
     * \exception const <b>char *</b> Si la expresi&oacute;n infija contiene caracteres no v&aacute;lidos.
     */
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
