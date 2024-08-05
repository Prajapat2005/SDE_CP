#include <bits/stdc++.h>
using namespace std;

string number_to_binary(int x)
{

    string s;
    while (x != 1)
    {

        if (x % 2 == 0)
            s.push_back('0');
        else
            s.push_back('1');

        x = x / 2;
    }
    s.push_back('1');

    reverse(s.begin(), s.end());

    return s;
}

int binary_to_number(string s)
{

    int pow = 1;
    int ans = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {

        if (s[i] == '1')
            ans = ans + pow;

        pow = pow * 2;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << number_to_binary(n) << " " << binary_to_number(number_to_binary(n));
}