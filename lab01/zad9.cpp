#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char znak;
    cout << "Podaj znak: ";
    cin >> znak;
    cout << "Odpowiednik wielkiej litery: " << char(toupper(znak)) << endl;
    return 0;
}
