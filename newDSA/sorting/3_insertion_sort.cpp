 #include <iostream>
 using namespace std;

 void insertion_sort(int arr[] , int n){
    for( int i=1 ; i<n; i++){
        int k=arr[i];
        for( int j=i-1; j>=0 && k<arr[j]; j--){
            arr[j+1]=arr[j];
            arr[j]=k;
        }
    }
 }

 void print(int arr[] , int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    } 
    cout << endl;
}


 int main(){
    int arr[]={4, 1, 9, 5 , 7 , 20 , 10 , 15};
    print(arr , 8);
    insertion_sort(arr, 8);
    print(arr, 8);
    return 0;
 }