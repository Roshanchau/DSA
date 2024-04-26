#include <iostream>
using namespace std;

bool search(int arr[], int size, int key)
{
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[10] = {4, 3, 4, 5, -2, 3, 5, 2, 1, 0};

    cout << "Enter the key to search" << endl;
    int key;
    cin >> key;

    bool found = search(arr, 10, key);
    if (found)
    {
        cout << "key is present" << endl;
    }
    else
    {
        cout << "key not present" << endl;
    }

    return 0;
}