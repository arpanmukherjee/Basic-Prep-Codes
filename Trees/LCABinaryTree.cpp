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

Node* LowestCommonAncestor(Node* root ,int n1 ,int n2 )
{
    if(root == NULL)
        return root;
    if(root->data == n1 or root->data == n2)
        return root;
    Node* left = LowestCommonAncestor(root->left, n1, n2);
    Node* right = LowestCommonAncestor(root->right, n1, n2);
    if(left != NULL and right != NULL)
        return root;
    if(left != NULL)
        return left;
    if(right != NULL)
        return right;
    return NULL;
}


int main()
{

    return 0;
}