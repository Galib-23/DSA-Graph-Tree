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
void convert_to_mirror(node *root){
    if(root){
        convert_to_mirror(root->left);
        convert_to_mirror(root->right);
        node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return;
}
void inorder(node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    node *root;
    root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    cout<<"Original Tree: ";
    inorder(root);
    cout<<endl;
    cout<<"Mirror Tree: ";
    convert_to_mirror(root);
    inorder(root);

}
/***
                     1
                   /   \
                  2     3
                 / \
                4   5
***/
