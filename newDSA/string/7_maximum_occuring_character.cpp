#include <iostream>
using namespace std;

char checkMaximumOccuringChar(string str){
    int arr[26]={};

    // find the count of the charcters
    for(int i=0; i<str.length(); i++){
        char ch=str[i];
        int number=0;
        number =ch-'a';
        arr[number]++;
    }

    // find the maximum occuring charcter
    int maxi=-1 , ans=0;
    for(int i=0; i<26; i++){
        if(maxi< arr[i]){
            ans=i;
            maxi=arr[i];
        }
    }

    return ans+'a';
}

int main(){
    string s;
    cin>>s;
    cout<<checkMaximumOccuringChar(s)<<endl;
    return 0;
}