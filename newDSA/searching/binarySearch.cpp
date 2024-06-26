#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    while (key != arr[mid] && start <= end)
    {
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    if (key == arr[mid])
    {
        return mid;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int arr[] = {3, 4, 8, 10, 25};
    int ans = binarySearch(arr, 5, 25);
    cout << "The key is found and is at index:" << ans << endl;
    return 0;
}