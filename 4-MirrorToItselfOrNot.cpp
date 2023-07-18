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
vector<int> v;
void inorder(node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    v.push_back(root->data);
    inorder(root->right);
}
void mirrorCheck(){
    int count = 0;
    for (int i = 0, j= v.size()/2+1; i < v.size()/2 , j<v.size(); i++,j++)
    {
        if(v[i]!=v[j]){
            count++;
        }
    }
    if(count==0){
        cout<<"MIRROR"<<endl;
    }
    else cout<<"NOT MIRROR"<<endl;
    
}
int main(){
    node *root;
    root = create(1);
    root->left = create(2);
    root->right = create(2);
    root->left->left = create(4);
    root->left->right = create(5);
    root->right->left = create(4);
    root->right->right = create(5);
    inorder(root);
    mirrorCheck();
    
}
/***
                     1
                   /   \
                  2     2
                 / \    / \
                4   5  4   5
***/
