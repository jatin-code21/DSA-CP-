#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> seg;
public:
    SegmentTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(int ind, int low, int high, int a[])
    {
        if (low == high)
        {
            seg[ind] = a[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r)
    {
        // no overlap
        if (r < low || l > high)
            return INT_MAX;
        // complete overlap
        if (l <= low && r >= high)
            return seg[ind];
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        // here i is the index of the element to be updated
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

int main()
{
    int n;
    cin >> n;
    int a[n];
    int seg[4 * n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
}