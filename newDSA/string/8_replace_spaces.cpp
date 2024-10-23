#include <iostream>
using namespace std;

// string replaceSpaces(string str){
//     string result="";
//     for(int i=0; i<str.length(); i++){
//         if(str[i]==' '){
//             result.push_back('@');
//             result.push_back('4');
//             result.push_back('0');
//         }else{
//             result.push_back(str[i]);
//         }
//     }
//     return result;
// }
string replaceSpaces(string str){
    for(int i=0; i<str.length(); i++){
        if(str[i]==' '){
            str.replace(i, 1, "@40");
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
    string str;
    cout << "Enter your string: ";
    getline(cin, str); //cin can only input strings without spaces and line breaks so we use getline.
    print(str);
    string res=replaceSpaces(str);
    cout<<"After replacing spaces: "<<endl;
    print(res);
    return 0;
}