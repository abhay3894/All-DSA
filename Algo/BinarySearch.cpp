#include <bits/stdc++.h>

using namespace std;

bool binarySearch(int search, int right, int *arr)
{
    int left = 0;
    while (left <= right)
    {

        int mid = left + (right - left) / 2;
        if (search == arr[mid])
        {
            return true;
        }
        else if (search < arr[mid])
        {
            right = mid - 1;
        }
        else if (search > arr[mid])
        {
            left = mid + 1;
        }
    }
    return false;
}

int main()
{
    int n = 14;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 34, 44, 55};
    if (binarySearch(78, n, arr))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}