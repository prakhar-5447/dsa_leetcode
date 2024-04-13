// https://leetcode.com/problems/maximum-gap/description/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return 0;
        if (n == 2)
            return abs(nums[0] - nums[1]);

        int maxEle = nums[0];
        int minEle = nums[0];
        for (int i = 1; i < n; i++)
        {
            maxEle = max(maxEle, nums[i]);
            minEle = min(minEle, nums[i]);
        }

        int bucketSize = ceil(float(maxEle - minEle) / (n - 1));
        if (bucketSize == 0)
            return 0;

        int numOfBuckets = n;

        vector<int> maxOfBucket(numOfBuckets, INT_MIN);
        vector<int> minOfBucket(numOfBuckets, INT_MAX);

        for (int i = 0; i < n; i++)
        {
            int ele = nums[i];
            int whichBucket = ((ele - minEle) / bucketSize);

            maxOfBucket[whichBucket] = max(maxOfBucket[whichBucket], ele);
            minOfBucket[whichBucket] = min(minOfBucket[whichBucket], ele);
        }

        int ans = bucketSize;

        int prevMax = maxOfBucket[0];
        for (int i = 1; i < numOfBuckets; i++)
        {
            if (minOfBucket[i] == INT_MAX)
                continue;

            ans = max(ans, (minOfBucket[i] - prevMax));
            prevMax = maxOfBucket[i];
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 4, 3, 67, 5, 8, 5, 2, 45, 32, 12, 28, 99};
    cout << s.maximumGap(arr) << endl;
}