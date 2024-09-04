#include <iostream>
using namespace std;

bool valid_char(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char lowercase(char ch)
{
    if((ch>='a' && ch<='z')|| (ch>='0' && ch<='9')){
        return ch;
    }else{
        char temp= ch-'A'+'a';
        return temp;
    }
}

void print (string s){
    for(int i=0; i<s.length(); i++){
        cout<<s[i];
    }
}

bool palindrome(string str)
{
    int n=str.length();
    int s = 0;
    string temp;
    for(int i=0; i<n; i++){
        if(valid_char(str[i])){
            temp.push_back(str[i]);
        }
    }

    for(int j=0; j<n; j++){
        temp[j]=lowercase(str[j]);
    }

    print(temp);


    int e=temp.length()-1;
    while(s<=e){
        if(temp[s]!=temp[e]){
            return 0;

        }else{
            s++;
            e--;
        }
    }
    return 1;
}

int main()
{
    string s;
    cout<<"Enter your string"<<endl;
    cin>>s;

    bool flag=palindrome(s);
    if(flag){
        cout<<"The given string is palindrome"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}