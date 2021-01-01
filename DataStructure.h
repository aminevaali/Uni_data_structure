//
// Created by amin on 08.11.20.
//

#ifndef DS_DATASTRUCTURE_H
#define DS_DATASTRUCTURE_H

#include "iostream"

using namespace std;

template<class T>
struct Node {
    T info;
    Node<T> *next;
};

template<class T>
class Stack {
private:
    Node<T> *top = NULL;
public:
    bool empty() {
        if (top == NULL)
            return true;
        return false;
    }

    void push(T x) {
        Node<T> *p = new Node<T>();
        p->info = x;
        p->next = top;
        top = p;
    }

    T pop() {
        if (empty()) {
            cout << "Stack is empty";
            exit(1);
        }
        Node<T> *p = top;
        top = top->next;
        p->next = NULL;
        T result = p->info;
        delete p;
        return result;
    }

    T stackTop(){
        if(empty()){
            cout << "Stack is empty";
            exit(1);
        }
        return top->info;
    }
};

/*
template <class T, int MAX>
class Stack{
    T items[MAX];
    int top = -1;

public:
    bool push(T x){
        if(top == MAX - 1){
            return false;
        }
        items[++top] = x;
        return true;
    }

    T pop(){
        if(top == -1){
            cout << "Stack is empty";
            exit(1);
        }

        return items[top--];
    }

    bool empty(){
        return top == -1;
    }

     T stackTop(){
        return items[top];
     }
};
 */

template<class T>
class Queue{
private:
    Node<T> *front, *rear;
public:
    Queue(){
        front = rear = NULL;
    }

    bool empty(){
        if(front == NULL)
            return true;
        return false;
    }

    void insert(T x){
        Node<T> *p = new Node<T>;
        p->info = x;
        p->next = NULL;
        if(rear == NULL){
            rear = front = p;
        }else{
            rear->next = p;
            rear = p;
        }
    }

    T remove(){
        if(empty()){
            cout << "Queue is empty";
            exit(1);
        }

        Node<T> *tmp = front;
        front = front->next;
        if(front == NULL)
            rear = NULL;

        tmp->next = NULL;
        T result = tmp->info;
        delete tmp;
        return result;
    }
};

/*
template<class T, int MAX>
class Queue {
private:
    int front, rear;
    T items[MAX + 1];

public:
    Queue() {
        front = rear = MAX;
    }

    bool empty() {
        return rear == front;
    }

    bool insert(T x) {
        int i = rear;
        if (i == MAX)
            i = 0;
        else
            i++;
        if (i == front)
            return false;
        rear = i;
        items[rear] = x;
        return true;
    }

    T remove() {
        if (empty()) {
            cout << "Queue is empty";
            exit(1);
        }
        if (front == MAX)
            front = 0;
        else
            front++;
        T x = items[front];
        return x;
    }

    int len() {
        if (rear >= front) {
            return rear - front;
        } else {
            return MAX + 1 - front + rear;
        }
    }
};
*/

template<class T, int MAX>
class PriorityQueue {
private:
    T items[MAX];
    int rear = -1;

public:
    bool empty() {
        if (rear == -1)
            return true;
        return false;
    }

    bool insert(T x) {
        if (rear == MAX - 1)
            return false;
        items[++rear] = x;
        return true;
    }

    T maxDelete() {
        if (empty()) {
            cout << "PriorityQueue is empty!" << endl;
            exit(1);
        }

        int imax = 0;
        for (int i = 0; i <= rear; i++) {
            if (items[i] > items[imax])
                imax = i;
        }
        T max = items[imax];
        items[imax] = items[rear--];
        return max;
    }

    T minDelete() {
        if (empty()) {
            cout << "PriorityQueue is empty!" << endl;
            exit(1);
        }

        int iMin = 0;
        for (int i = 0; i <= rear; i++) {
            if (items[i] < items[iMin])
                iMin = i;
        }
        T min = items[iMin];
        items[iMin] = items[rear--];
        return min;
    }

};

#endif //DS_DATASTRUCTURE_H
