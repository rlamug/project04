//calc.cpp
//Rodolfo Lamug
//rlamug

//Libraries used
#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<sstream>
#include<iomanip>
#include<cctype>

//dstack used
#include"dstack.h"

using namespace std;

//function protoypes
void popNumbers(double&, double&);
bool decimal(double);
void error();
void add(double, double);
void subtract(double, double);
void multiply(double, double);
void divide(double, double);
void exponent(double, double);

//object declaration of class dstack
Dstack math;
int main()
{
        //variable declaration
        char operation;
        double input;
        double next;// next input taken
        double num1 = 0;
        double num2 = 0;

        while(cin.peek() != EOF)
        {
                cin >> ws;// stands for white space and is used to get all the white spaces the user enters 
                next = cin.peek();
                if( isdigit(next) || cin.peek() == '.')
                {
                        cin>>input;
                        if(cin.good())
                        {
                                math.push(input);
                                if(cin.peek() == '.')
                                {
                                        error();
                                }
                        }
                        else
                        {
                                error();
                        }
                }
                //cctype library used here to check if input is punctuation character
                else if (ispunct(next))
                {
                        cin>>operation;

                        //operation functions
                        if(operation == '+' && math.size() >= 2)//add
                        {

                                add(num1, num2);
                        }
                        else if (operation == '-' && math.size() >= 2)//subtract
                        {

                                subtract(num1, num2);
                        }

                        else if(operation == '*' && math.size() >= 2)//multiply
                        {

                                multiply(num1, num2);
                        }
                        else if (operation == '/' && math.size() >= 2)//divide
                        {

                                divide(num1, num2);
                        }

                        else if(operation == '^' && math.size() >= 2)//exponent
                        {

                                exponent(num1, num2);
                        }
                        //Sends error if the stack is not large enough for operations
                        else if (math.size() < 2)
                        {

                                error();
                        }

                        //Sends error if a letter is entered
                        else if (isalpha(next))
                        {

                                error();
                        }
                }
                if(collec.size() >= 2){
                }
                //Prints out the stack
                math.print();
                return 0;
        }


        //function definitions

        //add function: adds two values and pushs to stack
        void add(double num1, double num2)
        {

                double result;
                popNumbers(num1, num2);
                result = num1 + num2;
                math.push(result);
        }
        //subtract function: subtracts two values and pushes to stack
        void subtract(double num1, double num2)
        {

                double result;
                popNumbers(num1, num2);
                result = num1 - num2;
                math.push(result);
        }
        //multiply function
        void multiply(double num1, double num2)
        {

                double result;
                popNumbers(num1, num2);
                result = num1 * num2;
                math.push(result);
        }
        //divide function
        void divide(double num1, double num2)
        {

                double result;
                popNumbers(num1, num2);
                if(num2 == 0) //prevents division by zero
                {

                        error();
                }
                result = num1 / num2;
                math.push(result);
        }
        //decimal function: returns true if number is decimal or false if not.
        bool decimal(double input)
        {

                ostringstream changer;
                string num;
                changer << input;
                num = changer.str();
                int numLength = num.length();

                for(int i = 0; i < numLength; i++)
                {
                        if(num[i] == '.') //confirms number is a decimal by looking for a period . and then returns true
                        { 

                                return true;
                        }
                }
                return false;
        }
        //exponent function
        void exponent(double num1, double num2)
        {

                double result;
                popNumbers(num1, num2);
                if(num1 < 0 && decimal(num2))
                {

                        error();
                }
                result = pow(num1, num2);
                if(isinf(result))
                {

                        error();
                }
                math.push(result);
        }

        //function that removes the two inputed values from the stack
        void popNumbers(double &num1, double &num2)
        {

                math.pop(num2);
                math.pop(num1);
        }
        //error message function
        void error()
        {

                cerr << "Error: Invalid expression."<<endl;
                exit(1);
        }
