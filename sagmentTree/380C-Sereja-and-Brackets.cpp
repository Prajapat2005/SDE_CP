#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int open;
    int close;
    int full;
}

class SEGtree
{
private:
    vector<Node> seg;

public:
    SEGtree()
    {
        v.resize(4 * n + 1);
    }
    void build(int ind, int left, int right, vector<char> v)
    {

        if (left == right)
        {
            (v[left] == '(') ? (seg[ind].open++) : (seg[ind].close++);
            return;
        }

        int mid = (right + left) >> 1;
        build(ind * 2 + 1, left, mid, v);
        build(ind * 2 + 1, mid + 1, right, v);

        seg[ind].full = min(seg[ind * 2 + 1].open, seg[int * 2 + 2].close) + seg[ind * 2 + 1].full + seg[int * 2 + 2].full;
        seg[ind].open = seg[ind * 2 + 1].open + seg[int * 2 + 2].open - min(seg[ind * 2 + 1].open, seg[int * 2 + 2].close);
        seg[ind].close = seg[ind * 2 + 1].close + seg[int * 2 + 2].close - min(seg[ind * 2 + 1].open, seg[int * 2 + 2].close);
    }

} int main()
{
}