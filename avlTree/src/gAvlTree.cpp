#include "gAvlTree.h"
#include <iostream>
#include <list>
#include <queue>
// C++ program to insert a node in AVL tree

// A utility function to get the
// height of the tree
int gAVLtree::height(gNode *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum
// of two integers
int gAVLtree::max(int a, int b) { return (a > b) ? a : b; }

/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */
gNode *gAVLtree::newNode(int key) {
    gNode *node = new gNode(key);
    return (node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
gNode *gAVLtree::rightRotate(gNode *y) {
    gNode *x = y->left;
    gNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
gNode *gAVLtree::leftRotate(gNode *x) {
    gNode *y = x->right;
    gNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int gAVLtree::getBalance(gNode *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
gNode *gAVLtree::insertNode(gNode *node, int key) {
    /* 1. Perform the normal BST insertion */
    if (node == NULL) {
        return (newNode(key));
    }

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));

    /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void gAVLtree::preOrder(gNode *root) {
    if (root != NULL) {
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void gAVLtree::levelOrder(gNode *root, treeLevels &levels) {
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    std::queue<gNode *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
        // nodeCount (queue size) indicates number
        // of nodes at current level.
        int nodeCount = q.size();
        // printf("nodeCount (%d)\n", nodeCount);
        std::list<int> nodesInLevel;

        // Dequeue all nodes of current level and
        // Enqueue all nodes of next level
        while (nodeCount > 0) {
            gNode *node = q.front();
            q.pop();
            nodesInLevel.push_back(node->key);
            // printf("%d ", node->getData());
            if (node->left != nullptr) {
                q.push(node->left);
            }

            if (node->right != nullptr) {
                q.push(node->right);
            }

            nodeCount--;
        }
        // printf("\n");
        levels.push_back(nodesInLevel);
    }
}
