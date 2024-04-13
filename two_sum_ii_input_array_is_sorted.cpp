// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> v;
        int i = 0, j = numbers.size() - 1;
        while (i != j)
        {
            if (numbers[i] + numbers[j] > target)
                j--;
            else if (numbers[i] + numbers[j] < target)
                i++;
            else
            {
                v.push_back(i + 1);
                v.push_back(j + 1);
                break;
            }
        }
        return v;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {-3, 4, 3, 90};
    int target = 0;
    vector<int> result = sol.twoSum(arr, target);

    vector<int>::iterator it;
    for (it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }
}