/*

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.

*/


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // pair<i,j> means take j befor i
        vector<unordered_set<int>> g(numCourses);
        vector<int> indegree(numCourses);
        
        // make graph g, g[i] is set of all vertices for vertex i
        for(pair<int, int> p: prerequisites) { // p - pair
            g[p.second].insert(p.first);
        }

        // make indegree
        for(int i = 0; i < g.size(); i++) {
            auto s = g[i]; //s is set of neighbor vertices of vertex i
            for(auto it = s.begin(); it != s.end(); it++) {
                indegree[*it]++;
            }
        }
        for(int i = 0; i < numCourses; i++) { // find position of numCourses vertex
            int j = 0;
            for(; j<numCourses; j++) if(indegree[j] == 0) break;
            if(j == numCourses) return false; // didn't find indegree 0
            indegree[j] = -1; //changed so that we dont find it again
            auto s = g[j]; // set of neighbor vertices of j
            for(auto it = s.begin(); it != s.end(); it++) {
                indegree[*it]--;
            }
        }
        return true;
    }
};
