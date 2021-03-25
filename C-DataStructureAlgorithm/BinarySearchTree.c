#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        root->data = data;
        return root;
    } else {
        if (root->data > data) {
            root->leftChild = insertNode(root->leftChild, data);
        } else {
            root->rightChild = insertNode(root->rightChild, data);
        }
    }
    return root;
}

Node* searchNode(Node* root, int data) {
    if (root == NULL) return NULL;
    if (root->data == data) return root;
    else if (root->data > data) return searchNode(root->leftChild, data);
    else return searchNode(root->rightChild, data);
}

Node* findMinNode(Node* root) {
    Node* node = root;
    while (node->leftChild != NULL) {
        node = node->leftChild;
    }
    return node;
}

Node* deleteNode(Node* root, int data) {
    Node* node = NULL;
    if (root == NULL) return NULL;
    if (root->data > data) root->leftChild = deleteNode(root->leftChild, data);
    else if (root->data < data) root->rightChild = deleteNode(root->rightChild, data);
    else {
        // 자식이 둘 다 존재하는 경우
        if (root->leftChild != NULL && root->rightChild != NULL) {
            node = findMinNode(root->rightChild);   // 오른쪽 노드에서 가장 작은걸 찾는다.
            root->data = node->data;
            root->rightChild = deleteNode(root->rightChild, node->data);
        } else {
            // 왼쪽 자식이 존재한다면
            node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;
            free(root);
            return node;    // node를 반환함으로써 해당 자식노드가 root 노드를 대체할 수 있도록 한다.
        }
    }
    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->leftChild);
    preorder(root->rightChild);
}

int main(void) {
    Node* root = NULL;
    root = insertNode(root, 30);
    root = insertNode(root, 17);
    root = insertNode(root, 48);
    root = insertNode(root, 5);
    root = insertNode(root, 23);
    root = insertNode(root, 37);
    root = insertNode(root, 50);
    root = deleteNode(root, 30);
    preorder(root);
    return 0;
}