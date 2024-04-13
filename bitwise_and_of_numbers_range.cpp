// https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right)
            return left;
        int temp{0};
        for(int i=0; i<31; i++, left>>=1, right>>=1, temp<<=1) {
            if ((left&1) == (right&1))
                temp |= (left&1);
            else
                temp = 0;
        }
        int res{0};
        for(int i=0; i<31; i++) {
            res |= (temp&1);
            temp >>= 1;
            res <<= 1;
        }

        return res;
    }
};

int main()
{
    Solution s;
    c(s.rangeBitwiseAnd(1, 2147483647));
}
