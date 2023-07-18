#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *create(int data){
    node *newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
}
vector<int> v1;
vector<int> v2;
void inorder1(node *root){
    if(root == NULL){
        return;
    }
    inorder1(root->left);
    v1.push_back(root->data);
    inorder1(root->right);
}
void inorder2(node *root){
    if(root == NULL){
        return;
    }
    inorder2(root->left);
    v2.push_back(root->data);
    inorder2(root->right);
}
void identicalCheck(){
    int count =0;
    if(v1.size()==v2.size()){
        for (int i = 0; i < v1.size(); i++)
        {
            if(v1[i]!=v2[i]){
                count++;
            }
        }
        if(count == 0) cout<<"IDENTICAL"<<endl;
        else cout<<"NOT IDENTICAL"<<endl;
    }
    else{
        cout<<"NOT IDENTICAL"<<endl;
    }
}
int main(){
    node *root1;
    root1 = create(1);
    root1->left = create(2);
    root1->right = create(3);
    root1->left->left = create(4);
    root1->left->right = create(5);
    root1->left->right->left = create(6);
    inorder1(root1);
    node *root2;
    root2 = create(1);
    root2->left = create(2);
    root2->right = create(3);
    root2->left->left = create(4);
    root2->left->right = create(5);
    root2->left->right->left = create(6);
    inorder2(root2);
    identicalCheck();
    
}