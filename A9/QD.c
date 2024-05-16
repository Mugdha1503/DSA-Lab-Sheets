#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode* CreateNode(int value)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int Search(int A[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
        if(A[i] == value)
            return i;
}
TreeNode* BuildTree(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex)
{
    if(inStart > inEnd)
        return NULL;
    TreeNode* root = CreateNode(preorder[*preIndex]);
    (*preIndex)++;
    if(inStart == inEnd)
        return root;
    int inIndex = Search(inorder, inStart, inEnd, root->val);
    root->left = BuildTree(inorder, preorder, inStart, inIndex-1, preIndex);
    root->right = BuildTree(inorder, preorder, inIndex+1, inEnd, preIndex);
    return root;
}
int Height(TreeNode* root)
{
    if(root == NULL)
        return 0;
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return (leftHeight > rightHeight) ? (leftHeight+1) : (rightHeight+1);
}
void PrintLevel(TreeNode* root, int level)
{
    if(root == NULL)
    {
        printf("-1 ");
        return;
    }
    if(level == 1)
        printf("%d ", root->val);
    else if(level > 1)
    {
        PrintLevel(root->left, level-1);
        PrintLevel(root->right, level-1);
    }
}
void LevelOrderTraversal(TreeNode* root)
{
    int h = Height(root);
    for(int i=1; i<=h; i++)
        PrintLevel(root, i);
}
void main()
{
    int n;
    scanf("%d",&n);
    int inorder[n];
    for(int i=0; i<n; i++)
        scanf("%d",&inorder[i]);
    int preorder[n];
    for(int i=0; i<n; i++)
        scanf("%d",&preorder[i]);
    int preIndex = 0;
    TreeNode* root = BuildTree(inorder, preorder, 0, n-1, &preIndex);
    LevelOrderTraversal(root);
}


