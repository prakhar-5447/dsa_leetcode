// https://leetcode.com/problems/teemo-attacking/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int result = duration, len = timeSeries.size();
        for (int i = 1; i < len; i++)
        {
            if (timeSeries[i] <= timeSeries[i - 1] + duration - 1)
                result = result + timeSeries[i] - timeSeries[i - 1];
            else
                result += duration;
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 5, 6, 8, 9, 12, 14, 23};
    cout << s.findPoisonedDuration(arr, 2) << endl;
}