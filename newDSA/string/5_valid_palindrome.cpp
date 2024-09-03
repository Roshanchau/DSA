#include <iostream>
using namespace std;

bool valid_char(char ch){
    if((ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z')||(ch>='0'&& ch<='9') ){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char str[10]={'a' , 'e' , '\0' , 's', 'd', '\0'};
    cout<<"hehe this is char array "<<str;

    // string s="heheh\0jdkfjdk\0";
    // cout<<"this is string "<<s;
    return 0;
} 