// https://leetcode.com/problems/gas-station/description/

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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total_gas = 0, total_cost = 0;
        int curr_gas = 0, starting_point = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            total_gas += gas[i];
            total_cost += cost[i];
            curr_gas += gas[i] - cost[i];
            if (curr_gas < 0)
            {
                starting_point = i + 1;
                curr_gas = 0;
            }
        }
        return (total_gas < total_cost) ? -1 : starting_point;
    }
};

int main()
{
    vi gas = {1, 2, 3, 4, 5}, cost = {3, 4, 5, 1, 2};
    Solution s;
    c(s.canCompleteCircuit(gas, cost));
}