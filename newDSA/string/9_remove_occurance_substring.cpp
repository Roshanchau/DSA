#include <iostream>
using namespace std;

string removeOccSubStr(string str, string part){
    cout<<"hello"<<endl;
    int i=0;
    int flag=0;
    int partLen=part.length();
    cout<<"this is part lenght: "<<partLen<<endl;
    while(str[i]!='\0'){
        if(str[i+partLen-1]!=' '){
        for(int j=i; j<i+partLen; j++){
            if(str[j]==part[j-i]){
                cout<<"yo srting ho->"<<str[j]<<endl;
                flag=1;
            }else{
                flag=0;
                break;
            }
        }
        }
        cout<<"This is flag->"<<flag<<endl;
        cout<<"this is the index i->"<<i<<endl;
        if(flag==1){
            str.erase(i, partLen);
            cout<<str<<endl;
            i=i-(partLen-1);
            if(i<0){
                i=0;
            }
            cout<<"i lai ghatyepaxi hai=>"<<i<<endl;
        }else{
        i++;
        }
    }

    return str;
}

void print(string str){
    int i=0;
    int n=str.length();
    while(i<n){
        cout<<str[i];
        i++;
    }
    cout<<endl;
}

int main(){
    string s;
    cout<<"Enter the srting: "<<endl;
    cin>>s;
    string part;
    cout<<"enter the part: "<<endl;
    cin>>part;
    print(s);
    string res=removeOccSubStr(s , part);
    print(res);
    return 0;
}