#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a > b) ? a : b)

typedef int element;
typedef struct _TreeNode {
    element key;
    struct _TreeNode *left, *right;
} TreeNode;

// ��ȯ���� Ž�� �Լ�
TreeNode *search(TreeNode *node, int key) {
    if (node == NULL) return NULL;
    if (key == node->key) return node;
    else if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode *new_node(element item) {
    TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode *insert_node(TreeNode *node, element key) {
    // Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
    if(node == NULL) return new_node(key);

    // �׷��� ������ ��ȯ������ Ʈ���� ��������.
    if(key < node->key)
        node->left = insert_node(node->left, key);
    else if(key > node->key)
        node->right = insert_node(node->right, key);

    // ����� ��Ʈ �����͸� ��ȯ�Ѵ�.
    return node;
}

TreeNode *min_value_node(TreeNode *node) {
    TreeNode *current = node;

    // �� ���� �ܸ� ��带 ã���� ������
    while(current->left != NULL)
        current = current->left;
    return current;
}

// ���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����Ѱ�
// ���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
TreeNode *delete_node(TreeNode *root, element key) {
    if(root == NULL) return root;

    // ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
    if(key < root->key)
        root->left = delete_node(root->left, key);
    // ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
    else if(key > root->key)
        root->right = delete_node(root->right, key);
    // Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
    else {
        // ù ��°�� �� ��° ���
        if(root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        // �� ��° ���
        TreeNode *temp = min_value_node(root->right);

        // ���� ��ȸ�� �İ� ��带 �����Ѵ�.
        root->key = temp->key;
        // ���� ��ȸ�� �İ� ��带 �����Ѵ�.
        root->right = delete_node(root->right, temp->key);
    }   
    return root;
}

// ���� ��ȸ
void inorder(TreeNode *root) {
    if(root) {
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}

int get_height(TreeNode *node) {
    int height = 0;

    if(node != NULL)
        height = 1+max(get_height(node->left), get_height(node->right));
    return height;
}

int main() {
    TreeNode *root = NULL;
    TreeNode *tmp = NULL;

    root = insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 10);
    insert_node(root, 40);
    insert_node(root, 50);
    insert_node(root, 60);

    printf("Ʈ���� ����=[%d] \n", get_height(root));
    printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
    inorder(root);
    printf("\n\n");
    if(search(root, 30) != NULL)
        printf("���� Ž�� Ʈ������ 30�� �߰��� \n");
    else
        printf("���� Ž�� Ʈ������ 30�� �߰߸��� \n");
    return 0;
}