#include <iostream>
using namespace std;
#include <vector>

// ***self***

// int findDup(vector<int> &arr)
// {
//     int ans = 0;
//     int size = arr.size();
//     for (int i = 0; i < size; i++)
//     {
//         ans = ans ^ arr[i] ^ i;
//     }
//     return ans;
// }

// tutorial method.
int findDup(vector<int> &arr)
{
    int ans = 0;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    for(int i=1; i<size; i++){
        ans=ans^i;
    }
    return ans;
}

int main()
{
    vector<int> arr = {6, 3, 1, 5, 4, 1, 2};
    int res = findDup(arr);
    cout << endl;
    cout << "ans->" << res << endl;
    return 0;
}