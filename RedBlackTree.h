#include <iostream>
#define COUNT 5
struct Node{
public:
    int data;
    Node *parent;
    Node *left;
    Node *right;
    char color;
};

Node* getUncle(Node* node){
    if(node->parent->parent->left==node->parent) {
        return node->parent->parent->right;
    }else{
        return node->parent->parent->left;
    }
}
class RedBlackTree {
private:
    Node *root;
    Node *NullNode;

    void printTreeUtil(Node *root, int space){
        if (root == NullNode)
            return;

        space += COUNT;
        printTreeUtil(root->right, space);
        std::cout<<std::endl;
        for (int i = COUNT; i < space; i++)
            std::cout<<" ";
        std::cout<<root->data<< root->color<<"\n";
        printTreeUtil(root->left, space);
    }

    void insertFixOrder(Node *node){
        if(node->parent == NullNode){
            node->color= 'b';
        } else
            case2(node);
        std::cout<<std::endl;
    }
    void case2(Node* node){
        if(node->parent->color=='b'){
            return;
        }
        else
            case3(node);
    }
    void case3(Node* node){
        if((getUncle(node)!=NullNode) && (getUncle(node)->color=='r')){
            node->parent->color='b';
            getUncle(node)->color='b';
            node->parent->parent->color='r';
            insertFixOrder(node->parent->parent);
        }else{
            case4(node);
        }
    }
    void case4(Node* node){
        if ((node == node->parent->right)&& (node->parent==node->parent->parent->left)){
            leftRotate(node->parent);
            node = node->left;
        }else if((node == node->parent->left) && (node->parent== node->parent->parent->right)){
            rightRotate(node->parent);
            node = node->right;
        }
        case5(node);
    }
    void case5(Node* node){
        node->parent->color='b';
        node->parent->parent->color='r';
        if((node== node->parent->left) && (node->parent == node->parent->parent->left)){
            rightRotate(node->parent->parent);
        } else{
            leftRotate(node->parent->parent);
        }
    }

public:
    RedBlackTree(){
        NullNode = new Node;
        NullNode->color = 'b';
        NullNode->left = nullptr;
        NullNode->right = nullptr;
        root = NullNode;
    }
    void leftRotate(Node *x){
        Node* y = x->right;
        x->right = y->left;
        if (y->left != NullNode) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NullNode) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }
    void rightRotate(Node *x){
        Node* y = x->left;
        x->left = y->right;
        if (y->right != NullNode) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NullNode) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }
    void insertNode(int key){
        Node* node = new Node;
        node->parent = NullNode;
        node->data = key;
        node->left=NullNode;
        node->right=NullNode;
        node->color = 'r';
        Node* y = NullNode;
        Node* x = this->root;
        while (x!=NullNode){
            y=x;
            if(node->data<x->data){
                x=x->left;
            }
            else{
                x = x->right;
            }
        }
        node->parent = y;
        if( y == NullNode){
            this->root=node;
        } else if (node->data < y->data){
            y->left = node;
        }else{
            y->right = node;
        }
        if (node->parent == NullNode) {
            node->color = 'b';
            return;
        }
        if(node->parent->parent == NullNode){
            return;
        }
        insertFixOrder(node);
    }




    void printTree(Node *root){
        printTreeUtil(root, 0);
    }
    Node* getRoot(){
        return this->root;
    }



};