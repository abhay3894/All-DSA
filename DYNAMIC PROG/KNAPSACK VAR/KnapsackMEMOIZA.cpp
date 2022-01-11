#include <bits/stdc++.h>
#define ll long long

int t[1000][1000];

using namespace std;

int knapsack(int *wt, int *pr, int w, int n)
{
    if (w == 0 || n == 0)
    {
        return 0;
    }
    if (t[w][n] != -1)
    {
        return t[w][n];
    }

    if (wt[n - 1] <= w)
    {
        return t[w][n] = max(pr[n - 1] + knapsack(wt, pr, w - wt[n - 1], n - 1), knapsack(wt, pr, w, n - 1));
    }
    return t[w][n] = knapsack(wt, pr, w, n - 1);
}

int main()
{
    memset(t, -1, sizeof(t));
    int wt[5] = {2, 3, 4, 6, 5};
    int pr[5] = {2, 3, 4, 5, 6};
    cout << knapsack(wt, pr, 7, 5);
    return 0;
}