// https://www.codingninjas.com/codestudio/problems/deque_1170059?leftPanelTab=1

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> q;
    q.push_front(11);
    q.push_back(10);
    cout << q.front() << endl;
    cout << q.back() << endl;

    q.pop_back();
    cout << q.front() << endl;
    cout << q.back() << endl;

    q.pop_front();
    if (q.empty())
    { 
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
}
