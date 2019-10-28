/*
 * This is not a complete solution
 * This is just an approach
 * 
 */

#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>

using namespace std;

int main() {
    /*
     * We can reduce our search space by parsing the dictionary
     * The map uses a string of consonants as a key, and a pair of the number of vowels and the whole word
     * For example, if our dictionary had the word 'to' we would have ['t': 1,'to'] in the map
     * If we then come across the word 'too', we replace the element at 't' with ['t': 2,'too']
     *
     */
    unordered_map<string, pair<int, string> > dictionary;

    int n;
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++) {
	int vowels = 0;
	string str, key = "";
	cin >> str;

	//Parse out the number vowels and the "key"
	for(int j = 0; j < str.size(); j++) {
	    if(str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U') {
		vowels++;
	    } else {
		key += str[j];
	    }
	}

	//Insert the word into the map, or update entry
	unordered_map<string, pair<int,string>>::iterator it;
	if((it = dictionary.find(key)) == dictionary.end()) { //key is not in the dictionary yet
	    dictionary.emplace(key, make_pair(vowels, str));
	} else { //key is in the dictionary, compare
	    if(it->second.first < vowels) {
		it->second = make_pair(vowels, str);
	    }
	}

    }

    //Print out the dictionary map
    for(unordered_map<string, pair<int, string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
	cout << it->first << ": " << it->second.first << ", " << it->second.second << endl;
    }

    return 0;
}
