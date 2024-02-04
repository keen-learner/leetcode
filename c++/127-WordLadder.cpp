/*

Given two words (beginWord and endWord), and a dictionary's word list, 
find the length of shortest transformation sequence from 
beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

*/

class Solution1 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());//set has endword
        queue<string> toVisit;
        bfs(beginWord,dict,toVisit);
        int dist=2;
        while(!toVisit.empty()){
            int n=toVisit.size();
            for(int i=0;i<n;i++){
                string word=toVisit.front();
                toVisit.pop();
                if(word==endWord) return dist;
                bfs(word,dict,toVisit);
            }
            dist++;
        }
        return 0;
    }
    
    void bfs(string word, unordered_set<string>& dict, queue<string>& toVisit){
        dict.erase(word);
        for(int i=0;(int)i<word.size();i++){
            char letter=word[i];
            for(int k=0;k<26;k++){
                word[i]='a'+k;
                if(dict.find(word)!=dict.end()){
                    toVisit.push(word);
                    dict.erase(word);
                }
            }
            word[i]=letter;
        }
    }
    
};


class Solution2 {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int sz = wordList.size(), i, j, k;
    if (sz == 0 or beginWord == endWord) {
      return 0;
    }
    i = 0;
    while (i < sz and wordList[i] != endWord) {
      ++i;
    }
    if (i == sz) {
      return 0;
    }
    k = i;
    vector<vector<int>> A(sz);
    for (i = 0; i + 1 < sz; ++i) {
      for (j = i + 1; j < sz; ++j) {
        if (f(wordList[i], wordList[j])) {
          A[i].push_back(j);
          A[j].push_back(i);
        }
      }
    }
    vector<bool> B(sz, true), C(sz, true), *b = &B, *c = &C;
    list<int> X, Y, * x = &X, * y = &Y;
    for (i = 0; i < sz; ++i) {
      if (f(beginWord, wordList[i])) {
        B[i] = false;
        X.push_back(i);
      }
    }
    Y.push_back(k);
    C[k] = false;
    int result = 1;
    while (!x->empty() and !y->empty()) {
      ++result;
      if (x->size() > y->size()) {
        swap(x, y);
        swap(b, c);
      }
      sz = x->size();
      for (i = 0; i < sz; ++i) {
        j = x->front();
        x->pop_front();
        if (!c->at(j)) {
          return result;
        }
        for (const auto & l : A[j]) {
          if (b->at(l)) {
            b->at(l) = false;
            x->push_back(l);
          }
        }
      }
    }
    return 0;
  }
private:
  bool f(const string & x, const string & y) {
    int sz1 = x.size(), sz2 = y.size(), i = 0, cnt = 0;
    if (sz1 != sz2) {
      return false;
    }
    while (i < sz1 and cnt <= 1) {
      if (x[i] != y[i]) {
        ++cnt;
      }
      ++i;
    }
    return i == sz1 and cnt == 1;
  }
};

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        if(n == 0 || beginWord == endWord) return 0;
        int i = 0;
        for(i = 0; i<n && wordList[i]!= endWord; i++) ;
        if(i == n) return 0;
        queue<string> q;
        q.push(beginWord);
        int res = 2; // for start and end word
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i<size; i++) {
                string temp = q.front();
                q.pop();
                for(int j = 0; j < wordList.size(); j++) {
                    if(oneDifference(temp, wordList[j])) {
                        if(wordList[j] == endWord) return res;
                        q.push(wordList[j]);
                        wordList.erase(wordList.begin() + j);
                        j--;
                    }
                }
            }
            res++;
        }
    return 0;
  }
    
private:
  bool oneDifference(const string & x, const string & y) {
    int n1 = x.size(); 
        int n2 = y.size();
        int i = 0, cnt = 0;
    if (n1 != n2) return false;
    
    while (i < n1 and cnt <= 1) {
      if (x[i] != y[i]) {
        ++cnt;
      }
      ++i;
    }
    return i == n1 and cnt == 1;
  }
};
