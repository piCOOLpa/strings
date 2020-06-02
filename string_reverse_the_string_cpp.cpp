// recursion_head-recursion_tail-recursion_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void headrecursive_function(string &passedword , int length)
{
    static int index = 0;
    // first call the sub-problem and then solve the sub-problem:

    //check if the problem is already solved [base case] , no more function call 
    if (length < passedword.size())
    {
        headrecursive_function(passedword, length + 1);

        // swap the string with the indices only  till the index value reaches half of the string length 
        // recursive state at which the swap happens : (passedword , stringlength - 1)


        if (index < length)
        {
            swap(passedword[index++], passedword[length]);
        }

    }

}


void tailrecursive_function(string& passedword, int start , int end)
{
    
    // solve the problem and then check if the sub-problem exist --> if sub-prob exist make the recursive call 
     

    if (start < end)
    {
        swap(passedword[start], passedword[end]);
        // solve the problem 

        tailrecursive_function(passedword, ++start,--end);
    }
}

void reversefunction_using_stack(string& passedword)
{

    stack<int> reverse_word_stack;
    int stringlength = passedword.length() - 1;

    for (int i = 0 ; i < passedword.length() ; i++)
    {
        // push the index into the stack 
        reverse_word_stack.push(i);
    }
    // building the stack 

    for (int start = 0; start < (passedword.length()) / 2; start++)
    {
       int end = reverse_word_stack.top() ;
       swap(passedword[start], passedword[end]);
       // swap the string at the start and the end index  

       reverse_word_stack.pop();

    }
    // actual reversal 

}
int main()
{
    string givenword;
    // input string.

    int choice;
    cout << "enter the string:\n";
    cin >> givenword; 

    // menu for the reversing 
    cout <<"menu :\n";
    cout <<"1 - head recursion \n";
    cout <<"2 - tail recursion \n";
    cout <<"3 - stack reverse  \n";
    cout <<"enter the choice :";
    cin  >> choice;

    switch (choice)
    {
     case 1:  
            cout << "the string  before reversing :";
            // check the contents of the collection before the swap 

            cout << givenword; 

            cout << endl;

            cout << "the string  after reversing :";

            headrecursive_function(givenword , 0);
            // recursive function call to reverse the string.

            cout << givenword;
            break; 

     case 2:
         cout << "the string  before reversing :";
         // check the contents of the collection before the swap 

         cout << givenword;

         cout << endl;

         cout << "the string  after reversing :";

         tailrecursive_function(givenword, 0 , givenword.length() - 1 );
         // recursive function call to reverse the string.

         cout << givenword;
         break;  

     case 3:
         cout << "the string  before reversing :";
         // check the contents of the collection before the swap 

         cout << givenword;

         cout << endl;

         cout << "the string  after reversing :";

         reversefunction_using_stack(givenword);
         // recursive function call to reverse the string.

         cout << givenword;
         break;
     default : 
               cout << "wrong input choice ";
    }

}

