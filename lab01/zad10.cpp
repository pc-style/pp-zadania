#include <iostream>

using namespace std;

void display_binary(int liczba) {
    cout << "Suma w systemie binarnym: ";
    for (int i = 31; i >= 0; i--) {
        cout << ((liczba >> i) & 1);
    }
    cout << endl;
}

int main() {
    int liczba1, liczba2, suma;
    cout << "Podaj pierwszą liczbę: ";
    cin >> liczba1;
    cout << "Podaj drugą liczbę: ";
    cin >> liczba2;
    suma = liczba1 + liczba2;

    cout << "Suma: " << suma << endl;
    display_binary(suma);
    cout << "Suma w systemie szesnastkowym: " << hex << suma << endl;
    return 0;
}
