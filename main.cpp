#include <iostream>

using namespace std;

struct Node{
    int data;
    int count;
    int height;
    Node* left = NULL;
    Node* right = NULL;
};

int Height(Node* X){
    if(X==NULL){
        return 0;
    }
    return X->height;
}

Node* SingleLeftRotate(Node* X){
    Node* Y = X->left;
    X->left = Y->right;
    Y->right = X;
    X->height = max(Height(X->left), Height(X->right))+1;
    Y->height = max(Height(Y->left), X->height)+1;
    return Y;
}

Node* SingleRightRotate(Node* X){
    Node* Y = X->right;
    X->right = Y->left;
    Y->left = X;
    X->height = max(Height(X->left), Height(X->right))+1;
    Y->height = max(X->height, Height(Y->right))+1;
    return Y;
}

Node* DoubleRotateLeft(Node* Z){
    Z->left = SingleRightRotate(Z->left);
    return SingleLeftRotate(Z);
}

Node* DoubleRotateRight(Node* Z){
    Z->right = SingleLeftRotate(Z->right);
    return SingleRightRotate(Z);
}

Node* insert(Node* root, int data){
    if(root==NULL){
        root = new Node{data, 1, 0, NULL, NULL};
    }
    else if(data<root->data){
        root->left = insert(root->left, data);
        if(Height(root->left)-Height(root->right)==2){
            if(data<root->left->data){
                root = SingleLeftRotate(root);
            }
            else{
                root = DoubleRotateLeft(root);
            }
        }
    }
    else if(data>root->data){
        root->right = insert(root->right, data);
        if(Height(root->right)-Height(root->left)==2){
            if(data>root->right->data){
                root = SingleRightRotate(root);
            }
            else{
                root = DoubleRotateRight(root);
            }
        }
    }
    else{
        root->count++;
        return root;
    }
    root->height = max(Height(root->left), Height(root->right))+1;
    return root;
}

void deletion(Node* root, int data) {
    if(root!=NULL){
        if(data<root->data) {
            deletion(root->left, data);
        }
        else if(data>root->data) {
            deletion(root->right, data);
        }
        else {
            root->count--;
        }
    }
}

void reset(Node* root){
    if(root!=NULL){
        root->count = 0;
        reset(root->left);
        reset(root->right);
    }
}


int main() {



    return 0;
}