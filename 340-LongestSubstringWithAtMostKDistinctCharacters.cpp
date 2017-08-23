/*

Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

*/

class Solution {
    int lengthOfLongestSubstringKDistinct(string s) {
        unordered_map<char, int> m;
        //Map<Character,Integer> map = new HashMap<>();
        int begin = 0;
        int end = 0;
        int counter = 0;
        int res = 0;
        while(end < s.size()){
            ++m[s[end]];
            //char c = s.charAt(end);
            //map.put(c, map.getOrDefault(c, 0) + 1);
            if(m[s[end]] == 1) ++counter; // new char
            //if(map.get(c) == 1) counter++;//new char
            while(counter > k){
                //char cTemp = s.charAt(start);
                //map.put(cTemp, map.get(cTemp) - 1);
                --m[s[begin]];
                if(m[s[begin]] == 0) --counter;
                //if(map.get(cTemp) == 0){
                //    counter--;
                //}
                begin++;
            }
            res = max(res, end-begin+1);
            //len = Math.max(len, end-start);
            end++;
        }
        return res;
        //return len;
    }
}
