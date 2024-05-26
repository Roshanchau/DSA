#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
    int i=0,j=1;
    sort(arr.begin(), arr.end());
    vector<int> pair;
    vector<vector<int>>ans;
    while(i<arr.size()){
        if(arr[i]>s/2){
            break;
        }
        if(j==arr.size()){
            i++;
            j=i+1;
        }
        if(arr[i]+arr[j]==s){
            pair.push_back(arr[i]);
            pair.push_back(arr[j]);
            ans.push_back(pair);
            pair.clear();
        }
        j++;
    }
    return ans;
}

void print(vector<vector<int>> &arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << endl;
}


int main(){

    vector<int> arr={-3,-2,2,3,3};
    vector<vector<int>>res=pairSum(arr,0);
    print(res);
    return 0;
}