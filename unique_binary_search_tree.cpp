// https://leetcode.com/problems/unique-binary-search-trees/dsecription/

#include <iostream>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        unsigned long int catalan[n + 1];
        catalan[0] = catalan[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            catalan[i] = 0;
            for (int j = 0; j < i; j++)
                catalan[i] += catalan[j] * catalan[i - j - 1];
        }
        return catalan[n];
    }
};

int main()
{
    Solution s;
    cout << s.numTrees(3) << endl;
}