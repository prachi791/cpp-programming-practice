/* 
--------------This program is a grocery store system where following operations are done:------------------------
* 1. adding product : can easily add products with name, quantity and price
* 2. automatic ID generation without any repeated ID to another product
* 3. get price of the registerd product : Given a product ID, this function calculates and returns the total value of that product available in the store.
* 4. Update product : This function updates the quantity of the registered product where it can be sold (-) or new stock added (+), it handles both operations
*    and provides real time modified answer.  
* 5. Display function : This function displays all the registered items with their information. It is also updated real time and so we get accurate answer everytime.
**************
* the menu option is set up in main() function and i have used switch case to use proper function in each case.
* a while loop is used so that it can ask the choice of the user each time and user doesn't have to run the program again and again.
* Exit case is also handeled properly here!
*/

#include<iostream>
using namespace std;

class products{
    float total;
    int ID, PID;
    string PName;
    int Qty;
    float price;
    public:
    void addProduct(){
        static int m = 0;
        cout << "Product name: ";
        cin >> PName;
        cout << "Quantity: ";
        cin >> Qty;
        cout << "price: ";
        cin >> price;
        ID = 1 + m;
        cout << "ID generated: " << ID << endl;
        m++;
        }
    public:
    void get_price(){
    total = Qty * price;
    cout << "Total price is : " << total << endl;
        }
    public:
    void update_product(){
        int choice;
        int newQty;
        choice:
        cout << "1. increment \n2. decrement \nEnter choice: ";
        cin >> choice;
        cout << "Enter Quantity: ";
        cin >> newQty;
        if(choice == 1) {
                Qty += newQty;
            }
        else if (choice == 2) {
                Qty -= newQty;
            }
        else {
                cout << "enter valid choice!" << endl;
                goto choice;
            }
        }
    public:
    void display(){
        cout << "Product: " << PName<< endl;
        cout << "Quantity: " << Qty << endl;
        cout << "ID: " << ID << endl;
        cout << "Price: " << price << endl;
        }
};
int main(){
    int total_products=0;
    int number;
    int ID;
    int choice;
    products p1[4];
    cout << "Menu: \n1. Add product \n2. get price of the product \n3. update product \n4. display all products \n5. Exit" << endl;
    while(true){
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1: {
                cout << "How many products do you want to add? : ";
                cin >> number;
                total_products += number;
                for(int i = 0 ; i < number ; i++){
                p1[i].addProduct();
                    }
                break;
            }
            case 2: {
                cout << "enter product ID: ";
                cin >> ID;
                p1[ID].get_price();
                break;
            }
            case 3: {
                cout << "Enter product ID: ";
                cin >> ID;
                p1[ID].update_product();
                break;
            }
            case 4: {
                for (int k = 0; k < total_products ; k++){
                    p1[k].display();
                }
                break;
            }
            case 5: {
                return 0;
            }
        }
    }
    return 0;
}
