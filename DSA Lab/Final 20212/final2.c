#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
typedef struct Node
{
    char account[MAX];
    struct Node* left;
    struct Node* right;
}Node;

Node* root = NULL;

Node *makeNode(char account[])
{
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->account, account);
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node* find(Node* r, char account[])
{
    if (r==NULL) return NULL;
    int c = strcmp(r->account, account);
    if (c==0) return r;
    else if (c<0) return find(r->right, account);
    else return find(r->left, account);
}

Node* insert(Node* root, char account[])
{
    if (root == NULL)
    {
        return makeNode(account);
    }
    if (strcmp(account, root->account) > 0)
    {
        root->right = insert(root->right, account);
    }
    else
    {
        root->left = insert(root->left, account);
    }
    return root;
}

void inorder(Node* root)
{
    if (root == NULL) return;
    inorder(root->left);
    printf("%s ", root->account);
    inorder(root->right);
}

int main()
{
    char cmd[MAX];
    char from_acc[MAX];
    char to_acc[MAX];
    int money;
    char time[MAX];
    char atm[MAX];
    while(1)
    {
        scanf("%s", from_acc);
        if (strcmp(from_acc,"#") == 0) break;
        else {
            scanf("%s %d %s %s", to_acc,&money, time, atm);
            Node* p = find(root, from_acc);
            Node* q = find(root, to_acc);
            if (p == NULL) root = insert(root, from_acc);
            if (q == NULL) root = insert(root, to_acc);
        }
    }
    while(1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "#")==0) break;
        if(strcmp(cmd, "?list_sorted_accounts")==0)
        {
            inorder(root);
        } 
    }
    return 0;
}