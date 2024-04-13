// https://leetcode.com/problems/majority-element/description/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> count;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (count[nums[i]] <= 0)
                count[nums[i]] = 1;
            else
                count[nums[i]]++;
            if (count[nums[i]] > n / 2)
                return nums[i];
        }

        return nums[0];
    }
};

int main()
{
    vector<int> a = {2, 3, 3, 2, 2, 2, 3, 3, 3};
    Solution s;
    cout << s.majorityElement(a) << endl;
}