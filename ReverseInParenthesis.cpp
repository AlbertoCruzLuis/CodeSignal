#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverseInParentheses(string);

int main()
{
    string texto = "foo(bar(baz))blim";
    cout << reverseInParentheses(texto) << endl;
}

std::string reverseInParentheses(std::string inputString) 
{
    //Algoritmo para este Problema
    //Estructura de datos: Pila de Char
    //Utilizar la pila cuando se encuentre dentro de los parentesis
    //1)Si es un caracter '(' hacer un push
    //  Si es un caracter ')' hacer un pop
    //2)Eliminar Parentesis al hacer pop
    //3)Si no es un Parentesis meter en un string
    //Nota: Cuando se termine de utilizar la pila sumar con el string
    // Ejemplo string "foo(bar(baz))blim" 
    // f o o                -
    // ( b a r ( b a z )    -push
    // ) z a b (            -pop
    // ( b a r ) z a b )      -push
    // ) b a z r a b (        -pop
    // f o o b a z r a b b l i m    -Resultado

    //Crear string con el Resultado Final
    std::string result = "";
    //String auxiliar
    std::string aux = "";

    //Crear Pila de Char para almacenar los datos 
    stack<char> pila;
    //Crear Pila de Char para salir del modo pila. Introducir Parentesis
    stack<char> pila_brackets;
    
    //Recorrer el string con la informacion
    for(int i = 0; i < inputString.size(); i++)
    {
        string aux2 = "";
        //Si es un Parentesis de Entrada meter en la pila
        if(inputString[i] == '(')
            pila_brackets.push(inputString[i]);
        else if(inputString[i] == ')')
            pila_brackets.pop();
        if(!pila_brackets.empty() || inputString[i] == ')')
        {
            pila.push(inputString[i]);
            if(pila.top() == ')')
            {
                while(pila.top() != '(')
                {
                    if(pila.top() != '(' 
                    && pila.top() != ')')
                    {
                        if(pila_brackets.empty())
                        {
                            result.push_back(pila.top());
                        }
                        else
                        {
                            aux2.push_back(pila.top());
                        }
                    }
                    pila.pop();
                }
                if(!aux2.empty())
                {
                    pila.pop();
                    for(int i = 0; i < aux2.size(); i++)
                        pila.push(aux2[i]);
                }
            }
        }
        else 
        {
            //En otro caso meter en el string result
            result.push_back(inputString[i]);
        }
    }
    return result;
}
