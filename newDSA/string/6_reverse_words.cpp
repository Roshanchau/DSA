#include <iostream>
using namespace std;


int getLength(char st[]){
    int len=0 , i=0;

    while(st[i]!='\0'){
        len++;
        i++;
    }
    return len;
}

void reverse_string(char str[] ,int i ,int n){
    cout<<"i=>"<<i<<endl;
    cout<<"n=>"<<n<<endl;
    int k=i+n;
    while(i<k/2){
        swap(str[k-i-1] , str[i]);
        i++;
    }
}

void reverse_words(char str[] ){
    int n=getLength(str);
    int s=0;
    int e=0;
    int i=0;
    reverse_string(str, s , n);
        while(i<n){
        cout<<str[i];
        i++;
    }
    cout<<endl;
    while(e<n){
        while(str[e]!=' '  && str[e]!='\0'){
         e++;
         cout<<"this is e =>"<<e<<endl;
    }  
    cout<<"this is e after reaching a space"<<e<<endl;
    reverse_string(str , s , e);
        s=e+1;
        e+=1;
    }
}


void print(char str[]){
    int i=0;
    int n=getLength(str);
    while(i<n){
        cout<<str[i];
        i++;
    }
    cout<<endl;
}


int main(){
    char s[]="My name is joe";
    print(s);
    cout<<"after reversing "<<endl;
    reverse_words(s);
    print(s);
    return 0;
}