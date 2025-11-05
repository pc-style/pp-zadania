#include <iostream>

using namespace std;

// suma przez wartość
int suma_wartosc(int n) {
    int wynik = 0;
    for (int i = 1; i <= n; i++) {
        wynik += i;
    }
    return wynik;
}

// suma przez referencję
int suma_referencja(int& n) {
    int wynik = 0;
    for (int i = 1; i <= n; i++) {
        wynik += i;
    }
    return wynik;
}

// suma przez wskaźnik
int suma_wskaznik(int* n) {
    int wynik = 0;
    for (int i = 1; i <= *n; i++) {
        wynik += i;
    }
    return wynik;
}

// sprawdza czy parzysta przez wskaźnik
bool czy_parzysta(int* n) {
    return (*n % 2 == 0);
}

// potęga bez pow() - iteracyjnie
int potega(const int a, const int n) {
    if (n == 0) return 1;
    int wynik = 1;
    for (int i = 0; i < n; i++) {
        wynik *= a;
    }
    return wynik;
}

// suma cyfr przez referencję
int suma_cyfr(int& n) {
    int wynik = 0;
    int temp = n; // kopia żeby nie psuć oryginału
    while (temp > 0) {
        wynik += temp % 10;
        temp /= 10;
    }
    return wynik;
}

// suma parzystych z przedziału [a, b]
int suma_parzystych(const int a, const int b) {
    int wynik = 0;
    int start = a;
    if (start % 2 != 0) start++; // zaczynamy od pierwszej parzystej
    
    for (int i = start; i <= b; i += 2) {
        wynik += i;
    }
    return wynik;
}

// kod ASCII znaku
int kod_ascii(char znak) {
    return (int)znak;
}

int main() {
    int n;
    
    // pobieramy n dopóki nie będzie > 2
    do {
        cout << "Podaj n (musi byc > 2): ";
        cin >> n;
    } while (n <= 2);
    
    cout << "\n=== WYNIKI ===\n";
    
    // test sumy przez wartość
    cout << "Suma (wartosc): " << suma_wartosc(n) << endl;
    
    // test sumy przez referencję
    cout << "Suma (referencja): " << suma_referencja(n) << endl;
    
    // test sumy przez wskaźnik
    cout << "Suma (wskaznik): " << suma_wskaznik(&n) << endl;
    
    // test czy parzysta
    cout << "Czy " << n << " jest parzysta? " << (czy_parzysta(&n) ? "TAK" : "NIE") << endl;
    
    // test potęgi
    int a, pot;
    cout << "\nPodaj podstawe potegi: ";
    cin >> a;
    cout << "Podaj wykladnik: ";
    cin >> pot;
    cout << a << "^" << pot << " = " << potega(a, pot) << endl;
    
    // test suma cyfr
    int liczba_cyfr;
    cout << "\nPodaj liczbe do sumy cyfr: ";
    cin >> liczba_cyfr;
    cout << "Suma cyfr liczby " << liczba_cyfr << " = " << suma_cyfr(liczba_cyfr) << endl;
    
    // test suma parzystych
    int dolna, gorna;
    cout << "\nPodaj dolna granice przedzialu: ";
    cin >> dolna;
    cout << "Podaj gorna granice przedzialu: ";
    cin >> gorna;
    cout << "Suma parzystych z [" << dolna << ", " << gorna << "] = " 
         << suma_parzystych(dolna, gorna) << endl;
    
    // test kod ASCII
    char znak;
    cout << "\nPodaj znak: ";
    cin >> znak;
    cout << "Kod ASCII znaku '" << znak << "' = " << kod_ascii(znak) << endl;
    
    return 0;
}
