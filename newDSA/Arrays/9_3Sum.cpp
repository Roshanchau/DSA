#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// TLE


// vector<vector<int>> findTriplets(vector<int> &arr, int n, int K)
// {
//     sort(arr.begin() , arr.end());
//     vector<vector<int>> res;
//     for (int i = 0; i < n - 2; i++)
//     {
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             for (int m = j + 1; m < n; m++)
//             {
//                 int flag=0;
//                 for(int l=0; l<res.size(); l++){
//                     for(int n=0; n<res[l].size(); n++){
//                         if(arr[i]==res[l][n] && arr[j]==res[l][n+1]){
//                             flag=1;
//                         }
//                     }
//                 }
//                 if (arr[i] + arr[j] + arr[m] == K && flag!=1)
//                 {
//                     vector<int> temp;
//                     temp.push_back(arr[i]);
//                     temp.push_back(arr[j]);
//                     temp.push_back(arr[m]);
//                     res.push_back(temp);
//                     i+=3;
//                     j=n;
//                     break;
//                 }
//             }
//         }
//     }
//     return res;
// }

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum= arr[i]+arr[j]+arr[k];
            if(sum<K){
                j++;
            }
            else if(sum>K){
                k--;
            }else{
                vector<int> temp={arr[i] , arr[j] , arr[k]};
                res.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1]) j++;
                while(j<k && arr[k]==arr[k-1]) k--;
            }
        }
    }
    return res;
}
void print(vector<vector<int>> &arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main()
{
    vector<int> arr={10,5,5,5,2};
    vector<vector<int>> ans=findTriplets(arr, 5, 12);
    print(ans);
    return 0;
}