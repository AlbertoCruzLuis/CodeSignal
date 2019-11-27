//
//
//  Author: Alberto Cruz Luis
//  Date: 27/11/2019
//  https://github.com/AlbertoCruzLuis
//
///////////////////////////////////

//How the Code Works?
//Step 1: Choose one Algorithm and comment the other

//Problem
//Given a sequence of integers as an array, determine whether it is possible 
//to obtain a strictly increasing sequence by removing no more than one element
// from the array.

//If all element are minor that the following  (a0 < a1 < ... < an) is True

//----------Example 1 -------------

//For sequence = [1, 3, 2, 1], the output should be
//almostIncreasingSequence(sequence) = false.

//There is no one element in this array that can be removed in order 
//to get a strictly increasing sequence.

//----------Example 2 --------------

//For sequence = [1, 3, 2], the output should be
//almostIncreasingSequence(sequence) = true.

//You can remove the element 3 from the array
//to get the strictly increasing sequence [1, 2].
//Alternately, you can remove 2 to get the strictly increasing sequence [1, 3].

#include<iostream>
#include<vector>

using namespace std;

bool almostIncreasingSequence(vector<int>);

int main()
{
    vector<int> Seq;
    //Input, Modify it to check the correct performance of the algorithm
    //Other Example: Seq = {30, 60, 50, 80, 100, 200, 150} - Solution: False
    Seq = {1, 2, 3, 4, 3, 6};  

    bool result;

    result = almostIncreasingSequence(Seq);

    cout << "Solucion: ";

    if(result == 0)
    cout << "False"<<endl;
    else
    cout << "True" <<endl;
}

//Algorithm O(n^2) - Inefficient
//This algorithm face off everyone against everyone.

bool almostIncreasingSequence(vector<int> sequence) {
    
    bool check = true;
    
    for(int i = 0; i < sequence.size(); i++)
    {
        vector<int> temp(0,0);  //Set the temporal vector to 0 in each iteration.
        temp = sequence;
        temp.erase(temp.begin()+i); //Remove one element in each iteration
        
        for(int j = 1; j < temp.size(); j++)
        {
                //Check if all the elements are minor to the following element
                if(temp[j-1] < temp[j])
                {
                    check = true;
                }else
                {
                    check = false;
                    break;
                }
        }
        if (check == true)  return true;
    }
    return false;
}

//Algorithm O(n) - This is the Correct for solved the Challenge in CodeSignal

bool almostIncreasingSequence(vector<int> sequence) {
    
    vector<int> temp;
    temp = sequence;
    bool check = true;

    //Search what is the index to remove
    for(int i = 2; i < sequence.size(); i++)
    {
        //We search the first major value 
        if(temp[i-2] >= temp[i-1])
        {
            if(temp[i-2] < temp[i])
            temp.erase(temp.begin()+(i-1));
            else
            temp.erase(temp.begin()+(i-2));
            break;
        }   
    }

    //Check if don't remove any element
    //Step to avoid a new loop in same cases
    if(sequence.size() == temp.size())  return true;

    //Go through the new vector 
    for(int i = 1; i < temp.size(); i++)
    {   
        //Check if all the elements are minor to the following element
        if(temp[i-1] < temp[i])
        {
            check = true;
        }else
        {
            check = false;
            break;
        }
    }
    if(check == true)   return true;

    return false;
}