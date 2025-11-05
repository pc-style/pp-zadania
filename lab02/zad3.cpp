#include <iostream>
#include <cmath>

using namespace std;

// suma dwóch liczb
double suma(const double a, const double b) {
    return a + b;
}

// różnica dwóch liczb
double roznica(const double a, const double b) {
    return a - b;
}

// iloczyn dwóch liczb
double iloczyn(const double a, const double b) {
    return a * b;
}

// iloraz dwóch liczb
double iloraz(const double a, const double b) {
    if (b == 0) {
        cout << "Blad: dzielenie przez zero!\n";
        return 0;
    }
    return a / b;
}

// kwadrat liczby (bez pow)
double kwadrat(const double x) {
    return x * x;
}

// sześcian liczby (bez pow)
double szescian(const double x) {
    return x * x * x;
}

// wartość wyrażenia f(x) = (10·x³ + 3.1415·x²) · (x³ - 1/x²)
double wartosc_wyrazenia(const double x) {
    if (x == 0) {
        cout << "Blad: x nie moze byc 0 (dzielenie przez zero w wyrazeniu)!\n";
        return 0;
    }
    
    double czesc1 = 10 * szescian(x) + 3.1415 * kwadrat(x);
    double czesc2 = szescian(x) - 1.0 / kwadrat(x);
    
    return czesc1 * czesc2;
}

// obwód trójkąta
double obwod(const double a, const double b, const double c) {
    // sprawdzamy czy można zbudować trójkąt
    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Blad: z podanych bokow nie mozna zbudowac trojkata!\n";
        return -1; // zwracamy -1 jako sygnał błędu
    }
    
    return a + b + c;
}

// pole trójkąta metodą Herona
double pole(const double a, const double b, const double c) {
    double obw = obwod(a, b, c);
    if (obw < 0) {
        return -1; // błąd - nie można zbudować trójkąta
    }
    
    double p = obw / 2.0; // półobwód
    double pole_wynik = sqrt(p * (p - a) * (p - b) * (p - c));
    
    return pole_wynik;
}

// menu kalkulatora
bool kalkulator() {
    int wybor;
    double a, b, c, x;
    
    cout << "\n=== KALKULATOR ===\n";
    cout << "1. Suma\n";
    cout << "2. Roznica\n";
    cout << "3. Iloczyn\n";
    cout << "4. Iloraz\n";
    cout << "5. Kwadrat\n";
    cout << "6. Szescian\n";
    cout << "7. Wartosc wyrazenia f(x)\n";
    cout << "8. Obwod trojkata\n";
    cout << "9. Pole trojkata\n";
    cout << "0. Wyjscie\n";
    cout << "Wybierz opcje: ";
    
    cin >> wybor;
    
    switch (wybor) {
        case 1:
            cout << "Podaj dwie liczby: ";
            cin >> a >> b;
            cout << "Wynik: " << suma(a, b) << endl;
            break;
            
        case 2:
            cout << "Podaj dwie liczby: ";
            cin >> a >> b;
            cout << "Wynik: " << roznica(a, b) << endl;
            break;
            
        case 3:
            cout << "Podaj dwie liczby: ";
            cin >> a >> b;
            cout << "Wynik: " << iloczyn(a, b) << endl;
            break;
            
        case 4:
            cout << "Podaj dwie liczby: ";
            cin >> a >> b;
            cout << "Wynik: " << iloraz(a, b) << endl;
            break;
            
        case 5:
            cout << "Podaj liczbe: ";
            cin >> x;
            cout << "Wynik: " << kwadrat(x) << endl;
            break;
            
        case 6:
            cout << "Podaj liczbe: ";
            cin >> x;
            cout << "Wynik: " << szescian(x) << endl;
            break;
            
        case 7:
            cout << "Podaj x: ";
            cin >> x;
            cout << "Wynik: " << wartosc_wyrazenia(x) << endl;
            break;
            
        case 8:
            cout << "Podaj trzy boki trojkata: ";
            cin >> a >> b >> c;
            {
                double obw_wynik = obwod(a, b, c);
                if (obw_wynik >= 0) {
                    cout << "Wynik: " << obw_wynik << endl;
                }
            }
            break;
            
        case 9:
            cout << "Podaj trzy boki trojkata: ";
            cin >> a >> b >> c;
            {
                double pole_wynik = pole(a, b, c);
                if (pole_wynik >= 0) {
                    cout << "Wynik: " << pole_wynik << endl;
                }
            }
            break;
            
        case 0:
            cout << "Do widzenia!\n";
            return false;
            
        default:
            cout << "Nieprawidlowa opcja!\n";
            break;
    }
    
    return true; // kontynuuj działanie
}

int main() {
    while (kalkulator());
    return 0;
}
