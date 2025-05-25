void merge(vector<int> &v, int l, int mid, int r, int &count)
{

    int an = mid - l + 1;
    int bn = r - mid;

    vector<int> a(an);
    vector<int> b(bn);
    for (int i = 0; i < an; i++)
    {
        a[i] = v[l + i];
    }
    for (int i = 0; i < bn; i++)
    {
        b[i] = v[mid + i + 1];
    }

    int k = l, i = 0, j = 0;
    while (i < an && j < bn)
    {
        if (a[i] > b[j])
        {
            count += (an - i);
            v[k++] = b[j++];
        }
        else
        {
            v[k++] = a[i++];
        }
    }

    while (i < an)
    {
        v[k++] = a[i++];
    }
    while (j < bn)
    {
        v[k++] = b[j++];
    }
}
void mergsort(vector<int> &v, int l, int r, int &count)
{

    if (l >= r)
        return;

    int mid = (r - l) / 2 + l;
    mergsort(v, l, mid, count);
    mergsort(v, mid + 1, r, count);
    merge(v, l, mid, r, count);
}
int numberOfInversions(vector<int> &a, int n)
{

    int ans = 0;
    mergsort(a, 0, n - 1, ans);
    return ans;
}