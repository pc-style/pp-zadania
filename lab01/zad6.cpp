#include <iostream>

using namespace std;

void bin(int liczba) {
    cout << "Liczba w systemie binarnym: ";
    for (int i = 31; i >= 0; i--) {
        cout << ((liczba >> i) & 1);
    }
    cout << endl;
}

int main() {
    int liczba;
    cout << "Podaj liczbę: ";
    cin >> liczba;
    bin(liczba);
    return 0;
}
