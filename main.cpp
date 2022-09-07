#include <iostream>
#include "RedBlackTree.h"
int main(){
    RedBlackTree tree;
    tree.insertNode(12);

    tree.printTree(tree.getRoot());
    tree.insertNode(6);

    tree.printTree(tree.getRoot());
    tree.insertNode(18);

    tree.printTree(tree.getRoot());
    tree.insertNode(3);

    tree.printTree(tree.getRoot());
    tree.insertNode(7);

    tree.printTree(tree.getRoot());
    tree.insertNode(9);

    tree.printTree(tree.getRoot());
    tree.insertNode(2);

    tree.printTree(tree.getRoot());
    tree.insertNode(1);

    tree.printTree(tree.getRoot());
    tree.insertNode(5);

    tree.printTree(tree.getRoot());
    RedBlackTree rbt1;
    for(int i=1; i<10;i++){
        rbt1.insertNode(i);
        rbt1.printTree(rbt1.getRoot());
    }
    return 0;
}