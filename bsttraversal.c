#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node *left, *right;
};
struct Node* newNode(int key) {
    struct Node* node = malloc(sizeof(struct Node));
    node->key = key; node->left = node->right = NULL;
    return node;
}
void inorder(struct Node* root) 
{
    if (root) { inorder(root->left); printf("%d ", root->key); inorder(root->right); }
}

void preorder(struct Node* root)
 {
    if (root) { printf("%d ", root->key); preorder(root->left); preorder(root->right); }
}

void postorder(struct Node* root) 
{
    if (root) { postorder(root->left); postorder(root->right); printf("%d ", root->key); }
}

int main() {
    struct Node* root = NULL;
    root = newNode(50); insert(root, 30); insert(root, 70);
    insert(root, 20); insert(root, 40); insert(root, 60); insert(root, 80);
    printf("Inorder: "); inorder(root); printf("\n");
    printf("Preorder: "); preorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");
    return 0;
}
