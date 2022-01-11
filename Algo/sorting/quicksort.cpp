#include <bits/stdc++.h>
#define ll long long

using namespace std;

int partition(int *arr, int s, int e)
{
    int pivot = arr[e];
    int p = s;
    for (int i = s; i < e; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[p]);
            p++;
        }
    }
    swap(arr[e], arr[p]);
    return p;
}

void quickSort(int *arr, int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e);
        quickSort(arr, s, p - 1);
        quickSort(arr, p + 1, e);
    }
}

void print(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[5] = {5, 3, 6, 8, 2};
    int length = sizeof(arr) / sizeof(arr[0]);
    print(arr, length);
    cout << "\n";
    quickSort(arr, 0, length - 1);
    print(arr, length);
    return 0;
}