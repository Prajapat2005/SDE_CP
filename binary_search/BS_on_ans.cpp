/*https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/*/

class Solution
{
public:
    bool check(vector<long long> pref, vector<int> v, long long freq, long long k)
    {

        long long i = 0, j = freq - 1;

        while (j < v.size())
        {
            long long median = (i + j) / 2;

            long long left = (median - i) * v[median];
            long long right = (j - median) * v[median];

            long long left_op = 0;
            if (median - 1 >= 0)
            {
                left_op = left - (pref[median - 1] - ((i <= 0) ? (0) : (pref[i - 1])));
            }
            long long right_op = (pref[j] - pref[median]) - right;

            if (left_op + right_op <= k)
            {
                return true;
            }

            i++;
            j++;
        }

        return false;
    }
    long long solve(vector<int> v, vector<long long> pref, long long k)
    {

        long long l = 1, r = v.size();

        while (l <= r)
        {
            long long mid = (r + l) / 2;
            if (check(pref, v, mid, k))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r;
    }
    long long maxFrequencyScore(vector<int> &v, long long k)
    {

        sort(v.begin(), v.end());
        vector<long long> pref(v.size());
        pref[0] = v[0];
        for (long long i = 1; i < v.size(); i++)
        {
            pref[i] = v[i] + pref[i - 1];
        }

        return solve(v, pref, k);
    }
};