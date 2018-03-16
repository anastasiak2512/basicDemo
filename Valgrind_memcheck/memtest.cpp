#include "BinaryTree.h"

int foo(int x)
{
    if(x < 10)
    {
        return 100;
    }
    return 1000;
}

void constructTree() {
    BinaryTreeNode<int> rootNode{};
    insert(new int(0), rootNode);
    insert(new int(5), rootNode);
    insert(new int(-5), rootNode);
}

int main() {
    char *name = new char[10];
    name[10] = 'x';

    int var;
    foo(var);
    constructTree();

    return 0;
}
