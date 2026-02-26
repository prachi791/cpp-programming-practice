#include<iostream>
#include <string>
#include<unistd.h>
using namespace std;

class bank{
        int balance[50];
        string userName1[50];
        int accountNo[50];
        int accNo;
        int withdrawAmt;
        public:
        void createAccount(){
            static int i = 0;
        cout << "enter name: ";
        cin >> ws;
        getline(cin,userName1[i]);
        accountNo[i] = 1 + i;
        cout << "Congratulations! Account created successfully!! \nAccount no.: " << accountNo[i] << endl;
        sleep(2);
        start:
        cout << "how much amount you want to deposit? (maintain at least 10,000 balance): ";
        cin >> balance[i];
        if (balance[i] < 10000){
            cout << "ERROR: deposit should be atleast 10,000 rs." << endl;
            goto start;
        }else{
                cout << "Account created!" << endl;
                cout << "Name: " << userName1[i] << endl;
                cout << "Account no.: " << accountNo[i] << endl;
                cout << "Initial balance: " << balance[i] << endl;
            }
            i++;

        }
        public:
    void deposit(){
        int j =0;
        cout << "Enter account no.: ";
        cin >> accNo;
        while (accountNo[j] != '\0'){
        if (accNo == accountNo[j]){
            cout << "Enter amount to be deposited: ";
            int amount;
            cin >> amount;
            balance[j] += amount;
            cout << "Amount deposited successfully! \nNew balance: " << balance[j] << endl;
            break;
        }else if (accNo != accountNo[j] && accountNo[j] != '\0'){
            j++;
            continue;
            
        }
        else{
            cout << "Invalid account no." << endl;
        }
        }
    }
        public:
    void withdraw(){
        cout << "Enter account no.: ";
        cin >> accNo;
        int k = 0;
        while (accountNo[k] != '\0'){
        if (accNo == accountNo[k]){
             cout << "Enter withdraw amount: ";
            cin >> withdrawAmt;
            if (withdrawAmt > balance[k]){
                cout << "Insufficient balance! \nEnter balance less than " << balance[k] << endl;
            }else{
                balance[k] -= withdrawAmt;
                cout << "Please collect your cash. \nNew balance: " << balance[k] << endl;
                break;
            }
        } else if (accNo != accountNo[k] && accountNo[k] != '\0'){
            k++;
            continue;
        }else{
            cout << "Invalid account no." << endl;
        }
        }
    }
};

int main(){
    bank t1;
    int choice;
    cout << "Menu: \n1. Create Account \n2. Deposit \n3. Withdraw \n4. Exit" << endl;
    do{
            cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1: {
            t1.createAccount();
            break;
            }
            case 2: {
            t1.deposit();
            break;
            }
            case 3: {
            t1.withdraw();
            break;
            }
           if(choice > 4 || choice < 1){
                cout << "Enter valid choice!!" << endl;
           }
        }
    }while(choice != 4);
        if(choice == 4){
                cout << "Thank you for visiting!!" << endl;
        return 0;
        }
}
