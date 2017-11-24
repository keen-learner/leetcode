/*

Given two words (beginWord and endWord), and a dictionary's word list, 
find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> visit;  //notice we need to clear visited word in list after finish this level of BFS
        queue<vector<string>> q;
        unordered_set<string> wordlist(wordList.begin(),wordList.end());
        q.push({beginWord});
        bool flag= false; //to see if we find shortest path
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){            //for this level
                vector<string> cur = q.front();
                q.pop();
                vector<string> newadd =  addWord(cur.back(),wordlist); 
                for(int j=0;j<newadd.size();j++){   //add a word into path
                    vector<string> newline(cur.begin(),cur.end());
                    newline.push_back(newadd[j]);
                    if(newadd[j]==endWord){       
                     flag=true;
                    res.push_back(newline);
                    }
                    visit.insert(newadd[j]);
                    q.push(newline);
                }
            }
            if(flag) break;  //do not BFS further 
            for(auto it=visit.begin();it!=visit.end();it++) wordlist.erase(*it); //erase visited one 
            visit.clear();
        }
        return res;
    }

private:    
    // find words with one char different in dict
    // hot->[dot,lot]
    vector<string> addWord( string word,unordered_set<string>& wordlist ){
        vector<string> res;
        for(int i=0;i<word.size();i++){
            char s =word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(wordlist.count(word)) res.push_back(word);
            }
            word[i]=s;
        }
        return res;
    }
};

