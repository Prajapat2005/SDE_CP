#include <bits/stdc++.h>
using namespace std;

class Fenwick
{
private:
    vector<int> bits;

public:
    Fenwick(int n)
    {
        bits.resize(n + 1, 0);
    }

    void update(int i, int val)
    {
        int num = i;
        while (num < bits.size())
        {
            bits[num] += val;
            num = num + (num & ((-1) * num));
        }
    }

    int pref(int i)
    {
        int num = i;
        int sum = 0;
        while (num)
        {
            sum += bits[num];
            num = num - (num & ((-1) * num));
        }

        return sum;
    }

    int query(int i, int j)
    {
        return pref(j) - pref(i);
    }
};

int main()
{
    int n;
    cin >> n;
    Fenwick *fen = new Fenwick(2 * n);
    vector<int> ans(n + 1);
    vector<int> prev(n + 1, 0);
    for (int i = 1; i <= 2 * n; i++)
    {
        int num;
        cin >> num;

        if (prev[num] == 0)
        {
            prev[num] = i;
        }
        else
        {
            ans[num] = fen->query(prev[num], i);
            fen->update(prev[num], 1); // when we visite node again then we make prev index of node ans 1
                                       // other wise prev node index mark ans 0;

            /*  Intersecting interval
                ans[num] = (i-prev[num]) - fen->query(prev[num], i)*2 - 2;
            */
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}

/*
   5 1 2 2 3 1 3 4 5 4

   i) 5 1 2 2 3 1 3 4 5 4
      0 0 0 0 0 0 0 0 0 0  // first visite of 5

   ii) 5 1 2 2 3 1 3 4 5 4
       0 0 0 0 0 0 0 0 0 0  // first visite of 1

   iii) 5 1 2 2 3 1 3 4 5 4
        0 0 0 0 0 0 0 0 0 0  // first visite of 2

   iv) 5 1 2 2 3 1 3 4 5 4
       0 0 1 0 0 0 0 0 0 0 // now it is second visit of 2 so ve mark pref as zero

   v) 5 1 2 2 3 1 3 4 5 4
      0 0 1 0 0 0 0 0 0 0  // first visite of 3

    vi) 5 1 2 2 3 1 3 4 5 4
        0 1 1 0 0 0 0 0 0 0  // now it is second visit of 1 so ve mark pref as zero


    ans count number of 1 in segment which denotes that segemnt lie inside that segment
    number 1 present starting point of segment

*/