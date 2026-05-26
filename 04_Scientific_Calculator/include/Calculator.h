
#ifndef CALCULATION_H
#define CALCULATION_H

class Calculator {
private:
    double number1;
    double number2;
    char operation; // +, -, *, /, %
    static double result;

public:
    // Constructor and destructor
    //Calculator();
    Calculator(double num1, double num2, char oper);
    ~Calculator();

    void setNumbers(double num1, double num2);
    void setOperation(char oper);
    void Operate();
    double returnResult() { Operate(); return result; }

    // make the functions static, so that we can point to them in Calculator.cpp
    static void Addition(double num1, double num2) { result = num1 + num2; }
    static void Substraction(double num1, double num2) { result = num1 - num2; }
    static void Multiplication(double num1, double num2) { result = num1 * num2; }
    static void Division(double num1, double num2) { result = num1 / num2; }
    //void Modulo(double num2, double num2) { result = num1 % num2; }

};
#endif /* CALCULATION_H */
