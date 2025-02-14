#include "tree.h"


int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

// function to Compute height of a tree.
int height(const Node* t)
{
    // base case tree is empty
    if (TreeIsEmpty(t))
        return 0;

    // If tree is not empty then height = 1 + max of left
    // height and right heights
    return 1 + max(height(TreeLeft(t)), height(TreeRight(t)));
}

// Function to get diameter of a binary tree
int Diameter(const Node* t)
{
    // base case where tree is empty
    if (TreeIsEmpty(t))
        return 0;

    // get the height of left and right sub-trees
    int lheight = height(TreeLeft(t));
    int rheight = height(TreeRight(t));

    // get the diameter of left and right sub-trees
    int ldiameter = Diameter(TreeLeft(t));
    int rdiameter = Diameter(TreeRight(t));

    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1

    return max(lheight + rheight + 1,
        max(ldiameter, rdiameter));
}
