#include <iostream>
#include <queue>  

using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


class BinaryTree {
public:
    Node* root;

    BinaryTree() { root = nullptr; }

 
    void insert(int data) {
        Node* newNode = new Node(data);

       
        if (root == nullptr) {
            root = newNode;
            return;
        }

      
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

         
            if (temp->left == nullptr) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

           
            if (temp->right == nullptr) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }


    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }


    void performTraversal(int choice) {
        switch (choice) {
            case 1:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
};

int main() {
    BinaryTree tree;
    int n, value, traversalChoice;
    cout << "Enter the number of nodes: ";
    cin >> n;


    cout << "Enter the values to insert into the tree:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        tree.insert(value);
    }

    cout<<"*********************"<<endl;
    cout << "Choose traversal"<<endl;
    cout<<"1.Preorder"<<endl;
    cout<<"2.Postorder"<<endl;
    cout<<"3.Inorder"<<endl;
    cout<<"*********************"<<endl;
    
    cin >> traversalChoice;

    tree.performTraversal(traversalChoice);

    return 0;
}
