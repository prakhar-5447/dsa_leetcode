// https://leetcode.com/problems/course-schedule-ii/description/

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
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> res;
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses), marked(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
                if (hasCycle(i, adj, visited, marked, res))
                    return {};
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool hasCycle(int i, vector<vector<int>> &adj, vector<int> &visited, vector<int> &marked, vector<int> &res)
    {
        visited[i] = 1;
        marked[i] = 1;

        for (auto it : adj[i])
        {
            if (!visited[it] && hasCycle(it, adj, visited, marked, res))
                return true;

            else if (marked[it] == 1)
                return true;
        }

        res.push_back(i);
        marked[i] = 0;
        return false;
    }
};

int main()
{
    vii a{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    Solution s;
    vi ans = s.findOrder(4, a);
    f(i, 0, ans.size()) c(ans[i]);
}