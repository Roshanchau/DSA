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


void print(string str){
    cout<<"trying to print res"<<endl;
    int i=0;
    int n=str.length();
    cout<<"this is length"<<n<<endl;
    while(i<n){
        cout<<str[i];
        i++;
    }
    cout<<endl;
}


int main(){
    string s="My name is joe";
    return 0;
}