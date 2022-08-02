#include <iostream>
#include "complex.h"
#include "menu.h"

using namespace std;

void menuCout () {
    cout << "\n------------" << endl;
    cout << "----MENU----" << endl;
    cout << "------------" << endl;
    cout << "1 - Add" << endl;
    cout << "2 - Sub" << endl;
    cout << "3 - Mul" << endl;
    cout << "4 - Div" << endl;
    cout << "5 - Terminate" << endl;
    cout << "Choose: ";
    cin >> option;
}   

void stopCout () {
    do {
       cout << "\n--------------" << endl;
        cout << "---CONTINUE---" << endl;
        cout << "--------------" << endl;

        cout << "1 - Yes" << endl;
        cout << "2 - No (Terminate)" << endl;
        cout << "Choose: ";
        cin >> stoption;

        switch (stoption) {
            case 1:
                break;
            case 2:
                exit (EXIT_FAILURE);
                break;
            default:
                cerr << "\nWrong option." << endl;
                break;
        } 
    } while (stoption != 1);
}


void menu (Comp a, Comp b) {
    do {
        menuCout();

        switch (option) {
            case 1:
            {
                Comp add = add.Add (a, b);
                cout << "\nResult of add: "; add.print();
                stopCout ();
                break;
            }
            case 2:
            {
                Comp sub = sub.Sub (a, b);
                cout << "\nResult of sub: "; sub.print();
                stopCout ();
                break;
            }  
            case 3:
            {
                Comp mul = mul.Mul (a, b);
                cout << "\nResult of mul: "; mul.print();
                stopCout ();
                break; 
            }
            case 4:
            {
                Comp div = div.Div (a, b);
                cout << "\nResult of div: "; div.print();
                stopCout ();
                break;
                
            }
            case 5:
                break;
            default:
                cerr << "\nWrong option." << endl;
                break;
        }
    } while (option != 5);
}
