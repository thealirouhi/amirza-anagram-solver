#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Node {
    Node* child[26];
    bool isWord;

    Node() {
        isWord = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

// loading dictionary
void loadDictionary(Node* root, int n);

void dfs(Node* node, int freq[26], string current, vector<string>& result);

// handle one query
vector<string> processQuery(Node* root);

// main driver
void runGame();

void insertWord(Node* root, const string& word);

void loadDictionary(Node* root, int n)
{
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        insertWord(root, word);
    }
}

void readQuery(int freq[26])
{
    for (int i = 0; i < 26; i++)
        freq[i] = 0;

    string line;

    // Skip empty line left after previous >> extraction
    while (getline(cin, line)) {
        if (!line.empty()) break;
    }

    string token;
    stringstream ss(line);

    while (ss >> token)
    {
        char c = token[0];
        freq[c - 'a']++;
    }
}

void insertWord(Node* root, const string& word)
{
    Node* curr = root;

    for (char c : word)
    {
        int idx = c - 'a';

        if (!curr->child[idx])
            curr->child[idx] = new Node();

        curr = curr->child[idx];
    }

    curr->isWord = true;
}

void dfs(Node* node, int freq[26], string current, vector<string>& result)
{
    if (node->isWord)
    {
        result.push_back(current);
    }

    for (int i = 0; i < 26; i++)
    {
        if (node->child[i] != nullptr && freq[i] > 0)
        {
            freq[i]--;  // choose

            dfs(node->child[i], freq, current + char('a' + i), result);

            freq[i]++;  // backtrack
        }
    }
}

vector<string> findValidCombinations(const map<string, bool> &dictionary, int freq[26])
{
    vector<string> result;

    for (auto &entry : dictionary)
    {
        const string &word = entry.first;

        int wordFreq[26] = {0};
        for (char c : word)
        {
            wordFreq[c - 'a']++;
        }

        bool ok = true;
        for (int i = 0; i < 26; i++)
        {
            if (wordFreq[i] > freq[i])
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            result.push_back(word);
        }
    }

    sort(result.begin(), result.end());
    return result;
}

vector<string> processQuery(Node* root)
{
    int freq[26];
    readQuery(freq);

    vector<string> result;

    dfs(root, freq, "", result);

    sort(result.begin(), result.end());

    return result;
}

void runGame()
{
    int n;
    cin >> n;

    Node* root = new Node();
    loadDictionary(root, n);

    int q;
    cin >> q;

    vector<vector<string>> allResults;
    for (int i = 0; i < q; i++)
    {
        allResults.push_back(processQuery(root));
    }

    for (auto &res : allResults)
    {
        if (res.empty())
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << res.size() << "\n";
            for (auto &w : res)
                cout << w << "\n";
        }
    }
}

int main()
{
    runGame();
    return 0;
}