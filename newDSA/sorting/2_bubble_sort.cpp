#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped=false;
        for (int j =0; j < n-1-i; j++)
        {
            if (arr[j+1] < arr[j])
            {
                swap(arr[j+1], arr[j]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
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