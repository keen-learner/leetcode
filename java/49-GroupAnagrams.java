/*

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.

*/

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        // List<List<String>> res = new ArrayList<ArrayList<String>>(); /*gives error*/
        // List<List<String>> res = new ArrayList<List<String>>(); /*OK*/
        List<List<String>> res = new ArrayList<>();
        for(String s: strs) {
            char[] c = s.toCharArray();
            Arrays.sort(c);
            String ss = String.valueOf(c);
            if(!map.containsKey(ss)) map.put(ss, new ArrayList<String>());
            map.get(ss).add(s);
        }
        for(List<String> value : map.values()) {
            res.add(value);
        }
        return res;
    }
}
