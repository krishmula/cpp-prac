#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Trie {
public:
    vector<Trie*> nodes;
    bool isComplete;

    Trie() {
        this->nodes.resize(26, nullptr);
        this->isComplete = false;
    }
};


void insert(string word, Trie* root) {
    Trie* temp = root;
    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        int index = c - 'a';

        if (temp->nodes[index] == nullptr) {
            Trie* newTrie = new Trie();
            temp->nodes[index] = newTrie;
            temp = newTrie;
        } else {
            Trie* nextTrie = temp->nodes[index];
            temp = nextTrie;
        }
    }
    temp->isComplete = true;
}

bool search(string word, Trie* root) {
    Trie* temp = root;
    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        int index = c - 'a';

        if (temp->nodes[index] == nullptr) return false;
        else {
            Trie* nextTrie = temp->nodes[index];
            temp = nextTrie;
        }
    }

    if (temp->isComplete) return true;
    return false;

}

bool startsWith(string word, Trie* root) {
    Trie* temp = root;
    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        int index = c - 'a';

        if (temp->nodes[index] == nullptr) return false;
        else {
            Trie* nextTrie = temp->nodes[index];
            temp = nextTrie;
        }
    }

    return true;
}

int main () {
    vector<string> words = {"apple", "app", "apricot", "banana", "band", "bandana"};

    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }

    Trie* test = new Trie();
    insert("apple", test);
    insert("app", test);
    insert("apricot", test);
    insert("banana", test);
    insert("band", test);
    insert("bandana", test);

    string res1 = search("apple", test) ? "Found" : "Not Found";
    string res2 = search("appx", test) ? "Found" : "Not Found";

    string res3 = startsWith("ap", test) ? "Found" : "Not Found";
    string res4 = startsWith("bax", test) ? "Found" : "Not Found";


    cout << res1 << endl;
    cout << res2 << endl;

    cout << res3 << endl;
    cout << res4 << endl;

}