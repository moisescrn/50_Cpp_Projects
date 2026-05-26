#include <stdio.h>

#include "Calculator.h"

int main(){
    Calculator Calc(21.9,333.11,'-');

    Calc.setNumbers(30.6,3.111);
    Calc.setOperation('+');

    double rrr = Calc.returnResult();
    printf("The program has worked correctly\n");
    printf("The result is %lf\n",rrr);
    return 0;
}
