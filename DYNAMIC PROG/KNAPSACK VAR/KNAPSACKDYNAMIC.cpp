#include <bits/stdc++.h>
#define ll long long

using namespace std;

int knapsack(int *wt, int *pr, int w, int n)
{
    if (w == 0 || n == 0)
    {
        return 0;
    }
    if (wt[n - 1] <= w)
    {
        return max(pr[n - 1] + knapsack(wt, pr, w - wt[n - 1], n - 1), knapsack(wt, pr, w, n - 1));
    }
    return knapsack(wt, pr, w, n - 1);
}

int main()
{
    int wt[5] = {2, 3, 4, 6, 5};
    int pr[5] = {2, 3, 4, 5, 6};
    cout << knapsack(wt, pr, 15, 5);
    return 0;
}