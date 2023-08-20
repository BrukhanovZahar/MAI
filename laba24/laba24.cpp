#include <bits/stdc++.h>


using namespace std;

// структура узла дерева
struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// функция, которая строит дерево возведения в степень
Node *buildTree(int base, int exponent) {
    if (exponent == 0) {
        return new Node(1);
    }
    if (exponent == 1) {
        return new Node(base);
    }
    Node *node = new Node(base);
    node->left = buildTree(base * base, exponent / 2);
    node->right = buildTree(base, exponent % 2);
    return node;
}

// функция, которая вычисляет результат возведения числа в степень
int power(int base, int exponent) {
    Node *root = buildTree(base, exponent);
    int res = 1;
    while (root != nullptr) {
        if (exponent % 2 == 1) {
            res *= root->val;
        }
        root = exponent / 2 > 0 ? root->left : nullptr;
        exponent /= 2;
    }
    return res;
}

// функция для вывода дерева в консоль
void printTree(Node *node) {
    if (node == nullptr) {
        return;
    }

    // вычисляем количество уровней в дереве
    queue<Node *> q;
    q.push(node);
    int levels = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node *n = q.front();
            q.pop();
            if (n->left != nullptr) {
                q.push(n->left);
            }
            if (n->right != nullptr) {
                q.push(n->right);
            }
        }
        levels++;
    }

    // выводим дерево
    int level = 0;
    queue<Node *> q2;
    q2.push(node);
    while (!q2.empty()) {
        int size = q2.size();
        for (int i = 0; i < size; i++) {
            Node *n = q2.front();
            q2.pop();
            int spaces = (1 << (levels - level - 1)) - 1;
            cout << string(spaces, ' ');
            if (n != nullptr) {
                cout << n->val;
                q2.push(n->left);
                q2.push(n->right);
            } else {
                cout << " ";
                q2.push(nullptr);
                q2.push(nullptr);
            }
            cout << string(spaces, ' ');
            if (i != size - 1) {
                cout << string((1 << (levels - level)) - 1, ' ');
            }
        }
        level++;
        cout << endl;
        if (level == levels) {
            break;

        }
    }
}

int main() {
    int base, exponent;
    cout << "Введите основание и показатель степени: ";
    cin >> base >> exponent;
    int res = power(base, exponent);

    cout << "Результат: " << res << endl;
    cout << "Дерево: " << endl;
    Node *root = buildTree(base, exponent);
    printTree(root);

    return 0;
}
