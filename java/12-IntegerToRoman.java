/*

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

*/

public class Solution {
    public String intToRoman(int num) {
        int[] values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] strs = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        StringBuilder s = new StringBuilder();
        int i = 0;
        while(num != 0) {
            int times = num/values[i];
            while(times != 0) {
                s.append(strs[i]);
                --times;
            }
            num = num%values[i];
            ++i;
        }
        return s.toString();
    }
}
