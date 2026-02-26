#include<iostream>
#include<string>
using namespace std;

class student{
    int RollNo;
    string name;
    float marks[3];
    float Average;
    public:
    void SetMarks(int index, float values){
        if( values >= 0 && values <= 100){
            marks[index] = values;
        }
        else {
            cout << "Invalid marks entered. please enter marks between 0 and 100." << endl;
            marks[index] = 0;
        }
    }
    student(){
        RollNo = 44;
        name = "Shubham mendapara";
        marks[0] = 95;
        marks[1] = 90;
        marks[2] = 85;
    }
    student(int r, string n, float m1, float m2, float m3){
        RollNo = r;
        name = n;
        SetMarks(0, m1);
        SetMarks(1, m2);
        SetMarks(2, m3);
    }
    void AverageMarks(){
        Average = (marks[0] + marks[1] + marks[2]) / 3;
    }
    void display(){
        cout << "-----------------------------" << endl;
        cout << "-----------------------------" << endl;
        cout << "student name: " << name << endl << endl;
        cout << "ID No.: " << RollNo << endl << endl;
        cout << "Average marks: " << Average << endl;
        cout << "-----------------------------" << endl;
    }
};
int main(){
    int r,choice;
    float m1, m2, m3;
    string n;
    cout << "----------Student Acedemic Record System----------" << endl;
    cout << "Menu: \n1. user input \n2. defualt case \n3. exit" << endl;
    while(true){
        cout << "Enter your choice: ";   
        cin >> choice;
        switch(choice){
    case 1:{
    cout << "Enter your roll number: ";
    cin >> r;
    cin.ignore();
    cout << "Enter the name of the student: ";
    getline(cin,n);
    cout << "Enter marks of 3 subjects: ";
    cin >> m1 >> m2 >> m3;
    student s1(r, n, m1, m2, m3);
    s1.AverageMarks();
    s1.display();
    break;
    }
    case 2:{

        student s2;
        s2.AverageMarks();
        s2.display();
        break;
    }
    case 3: return 0;
        }
    }
    return 0;
}