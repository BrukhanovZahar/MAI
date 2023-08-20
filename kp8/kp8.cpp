#include <bits/stdc++.h>

using namespace std;

struct Node {
    pair<int, int> data;
    Node *next;
};

pair<int, int> bar = make_pair(-1, -1);


Node *NewNode(int d) {
    int n = d;
    Node *phead = nullptr;
    if (n > 0) {
        phead = new Node;
        Node *pNode = phead;
        phead->data.first = 1;
        phead->data.second = 1;
        for (int i = 1; i < n; i++) {
            pNode->next = new Node;
            pNode = pNode->next;
            pNode->data.first = i + 1;
            pNode->data.second = i + 1;
            pNode->next = new Node;
            pNode->next->data = bar;
        }
    }
    return phead;
}


void PrintNode(Node *pNode) {
    cout << pNode->data.first << " + " << pNode->data.second << "i" << " -> ";
}

void PrintList(Node *phead) {
    Node *zNode = phead;
    while ((zNode->next->data) != bar) {
        PrintNode(zNode);
        zNode = zNode->next;
    }
    cout << zNode->data.first << " + " << zNode->data.second << "i" << endl;
}

//добавить элемент после индекса d
void AddNewNode(int d, pair<int, int> elem, Node *phead) {
    Node *pNode = phead;
    for (int i = 0; i < d; i++) {
        pNode = pNode->next;
    }
    Node *zNode = new Node;
    zNode->data = elem;
    zNode->next = pNode->next;
    pNode->next = zNode;
}

//удалить Node с d индексом
void DeleteNode(int d, Node *phead) {
    Node *pNode = phead;
    Node *prew = pNode;
    for (int i = 0; i < d; i++) {
        prew = pNode;
        pNode = pNode->next;
    }
    prew->next = pNode->next;
    delete pNode;
}

int getSize(Node *phead) {
    Node *pNode = phead;
    int n = 0;
    while (pNode->next->data != bar) {
        pNode = pNode->next;
        n++;
    }
    n++;
    return n;
}

void speshialFunc(int k, Node *phead) {
    Node *pNode = phead;
    Node *prew = pNode;
    int d = 1;
    while (pNode->next->data != bar) {
        if (d % k == 0) {
            prew->next = pNode->next;
        }
        prew = pNode;
        pNode = pNode->next;
        d++;
    }
    if (d % k == 0) {
        prew->next = pNode->next;
    }
}

int main() {
    int n;
    cin >> n;

    Node *phead = NewNode(n);
    PrintList(phead);
    cout << endl;

    pair<int, int> x;
    x.first = 111;
    x.second = 111;
    AddNewNode(3, x, phead);
    PrintList(phead);
    cout << endl;

    DeleteNode(3, phead);
    PrintList(phead);
    cout << endl;

    cout << getSize(phead) << endl;

    speshialFunc(2, phead);
    PrintList(phead);
}
