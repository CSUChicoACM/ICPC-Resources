#include <iostream>
#include <vector>
using namespace std;


/***
 *
 *  take the string abcaca:
 *
 *      there are 4 ways we can include a:
 *           abcc, bcac, bcca, or bcc
 *
 *      for each way we can include a, there are 3 ways we can include c:
 *          *bc**, *b*c*, or *b**
 *
 *      there are two ways we can include b, either we do or we don't
 *
 *      the solution is (num a's +1)*(num b's +1)*(num c's +1)
 */


long long int numRainbowStrings(string &s) {

    // count occurances, every character gets a freebee
    vector<int> counts(26,1);
    for (char c : s) counts[c-'a']++;

    // keep the running count [ (a*b % p)*c % p = a*b*c % p ]
    long long int total = 1;
    for (int i : counts) total = (total*i) % 11092019;

    return total;
}

int main() {
    string s;
    cin >> s;
    cout << numRainbowStrings(s) << endl;
}
