//dstack.h
//Rodolfo Lamug
//rlamug
#ifndef DSTACK_H
#define DSTACK_H

#include<iostream>
#include<string>

using namespace std;

class Dstack{

        public:
                Dstack();
                ~Dstack();
                void push(double value);
                bool pop(double &value);
                int size();
                bool empty();
                void print();

        private:
                // node declared
                class Node{

                        public:
                                Node(double value, Node *next){

                                        m_value = value; m_next = next;
                                }
                                double m_value;
                                Node *m_next;
                };
                Node *top;
};
#endif
