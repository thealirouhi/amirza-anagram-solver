#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// loading dictionary
void loadDictionary(map<string, bool> &dictionary, int n);

// backtracking helper (to be redesigned later)
bool goForward(const string &word, const map<string, bool> &dictionary);

// find valid words for a query
vector<string> findValidCombinations(const vector<char> &letters,
                                     const map<string, bool> &dictionary);

// handle one query
void processQuery(const map<string, bool> &dictionary);

// main driver
void runGame();

void loadDictionary(map<string, bool> &dictionary, int n)
{
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        dictionary[word] = true;
    }
}

void readQuery(int freq[26]) {
    for (int i = 0; i < 26; i++) freq[i] = 0;

    string line;
    cin.ignore(); // consume newline

    getline(cin, line);

    string token;
    stringstream ss(line);

    while (ss >> token) {
        char c = token[0];
        freq[c - 'a']++;
    }
}

void processQuery(const map<string, bool>& dictionary) {
    int freq[26];
    readQuery(freq);

    // placeholder output for now
    cout << 0 << "\n";
}

void runGame()
{
    int n;
    cin >> n;

    map<string, bool> dictionary;
    loadDictionary(dictionary, n);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        processQuery(dictionary);
    }
}

int main()
{
    runGame();
    return 0;
}