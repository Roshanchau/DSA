#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// runtime error :(
// vector<int> findDuplicates(vector<int> &nums)
// {
//     int ans = 0;
//     sort(nums.begin(), nums.end());
//     vector<int> index;
//     vector<int>res;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         ans = ans ^ nums[i] ^ nums[i + 1];
//         if (ans == 0)
//         {
//             ;
//             index.push_back(i);
//         }
//         ans = 0;
//     }
//     for(int i=0; i<index.size(); i++){
//         res.push_back(nums[index[i]]);
//     }
//     return res;
// }
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
        {
            ans.push_back(abs(nums[i]));
        }
        else
        {
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
    }
    return ans;
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
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    print(nums);
    vector<int> ans = findDuplicates(nums);
    print(ans);
    return 0;
}