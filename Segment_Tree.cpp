#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> seg;
    vector<int> lazy;
public:
    SegmentTree(int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
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

    void pointUpdate(int ind, int low, int high, int i, int val)
    {
        // here i is the index of the element to be updated
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            pointUpdate(2 * ind + 1, low, mid, i, val);
        else
            pointUpdate(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    // l, r -> update the range value
    // this is for the sum of range
    void rangeUpdate(int ind, int low, int high, int l, int r, int val)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1)*lazy[ind];
            if (low != high) // not a leaf node
            {
                lazy[2 * ind + 1] += lazy[ind]; // propogation the lazy value to the children
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0; // reset the lazy value as it has been propogated
        }

        if (r <low || l > high || low > high) return;
        if (low >= l && high <= r)
        {
            seg[ind] += (high - low + 1)*val;
            if (low != high)
            {
                lazy[2 * ind + 2] += lazy[ind];
                lazy[2 * ind + 1] += lazy[ind];
            }
            return;
        }

        int mid = (low + high) >> 1;
        rangeUpdate(2 * ind + 1, low, mid, l, r, val);
        rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int querySumLazy(int ind, int low, int high, int l, int r, int val)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1)*lazy[ind];
            if (low != high) // not a leaf node
            {
                lazy[2 * ind + 1] += lazy[ind]; // propogation the lazy value to the children
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0; // reset the lazy value as it has been propogated
        }

        if (r <low || l > high || low > high) return 0;
        if (low >= l && high <= r)
        {
            return seg[ind];
        }

        int mid = (low + high) >> 1;
        int left = querySumLazy(2 * ind + 1, low, mid, l, r, val);
        int right = querySumLazy(2 * ind + 2, mid + 1, high, l, r, val);
        return left + right;
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