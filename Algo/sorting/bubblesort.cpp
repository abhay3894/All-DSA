#include <bits/stdc++.h>

using namespace std;

void bubblesort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[i])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}
// complexity = O(n^2)
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n = 5;
    int arr[n] = {11, 34, 54, 3, 23};
    bubblesort(arr, n);
    printArray(arr, n);

    return 0;
}