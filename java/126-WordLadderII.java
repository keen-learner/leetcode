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
    // use a hashmap to store words and their corresponding depths.
    HashMap<String,Integer> path = new HashMap<String,Integer>();
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> res = new ArrayList<>();
        List<String> tmp = new ArrayList<>();
        Set<String> set = new HashSet<>(wordList);
        // beginWord is not in the wordlist, but the endword is ! check the endword first
        if (beginWord == null || endWord == null || !set.contains(endWord)) return res;
        bfs(beginWord, endWord, set);
        dfs(endWord, beginWord, set, tmp, res);
        return res;
    }
    private void dfs(String beginWord, String endWord, Set<String> set, List<String> tmp_path, List<List<String>> res) {
        if (beginWord.equals(endWord)) {
            tmp_path.add(beginWord);
            Collections.reverse(tmp_path);
            res.add(tmp_path);
            return;
        }
        if (path.get(beginWord) == null) return;
        tmp_path.add(beginWord);
        int nextDepth = (int) path.get(beginWord) - 1;
        for (int i = 0; i < beginWord.length(); i++) {
            char[] ca = beginWord.toCharArray();
            for (char c = 'a'; c <= 'z'; c++) {
                if (ca[i] == c) continue;
                ca[i] = c;
                String newWord = new String(ca);
                if (path.get(newWord) != null && path.get(newWord) == nextDepth) {
                    List<String> new_tmp_path = new ArrayList<>(tmp_path);
                    dfs(newWord, endWord, set, new_tmp_path, res);
                }
            }
        }
    }
    private void bfs(String start, String end, Set<String> set) {
        Queue<String> queue = new LinkedList<>();
        queue.add(start);
        path.put(start, 0);
        String current;
        while (!queue.isEmpty()) {
            current = queue.poll();
            if (current == end) continue;
            for (int i = 0; i < current.length(); i++) {
                char[] ca = current.toCharArray();
                for (char c = 'a'; c <= 'z'; c++) {
                    if (ca[i] == c) continue;
                    ca[i] = c;
                    String newWord = new String(ca);
                    // if newWord is the same as the endword or wordlist contains newWord
                    if (newWord.equals(end) || set.contains(newWord)) {
                        if (path.get(newWord) == null) {
                            int depth = path.get(current);
                            path.put(newWord, depth + 1);
                            queue.add(newWord);
                        }
                    }
                }
            }
        }
    }
}

class Solution1 {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> res = new ArrayList<>();
        Queue<List<String>> queue = new LinkedList<>();
        queue.offer(new ArrayList<>(Arrays.asList(beginWord)));
        Set<String> visited = new HashSet<>();
        Set<String> word_list = new HashSet<>(wordList);
        boolean found = false;
        if (!word_list.contains(endWord)) return res;
        while (!queue.isEmpty() && !word_list.isEmpty()) {
            for (int i = queue.size(); i > 0; --i) {
                List<String> path = queue.poll();
                String back_word = path.get(path.size() - 1);
                for (int j = 0; j < back_word.length(); j++) {
                    char[] chs = back_word.toCharArray();
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (chs[j] == c) continue;
                        chs[j] = c;
                        String next_word = String.valueOf(chs);
                        if (next_word.equals(endWord)) {
                            path.add(next_word);
                            res.add(path);
                            found = true;
                        }
                        if (word_list.contains(next_word)) {
                            visited.add(next_word);
                            List<String> new_path = new ArrayList<>(path);
                            new_path.add(next_word);
                            queue.offer(new_path);
                        }
                    }
                }
            }
            if (found) break;
            word_list.removeAll(visited);
            visited.clear();
        }
        return res;
    }
}

