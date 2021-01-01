#include <iostream>
#include "DataStructure.h"
#include "LinkedListOperations.h"

using namespace std;

int main() {
    Stack<int> s;
    s.push(51);
    s.push(40);
    s.push(27);
    s.push(25);
    s.push(19);

    while(!s.empty()){
        cout << s.pop() << endl;
    }

    return 0;


    PriorityQueue<int, 10> pq;
    pq.insert(5);
    pq.insert(6);
    pq.insert(4);

//    cout << pq.items[0] << endl;
//    cout << pq.items[1] << endl;
//    cout << pq.items[2] << endl;


    cout << pq.maxDelete() << endl;
    cout << pq.maxDelete() << endl;
    cout << pq.maxDelete() << endl;
    if(pq.empty()){
        cout << "pq is empty" << endl;
    }

    for(int i = 1; i <= 10; i++){
        if(!pq.insert(20 - i * 2)){
            cout << "cannot insertWithOrder " << endl;
        }
    }

    while(!pq.empty()){
        cout << pq.minDelete() << endl;
    }

    return 0;

    Queue<int, 10> q;
    q.insert(50);
    q.insert(40);

    cout << q.len() << endl;

    q.insert(26);
    q.insert(24);
    q.insert(19);

    cout << q.len() << endl;

    cout << q.remove() << endl;
    cout << q.remove() << endl;

    cout << q.len() << endl;

    cout << q.remove() << endl;
    cout << q.remove() << endl;

    cout << q.len() << endl;

    cout << q.remove() << endl;

    cout << q.len() << endl;

    return 0;
}