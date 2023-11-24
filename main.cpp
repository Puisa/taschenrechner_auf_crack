// intelligenter Taschenrechner
#include "std_lib_inc.h"

int schrift_zu_ziffer(string x)         // konvertiert das geschriebene Wort in eine Zahl
{
    if (x == "ein" || x == "eins")      // ermöglicht Erkennung von "eins" und "ein" als 1
        return 1;
    else if (x == "zwei")
        return 2;
    else if (x == "drei")
        return 3;
    else if (x == "vier")
        return 4;
    else if (x == "fuenf")
        return 5;
    else if (x == "sechs")
        return 6;
    else if (x == "sieben")
        return 7;
    else if (x == "acht")
        return 8;
    else if (x == "neun")
        return 9;
    else if (x == "zehn")
        return 10;
    else if (x == "null")
        return 0;
    else {                  // abweichende Eingabe wird als ungültig erkannt
        cout << "Ungültige Eingabe für schrift_zu_ziffer: " << x << endl;
        return -1;
    }
}


// Eingabe einer Rechenoperation und Berechnung d. Ergebnisses

int addition(int x, int y)
{
    return x+y;
}
int subtraktion(int x, int y)
{
    return x-y;
}
int multiplikation(int x, int y)
{
    return x*y;
}
double division(int x, int y)
{
    if(y != 0){
        return double(x)/y;
    }
    else{
        cout << "Fehler: Division durch Null";
        return -1;
    }
}
double geteilt(int x, int y)
{
    if(y != 0){
        return x/y;
    }
    else{
        cout << "Fehler: Geteilt durch Null";
        return -1;
    }
}

// Ausgabe
int main()
{
    string operand1, operation, operand2;
    vector<double>ergebnisse={}; // vector um Ergebnisse zu speichern

    while(true) {
        cin >> operand1;
        if(operand1 == "ende") {
            break;
        }
        cin >> operation;
        cin >> operand2;

        int x = schrift_zu_ziffer(operand1);
        int y = schrift_zu_ziffer(operand2);

        if(operation == "plus")
        {
            ergebnisse.push_back(addition(x, y));
            cout << "gespeichert\n";
        }
        else if(operation == "minus")
        {
            ergebnisse.push_back(subtraktion(x, y));
            cout << "gespeichert\n";
        }
        else if(operation == "mal")
        {
            ergebnisse.push_back(multiplikation(x, y));
            cout << "gespeichert\n";
        }
        else if(operation == "geteilt-durch")
        {
            cout << "Das Ergebnis ist: " << geteilt(x,y) << '\n';
        }
        else if(operation == "dividiert-durch")
        {
            cout << "Das Ergbnis ist: " << division(x,y) << '\n';
        }
        else
        {
            cout << "Ungültige Operation: " << operation;
        }
    }
    if (ergebnisse.size() == 0) {
        cout << "Es gibt keine Ergebnisse." << endl;
    } else if (ergebnisse.size() == 1) {
        cout << "Das Ergebnis lautet: " << ergebnisse[0] << "\n";
    } else {
        cout << "Die Ergebnisse lauten: ";
        for (int i = 0; i < ergebnisse.size() - 1; i++) {
            cout <<  ergebnisse[i] << ", ";
            cout << ergebnisse[ergebnisse.size() - 1] << endl;
        }
    }
    return 0;
}



