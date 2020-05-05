#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}


int main()
{

    return 0;
}