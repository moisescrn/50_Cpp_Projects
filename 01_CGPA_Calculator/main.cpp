/* CGPA calculator
The grades shall be given as percentages (0-100),
although computing it for a different grading system is exactly the same
The weight (credits) of each subject may be given from 0 to 10
*/

#include <iostream>
#include <cstdarg>    // Contains va_list, va_start, ...

double cgpa(int n_args, ...){
    // First argument is the number of subjects
    // The rest of arguments shall be "grade and weight" alternantingly

    double sum = 0.0; // double to enable a double result at the end

    // Read the arguments
    va_list args;
    va_start(args,n_args);

    for (int i = 0; i < n_args; i++){
        sum += va_arg(args, int) * va_arg(args,int); // Grade*Weight
    }
    va_end(args);

    double mean = sum / n_args;

    return mean;
}

int main(){
    double cf = cgpa(3,70,3,20,5,0,2);
    return 0;
}
