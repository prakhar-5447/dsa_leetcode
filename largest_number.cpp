// https://leetcode.com/problems/binary-search-tree-iterator/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

class Solution
{
public:
    string largestNumber(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        string ans = "";
        for (int i = 0; i < arr.size(); i++)
            ans += to_string(arr[i]);
        if (ans[0] == '0')
            return "0";
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 4, 5, 23, 76, 45, 12, 43, 2};
    Solution s;
    cout << s.largestNumber(arr) << endl;
}