#include <bits/stdc++.h>
using namespace std;

pair<int, int> single(vector<int> v)
{

    int differentiating_number = 0;
    for (int i = 0; i < v.size(); i++)
    {
        differentiating_number = v[i] ^ differentiating_number;
    }

    differentiating_number = (differentiating_number & (differentiating_number - 1)) ^ differentiating_number;

    int b1 = 0, b2 = 0;

    for (int i = 0; i < v.size(); i++)
    {

        if (differentiating_number & v[i])
            b1 = b1 ^ v[i];
        else
            b2 = b2 ^ v[i];
    }

    return {b1, b2};
}
int main()
{

    pair<int, int> ans = single({2, 4, 2, 14, 3, 7, 7, 3});

    cout << ans.first << " " << ans.second;
}