#include <stdio.h>
#include <stdlib.h>
// Structure for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function to create a new binary tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// Function to construct a binary tree from the given array
struct TreeNode* constructTree(int arr[], int n, int index) {
    struct TreeNode* root = NULL;
    // Base case: If index is out of bounds or element is -1, return NULL
    if (index < n && arr[index] != -1) {
        root = newNode(arr[index]);
        root->left = constructTree(arr, n, 2 * index + 1); // Construct left subtree
        root->right = constructTree(arr, n, 2 * index + 2); // Construct right subtree
    }
    return root;
}
// Function to calculate the height of a binary tree
int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        // Return the maximum height of left and right subtrees, plus 1 for the root node
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}
// Function to delete a binary tree node and its subtree
void deleteNode(struct TreeNode* root, int target) {
    if (root == NULL)
        return;
    if (root->left != NULL && root->left->val == target) {
        root->left = NULL; // Cut off the left subtree
        free(root->left); // Free the memory
    }
    else if (root->right != NULL && root->right->val == target) {
        root->right = NULL; // Cut off the right subtree
        free(root->right); // Free the memory
    }
    else {
        deleteNode(root->left, target);
        deleteNode(root->right, target);
    }
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    // Construct the binary tree
    struct TreeNode* root = constructTree(arr, n, 0);
    // Delete the node Kira cut off
    deleteNode(root, k);
    // Calculate the height of the remaining tree
    int remainingHeight = height(root);
    printf("%d\n", remainingHeight);
    return 0;
}

