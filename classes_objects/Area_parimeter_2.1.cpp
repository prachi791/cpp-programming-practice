#include <iostream>
using namespace std;

class Rectangle {
private:
    double length=0;
    double width=0;

public:
    bool setDimensions(double l, double w) {
        if (l > 0 && w > 0 && l != w) {
            length = l;
            width = w;
            cout << "Rectangle dimensions set successfully.\n";
            return true;
        } else {
            cout << "Invalid dimensions (Must be positive and should not be same).\n";
            return false;
        }
    }

    void updateDimensions() {
        double l, w;

        cout << "Enter new length: ";
        cin >> l;

        cout << "Enter new width: ";
        cin >> w;

        if (l > 0 && w > 0 && l != w) {
            length = l;
            width = w;
            cout << "Dimensions updated successfully.\n";
        } else {
            cout << "Update failed (Invalid dimensions).\n";
        }
    }

    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }

    void displayDetails(int index) {
        cout << "\nRectangle Index: " << index;
        cout << "\nLength: " << length;
        cout << "\nWidth: " << width;
        cout << "\nArea: " << calculateArea();
        cout << "\nPerimeter: " << calculatePerimeter() << endl;
    }
};

int main() {
    Rectangle rects[10];
    int count = 0;

    int choice;
    int index;
    double l, w;

    do {
        cout << "\n----- RECTANGLE MENU -----\n";
        cout << "1. Create New Rectangle\n";
        cout << "2. Update Rectangle Dimensions\n";
        cout << "3. Display All Rectangles\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
            {
                if (count < 10) {
                    cout << "Enter length: ";
                    cin >> l;

                    cout << "Enter width: ";
                    cin >> w;

                   if( rects[count].setDimensions(l, w)){
                       count++;
                   }
                } else {
                    cout << "Cannot create more rectangles (Limit reached).\n";
                }
                break;
            }

            case 2:
            {
                if (count == 0) {
                    cout << "No rectangles available (Create first).\n";
                    break;
                }

                cout << "Enter rectangle index: ";
                cin >> index;

                if (index >= 0 && index < count) {
                    rects[index].updateDimensions();
                } else {
                    cout << "Invalid rectangle index.\n";
                }
                break;
            }

            case 3:
            {
                if (count == 0) {
                    cout << "No rectangles to display.\n";
                } else {
                    for (int i = 0; i < count; i++) {
                        rects[i].displayDetails(i);
                    }
                }
                break;
            }

            case 4:
            {
                cout << "Exiting program.\n";
                break;
            }

            default:
            {
                cout << "Invalid choice.\n";
            }
        }

    } while(choice != 4);

    return 0;
}
