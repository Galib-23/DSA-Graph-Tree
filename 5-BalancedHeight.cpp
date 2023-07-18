#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
};
node * create(int data){
    node *newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int getHeight(node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(node* root) {
    if (root == nullptr) {
        return true;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    int heightDiff = abs(leftHeight - rightHeight);
    if (heightDiff > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}
int main(){
    node *root;
    root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    root->left->right->left = create(6);
    if(isBalanced(root)) cout<<"HEIGHT IS BALANCED"<<endl;
    else cout<<"NOT BALANCED"<<endl;
}
/***
                     1
                   /   \
                  2     3
                 / \
                4   5
                   /
                  6
***/
