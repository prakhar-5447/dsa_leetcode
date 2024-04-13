// https://leetcode.com/problems/two-sum/description/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                    return {i, j};

        return {};
    }
};

// class Solution
// {
// public:
//     map<string, int> m;
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         int numLen = nums.size();
//         for (int i = 0; i < numLen; i++)
//         {
//             if (m.find(to_string(target - nums[i])) == m.end())
//                 m.insert({to_string(nums[i]), i});
//             else
//                 return {m[to_string(target - nums[i])], i};
//         }

//         return {};
//     }
// };

int main()
{
    vector<int> n = {2, 7, 11, 15};
    int ans;
    cin >> ans;
    Solution s;
    vector<int> res = s.twoSum(n, ans);
    vector<int>::iterator it;
    for (it = res.begin(); it < res.end(); it++)
    {
        cout << (*it) << " ";
    }
}