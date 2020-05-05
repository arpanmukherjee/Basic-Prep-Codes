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
    stack<Node*> st;

    while(root != NULL or !st.empty())
    {
        while(root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        cout << root->data << endl;
        root = root->right;
    }
}


int main()
{

    return 0;
}