#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    int peak;
    while (start <= end)
    {
        if (arr[mid - 1]<arr[mid] && arr[mid]> arr[mid+1])
        {
            peak = mid;
            start++;
        }
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        if (arr[mid - 1] > arr[mid])
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return peak;
}

int main()
{
    vector<int> arr = {3, 4, 5,1};
    cout<<"hello";
    int ans = peakIndexInMountainArray(arr);

    cout << "this iss the peak index: " << ans << endl;
    return 0;
}