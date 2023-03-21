#include <iostream>
#include <queue>
using namespace std;

void printQ(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

void reverse(queue<int>&q){
    if(q.empty()){
        return;
    }

    int ele = q.front();
    q.pop();
    reverse(q);
    q.push(ele);
}

int main(){
    queue<int>q;
    for(int i = 1; i <= 5; i++){
        q.push(i);
    }

    cout<<"Original Queue : ";
    printQ(q);
    cout<<endl;
    reverse(q);
    cout<<"Reversed Queue : ";
    printQ(q);
}
