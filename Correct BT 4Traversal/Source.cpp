#include <iostream>
using namespace std;

template <class Binary>
class BinaryTree {
public:
    Binary data;
    BinaryTree<Binary>* left;
    BinaryTree<Binary>* Right;

    BinaryTree(Binary d) {
        this->data = d;
        this->left = NULL;
        this->Right = NULL;
    }
};

template <class Binary>
class QueueNode {
public:
    BinaryTree<Binary>* data;
    QueueNode<Binary>* next;

    QueueNode(BinaryTree<Binary>* d) {
        data = d;
        next = NULL;
    }
};

template <class Binary>
class Queue {
public:
    QueueNode<Binary>* front;
    QueueNode<Binary>* rear;

    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void push(BinaryTree<Binary>* val) {
        QueueNode<Binary>* temp = new QueueNode<Binary>(val);
        if (isEmpty()) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }
    }

    BinaryTree<Binary>* pop() {
        if (isEmpty()) {
            return NULL;
        }
        QueueNode<Binary>* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        BinaryTree<Binary>* val = temp->data;
        delete temp;
        return val;
    }

    BinaryTree<Binary>* frontElement() {
        if (isEmpty()) return NULL;
        return front->data;
    }
};


template <class Binary>
void BuildTree(BinaryTree<Binary>* root) {
    if (root == NULL) return;

    int leftData, rightData;

    cout << "Enter the value for left child of (-1 for no node) " << root->data << ": ";
    cin >> leftData;
    if (leftData != -1) {
        root->left = new BinaryTree<Binary>(leftData);
        BuildTree(root->left);
    }

    cout << "Enter the value for right child of (-1 for no node) " << root->data << ": ";
    cin >> rightData;
    if (rightData != -1) {
        root->Right = new BinaryTree<Binary>(rightData);
        BuildTree(root->Right);
    }
}


template <class Binary>
void BuildTreefronLOT(BinaryTree<Binary>*& root) {
    int data;
    cout << "Enter the data for root: ";
    cin >> data;

    if (data == -1) {
        root = NULL;
        return;
    }

    root = new BinaryTree<Binary>(data);
    Queue<Binary> q;
    q.push(root);

    while (!q.isEmpty()) {
        BinaryTree<Binary>* temp = q.pop();
        int leftData, rightData;

        cout << "Enter the left child of " << temp->data << " (-1 for no child): ";
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new BinaryTree<Binary>(leftData);
            q.push(temp->left);
        }

        cout << "Enter the right child of " << temp->data << " (-1 for no child): ";
        cin >> rightData;
        if (rightData != -1) {
            temp->Right = new BinaryTree<Binary>(rightData);
            q.push(temp->Right);
        }
    }
}


//template<class Binary>
//void Levelorder(BinaryTree<Binary>* root) {
//    if (root == NULL) return;
//
//    Queue<Binary> q;
//    q.enqueue(root);
//
//    while (!q.isEmpty()) {
//        BinaryTree<Binary>* temp = q.dequeue();
//        cout << temp->data << " ";
//
//        if (temp->left != NULL) q.enqueue(temp->left);
//        if (temp->Right != NULL) q.enqueue(temp->Right);
//    }
//}
template<class Binary>
void Levelorder(BinaryTree<Binary>* root) {
    Queue<Binary> q;
    q.push(root);
    q.push(NULL);
    while (!q.isEmpty()) {
        BinaryTree<Binary>* temp = q.frontElement();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.isEmpty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->Right) {
                q.push(temp->Right);
            }
        }

    }
}

template <class Binary>
void InorderTraversal(BinaryTree<Binary>* root) {
    if (root == NULL) return;
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->Right);
}

template<class Binary>
void PreorderTraversal(BinaryTree<Binary>* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->Right);
}

template<class Binary>
void PostorderTraversal(BinaryTree<Binary>* root) {
    if (root == NULL) return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->Right);
    cout << root->data << " ";
}

int main() {
    BinaryTree<int>* root = NULL;

    int choice;
    do {
        cout << "\n1. Recursive Build Tree";
        cout << "\n2. Build Tree from Level Order";
        cout << "\n3. Level Order Traversal";
        cout << "\n4. Inorder Traversal";
        cout << "\n5. Preorder Traversal";
        cout << "\n6. Postorder Traversal";
        cout << "\n7. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int rootData;
            cout << "Enter root data: ";
            cin >> rootData;
            root = new BinaryTree<int>(rootData);
            BuildTree(root);
            break;
        }
        case 2: {
            BuildTreefronLOT(root);
            break;
        }
        case 3: {
            cout << "\nLevel Order: "<<endl;
            Levelorder(root);
            cout << endl;
            break;
        }
        case 4: {
            cout << "\nInorder: ";
            InorderTraversal(root);
            cout << endl;
            break;
        }
        case 5: {
            cout << "\nPreorder: ";
            PreorderTraversal(root);
            cout << endl;
            break;
        }
        case 6: {
            cout << "\nPostorder: ";
            PostorderTraversal(root);
            cout << endl;
            break;
        }
        case 7:
            cout << "Exiting Program...." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
