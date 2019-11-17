#include <iostream>
using namespace std;


int main() {
    int A, B;
    cin >> A >> B;

    int ops = 0;
    while (A>B) {
        if (A%2) {
            A++;
            ops++;
            continue;
        }
        if (A>B) {
            A/=2;
            ops++;
            continue;
        }
    }
    ops+=B-A;

    cout << ops << endl;
}
