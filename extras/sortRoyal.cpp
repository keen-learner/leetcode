/*

 // Bloomberg interview

 Royal titles consist of name followed by space and a Roman numeral. 
   
 Example:
   Richard IV. The Roman numeral in the title can go 
   to L (50). You are given the Roman numerals from 1 to 10:
   I II III IV V VI VII VIII IX X. And you are given the 10 
   multiples up to 50: XX XXX IL L. Numbers between 10 and 50 
   that are not given can be formed from 10 multiples and a 
   numeral b/w 1 and 9. Example: 48 is XLVIII which is XL (40) 
   plus VIII (8).
   
 You are given an array of Roman titles sort it as follows: 
 sort it on the name unless the names are equal, in which
 case you have to sort it on the ordinal of the numerals.
 Examples:
   Henry II, Edward VIII => Edward VII, Henry II
   Richard V, Richard II, Richard X => Richard II, 
     Richard V, Richard X

*/

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

map<char, int> vals = { {'I', 1}, 
                        {'V', 5}, 
                        {'X', 10}, 
                        {'L', 50}, 
                        {'C', 100}, 
                        {'D', 500}, 
                        {'M', 1000}
                    };


vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}


int romanToInt(string s){
    int res = vals[s[s.size() - 1]];
    for (int i = s.size() - 2; i >= 0; i--) {
        if (vals[s[i]] < vals[s[i+1]])
            res -= vals[s[i]];
        else
            res += vals[s[i]];
    }
    return res;
}

bool comp(string a, string b) {
    vector<string> s1 = split(a, ' ');
    vector<string> s2 = split(b, ' ');
    for (auto s: s1)
        cout << s << endl;
    if (s1[0] < s2[0]) return true;
    if (s1[0] == s2[0] and romanToInt(s1[1]) <= romanToInt(s2[1]))
        return true;
    return false;   

}

int main(){
    vector<string> names = {"Richard V","Henry VI","Edward II","Richard XXV","Henry IX","Edward LII"};
    sort(names.begin(), names.end(), comp);
    for (auto name: names)
        cout<< name << '\t';
return 0;
}
