// intersection of two array's
#include <iostream>
#include <vector>
using namespace std;

// vector<int> intersection(vector<int> &arr1, int n, vector<int> &arr2 , int m){
//     vector<int> inter;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(arr1[i]==arr2[j]){
//                 inter.push_back(arr1[i]);
//                 arr2[j]=-1;
//                 break;
//             }
//         }
//     }
//     return inter;
// }

// optimized code (2 pointer approach):
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

void print(vector<int> &arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr1 = {0, 0, 0, 1, 1, 3, 4, 6, 8, 8, 10, 12, 13, 15, 16, 19};
    vector<int> arr2 = {0, 1, 1, 1, 3, 3, 4, 10, 12, 15, 15, 18};
    print(arr1);
    print(arr2);
    vector<int> ans = findArrayIntersection(arr1, arr1.size(), arr2, arr2.size());
    print(ans);
    return 0;
}