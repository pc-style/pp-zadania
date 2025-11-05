#include <iostream>

using namespace std;

int main() {
    int liczba;
    cout << "Podaj liczbę: ";
    cin >> liczba;
    cout << "Liczba w systemie szesnastkowym: " << hex << liczba << endl;
    return 0;
}
