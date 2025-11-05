#include <iostream>

using namespace std;

// silnia rekurencyjnie
int silnia_rek(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * silnia_rek(n - 1);
}

// silnia iteracyjnie
int silnia_iter(int n) {
    int wynik = 1;
    for (int i = 2; i <= n; i++) {
        wynik *= i;
    }
    return wynik;
}

// fibonacci rekurencyjnie
int fib_rek(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib_rek(n - 1) + fib_rek(n - 2);
}

// fibonacci iteracyjnie
int fib_iter(int n) {
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

int main() {
    int n;
    
    cout << "=== SILNIA ===\n";
    cout << "Podaj n: ";
    cin >> n;
    
    if (n < 0) {
        cout << "Nie mozna obliczyc silni z liczby ujemnej!\n";
    } else {
        cout << "Silnia(" << n << ") rekurencyjnie: " << silnia_rek(n) << endl;
        cout << "Silnia(" << n << ") iteracyjnie: " << silnia_iter(n) << endl;
    }
    
    cout << "\n=== FIBONACCI ===\n";
    cout << "Podaj n (ktory wyraz ciagu): ";
    cin >> n;
    
    if (n < 0) {
        cout << "Nie mozna obliczyc ujemnego wyrazu ciagu!\n";
    } else {
        cout << "Fib(" << n << ") rekurencyjnie: " << fib_rek(n) << endl;
        cout << "Fib(" << n << ") iteracyjnie: " << fib_iter(n) << endl;
    }
    
    return 0;
}
