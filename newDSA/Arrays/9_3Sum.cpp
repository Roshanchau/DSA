#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr, int n, int K)
{
    sort(arr.begin() , arr.end());
    vector<vector<int>> res;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int m = j + 1; m < n; m++)
            {
                int flag=0;
                for(int l=0; l<res.size(); l++){
                    for(int n=0; n<res[l].size(); n++){
                        if(arr[i]==res[l][n] && arr[j]==res[l][n+1]){
                            flag=1;
                        }
                    }
                }
                if (arr[i] + arr[j] + arr[m] == K && flag!=1)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[m]);
                    res.push_back(temp);
                }
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