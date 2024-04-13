// https://leetcode.com/problems/distribute-candies/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_set<int> ans;
        for (int i = 0; i < candyType.size(); i++)
            ans.insert(candyType[i]);

        return min(ans.size(), candyType.size() / 2);
    }
};

int main()
{
    vector<int> a = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4};
    Solution s;
    cout << s.distributeCandies(a) << endl;
}