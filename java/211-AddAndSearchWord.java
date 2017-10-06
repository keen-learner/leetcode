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

class Node{
    
    public boolean isEnd;
    public Node[] children;
    public Node() {
        isEnd = false;
        children = new Node[26];
    }
}
public class WordDictionary {

    /** Initialize your data structure here. */
    private Node root;
    public WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        Node curr = root;
        for(int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            int index = ch - 'a';
            if(curr.children[index] == null) curr.children[index] = new Node();
            curr = curr.children[index];
        }
        curr.isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return search(word, 0, root);
    }
    
    private boolean search(String word, int st, Node root){
        if(st == word.length()) return root.isEnd;
        
        char ch = word.charAt(st);
        if(ch != '.') {
            int index = ch - 'a';
            if(root.children[index] == null) return false;
            root = root.children[index];
            return search(word, st+1, root);    
        }
        for(int i = 0; i < 26; i++) {
            if(root.children[i] != null && search(word, st+1, root.children[i])) return true;
        }
        return false;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
