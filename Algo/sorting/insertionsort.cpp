#include <bits/stdc++.h>
#define ll long long

using namespace std;

void insertion(int *arr, int length)
{
    int i, j, key;
    for (i = 1; i < length; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] >= key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {5, 3, 6, 8, 2};
    int length = sizeof(arr) / sizeof(arr[0]);
    print(arr, length);
    insertion(arr, length);
    print(arr, length);

    return 0;
}