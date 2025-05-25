#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void gray_code(int n)
{
    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    for (int i = 2; i < pow(2, n); i = i * 2)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            v.push_back(v[j]);
        }
        for (int j = 0; j < v.size() / 2; j++)
        {
            v[j] = "0" + v[j];
        }
        for (int j = v.size() / 2; j < v.size(); j++)
        {
            v[j] = "1" + v[j];
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
int main()
{
    gray_code(3);

    return 0;
}