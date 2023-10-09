#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    bool isEnd;
    Trie* child[26];

    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }

    void insert(string word) {
        Trie* current = this;
        for (char c : word) {
            int index = c - 'a';
            if (current->child[index] == NULL) {
                current->child[index] = new Trie();
            }
            current = current->child[index];
        }
        current->isEnd = true;
    }

    bool search(string word) {
        Trie* current = this;
        for (char c : word) {
            int index = c - 'a';
            if (current->child[index] == NULL) {
                return false;
            }
            current = current->child[index];
        }
        return current->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* current = this;
        for (char c : prefix) {
            int index = c - 'a';
            if (current->child[index] == NULL) {
                return false;
            }
            current = current->child[index];
        }
        return true;
    }

    // Helper function to check if a Trie node has no children
    bool isEmpty(Trie* node) {
        for (int i = 0; i < 26; i++) {
            if (node->child[i] != NULL) {
                return false;
            }
        }
        return true;
    }

    // Single method for word deletion
    bool deleteWordHelper(Trie* current, string word, int index) {
        if (index == word.size()) {
            if (current->isEnd) {
                current->isEnd = false;
                return isEmpty(current);
            }
            return false;
        }

        int charIndex = word[index] - 'a';
        if (current->child[charIndex] == NULL) {
            return false; // Word not found
        }

        bool shouldDeleteChild = deleteWordHelper(current->child[charIndex], word, index + 1);

        if (shouldDeleteChild) {
            delete current->child[charIndex];
            current->child[charIndex] = NULL;
            return isEmpty(current) && !current->isEnd;
        }

        return false;
    }

    void deleteWord(string word) {
        deleteWordHelper(this, word, 0);
    }
};

int main() {
    Trie* trie = new Trie();

    trie->insert("apple");
    cout << trie->search("apple") << endl; // Output: true
    cout << trie->search("app") << endl; // Output: false
    cout << trie->startsWith("app") << endl; // Output: true

    trie->deleteWord("apple");
    cout << trie->search("apple") << endl; // Output: false

    delete trie;

    return 0;
}
