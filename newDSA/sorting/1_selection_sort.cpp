#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &arr, int n)
{
    int i, j;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
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
    vector<int> arr={32, 20 , 2 , 10 ,9 , 14 ,8};
    print(arr);
     selection_sort(arr, 7);
    print(arr);
    return 0;
}