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

int main(){
    char name[20];

    cin>>name;
    cout<<"The length of the string is: "<<getLength(name);
    return 0;
}