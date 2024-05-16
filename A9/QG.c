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
TreeNode* BuildTree(int n, int A[])
{
    if(n<=0)
        return NULL;
    TreeNode** Node = (TreeNode**)malloc(n * sizeof(TreeNode*));
    for(int i=0; i<n; i++)
    {
        if(A[i] == -1)
            Node[i] = NULL;
        else
            Node[i] = CreateNode(A[i]);
    }
    TreeNode* root=Node[0];
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(Node[i]==NULL)
            count++;
        if(Node[i])
        {
            int leftIndex=2*i+1-(2*count);
            int rightIndex=2*i+2-(2*count);
            {
                if(leftIndex < n)
                    Node[i]->left = Node[leftIndex];
                if(rightIndex < n)
                    Node[i]->right = Node[rightIndex];
            }
        }
    }
    free(Node);
    return root;
}
int FindAncestors(TreeNode* root, int target, int ancestors[], int* index)
{
    if(root == NULL)
        return 0;
    ancestors[*index] = root->val;
    (*index)++;
    if(root->val == target)
        return 1;
    if((root->left && FindAncestors(root->left, target, ancestors, index)) || (root->right && FindAncestors(root->right, target, ancestors, index)))
        return 1;
    (*index)--;
    return 0;
}
int FindCommonBoss(TreeNode* root, int A, int B)
{
    int ancestors_A[1000], ancestors_B[1000];
    int index_A = 0, index_B = 0;
    if(!FindAncestors(root, A, ancestors_A, &index_A) || !FindAncestors(root, B, ancestors_B, &index_B))
        return -1;
    int commonBoss = -1;
    for(int i=0; i < index_A && i < index_B; i++)
    {
        if(ancestors_A[i] != ancestors_B[i])
            break;
        commonBoss = ancestors_A[i];
    }
    return commonBoss;
}
void main()
{
    int n, a, b;
    scanf("%d %d %d",&n,&a,&b);
    int A[n];
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    TreeNode* root = BuildTree(n, A);
    int commonBoss = FindCommonBoss(root, a, b);
    printf("%d",commonBoss);
}
