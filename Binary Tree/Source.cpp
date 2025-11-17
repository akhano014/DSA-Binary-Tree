#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class QueueNode {
public:
    Node* data;
    QueueNode* next;

    QueueNode(Node* d) {
        data = d;
        next = NULL;
    }
};

class Queue {
public:
    QueueNode* front;
    QueueNode* rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void push(Node* d) {
        QueueNode* newNode = new QueueNode(d);
        if (rear == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    Node* pop() {
        if (isEmpty()) return NULL;
        QueueNode* temp = front;
        Node* data = temp->data;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
        return data;
    }

    Node* frontElement() {
        if (isEmpty()) return NULL;
        return front->data;
    }
};

void InsertHelper(Node*& root, int value) {
    if (root == NULL) {
        root = new Node(value);
        return;
    }
    else if (value < root->data)
        InsertHelper(root->left, value);
    else if (value > root->data)
        InsertHelper(root->right, value);
}

bool RetrieveHelper(Node* root, int value) {
    if (root == NULL)
        return false;

    if (value == root->data)
        return true;
    else if (value < root->data)
        return RetrieveHelper(root->left, value);
    else
        return RetrieveHelper(root->right, value);
}

void PrintHelper(Node* root) {
    if (root != NULL) {
        PrintHelper(root->left);
        cout << root->data << " ";
        PrintHelper(root->right);
    }
}

void DestroyHelper(Node* root) {
    if (root != NULL) {
        DestroyHelper(root->left);
        DestroyHelper(root->right);
        delete root;
    }
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root) {
    if (root == NULL) return;

    Queue q;
    q.push(root);

    cout << "Level Order Traversal: ";

    while (!q.isEmpty()) {
        Node* temp = q.frontElement();
        q.pop();

        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

    cout << endl;
}

int main() {
    Node* root = NULL;
    int choice;

    do {
        cout << "\n==============================\n";
        cout << "        Binary Search Tree\n";
        cout << "==============================\n";
        cout << "1. Insert Item\n";
        cout << "2. Search Item\n";
        cout << "3. Print Tree (Inorder - Lab Style)\n";
        cout << "4. Level Order Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Inorder Traversal\n";
        cout << "7. Postorder Traversal\n";
        cout << "0. Exit\n";
        cout << "==============================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {

        case 1: {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            InsertHelper(root, val);
            cout << "Value Inserted.\n";
            break;
        }

        case 2: {
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            if (RetrieveHelper(root, key))
                cout << "Value FOUND in BST\n";
            else
                cout << "Value NOT FOUND\n";
            break;
        }

        case 3:
            if (root == NULL)
                cout << "Tree is empty.\n";
            else {
                cout << "BST (Inorder): ";
                PrintHelper(root);
                cout << endl;
            }
            break;

        case 4:
            levelOrder(root);
            break;

        case 5:
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            break;

        case 6:
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
            break;

        case 7:
            cout << "Postorder: ";
            postorder(root);
            cout << endl;
            break;

        case 0:
            cout << "Exiting Program...\n";
            DestroyHelper(root);
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 0);

    return 0;
}
