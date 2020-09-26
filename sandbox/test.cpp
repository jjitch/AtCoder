#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << 111 << endl;
    priority_queue<int> pq;
    pq.push(10);
    pq.push(3);
    pq.push(6);
    pq.push(1);
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    set<int> S;
    S.insert(10);
    S.insert(6);
    S.insert(10);
    cout << S.size() << endl;
    
    return 0;
}