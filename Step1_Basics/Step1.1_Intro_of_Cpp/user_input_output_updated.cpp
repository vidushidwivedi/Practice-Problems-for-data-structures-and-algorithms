//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> freqMap;  // Stores frequency of sentences
    bool isEnd = false;
};

class AutoCompleteSystem {
private:
    TrieNode* root;
    string currentInput;  // Stores current prefix typed by user

    void insert(string sentence, int times) {
        TrieNode* node = root;
        for (char c : sentence) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->freqMap[sentence] += times;  // Store frequency
        }
        node->isEnd = true;
    }

    vector<string> search(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children.count(c)) {
                return {};  // No matches found
            }
            node = node->children[c];
        }

        // Fetch all sentences with the prefix and sort
        vector<pair<int, string>> candidates;
        for (auto& entry : node->freqMap) {
            candidates.push_back({-entry.second, entry.first}); // Store negative freq for sorting
        }

        // Sort by frequency (higher first), and if equal, by lexicographic order
        sort(candidates.begin(), candidates.end());

        // Get top 3
        vector<string> result;
        for (int i = 0; i < min(3, (int)candidates.size()); i++) {
            result.push_back(candidates[i].second);
        }
        return result;
    }

public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); i++) {
            insert(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            insert(currentInput, 1);  // Save the sentence
            currentInput = "";  // Reset input
            return {};
        }

        currentInput += c;
        return search(currentInput);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        vector<string> sentences(n);
        vector<int> times(n);
        for (int i = 0; i < n; ++i) {

            getline(cin, sentences[i]);
            cin >> times[i];
            cin.ignore();
        }
        AutoCompleteSystem *obj = new AutoCompleteSystem(sentences, times);
        int q;
        cin >> q;
        cin.ignore();

        for (int i = 0; i < q; ++i) {
            string query;
            getline(cin, query);
            string qq = "";
            for (auto &x : query) {
                qq += x;
                vector<string> suggestions = obj->input(x);
                if (x == '#')
                    continue;
                cout << "Typed : \"" << qq << "\" , Suggestions: \n";
                for (auto &y : suggestions) {
                    cout << y << "\n";
                }
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends