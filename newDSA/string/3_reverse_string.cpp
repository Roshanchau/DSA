#include <iostream>
using namespace std;

int getLength(char name[]){
    int len=0 , i=0;

    while(name[i]!='\0'){
        len++;
        i++;
    }
    return len;
}

void reverse_string(char str[]){
    cout<<"hello";
    int i=0;
    int n=getLength(str);
    cout<<"this is length"<<n;
    while(i<n/2){
        cout<<"this is inside rev loop->"<<i<<"->"<<str[i]<<endl;
        swap(str[n-i-1] , str[i]);
        i++;
    }
}

void print(char str[]){
    int i=0;
    int n=getLength(str);
    while(str[i]!='\0'){
        cout<<str[i];
        i++;
    }
    cout<<endl;
}

int main(){
    char str[20];

    cout<<"Enter your string"<<endl;
    cin>>str;
    cout<<"before rev"<<endl;
    print(str);
    reverse_string(str);
    cout<<"after reverse"<<endl;
    print(str);
    return 0;
}