#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Cn = sum(Ci*Cn-i-1)
int nthCatalan(int k)
{
    vector<int> catalanNum(k, 0);
    catalanNum[0] = catalanNum[1] = 1;
    for (int len = 2; len <= k; len++)
    {
        for (int j = 0; j < i; j++)
        {
            catalanNum[len] += catalanNum[j] * catalanNum[len - j - 1];
        }
    }
    return catalanNum[k];
}

int validParentheses(int N)
{
    int k = N / 2;
    return nthCatalan(k);
}
int main()
{
    int n = 6;
    cout << validParentheses(n);
    return 0;
}