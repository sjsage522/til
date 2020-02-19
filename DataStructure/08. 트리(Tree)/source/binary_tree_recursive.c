#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode {
    int data;
    struct _TreeNode *left, *right;
} TreeNode;

//       15
//  4         20
// 1        16  25
// TreeNode n1 = { 1, NULL, NULL };
// TreeNode n2 = { 4, &n1, NULL };
// TreeNode n3 = { 16, NULL, NULL };
// TreeNode n4 = { 25, NULL, NULL };
// TreeNode n5 = { 20, &n3, &n4 };
// TreeNode n6 = { 15, &n2, &n5 };
// TreeNode *root = &n6;

TreeNode n1 = {5, NULL, NULL};
TreeNode n2 = {15, &n1, NULL};
TreeNode n3 = {22, NULL, NULL};
TreeNode n4 = {35, &n3, NULL};
TreeNode n5 = {95, NULL, NULL};
TreeNode n6 = {93, &n4, &n5};
TreeNode n7 = {17, &n2, &n6};
TreeNode *root = &n7; 

// ���� ��ȸ
void inorder(TreeNode *root) {
    if(root != NULL) {
        inorder(root->left);         // ���ʼ���Ʈ�� ��ȸ
        printf("[%d] ", root->data); // ��� �湮
        inorder(root->right);        // �����ʼ���Ʈ�� ��ȸ
    }
}

// ���� ��ȸ
void preorder(TreeNode *root) {
    if(root != NULL) {
        printf("[%d] ", root->data); // ��� �湮
        preorder(root->left);        // ���ʼ���Ʈ�� ��ȸ
        preorder(root->right);       // �����ʼ���Ʈ�� ��ȸ
    }
}

// ���� ��ȸ
void postorder(TreeNode *root) {
    if(root != NULL) {
        postorder(root->left);       // ���ʼ���Ʈ�� ��ȸ
        postorder(root->right);      // �����ʼ���Ʈ�� ��ȸ
        printf("[%d] ", root->data); // ��� �湮
    }
}

int main() {
    printf("���� ��ȸ=");
    inorder(root);
    printf("\n");

    printf("���� ��ȸ=");
    preorder(root);
    printf("\n");

    printf("���� ��ȸ=");
    postorder(root);
    printf("\n");
}