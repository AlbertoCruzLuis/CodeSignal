//==============================================================
//@Autor: Alberto Cruz Luis
//@Github: albertocruzluis9@gmail.com
//@Fecha: Febrero 2020
//@Name: Minesweeper.cpp
//@Version: Minesweeper Game - Juego del Buscaminas
//==============================================================

//Problem Minesweeper - CodeSignal
/*In the popular Minesweeper game you have a board with some mines and
those cells that don't contain a mine have a number in it that indicates
the total number of mines in the neighboring cells.
Starting off with some arrangement of mines
we want to create a Minesweeper game setup.*/

#include <iostream>
#include <vector>

using namespace std;

bool is_valid(int, int, const vector<vector<bool>>&);
int numbers_mine(int, int, const vector<vector<bool>>&);
vector<vector<int>> minesweeper(const vector<vector<bool>>&);
void print_matrix(const vector<vector<int>>&);

int main()
{
    //Test para comprobar el funcionamiento del Programa
    //Test_a
    vector<vector<bool>> test_a {{{true,false,false}, 
                                {false,true,false}, 
                                {false,false,false}}};
    print_matrix(minesweeper(test_a));

    //Test_b
    vector<vector<bool>> test_b {{{false,true,true,false}, 
                                {true,true,false,true}, 
                                {false,false,true,false}}};
    print_matrix(minesweeper(test_b));
    return 0;
}

bool is_valid(int row, int col, const vector<vector<bool>> &matrix)
{
    //Comprobar si la Posicion de la matrix es valida
    return (row >= 0 && col >= 0) &&
    (row < matrix[0].size() && col < matrix.size());
}

int numbers_mine(int row, int col, const vector<vector<bool>> &matrix_original)
{
    //Contador para saber el numero de minas a su alrededor
    int mines = 0;

    /*
        N.W   N   N.E 
          \   |   / 
           \  |  / 
        W----Cell----E 
           /  |  \ 
          /   |   \ 
        S.W    S   S.E 

    Cell-->Current Cell (row, col) 
        N -->  North        (row-1, col)
        S -->  South        (row+1, col) 
        E -->  East         (row, col+1) 
        W -->  West            (row, col-1) 
        N.E--> North-East   (row-1, col+1) 
        N.W--> North-West   (row-1, col-1) 
        S.E--> South-East   (row+1, col+1) 
        S.W--> South-West   (row+1, col-1) 
    */

    //Comprobar Las 8 Posiciones de la matrix 3x3 
    //Si es una posicion valida y es una mina entonces mines++
    for(int i = col-1; i <= col+1; i++)
         for(int j = row-1; j <= row+1; j++)
            if(is_valid(j,i,matrix_original) && ((j != row) || (i != col)))
                if(matrix_original[i][j])
                    mines++;

    return mines;
}

vector<vector<int>> minesweeper(const vector<vector<bool>> &matrix) 
{
    //Nota: True->1 Hay Mina | False->0 No hay Mina
    //Creamos la matrix resultante
    vector<vector<int>> result;

    //Recorrer la matrix con la informacion de las minas
    for(int i = 0; i < matrix.size(); i++)
    {
        vector<int> aux;
        for(int j = 0; j < matrix[0].size(); j++)
        {
            //Poner los numeros correspondientes a cada posicion
            aux.push_back(numbers_mine(j,i,matrix));
        }
        result.push_back(aux);
    }
    return result;
}

void print_matrix(const vector<vector<int>> &matrix)
{
    cout << "Test - Minesweeper\n";
    //Recorrer la matrix y mostrar cada elemento de ella
    for(auto v : matrix)
    {
        for(auto i : v)
            cout << i << " ";
        cout << "\n";
    }
}