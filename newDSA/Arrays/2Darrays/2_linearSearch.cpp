#include <iostream>
using namespace std;

bool isPresent(int arr[][4] ,int  key ,int  m ,int  n ){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==key){
                return true;
            }
        }
    }
    return false;
}

int main()
{

    int arr[3][4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    int target;

    cout<<"Enter the target"<<endl;
    cin>>target;

    if(isPresent(arr, target,  3, 4)){
        cout<<"present"<<endl;
    }else{
        cout<<"not present"<<endl;
    }

    return 0;
}