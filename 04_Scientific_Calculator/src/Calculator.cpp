#include <stdio.h>

#include "Calculator.h"

typedef void (*fptrOperation)(double, double);

double Calculator::result; // Necessary as we have defined result to be static
/*
Calculator::Calculator() {
    // Standard initial set up
    number1 = 30;
    number2 = 3;
    operation = "+";
}*/

Calculator::Calculator(double num1, double num2, char oper) {
    setNumbers(num1, num2);
    setOperation(oper);
    printf("The calculator has been initialized with num1 = %lf, num2 = %lf and oper = %c\n",number1,number2,oper);
}

Calculator::~Calculator(){
    printf("The calculator has been closed\n");
}

void Calculator::setNumbers(double num1, double num2) {
    number1 = num1;
    number2 = num2;
}

void Calculator::setOperation(char oper){
    operation = oper;
}

// we need to define the operation functions as static
// because 'select' is not part of the  class,
// so it could not access to them
fptrOperation select(char oper){
    switch(oper){
        case '+' : return Calculator::Addition; break;
        case '-' : return Calculator::Substraction; break;
        case '*' : return Calculator::Multiplication; break;
        case '/' : return Calculator::Division; break;
        //case '%' : return Modulo; break;

        default:
          printf("Invalid operation\n");
          return nullptr;
    }
}

void Calculator::Operate(){
    fptrOperation OPERAT = select(operation);
    OPERAT(number1, number2);
}
