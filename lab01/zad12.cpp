#include <iostream>

using namespace std;

void print_with_for(int n) {
    n += 5;  // zwiększamy licznik o 5
    for (int i = 0; i < n; i++) {
        cout << "Adam Krupa" << endl;
    }
}

void print_with_while(int &n) {
    n += 5;  // zwiększamy licznik o 5
    int i = 0;
    while (i < n) {
        cout << "Adam Krupa" << endl;
        i++;
    }
}

void print_with_do_while(int *n) {
    *n += 5;  // zwiększamy licznik o 5
    int i = 0;
    do {
        cout << "Adam Krupa" << endl;
        i++;
    } while (i < *n);
}

int main() {
    int n;
    cout << "Podaj liczbę wyświetleń: ";
    cin >> n;

    cout << "Funkcja z pętlą for (przekazywanie przez wartość):" << endl;
    print_with_for(n);
    cout << "Wartość n po wywołaniu funkcji for: " << n << endl;

    cout << "Funkcja z pętlą while (przekazywanie przez referencję):" << endl;
    print_with_while(n);
    cout << "Wartość n po wywołaniu funkcji while: " << n << endl;

    cout << "Funkcja z pętlą do-while (przekazywanie przez wskaźnik):" << endl;
    print_with_do_while(&n);
    cout << "Wartość n po wywołaniu funkcji do-while: " << n << endl;

    return 0;
}

