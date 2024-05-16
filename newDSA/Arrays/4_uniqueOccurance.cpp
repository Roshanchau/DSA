#include <iostream>
#include <algorithm> // Include the <algorithm> header for the sort function
#include <vector>
using namespace std;

// ******brute force*****

// bool uniqueOccurance(vector<int>& arr)
// {
//     int size=arr.size();
//     int countArr[size];
//     int occur[size];
//     int flag = 0;
//     int count = 0;
//     int check=0;
//     for (int i = 0; i < size; i++)
//     {
//         cout<<endl;
//         cout<<arr[i]<<endl;;
//         for (int j = 0; j < size; j++)
//         {
//             cout<<endl;
//         cout<<"occured->"<<occur[j];
//             if (occur[j] == arr[i])
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag != 1)
//         {
//             count++;
//             occur[i] = arr[i];
//             for (int k = i + 1; k < size; k++)
//             {
//                 if (arr[i] == arr[k])
//                 {
//                     count++;
//                 }
//             }
//             cout<<endl;
//             cout<<"this is count->"<<count<<endl;;
//             countArr[i] = count;
//         }
//         count = 0;
//         flag=0;
//     }
//     for(int i=0; i<size-1; i++){
//         if(countArr[i]==countArr[i+1]){
//             check=1;
//         }
//     }
//     if(check==0){
//     return true;
//     }else{
//         return false;
//     }
// }

// optimized solution.
bool uniqueOccurance(vector<int>& arr) {
        vector<int> ans;

        int size=arr.size();
        sort(arr.begin() ,arr.end());
        int i=0;
        while(i<size){
            int count=1;
            for(int j=i+1; j<size; j++){
                if(arr[i]==arr[j]){
                    count++;
                }else{
                    break;
                }
            }
            ans.push_back(count);
            i=i+count;
        }
        size=ans.size();
        sort(ans.begin() , ans.end());
        for(int i=0; i<size-1; i++){
            if(ans[i]==ans[i+1]){
                return false;
            }
        }
        return true;    
    }

int main()
{
    vector<int> arr = {1, 2, 1, 1, 2, 2};
    bool ans = uniqueOccurance(arr);
    cout << "hello->" << ans << endl;
}
