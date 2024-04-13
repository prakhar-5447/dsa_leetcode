// https://leetcode.com/problems/plus-one/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] += carry;
            carry = 0;
            if (digits[i] > 9)
            {
                carry++;
                digits[i] = 0;
            }
        }
        if (carry > 0)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main()
{
    vector<int> a = {1, 9};
    Solution s;
    vector<int> ans = s.plusOne(a);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
}