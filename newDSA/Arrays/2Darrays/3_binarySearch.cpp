#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int key)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = row * col - 1;

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int element = matrix[mid / col][mid % col];
        if (element == key)
        {
            return true;
        }
        if (element < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}

int main()
{
    int rows = 3;
    int cols = 4;
    vector<vector<int>> arr(rows, vector<int>(cols));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    int target;
    cout << "Enter the target" << endl;
    cin >> target;

    if (searchMatrix(arr, target))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }

    return 0;
}