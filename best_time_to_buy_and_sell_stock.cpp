// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for (int i = 0; i < prices.size(); i++)
        {
            minVal = min(minVal, prices[i]);
            maxVal = max(maxVal, prices[i] - minVal);
        }
        return maxVal;
    }
};

int main()
{
    vector<int> a = {1, 2};
    Solution s;
    cout << s.maxProfit(a) << endl;
}