// https://leetcode.com/problems/relative-ranks/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    string findRank(int num)
    {
        switch (num)
        {
        case 1:
            return "Gold Medal";
            break;
        case 2:
            return "Silver Medal";
            break;
        case 3:
            return "Bronze Medal";
            break;
        }

        return to_string(num);
    }

    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<int> rank;
        copy(score.begin(), score.end(), back_inserter(rank));
        sort(rank.begin(), rank.end());
        int len = rank.size();
        vector<string> result;

        for (auto it = score.begin(); it != score.end(); it++)
        {
            auto index = find(rank.begin(), rank.end(), *it);
            result.push_back(findRank(len - (index - rank.begin())));
        }

        return result;
    }
};

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    Solution s;
    vector<string> ans = s.findRelativeRanks(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}