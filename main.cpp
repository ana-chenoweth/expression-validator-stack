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
