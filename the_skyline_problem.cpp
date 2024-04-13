// https://leetcode.com/problems/the-skyline-problem/description/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
    vector<vector<int>> result;

public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        priority_queue<pair<int, int>> max_heap;
        int i = 0, cur_x, cur_height = 0, cur_max_height = 0;
        int n = buildings.size();

        while (i < n || !max_heap.empty())
        {
            if (max_heap.empty() || (i < n && buildings[i][0] <= max_heap.top().second))
            {
                cur_x = buildings[i][0];
                while (i < n && buildings[i][0] == cur_x)
                {
                    max_heap.push(make_pair(buildings[i][2], buildings[i][1]));
                    i++;
                }
            }
            else
            {
                cur_x = max_heap.top().second;
                while (!max_heap.empty() && max_heap.top().second <= cur_x)
                    max_heap.pop();
            }

            cur_max_height = max_heap.empty() ? 0 : max_heap.top().first;
            if (result.empty() || cur_max_height != cur_height)
            {
                result.push_back({cur_x, cur_max_height});
                cur_height = cur_max_height;
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> arr = {{2, 9, 10}, {3, 7, 15}, {5, 12, 1}, {15, 20, 0}, {19, 24, 8}};
    vector<vector<int>> ans = s.getSkyline(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}