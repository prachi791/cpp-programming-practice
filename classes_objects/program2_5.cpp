#include <iostream>
#include <math.h>
using namespace std;

class EMI{
    string name;
    int loanID;
    float amount;
    float interestRate;
    int tenure;
    double emi;
    public:
        EMI(){
            loanID = 1;
            amount = 100000;
            interestRate = 8;
            tenure = 24;
            emi = (amount * (interestRate/1200) * pow(1 + (interestRate/1200), tenure)) / (pow(1 + (interestRate/1200), tenure) - 1);
        }
         EMI(float loanAmt,float rate, int duration ){
            amount = loanAmt;
            interestRate = rate;
            tenure = duration;
            emi = (amount * (interestRate/1200) * pow(1 + (interestRate/1200), tenure)) / (pow(1 + (interestRate/1200), tenure) - 1);
        }

        void display(){
            cout << "----------Loan Display system----------" << endl;
            cout <<"Loan ID: " << loanID << endl;
            cout << "Loan Amount: " << amount << endl;
            cout << "Interest rate: " << interestRate << "%" << endl;
            cout << "Tenure: " << tenure << " Months" << endl;
            cout << "EMI: " << emi << endl;
        }
};
int main(){
    cout << endl;
    cout << "---This is a test case with default values:::---" << endl << endl;
    EMI Loan;
    Loan.display();
    cout << endl;
    cout << "---This is a test case with user defined values:::---" << endl << endl;
    EMI Loan2(500000, 10, 60);
    Loan2.display();

    return 0;
}