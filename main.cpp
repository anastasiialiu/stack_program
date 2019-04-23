//
// Created by Anastasiia Burlya on 3/20/19.
//

#include <iostream>
using namespace std;

#include "stack.h"
#include "stack.cpp"

//function to find precedence
int precedence(char oper)
{
    if (oper == '+' || oper == '-')
        return 1;
    if (oper == '*' || oper == '/')
        return 2;
    return 0;
}

//function to perform calculation
int calculate (int a, int b, char oper)
{
    switch (oper)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

//function that evaluates the expression
// and returns the result
int evaluate (string exp)
{

    // stack of integers
    Stack <int> value;

    //stack of operators
    Stack <char> oper;

    //delete spaces
    for (int i = 0; i < exp.length(); i++)
    {

        if(exp[i] == ' ')
        {
            continue;
        }

        else if (exp[i] == '(')
        {
            oper.push(exp[i]);
        }

        //push if a number
        else if (isdigit(exp[i]))
        {
            int val = 0; //temporary var that holds digit

            //check if there are more numbers
            val = (val * 10) + (exp[i] - '0');
            while (i < exp.length() && isdigit(exp[i+1]))
            {
                val = (val * 10) + (exp[i+1] - '0');
                i++;
            }

            value.push(val);
        }

        //check if any of the numbers are negative
        else if (exp[i] == '-' && (i == 0 || exp[i-1] == '*' || exp[i-1] == '/' || exp[i-1] == ')' ))
        {

            if (isdigit(exp[++i]))
            {
                //temporary var that holds digit
                int val = 0;

                //check if there are more numbers
                val = (val * 10) + (exp[i] - '0');

                while (i < exp.length() && isdigit(exp[i + 1]))
                {
                    val = (val * 10) + (exp[i + 1] - '0');
                    i++;
                }

                //convert to negative
                value.push(val * -1);
            }
        }
        // if closing brace, solve
        // expression inside the braces
        else if (exp[i] == ')')
        {

            while (!oper.isEmpty() && oper.top() != '(')
            {

                int val2 = value.top();
                value.pop();

                int val1 = value.top();
                value.pop();

                char operate = oper.top();
                oper.pop();

                value.push(calculate(val1, val2, operate));
            }

            //pop open brace
            oper.pop();
        }
        else
        {
            while (!oper.isEmpty() && precedence(oper.top()) >= precedence(exp[i]))
            {
                int val2 = value.top();
                value.pop();

                int val1 = value.top();
                value.pop();

                char operate = oper.top();
                oper.pop();

                value.push(calculate(val1, val2, operate));
            }

            oper.push(exp[i]);

        }
    }

    while (!oper.isEmpty())
    {
        int val2 = value.top();
        value.pop();

        int val1 = value.top();
        value.pop();

        int operate = oper.top();
        oper.pop();

        value.push(calculate(val1, val2,operate));
    }

    return value.top();
}

int main() {

    string expression; //holds math expression

    cout << "Enter the expression:" << endl;
    getline(cin, expression);

    cout << "Result: " << evaluate(expression) << endl;

    return 0;
}
