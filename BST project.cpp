#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
public:
    BST() {
        root = nullptr;
    }
    
    void insert(int val) {
        root = insertRec(root, val);
    }
    
    bool search(int val) {
        return searchRec(root, val);
    }
    
    void remove(int val) {
        root = deleteRec(root, val);
    }
    
    void inorder() {
        inorderRec(root);
        cout << endl;
    }
    
private:
    Node* root;
    
    Node* insertRec(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        
        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else if (val > node->data) {
            node->right = insertRec(node->right, val);
        }
        
        return node;
    }
    
    bool searchRec(Node* node, int val) {
        if (node == nullptr) {
            return false;
        }
        
        if (node->data == val) {
            return true;
        }
        
        if (val < node->data) {
            return searchRec(node->left, val);
        }
        
        return searchRec(node->right, val);
    }
    
    Node* deleteRec(Node* node, int val) {
        if (node == nullptr) {
            return node;
        }
        
        if (val < node->data) {
            node->left = deleteRec(node->left, val);
        } else if (val > node->data) {
            node->right = deleteRec(node->right, val);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            
            Node* temp = minValueNode(node->right);
            
            
            node->data = temp->data;
            
            
            node->right = deleteRec(node->right, temp->data);
        }
        
        return node;
    }
    
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    
    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }
};

int main() {
    BST tree;
    int choice, value;
    
    while (true) {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display Inorder\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value)) {
                    cout << value << " found in the tree.\n";
                } else {
                    cout << value << " not found in the tree.\n";
                }
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.remove(value);
                break;
            case 4:
                cout << "Inorder traversal: ";
                tree.inorder();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
    
    return 0;
}
