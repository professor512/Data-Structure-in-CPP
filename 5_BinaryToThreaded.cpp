// B9- Convert given binary tree into threaded binary tree. Analyze time and space complexity 
// of the algorithm.

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    int data;
    node* left, * right;
    int lbit, rbit;
};

class TBT {
    node* temp = NULL, * t1 = NULL, * s = NULL, * head = NULL, * t = NULL;

public:
    node* create();
    void insert();
    node* inorderPredecessor(node*);
    node* inorderSuccessor(node*);
    void display();
    void thread(node*);
    void inorderDisplay(node*);
    void threadedTraversal();
};

node* TBT::create() {
    node* p = new node;
    p->left = NULL;
    p->right = NULL;
    p->lbit = 0;
    p->rbit = 0;
    cout << "\nEnter the data: ";
    cin >> p->data;
    return p;
}

void TBT::insert() {
    temp = create();
    if (head == NULL) {
        node* p = new node;
        head = p;
        head->left = temp;
        head->right = head;
        head->lbit = 1;
        head->rbit = 0;
        temp->left = head;
        temp->right = head;
        temp->lbit = 0;
        temp->rbit = 0;
        cout << "Root node added!" << endl;
    }
    else {
        t1 = head;
        t1 = t1->left;
        while (t1 != NULL) {
            s = t1;
            if ((temp->data > t1->data) && t1->rbit == 1)
                t1 = t1->right;
            else if ((temp->data < t1->data) && t1->lbit == 1)
                t1 = t1->left;
            else
                break;
        }
        if (temp->data > s->data) {
            s->right = temp;
            s->rbit = 1;
            temp->left = inorderPredecessor(head->left);
            temp->right = inorderSuccessor(head->left);
        }
        else {
            s->left = temp;
            s->lbit = 1;
            temp->left = inorderPredecessor(head->left);
            temp->right = inorderSuccessor(head->left);
        }
    }
}

node* TBT::inorderPredecessor(node* m) {
    if (m->lbit == 1) {
        inorderPredecessor(m->left);
    }
    if (m->data == temp->data && t == NULL)
        return head;
    if (m->data == temp->data)
        return t;
    t = m;
    if (m->rbit == 1) {
        inorderPredecessor(m->right);
    }
}

node* TBT::inorderSuccessor(node* m) {
    if (m->lbit == 1) {
        t = m;
        inorderSuccessor(m->left);
    }
    if (m->data == temp->data && t == NULL)
        return head;
    if (m->data == temp->data)
        return t;
    if (m->rbit == 1) {
        inorderSuccessor(m->right);
    }
}

void TBT::display() {
    inorderDisplay(head->left);
}

void TBT::inorderDisplay(node* m) {
    if (m->lbit == 1) {
        inorderDisplay(m->left);
    }
    cout << "\n" << m->data;
    if (m->rbit == 1) {
        inorderDisplay(m->right);
    }
}

void TBT::thread(node* m) {
    if (m->lbit == 1) {
        thread(m->left);
    }
    if (m->lbit == 0 || m->rbit == 0) {
        cout << "\n" << m->data;
    }
    if (m->rbit == 1) {
        thread(m->right);
    }
}

void TBT::threadedTraversal() {
    cout << "\nThreads are: ";
    thread(head->left);
}

int main() {
    TBT t;
    int ch;
    while (1) {
        cout << "\nEnter the choice: ";
        cout << "\n1. Insert data";
        cout << "\n2. Display all data";
        cout << "\n3. Display threaded nodes";
        cout << "\n4. Exit";
        cin >> ch;
        switch (ch) {
            case 1:
                t.insert();
                break;
            case 2:
                t.display();
                break;
            case 3:
                t.threadedTraversal();
                break;
            case 4:
                exit(0);
            default:
                cout << "\nInvalid entry!";
        }
    }
    return 0;
}
