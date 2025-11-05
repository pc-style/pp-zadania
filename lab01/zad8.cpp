#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char znak;
    cout << "Podaj znak: ";
    cin >> znak;
    if (isdigit(znak)) {
        cout << "Znak jest cyfrą" << endl;
    } else if (isalpha(znak)) {
        cout << "Znak jest literą" << endl;
    } else {
        cout << "Znak jest innym znakiem" << endl;
    }
    return 0;
}
