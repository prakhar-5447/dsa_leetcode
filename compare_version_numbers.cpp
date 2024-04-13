// https://leetcode.com/problems/compare-version-numbers/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> v1, v2;
        int i = 0, j = 0;
        int n1 = version1.size(), n2 = version2.size();
        while (i < n1 || j < n2)
        {
            int num1 = 0, num2 = 0;

            while (i < n1 && version1[i] != '.')
            {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < n2 && version2[j] != '.')
            {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if (num1 < num2)
                return -1;
            if (num1 > num2)
                return 1;

            i++;
            j++;
        }

        return 0;
    }
};

int main()
{
    Solution s;
    c(s.compareVersion("1.1", "1.10"));
}