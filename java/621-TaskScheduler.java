/*

Given a char array representing tasks CPU need to do. It contains 
capital letters A to Z where different letters represent different 
tasks.Tasks could be done without original order. Each task could be 
done in one interval. For each interval, CPU could finish one 
task or just be idle.

However, there is a non-negative cooling interval n that means 
between two same tasks, there must be at least n intervals that 
CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU 
will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

*/


// calculating idle slots
// Time complexity : O(n). We iterate over taskstasks array only once. (O(n).Sorting tasks array of length n 
// takes O(26log(26))= O(1) time. 
// After this, only one iteration over 26 elements of mapmap is done O(1).
// Space complexity : O(1). map array of constant size(26) is used.
class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] map = new int[26];
        for (char c: tasks) map[c - 'A']++;
        
        Arrays.sort(map);
        int max_val = map[25] - 1, idle_slots = max_val * n;
        for (int i = 24; i >= 0 && map[i] > 0; i--) {
            idle_slots -= Math.min(map[i], max_val);
        }
        return idle_slots > 0 ? idle_slots + tasks.length : tasks.length;
    }
}


// Priority Queue solution
// Time complexity : O(n)O(n). Number of iterations will be equal to resultant time timetime.
// Space complexity : O(1)O(1). queuequeue and temptemp size will not exceed O(26).
class Solution1 {
    public int leastInterval(char[] tasks, int n) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < tasks.length; i++) {
            map.put(tasks[i], map.getOrDefault(tasks[i], 0) + 1); // map key is TaskName,and value is number of times to be executed.
        }
        PriorityQueue<Map.Entry<Character, Integer>> q = new PriorityQueue<>( //frequency sort
                (a,b) -> a.getValue() != b.getValue() ? b.getValue() - a.getValue() : a.getKey() - b.getKey());

        q.addAll(map.entrySet());

        int count = 0;
        while (!q.isEmpty()) {
            int k = n + 1;
            List<Map.Entry> tempList = new ArrayList<>();
            while (k > 0 && !q.isEmpty()) {
                Map.Entry<Character, Integer> top = q.poll(); // most frequency task
                top.setValue(top.getValue() - 1); // decrease frequency, meaning it got executed
                tempList.add(top); // collect task to add back to queue
                k--;
                count++; //successfully executed task
            }

            for (Map.Entry<Character, Integer> e : tempList) {
                if (e.getValue() > 0) q.add(e); // add valid tasks 
            }

            if (!q.isEmpty()) count = count + k; // if k > 0, then it means we need to be idle
        }
        return count;
    }
}


// Using Sorting
// Time complexity : O(time). Number of iterations will be equal to resultant time timetime.
// Space complexity : O(1). Constant size array mapmap is used.
class Solution2 {
    public int leastInterval(char[] tasks, int n) {
        int[] map = new int[26];
        for (char c: tasks) map[c-'A']++;
        
        Arrays.sort(map);
        int time = 0;
        while (map[25] > 0) {
            int i = 0;
            while (i <= n) {
                if (map[25] == 0) break;
                if (i < 26 && map[25-i] > 0) map[25-i]--;       
                time++;
                i++;
            }
            Arrays.sort(map);
        }
        return time;
    }
}
