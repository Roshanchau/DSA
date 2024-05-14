#include <iostream>
using namespace std;

int find_unique(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i <n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arr[5]={1, 1 , 2, 3 ,2};

    int a=find_unique(arr, 5);
    cout<<a;

    return 0;
}