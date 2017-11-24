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

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if(wordList == null || wordList.size()==0) return 0;
        if(beginWord.equals(endWord)) return 1;
        Queue<String> q = new LinkedList<>();
        q.offer(beginWord);
        int res = 2;
        while(!q.isEmpty()) {
            int size = q.size();
            for(int i = 0; i<size; i++) { // check all words at distance 'res'
                String temp = q.poll();
                for(int j = 0; j<wordList.size(); j++) {
                    if(oneDifference(temp, wordList.get(j))) {
                        if(wordList.get(j).equals(endWord)) return res;
                        q.offer(wordList.get(j));
                        wordList.remove(j); // remove from wordList
                        j--;
                    }
                }
            }
            res++;
        }
        return 0;
    }
    
    private boolean oneDifference(String a, String b) {
        int n1 = a.length();
        int n2 = b.length();
        if(n1 != n2) return false;
        boolean flag = false;
        for(int i = 0; i<n1; i++) {
            if(a.charAt(i) != b.charAt(i)) {
                if(flag) return false;
                flag = true;
            }
        }
        return true;
    }
}
