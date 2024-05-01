#include <iostream>
using namespace std;

// void S_alt(int arr[] , int n){
//     int start=0;
//     int next=1;
//     while(next<=n-1){
//         swap(arr[start], arr[next]);
//         start+=2;
//         next+=2;
//     }
// }
void S_alt(int arr[] , int n){
    for(int i=0; i<n; i+=2){
        if(i+1<n){
            swap(arr[i] ,arr[i+1]);
        }
    }
}

void print(int arr[] , int n){
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"";
    }
    cout<<endl;
}

int main(){ 
    int arr[6]={1,2,7,8,5,0};

    S_alt(arr,6);
    print(arr,6);

    return 0;
}