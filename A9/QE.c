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
TreeNode* BuildBST(int n, int postorder[])
{
    if(n<=0)
        return NULL;
    TreeNode** stack = (TreeNode**)malloc(n * sizeof(TreeNode*));
    int top = -1;
    TreeNode* root = CreateNode(postorder[n - 1]);
    stack[++top] = root;
    for(int i = n-2 ; i>=0; i--)
    {
        TreeNode* node = CreateNode(postorder[i]);
        if(postorder[i] > stack[top]->val)
            stack[top]->right = node;
        else
        {
            TreeNode* parent = NULL;
            while(top >= 0 && postorder[i] < stack[top]->val)
                parent = stack[top--];
            parent->left = node;
        }
        stack[++top] = node;
    }
    free(stack);
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
    int postorder[n];
    for(int i=0; i<n; i++)
        scanf("%d",&postorder[i]);
    TreeNode* root = BuildBST(n, postorder);
    LevelOrderTraversal(root);
}
