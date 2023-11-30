#include <iostream>
#include <string>

using namespace std;

class Trie {
private:
    unordered_map<char, Trie*> children;
    int color; // 1 = gray, 2 = black
public:
    /** Initialize your data structure here. */
    Trie() {
        color = 1;
    }
    Trie(int c) {
        color = c;
    }

    void insert(string word) {
        Trie* node = this;
        for (char c: word){
            if (node->children.find(c) == children.end()){
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        
    }
    
    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        
    }
};

bool search(Trie t, string s){
    return false;
}
Trie add(string s, Trie t){

    return t;
}
int count(Trie t){
    return 0;
}

string* lexicon(Trie t){
    string *s = new string[2];
    s[0] = "a";
    s[1] = "b";
    return s;
}

int main(){

}