#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// losuje liczby z zakresu [a, b] i zwraca wskaźnik do tablicy
int* losuj_liczby(const int a, const int b, const int n) {
    int* tab = new int[n];
    srand(time(NULL));
    
    // losujemy bez powtórzeń
    for (int i = 0; i < n; i++) {
        int losowa;
        bool powtorzenie;
        
        do {
            losowa = a + rand() % (b - a + 1);
            powtorzenie = false;
            
            // sprawdzamy czy już mamy tę liczbę
            for (int j = 0; j < i; j++) {
                if (tab[j] == losowa) {
                    powtorzenie = true;
                    break;
                }
            }
        } while (powtorzenie);
        
        tab[i] = losowa;
    }
    
    // sortujemy dla czytelności
    sort(tab, tab + n);
    
    return tab;
}

// pobiera liczby od użytkownika
int* pobierz_liczby(const int a, const int b, const int n) {
    int* tab = new int[n];
    
    cout << "Podaj " << n << " liczb z zakresu [" << a << ", " << b << "]:\n";
    for (int i = 0; i < n; i++) {
        int liczba;
        bool poprawna;
        
        do {
            cout << "Liczba " << (i + 1) << ": ";
            cin >> liczba;
            
            if (liczba < a || liczba > b) {
                cout << "Blad: liczba musi byc z zakresu [" << a << ", " << b << "]!\n";
                poprawna = false;
            } else {
                // sprawdzamy czy już podaliśmy tę liczbę
                bool powtorzenie = false;
                for (int j = 0; j < i; j++) {
                    if (tab[j] == liczba) {
                        cout << "Blad: ta liczba juz zostala podana!\n";
                        powtorzenie = true;
                        break;
                    }
                }
                poprawna = !powtorzenie;
            }
        } while (!poprawna);
        
        tab[i] = liczba;
    }
    
    // sortujemy dla czytelności
    sort(tab, tab + n);
    
    return tab;
}

// sprawdza czy użytkownik wygrał i zwraca liczbę trafień przez referencję
bool czy_wygral(const int* wylosowane, const int* wybrane, const int n, int& trafienia) {
    trafienia = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (wylosowane[i] == wybrane[j]) {
                trafienia++;
                break;
            }
        }
    }
    
    return trafienia > 0;
}

// wypisuje tablicę
void wypisz_tablice(const int* tab, const int n, const char* nazwa) {
    cout << nazwa << ": [";
    for (int i = 0; i < n; i++) {
        cout << tab[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]\n";
}

// główna funkcja obsługująca loterię
void loteria() {
    int a, b, n;
    
    cout << "=== LOTTO ===\n";
    cout << "Podaj dolna granice zakresu: ";
    cin >> a;
    cout << "Podaj gorna granice zakresu: ";
    cin >> b;
    cout << "Ile liczb losujemy? ";
    cin >> n;
    
    if (a >= b) {
        cout << "Blad: nieprawidlowy zakres!\n";
        return;
    }
    
    if (n > (b - a + 1)) {
        cout << "Blad: za duzo liczb do wylosowania!\n";
        return;
    }
    
    // losujemy liczby
    int* wylosowane = losuj_liczby(a, b, n);
    cout << "\nLiczby zostaly wylosowane!\n";
    
    // pobieramy liczby od użytkownika
    int* wybrane = pobierz_liczby(a, b, n);
    
    // sprawdzamy wyniki
    int trafienia;
    bool wygrana = czy_wygral(wylosowane, wybrane, n, trafienia);
    
    cout << "\n=== WYNIKI ===\n";
    wypisz_tablice(wylosowane, n, "Wylosowane liczby");
    wypisz_tablice(wybrane, n, "Twoje liczby");
    cout << "\nTrafien: " << trafienia << endl;
    
    if (wygrana) {
        cout << "GRATULACJE! Trafiles " << trafienia << " liczb!\n";
    } else {
        cout << "Niestety, nie trafiles zadnej liczby. Sprobuj ponownie!\n";
    }
    
    // zwalniamy pamięć
    delete[] wylosowane;
    delete[] wybrane;
}

int main() {
    char kontynuuj;
    
    do {
        loteria();
        cout << "\nCzy chcesz zagrac ponownie? (t/n): ";
        cin >> kontynuuj;
    } while (kontynuuj == 't' || kontynuuj == 'T');
    
    cout << "Dziekujemy za gre!\n";
    
    return 0;
}
