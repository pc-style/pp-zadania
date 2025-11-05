#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Podaj liczbę wyświetleń: ";
    cin >> n;

    cout << "Pętla for:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Adam Krupa" << endl;
    }

    cout << "Pętla while:" << endl;
    int i = 0;
    while (i < n) {
        cout << "Adam Krupa" << endl;
        i++;
    }

    cout << "Pętla do-while:" << endl;
    i = 0;
    do {
        cout << "Adam Krupa" << endl;
        i++;
    } while (i < n);

    return 0;
}
