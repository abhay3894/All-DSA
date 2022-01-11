#include <bits/stdc++.h>

using namespace std;

bool linear(int key, int *arr)
{
    for (int i = 0; i < 14; i++)
    {
        if (key == arr[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n = 14;
    int sch;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 34, 44, 55};
    cout << "Enter element : " << endl;
    cin >> sch;
    if (linear(sch, arr))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}