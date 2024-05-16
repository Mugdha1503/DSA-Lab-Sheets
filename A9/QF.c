#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* CreateNode(int value)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if(node)
    {
        node->val = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}
void InOrderTraversal(TreeNode* root, int* result, int* index)
{
    if(root == NULL)
        return;
    InOrderTraversal(root->left, result, index);
    result[(*index)++] = root->val;
    InOrderTraversal(root->right, result, index);
}
int kthLeastPriorityError(TreeNode* root, int k)
{
    int* result = (int*)malloc(1000000 * sizeof(int));
    int index = 0;
    InOrderTraversal(root, result, &index);
    int kthError = result[index-k];
    free(result);
    return kthError;
}
void main()
{
    int n, k;
    scanf("%d %d",&n,&k);
    int A[n];
    for(int i=0; i<n; i++)
        scanf("%d", &A[i]);
    TreeNode* root = NULL;
    for(int i=0; i<n; i++)
    {
        if(i==0)
            root = CreateNode(A[i]);
        else
        {
            TreeNode* current = root;
            while(1)
            {
                if(A[i] < current->val)
                {
                    if(current->left == NULL)
                    {
                        current->left = CreateNode(A[i]);
                        break;
                    }
                    else
                        current = current->left;
                }
                else
                {
                    if(current->right == NULL)
                    {
                        current->right = CreateNode(A[i]);
                        break;
                    }
                    else
                        current = current->right;
                }
            }
        }
    }
    int kthError = kthLeastPriorityError(root, k);
    printf("%d",kthError);
}
