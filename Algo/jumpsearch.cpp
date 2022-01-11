#include <bits/stdc++.h>

using namespace std;

int jumpSearch(int *arr, int data, int n)
{
    int i = 0;
    int jump = sqrt(n);
    while (arr[i] < data)
    {
        i += jump;
    }
    for (int j = i; j > 0; j--)
    {
        if (arr[j] == data)
        {
            return j;
        }
    }
    return -1;
}

int main()
{
    int n = 14, sch;
    int arr[n] = {10, 20, 30, 40, 50, 63, 73, 85, 96, 103, 122, 346, 442, 555};
    cout << "Enter Element : ";
    cin >> sch;
    cout << "Element : " << sch << " at index : " << jumpSearch(arr, sch, n);

    return 0;
}