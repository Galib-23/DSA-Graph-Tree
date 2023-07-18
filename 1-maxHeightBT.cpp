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
int max_height(node*root){
    if(root==NULL){
        return 0;
    }
    int left_height = max_height(root->left);
    int right_height = max_height(root->right);
    return 1+max(left_height,right_height);
}
int main(){
    node *root;
    root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    root->left->right->left = create(6);
    int height = max_height(root);
    cout<<"Height of the Binary Tree is: "<<height<<endl;
}