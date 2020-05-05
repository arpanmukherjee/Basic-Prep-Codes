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

void inorderRecursive(Node* root)
{
    if(root == NULL)
        return;

    inorderRecursive(root->left);
    cout << root->data << endl;
    inorderRecursive(root->right);
}


int main()
{

    return 0;
}