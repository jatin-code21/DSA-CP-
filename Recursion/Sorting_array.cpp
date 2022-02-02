#include <bits/stdc++.h>
using namespace std;

vector<int> Insertion(vector<int> &a, int temp) // temp is last element of vector to which we have to insert by comparing into the vector
{
    if (a.size() == 0 || a[a.size() - 1] <= temp) // Base Condition
    {
        a.push_back(temp);
        return a;
    }
    int val = a[a.size() - 1];
    a.pop_back();
    Insertion(a, temp); // Hypthesis
    a.push_back(val);   // Induction of Insertion Function
    return a;
}

void Sort(vector<int> &a)
{
    if (a.size() == 1)
        return;                 // Base Condition
    int temp = a[a.size() - 1]; // Element which has to be inserted in sorted array/vector
    a.pop_back();               // poping last element of vector to apply the Sort Function for smaller size of vector
    Sort(a);                    // Hypothesis
    Insertion(a, temp);         // Induction of Sort Function
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Sort(a);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}