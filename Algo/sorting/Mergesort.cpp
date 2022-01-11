#include <bits/stdc++.h>
#define ll long long

using namespace std;

void merge(int *arr, int left, int mid, int right)
{
    int temp[right + 1];
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int s = left; s <= right; s++)
    {
        arr[s] = temp[s];
    }
}
void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    mergesort(arr, 0, length - 1);
    print(arr, length);
    return 0;
}