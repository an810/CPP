/*
    Cho một tập gồm các số nguyên a1,a2,...,an. Thực hiện trên tập số nguyên đã cho
    một dãy các thao tác gồm 2 loại sau:
    - insert x: thêm một phần tử x vào tập
    - delete-max: xóa khỏi tập và trả về giá trị của phần tử lớn nhất trong tập
    1 ≤ n ≤ 10^5    1 ≤ x ≤ 10^6    
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;

typedef struct Node {
    int val;
    Node* left;
    Node* right;
} Node;

Node* newNode(int v) {
    Node* node = new Node;
    node->val = v;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int v) {
    if (root == NULL) return newNode(v);
    if (v < root->val) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
}

Node* findMax(Node* root) {
    if (root == NULL) return NULL;
    if (root->right == NULL) return root;
    else return findMax(root->right);
}

Node* remove(Node* root, int v) {
    if (root == NULL) return root;
    if (v < root->val) root->left = remove(root->left, v);
    else if (v > root->val) root->right = remove(root->right, v);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMax(root->left);
        root->val = temp->val;
        root->left = remove(root->left, temp->val);
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = insert(root, x);
    }
    string cmd;
    while(1) {
        cin >> cmd;
        if (cmd == "*") break;
        else if (cmd == "insert") {
            int x; cin >> x;
            root = insert (root, x);
        }
        else if (cmd == "delete-max") {
            Node* maxNode = findMax(root);
            cout << maxNode->val << endl;
            root = remove(root, maxNode->val);
        }
    }
    
    return 0;
}