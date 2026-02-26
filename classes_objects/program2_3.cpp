#include <iostream>
#include <string>
using namespace std;

class Bank{
    string name;
    public: int ID;
    float amount;
    float balance = 0;
    public:
        void Account(){
            static int i = 0;
            cin.ignore();
            cout << "Enter the name of the account holder: ";
            getline(cin,name);
            ID = i + 1;
            i++;
            cout << "Do you want to deposit some amount? (1 -> yes/0 -> no): ";
            int choice;
            cin >> choice;
            if(choice == 1){
                cout << "Enter the deposit amount: ";
                cin >> amount;
                balance += amount;
            }else if(choice == 0){
                balance = 0;
            }else{
                cout << "Invalid input! Account created without deposit." << endl;
                balance = 0;
            }
            cout << "Account created successfully!" << endl;
        }

        void display(){
            cout << "===============================" << endl;
            cout << "Name: " << name << endl;
            cout << "ID: " << ID << endl;
            cout << "Balance: " << balance << endl;
        }
};
int main(){
    int flag = 0;
    int choice;
    Bank entry[50];
    cout << "==========Digital Savings Bank Account System===========" << endl;
    cout << endl;
    cout << "Menu: \n1. Create a new account \n2. Check your account details \n3. Exit" << endl;
    while(true){
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice){
        case 1:
        {
            static int i = 0;
            entry[i].Account();
            i++;
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter your account ID: ";
            cin >> id;
            for(int j = 0; j < 50; j++){
                if(entry[j].ID == id){
                    entry[j].display();
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                cout << "Account not found!" << endl;
            }
            flag = 0;
            break;
        }
        case 3: 
        {
            cout << "Exiting the program. Thank you for using our services!" << endl;
            return 0;
        }
    }
}
    return 0;
}