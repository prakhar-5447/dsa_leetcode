// https://leetcode.com/problems/candy/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

// class Solution
// {
// public:
//     int candy(vector<int> &ratings)
//     {
//         vector<int> mp(ratings.size(), 0);
//         int ans = 0;
//         mp[0] = 1;
//         for (int i = 1; i < ratings.size(); i++)
//         {
//             mp[i]++;
//             if (i > 0 && ratings[i] < ratings[i - 1])
//             {
//                 if (mp[i] >= mp[i - 1] || mp[i - 1] == 1)
//                 {
//                     mp[i]--;
//                     i = i - 2;
//                     continue;
//                 }
//             }
//             else if (i > 0 && ratings[i] > ratings[i - 1])
//             {
//                 mp[i] = mp[i - 1] + 1;
//             }
//             else if (i > 0 && mp[i] == 0 && ratings[i] == ratings[i - 1])
//             {
//             }
//         }

//         for (int i = 0; i < ratings.size(); i++)
//         {
//             ans += mp[i];
//         }

//         return ans;
//     }
// };

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> l(ratings.size(), 1);
        vector<int> r(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                l[i] = l[i - 1] + 1;
        }

        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i + 1] < ratings[i])
                r[i] = r[i + 1] + 1;
        }

        int sum = 0;
        for (int i = 0; i < ratings.size(); i++)
            sum += max(l[i], r[i]);

        return sum;
    }
};

int main()
{
    vi a = {1, 2, 3, 2, 1};
    Solution s;
    c(s.candy(a));
}