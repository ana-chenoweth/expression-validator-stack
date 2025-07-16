#include <iostream>
#include "Expresion/Expresion.hpp"
using namespace std;

int main()
{
    try{

    cout << "Clase Expresión..." << endl;
    Expresion exp("{[(5+7)*6+4]/[(2-3)/4]}^2");
    double num = exp.EvaluarExpPosfija();
    cout << "\nResultado de la expresión: " << num << endl;
    cout << "Expresion infija: ";
    exp.ImprimirInfija();
    cout << endl << "Expresion posfija: ";
    exp.ImprimirPosfija();

    cout << endl << endl << "También puedes ingresar una expresión: ";
    Expresion exp2;
    exp2.Capturar();
    double num2 = exp2.EvaluarExpPosfija();
    cout << "\nResultado de la expresión: " << num2 << endl;
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
