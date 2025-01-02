#include<iostream>
#include<queue>

using namespace std;

void showq(queue <int> gq){
    queue<int> q=gq;

    while(!q.empty()){
        cout<< '\t'<<q.front();
        q.pop();
    }
    cout<<endl;
}


int main(){
    queue<int> gqu;
    gqu.push(10);
    gqu.push(20);
    gqu.push(30);
     
     cout << "The queue gquiz is : ";
    showq(gqu);

    cout << "\ngquiz.size() : " << gqu.size();
    cout << "\ngquiz.front() : " << gqu.front();
    cout << "\ngquiz.back() : " << gqu.back();

    cout << "\ngquiz.pop() : ";
   gqu.pop();
    showq(gqu);
    
    return 0;
}