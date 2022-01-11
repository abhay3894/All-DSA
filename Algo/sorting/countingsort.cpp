#include <bits/stdc++.h>
#define ll long long

using namespace std;

int maxV(int *arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void printArr(int *arr, int n);

void countSort(int *arr, int n)
{
    // find max element in array
    int max = maxV(arr, n);
    int count[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    int j = 0;
    int i = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n = 5;
    int arr[n] = {1, 3, 2, 4, 2};
    printArr(arr, n);
    countSort(arr, n);
    cout << "\n";
    printArr(arr, n);

    return 0;
}