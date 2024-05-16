#include <iostream>
using namespace std;

bool uniqueOccurance(int arr[] , int size)
{
    int countArr[size];
    int occur[size];
    int flag = 0;
    int count = 0;
    int check=0;
    for (int i = 0; i < size; i++)
    {
        cout<<endl;
        cout<<arr[i]<<endl;;
        for (int j = 0; j < size; j++)
        {
            cout<<endl;
        cout<<"occured->"<<occur[j];
            if (occur[j] == arr[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            count++;
            occur[i] = arr[i];
            for (int k = i + 1; k < size; k++)
            {
                if (arr[i] == arr[k])
                {
                    count++;
                }
            }
            cout<<endl;
            cout<<"this is count->"<<count<<endl;;
            countArr[i] = count;
        }
        count = 0;
        flag=0;
    }
    for(int i=0; i<size-1; i++){
        if(countArr[i]==countArr[i+1]){
            check=1;
        }
    }
    if(check==0){
    return true;
    }else{
        return false;
    }
}

int main()
{
    int arr[6]={1,2, 1 , 1,6 ,2};
    bool ans=uniqueOccurance(arr , 6);
    cout<<"hello->"<<ans<<endl;
}
