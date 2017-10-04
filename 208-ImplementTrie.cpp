/*

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

*/

struct Node{
    bool isEnd;
    unordered_map<char, Node*> children;
    Node(): isEnd(false){}
};


class Trie {
private:
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            if(curr->children.find(word[i]) == curr->children.end()) {
                curr->children[word[i]] = new Node();
            }
            curr = curr->children[word[i]];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            // if(curr == NULL || curr->children.find(word[i]) == curr->children.end()) return false;
            if(curr->children.find(word[i]) == curr->children.end()) return false;
            curr = curr->children[word[i]];
        }
        // if(curr == NULL || curr->isEnd == false) return false; //not needed
        if(curr->isEnd == false) return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i = 0; i < prefix.size(); i++) {
            // if(curr == NULL || curr->children.find(prefix[i]) == curr->children.end()) return false;
            if(curr->children.find(prefix[i]) == curr->children.end()) return false;
            curr = curr->children[prefix[i]];
        }
        // if(curr == NULL) return false; //not needed
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
