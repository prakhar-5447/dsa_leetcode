// https://leetcode.com/problems/course-schedule/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses), marked(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
                if (hasCycle(i, adj, visited, marked))
                    return false;
        }

        return true;
    }

    bool hasCycle(int i, vector<vector<int>> &adj, vector<int> &visited, vector<int> &marked)
    {
        visited[i] = 1;
        marked[i] = 1;

        for (auto it : adj[i])
        {
            if (!visited[it] && hasCycle(it, adj, visited, marked))

                return true;
            else if (marked[it] == 1)
                return true;
        }

        marked[i] = 0;
        return false;
    }
};

int main()
{
    vii a{{1, 4}, {2, 4}, {3, 1}, {3, 2}};
    Solution s;
    c(s.canFinish(5, a));
}