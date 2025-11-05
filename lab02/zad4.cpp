#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// wypisuje tablicę
void wypisz(const int* tab, const int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << tab[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]\n";
}

// pomocnicza funkcja silnia
int silnia(int n) {
    if (n == 0 || n == 1) return 1;
    int wynik = 1;
    for (int i = 2; i <= n; i++) {
        wynik *= i;
    }
    return wynik;
}

// pomocnicza funkcja fibonacci
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, wynik = 0;
    for (int i = 2; i <= n; i++) {
        wynik = a + b;
        a = b;
        b = wynik;
    }
    return wynik;
}

// wypełnia tablicę: parzyste indeksy = silnia, nieparzyste = -fibonacci
void wypelnij(int* tab, const int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            tab[i] = silnia(i);
        } else {
            tab[i] = -fibonacci(i);
        }
    }
}

// wypełnia tablicę losowymi liczbami z zakresu [a, b]
void wypelnij(int* tab, const int n, const int a, const int b) {
    srand(time(NULL)); // inicjalizacja generatora
    
    for (int i = 0; i < n; i++) {
        tab[i] = a + rand() % (b - a + 1);
    }
}

// suma tablic - zwraca wskaźnik
int* suma1(const int* tab1, const int* tab2, const unsigned int n) {
    int* wynik = new int[n];
    for (unsigned int i = 0; i < n; i++) {
        wynik[i] = tab1[i] + tab2[i];
    }
    return wynik;
}

// suma tablic - przez referencję wskaźnika
void suma2(const int* tab1, const int* tab2, int*& tab3, const unsigned int n) {
    tab3 = new int[n];
    for (unsigned int i = 0; i < n; i++) {
        tab3[i] = tab1[i] + tab2[i];
    }
}

// suma tablic - tab3 już zaalokowana
void suma3(const int* tab1, const int* tab2, int* tab3, const unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        tab3[i] = tab1[i] + tab2[i];
    }
}

// tabliczka mnożenia i iloczyn wybranych liczb
int tabliczka_mnozenia() {
    // wypisujemy tabliczkę mnożenia
    cout << "\n=== TABLICZKA MNOZENIA ===\n";
    cout << "   ";
    for (int i = 1; i <= 10; i++) {
        cout << i << "\t";
    }
    cout << "\n";
    
    for (int i = 1; i <= 10; i++) {
        cout << i << "  ";
        for (int j = 1; j <= 10; j++) {
            cout << i * j << "\t";
        }
        cout << "\n";
    }
    
    // pobieramy dwie liczby z zakresu [1, 10]
    int a, b;
    cout << "\nPodaj pierwsza liczbe z zakresu [1, 10]: ";
    cin >> a;
    cout << "Podaj druga liczbe z zakresu [1, 10]: ";
    cin >> b;
    
    if (a < 1 || a > 10 || b < 1 || b > 10) {
        cout << "Blad: liczby musza byc z zakresu [1, 10]!\n";
        return 0;
    }
    
    int wynik = a * b;
    cout << a << " * " << b << " = " << wynik << endl;
    
    return wynik;
}

int main() {
    const int n = 5;
    int tab1[n], tab2[n], tab3[n];
    
    cout << "=== WYPELNIANIE TABLIC ===\n";
    
    // wypełniamy pierwszą tablicę (silnia/fibonacci)
    wypelnij(tab1, n);
    cout << "Tablica 1 (silnia/fibonacci): ";
    wypisz(tab1, n);
    
    // wypełniamy drugą tablicę losowymi liczbami
    int a, b;
    cout << "\nPodaj dolna granice zakresu losowania: ";
    cin >> a;
    cout << "Podaj gorna granice zakresu losowania: ";
    cin >> b;
    
    wypelnij(tab2, n, a, b);
    cout << "Tablica 2 (losowe): ";
    wypisz(tab2, n);
    
    cout << "\n=== SUMA TABLIC ===\n";
    
    // suma1 - zwraca wskaźnik
    int* wynik1 = suma1(tab1, tab2, n);
    cout << "Suma1 (zwraca wskaznik): ";
    wypisz(wynik1, n);
    delete[] wynik1; // zwalniamy pamięć
    
    // suma2 - przez referencję wskaźnika
    int* wynik2 = nullptr;
    suma2(tab1, tab2, wynik2, n);
    cout << "Suma2 (przez referencje wskaznika): ";
    wypisz(wynik2, n);
    delete[] wynik2; // zwalniamy pamięć
    
    // suma3 - tab3 już zaalokowana
    suma3(tab1, tab2, tab3, n);
    cout << "Suma3 (istniejaca tablica): ";
    wypisz(tab3, n);
    
    // tabliczka mnożenia
    tabliczka_mnozenia();
    
    return 0;
}
