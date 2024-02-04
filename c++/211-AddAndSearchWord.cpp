/*

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string 
containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

*/

struct Node{
    bool isEnd;
    vector<Node*> children{vector<Node*>(26, NULL)};
    Node(): isEnd(false){}
};

class WordDictionary {
private:
    Node* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            if(curr->children[word[i]-'a'] == NULL) {
                curr->children[word[i]-'a'] = new Node();
            }
            curr = curr->children[word[i]-'a'];
        }
        curr->isEnd = true;        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, root);
    }
private:
    bool dfs(string word, int st, Node* root) {
        if(st == word.size()) return root->isEnd;
        if(word[st]!='.') {
            if(root->children[word[st]-'a'] == NULL) return false;
            root = root->children[word[st]-'a'];
            return dfs(word, st+1, root);
        }
        for(int i = 0; i<26; i++) {
            if(root->children[i] && dfs(word, st+1, root->children[i])) 
                return true;
        }
        return false;
    }
    
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
