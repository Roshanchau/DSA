#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k=0;
        for (int j = k + 1; j < n; j++)
        {
            if (arr[j] < arr[k])
            {
                swap(arr[j], arr[k]);
            }
            k++;
        }
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {32, 20, 2, 10, 9, 14, 8};
    print(arr);
    bubble_sort(arr, 7);
    print(arr);
    return 0;
}