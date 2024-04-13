// https://leetcode.com/problems/count-and-say/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1)
            return 0;

        vector<int> prime(n, 0);
        int count = 0;

        for (long i = 2; i < n; i++)
        {
            if (prime[i] == 0)
            {
                long long j = i * i;
                for (j; j < n; j += i)
                    prime[j] = 1;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout << s.countPrimes(2) << endl;
}