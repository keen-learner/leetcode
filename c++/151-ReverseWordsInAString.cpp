/*

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.

Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.

How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

*/

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void reverseWords(string &s) {
        int i = 0;
        while(i<s.size() && s[i] == ' ') i++;
        if(i == s.size()) {s = "";return;}
        int j = 0;
        while(i<s.size()) {
            int k = j;
            while(i<s.size() && s[i] != ' ') s[j++] = s[i++];
            reverse(s.begin() + k, s.begin() + j);
            while(i<s.size() && s[i] == ' ') i++; 
            if(i<s.size()) s[j++] = ' ';
        }
        s.resize(j);
        reverse(s.begin(), s.end());
    }
};

// This and Solution 0 are same; only Sol 0 has own reverse
class Solution00 {
public:
    void reverseWords(string &s) {
        
        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;
        
        while(true){
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break;
            if(wordcount) s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ') {s[j]=s[i]; j++; i++;} 
            //reverseword(s,l,j-1);                 reverse word in place
            reverse(s.begin() + l, s.begin() + j);
            wordcount++;
        }
        
        s.resize(j);                           // resize result string
        reverse(s.begin(), s.end());
        //reverse(s.begin()+0, s.begin() +j);  /* can do this too */
        //reverseword(s,0,j-1);                   reverse whole string
    }
};


class Solution0 {
public:

    // function to reverse any part of string from i to j (just one word or entire string)
    void reverseword(string &s, int i, int j){
        while(i<j){
          char t=s[i];
          s[i++]=s[j];
          s[j--]=t;
        } 
    }
    
    void reverseWords(string &s) {
        
        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;
        
        while(true){
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break;
            if(wordcount) s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ') {s[j]=s[i]; j++; i++;} 
            reverseword(s,l,j-1);                // reverse word in place
            wordcount++;
            
        }
        
        s.resize(j);                           // resize result string
        reverseword(s,0,j-1);                  // reverse whole string
    }
};


class Solution1 {
public:
    void reverseWords(string &s) {
        // Reverse the whole string first.
        reverse(s.begin(), s.end());

        size_t begin = 0, end = 0, len = 0;
        while ((begin = s.find_first_not_of(" ", end)) != string::npos) {
            if ((end = s.find(" ", begin)) == string::npos) {
                end = s.length();
            }
            // Reverse each word in the string.
            reverse(s.begin() + begin, s.begin() + end);

            // Shift the word to avoid extra space.
            move(s.begin() + begin, s.begin() + end, s.begin() + len);
            len += end - begin;
            s[len++] = ' ';
        }
        s.resize(len ? len - 1 : 0);
    }
};

/*

storeIndex basically stores the start position of next word. The new word that I mean is
space + new word
except the first word(where storeIdx = 0). Obviously we need a space between two words.

The procedure inside the for loop is:

    put a blank space in front of the word if this word is not the first word
    copy the word to the position starts with storeIndex
    reverse the word
    update the possible start of next word

*/
class Solution2 {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int storeIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }   
        }
        s.erase(s.begin() + storeIndex, s.end());
    }
};
