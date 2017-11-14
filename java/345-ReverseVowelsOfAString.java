/*

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".

*/

class Solution {
    public String reverseVowels(String s) {
        if(s == null || s.length()==0) return s;
        String vowels = "aeiouAEIOU";
        char[] chars = s.toCharArray();
        int i = 0;
        int j = s.length()-1;
        while(i<j){

            while(i<j && vowels.indexOf(chars[i])==-1){
                i++;
            }

            while(i<j && vowels.indexOf(chars[j])==-1){
                j--;
            }

            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;

            i++;
            j--;
        }
        return new String(chars);
    }
}
