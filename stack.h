//
// Created by Anastasiia Burlya on 3/20/19.
//

#ifndef STACK_STACK_CPP_H
#define STACK_STACK_CPP_H
template <class x>
struct Node {
    x info;                                  //holds info
    Node<x> *next;                           //node pointer
};

template <class x>
class Stack {
private:
    Node<x> *first;                         //set pointer to the first element
    int length;                             //variable to hold the size of the stack

public:
    Stack();                                //constructor
    Stack(const Stack<x>& other);           //copy constructor
    ~Stack();                               //destructor
    void Copy(const Stack<x> &other);       //function to copy stack
    void operator=(const Stack<x> &other);  //'=' operator overload
    void push(x item);                      //function to put stuff in a stack
    void pop();                             //function to take stuff out of the stack
    x top();                                //function to see what is on top of the stack
    bool isEmpty();                         //function to check if the stack is empty
};

#endif //STACK_STACK_CPP_H

