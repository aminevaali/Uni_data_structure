//
// Created by amin on 31.12.20.
//

#ifndef DS_LINKEDLISTOPERATIONS_H
#define DS_LINKEDLISTOPERATIONS_H

#include <iostream>

using namespace std;

template<class T>
struct Node {
    T info;
    Node<T> *next;
};

template<class T>
void writeList(Node<T> *p) {
    Node<T> *q = p;
    while (q != NULL) {
        cout << q->info << endl;
        q = q->next;
    }
}

template<class T>
bool remove(Node<T> *&p, int n) {
    Node<T> *q = p, *r = NULL;
    int i = 0;
    while (q != NULL && i < n) {
        i++;
        r = q;
        q = q->next;
    }

    if (q == NULL)
        return false;

    if (r == NULL) {
        p = q->next;
        q->next = NULL;
        delete q;
    } else {
        r->next = q->next;
        q->next = NULL;
        delete q;
    }

    return true;
}

template<class T>
void removeMax(Node<T> *&p) {
    Node<T> *q = p, *r = NULL;
    Node<T> *maxptr = NULL;
    T max = q->info;

    while (q != NULL) {
        if (q->info > max) {
            max = q->info;
            maxptr = r;
        }
        r = q;
        q = q->next;
    }

    if (maxptr == NULL) {
        q = p;
        p = p->next;
        q->next = NULL;
        delete q;
    } else {
        Node<T> *t = maxptr->next;
        maxptr->next = t->next;
        t->next = NULL;
        delete t;
    }
}

template<class T>
void insertAtFirst(Node<T> *&p, T x) {
    Node<T> *s = new Node<T>();
    s->info = x;
    s->next = p;
    p = s;
}

template<class T>
void insertAtLast(Node<T> *&p, T x) {
    Node<T> *q = p;
    Node<T> *r = NULL;
    while (q != NULL) {
        r = q;
        q = q->next;
    }

    Node<T> *s = new Node<T>();
    s->info = x;
    s->next = NULL;
    r->next = s;
}

template<class T>
void insertInMiddle(Node<T> *p, T x) {
    Node<T> *q = p;
    int i = 0;
    while (q != NULL) {
        i++;
        q = q->next;
    }

    q = p;
    int j = 0;
    while (j < i / 2 - 1) {
        j++;
        q = q->next;
    }

    Node<T> *s = new Node<T>();
    s->info = x;
    s->next = q->next;
    q->next = s;
}

template<class T>
T getSumOfList(Node<T> *p) {
    Node<T> *q = p;
    T sum = 0;
    while (q != NULL) {
        sum += q->info;
        q = q->next;
    }

    return sum;
}

template<class T>
double getAverageOfList(Node<T> *p){
    Node<T> *q = p;
    int i = 0;
    T sum = 0;
    while(q != NULL){
        sum += q->info;
        i++;
        q = q->next;
    }

    return ((double)sum) / i;
}

void testLinkedList() {
    Node<int> *n1 = new Node<int>();
    n1->info = 50;
    n1->next = NULL;

    insertAtLast(n1,40);
    insertAtLast(n1, 27);
    insertAtLast(n1, 25);
    insertAtLast(n1, 19);

    writeList(n1);

    cout << "--------------------" << endl;
    cout << "average of list = " << getAverageOfList(n1);
}

#endif //DS_LINKEDLISTOPERATIONS_H
