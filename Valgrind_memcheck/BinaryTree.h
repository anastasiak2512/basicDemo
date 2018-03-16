//
// Created by AK on 25/10/2017.
//

#ifndef MEM_SAMPLE_BINARYTREE_H
#define MEM_SAMPLE_BINARYTREE_H


template<typename T>
struct BinaryTreeNode {
    T* Value;
    BinaryTreeNode<T>* Left;
    BinaryTreeNode<T>* Right;
};

template<typename T>
void insert(T* value, BinaryTreeNode<T>& node) {
    if(node.Value == nullptr) {
        node.Value = value;
    }
    else {
        if(value <= node.Value) {
            if(node.Left == nullptr) {
                node.Left = new BinaryTreeNode<T>();
            }
            insert(value, *node.Left);
        }
        else {
            if(node.Right == nullptr) {
                node.Right = new BinaryTreeNode<T>();
            }
            insert(value, *node.Right);
        }
    }
}



#endif //MEM_SAMPLE_BINARYTREE_H
