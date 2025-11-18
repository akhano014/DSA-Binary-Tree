#include<iostream>
using namespace std;
template<class Binary>
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
template<class Binary>
class QueueNode {
public:
	BinaryTree<Binary>* data;
	QueueNode<Binary>* next;

	QueueNode(BinaryTree<Binary>* d) {
		data = d;
		next = NULL;
	}
};
template<class Binary>
class Queue {
public:
	QueueNode<Binary>* front;
	QueueNode<Binary>* rear;

	Queue() {
		front = NULL;
		rear = NULL;
	}

	bool isEmpty() {
		return (front == NULL);
	}

	void push(BinaryTree<Binary>* d) {
		QueueNode<Binary>* newNode = new QueueNode<Binary>(d);
		if (rear == NULL) {
			front = rear = newNode;
			return;
		}
		rear->next = newNode;
		rear = newNode;
	}

	BinaryTree<Binary>* pop() {
		if (isEmpty()) return NULL;
		QueueNode<Binary>* temp = front;
		BinaryTree<Binary>* data = temp->data;
		front = front->next;

		if (front == NULL)
			rear = NULL;

		delete temp;
		return data;
	}

	BinaryTree<Binary>* frontElement() {
		if (isEmpty()) return NULL;
		return front->data;
	}
};
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
template<class Binary>
BinaryTree<Binary>* BuildTree(BinaryTree<Binary>* root) {
	Binary data;
	cout << "Enter Data: ";
	cin >> data;
	if (data == -1) {
		return NULL;
	}
	root = new BinaryTree<Binary>(data);
	cout << "Enter Data to insert on left of " << data << endl;
	root->left = BuildTree<Binary>(root->left);
	cout << "Enter Data to insert on Right of " << data << endl;
	root->Right = BuildTree<Binary>(root->Right);
	return root;
}
template<class Binary>
 void InorderTraversal(BinaryTree<Binary>* root) {
	if (root == NULL) {
		return;
	}

	InorderTraversal(root->left);
	cout << root->data << " ";
	InorderTraversal(root->Right);
}

 template<class Binary>
 void PreorderTraversal(BinaryTree<Binary>* root) {
	 if (root == NULL) {
		 return;
	 }

	 cout << root->data << " ";
	 PreorderTraversal(root->left);
	 PreorderTraversal(root->Right);
 }

int main() {
	cout << "\t\t***Build Tree**" << endl;
	BinaryTree<int>* root = NULL;
	root = BuildTree<int>(root);

	int choice;  

	do {
		cout << "1. Level Order Traversal" << endl;
		cout << "2. Inorder Traversal" << endl;
		cout << "3. Preorder Traversal" << endl;
		cout << "4. Exit" << endl;

		cout << "Enter Your Choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			Levelorder<int>(root);
			break;
		}
		case 2: {
			cout << "\t\t**Inorder traversal** "<<endl;
			InorderTraversal(root);
			cout << endl;
			break;
		}
		case 3: {
			cout << "\t\t**Preorder traversal** " << endl;
			PreorderTraversal(root);
			cout << endl;
			break;
		}
		case 4: {
			cout << "Exit...." << endl;
			break;
		}
		default: {
			cout << "Invalid Choice....." << endl;
			break;
		}
		}
	} while (choice != 3);



	
}