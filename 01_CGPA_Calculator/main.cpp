/* CGPA calculator
The grades shall be given as percentages (0-100),
although computing it for a different grading system is exactly the same
The weight (credits) of each subject may be given from 0 to 10
*/

#include <iostream>
using namespace std;

// Let's work with pointers, since it has more flexibility than arrays

double cgpa(int n_subj, int* grades, int* weights){
    // First argument is the number of subjects
    // The second is the address of where the grades begin
    // The third is the address of where the weights begin

    // prepare enough memory for each "array" of numbers
    //grades = (int*)malloc(sizeof(int)*n_subj);
    //weights = (int*)malloc(sizeof(int)*n_subj);
    // for the flow of this program we have to prepare the memory before the input
    // but in a more general case I think we would need this here

    double sum = 0.0; // double to enable a double result at the end
    int total_weights = 0;

    for (int i = 0; i < n_subj; i++){
        sum += *(grades+i) * *(weights+i);
        total_weights += *(weights+i);
    }

    return sum / total_weights;
}

int main(){
    int n_subj;
    cout << "How many subjects do you have? ";
    cin >> n_subj;

    int* grades = (int*)malloc(sizeof(int)*n_subj);
    int* weights = (int*)malloc(sizeof(int)*n_subj);

    for (int i = 0; i < n_subj; i++) {
        cout << "Grade " << i+1 << ":\t";
        cin >> *(grades+i);
        cout << "Weight " << i+1 << ":\t";
        cin >> *(weights+i);
        cout << endl;
    }

    double cf = cgpa(n_subj,grades,weights);
    cout << "CGPA:\t\t" << cf << endl;

    return 0;
}
