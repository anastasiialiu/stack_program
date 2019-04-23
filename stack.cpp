//
// Created by Anastasiia Burlya on 3/20/19.
//
#include "stack.h"
#include <iostream>
using namespace std;

//Constructor
template <class x>
Stack<x>::Stack()
{
    length = 0;
    first = nullptr;
}

//Destructor
template <class x>
Stack<x>::~Stack()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        Node<x> *temp;

        while (first != nullptr)
        {
            temp = first;
            first = first->next;
            delete temp;
        }
        length = 0;
    }
}

//Push items into stack
template <class x>
void Stack<x>::push(x item)
{

    //if stack is empty, create new item
    if (length == 0)
    {
        first = new Node<x>;
        first->info = item;
        first->next = nullptr;
    }

    //push item in the stack
    Node<x> *newNode = new Node<x>;
    newNode->info = item;
    newNode->next = first;
    first = newNode;

    length++;
}


//Copy function
template<class x>
void Stack<x>::Copy(const Stack<x> &other)
{
    length = other.length();
    Node<x> *q = other.first;

    this->first = new Node<x>;
    this->first->info = q->info;
    this->first->next = nullptr;

    //Walking pointers to traverse the stack for deep copy
    Node<x> *walk1 = first;
    Node<x> *walk2 = q;

    while (walk2 != nullptr)
    {
        walk1->next = new Node<x>;
        walk1->next->info = walk2->info;
        walk1->next->next = nullptr;

        walk2 = walk2->next;
        walk1 = walk1->next;
    }
}


//Pop items out of stack
template <class x>
void Stack<x>::pop()
{
    if (isEmpty())
    {
        return;
    }

    Node<x> *temp = first;
    first = first->next;

    delete temp;
    length--;
}


//Function to check what the last item in
template<class x>
x Stack<x>::top()
{
    if (isEmpty())
    {
        return 0; //is empty
    }

    return first->info;
}


//Copy constructor
template <class x>
Stack<x>::Stack(const Stack<x> &other)
{
    if (other.first == nullptr)
    {
        cout << "Empty!";
        return;
    }
    Copy(other);
}

//Function to overload '=' operator
template <class x>
void Stack<x>::operator=(const Stack<x> &other)
{
    if (other.first == nullptr)
    {
        cout << "Empty";
        return;
    }

    Copy(other);
}

//Function to check if the stack is empty
template  <class x>
bool Stack<x>::isEmpty()
{
    return length == 0;

}
