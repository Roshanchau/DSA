#include <iostream>
#include <vector>
using namespace std;



int getLength(char name[]){
    int len=0 , i=0;

    while(name[i]!='\0'){
        len++;
        i++;
    }
    return len;
}

bool palindrome(char s[]){
    int n=getLength(s);
    int i=0;
    bool flag;
    while(i<n/2){
        if(s[n-i-1]==s[i]){
            cout<<i<<endl;
            flag=true;
        }else{
            flag=false;
        }
        i++;
    }
    return flag;
}

int main(){
    char s[20];
    cout<<"enter your string"<<endl;
    cin>>s;
    bool haha=palindrome(s);
    if(haha){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}