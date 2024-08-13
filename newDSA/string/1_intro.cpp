#include <iostream>
using namespace std;

int main(){

    // cin stops operation after it finds
    /*
        --> space
        --> tab
        ---> \0
    */

    char name[20];
    cout<<"Enter your name"<<endl;
    cin>>name;

    name[3]='\0';

    cout<<"your name is "<<name<<endl;
    cout<<"hehe"<<name[6]<<endl;

    for(int i=0; i<20; i++){
        cout<<i<<"->";
        cout<<name[i]<<endl;
    }

    return 0;
}