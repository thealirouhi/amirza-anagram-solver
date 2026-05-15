#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

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

void runGame()
{
    int n;
    cin >> n;

    map<string, bool> dictionary;
    loadDictionary(dictionary, n);
}

int main()
{
    runGame();
    return 0;
}