#include <iostream>
#include <vector>
using namespace std;

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int index, left, right;
    while (k != arr[mid] && start <= end)
    {
        if (k < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    if (k == arr[mid])
    {
        index = mid;
    }else{
        return {-1, -1};
    }
    // left most index.
    while (arr[index] == k)
    {
        left = index;
        index--;
    }
    index = mid;
    while (arr[index] == k)
    {
        right = index;
        index++;
    }
    return {left, right};
}

int main()
{
    vector<int> arr = {0 ,2 ,2 ,2 ,2, 2 ,2 ,2, 3 ,3 };
    pair<int, int> ans = firstAndLastPosition(arr, 10, 0);
    cout << "The first and last position is: " << ans.first << ", " << ans.second << endl;
    return 0;
}