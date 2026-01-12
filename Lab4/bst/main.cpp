#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Employee {
    public:
        int id;
        string name;
        int age;


        Employee(int _id = 0, string _name = "", int _age = 0){
            id = _id;
            name = _name;
            age = _age;
        }
//        int getID(){ return id; }
//        string getName(){ return name; }
//        int getAge(){ return age; }
//
//        void setID(int _id){ id = _id; }
//        void setName(string _name){ name = _name; }
//        void setAge(int _age){ age = _age; }
};

class Node {
    public:
        Employee emp;
        Node* left;
        Node* right;
        int height;

        Node(const Employee& e)
            : emp(e), left(NULL), right(NULL), height(1) {}
};

int height(Node* n) {
    if(n)
        return n->height;
    else
        return 0;
}
int getBalance(Node* n) {
    if(n)
        return height(n->left) - height(n->right);
    else
        return 0;
}
void updateHeight(Node* n) {
    if (n)
        n->height = 1 + max(height(n->left), height(n->right));
}

// Right rotate (y is root of subtree)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // rotation
    x->right = y;
    y->left = T2;

    // update heights
    updateHeight(y);
    updateHeight(x);

    return x; // new root
}

// Left rotate (x is root of unbalanced subtree)
Node* leftRotate(Node* x) {
    Node* y = x->right; //y is the right child of x
    Node* T2 = y->left; // T2 is the left child of y

    // rotation
    y->left = x; // Make x the left child of y.
    x->right = T2; //The old left subtree of y (T2) becomes the new right subtree of x.

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insert by employee id
Node* insertNode(Node* root, const Employee& e) {
    if (!root) return new Node(e);

    if (e.id < root->emp.id)
        root->left = insertNode(root->left, e);
    else if (e.id > root->emp.id)
        root->right = insertNode(root->right, e);
    else {
        // duplicate ID
        cout << "Employee already exist\n";
        return root;
    }

    updateHeight(root);

    int balance = getBalance(root);

    // LL
    if (balance > 1 && e.id < root->left->emp.id)
        return rightRotate(root);

    // RR
    if (balance < -1 && e.id > root->right->emp.id)
        return leftRotate(root);

    // LR : do a left rotation on left child, then right rotation on node
    if (balance > 1 && e.id > root->left->emp.id) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL : do a right rotation on right child, then left rotation on node.
    if (balance < -1 && e.id < root->right->emp.id) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Find minimum node (by id) in subtree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
// Get minimum employee
bool getMinimum(Node* root, Employee &out) {
    Node* n = minValueNode(root);
    if (!n) return false;
    out = n->emp;
    return true;
}

// Get maximum employee (rightmost)
bool getMaximum(Node* root, Employee &out) {
    Node* curr = root;
    if (!curr) return false;
    while (curr->right) curr = curr->right;
    out = curr->emp;
    return true;
}

// Delete by id
Node* deleteNode(Node* root, int id) {
    if (!root) return root;

    if (id < root->emp.id)
        root->left = deleteNode(root->left, id);
    else if (id > root->emp.id)
        root->right = deleteNode(root->right, id);
    else {
        // Node to be deleted found
        if (!root->left || !root->right) {
            if(root->left)
                Node* temp = root->left ;
            Node* temp = root->right;

            if (!temp) {
                // no child
                temp = root;
                root = NULL;
            } else {
                // one child
                *root = *temp; // copy contents
            }
            delete temp;
        }
        else {
            // two children: get inorder successor (min in right subtree)
            Node* temp = minValueNode(root->right);
            root->emp = temp->emp;
            root->right = deleteNode(root->right, temp->emp.id);
        }
    }

    if (!root) return root;

    updateHeight(root);
    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Search by id
Node* searchNode(Node* root, int id) {
    if (!root || root->emp.id == id) return root;
    if (id < root->emp.id) return searchNode(root->left, id);
    return searchNode(root->right, id);
}

// DFS: inorder, preorder, postorder
void inorder(Node* root, vector<Employee>& out) {
    if (!root) return;
    inorder(root->left, out);
    out.push_back(root->emp);
    inorder(root->right, out);
}
void preorder(Node* root, vector<Employee>& out) {
    if (!root) return;
    out.push_back(root->emp);
    preorder(root->left, out);
    preorder(root->right, out);
}
void postorder(Node* root, vector<Employee>& out) {
    if (!root) return;
    postorder(root->left, out);
    postorder(root->right, out);
    out.push_back(root->emp);
}

// Wrapper BST class
class AVLTree {
private:
    Node* root;

public:
    AVLTree(): root(NULL) {}

    void insert(const Employee& e) {
        root = insertNode(root, e);
    }

    bool remove(int id) {
        if (!search(id)) return false;
        root = deleteNode(root, id);
        return true;
    }

    Employee* search(int id) {
        Node* n = searchNode(root, id);
        if (!n) return NULL;
        return &n->emp;
    }

    bool getMin(Employee &out) {
        return getMinimum(root, out);
    }
    bool getMax(Employee &out) {
        return getMaximum(root, out);
    }

    vector<Employee> inorderTraversal() {
        vector<Employee> out;
        inorder(root, out);
        return out;
    }
    vector<Employee> preorderTraversal() {
        vector<Employee> out;
        preorder(root, out);
        return out;
    }
    vector<Employee> postorderTraversal() {
        vector<Employee> out;
        postorder(root, out);
        return out;
    }

    // For debugging: print inorder to console
    void printInorder() {
        vector<Employee> v = inorderTraversal();
        for (int i=0; i<v.size(); i++)
            cout << "(" << v[i].id << ", " << v[i].name << ", " << v[i].age << ") ";
        cout << endl;
    }
};

int main() {
    AVLTree tree;

    tree.insert(Employee(10, "Ali", 28));
    tree.insert(Employee(20, "Mona", 30));
    tree.insert(Employee(5, "Samir", 25));
    tree.insert(Employee(8, "Laila", 27));
    tree.insert(Employee(15, "Tarek", 35));

    cout << "Inorder (sorted by ID): ";
    tree.printInorder();

    cout << "Search ID 8: ";
    Employee* e = tree.search(8);
    if (e) cout << e->id << " " << e->name << " " << e->age << endl;
    else cout << "Not found\n";

    cout << "Min and Max:\n";
    Employee mn, mx;
    if (tree.getMin(mn)) cout << "Min ID: " << mn.id << " Name: " << mn.name << endl;
    if (tree.getMax(mx)) cout << "Max ID: " << mx.id << " Name: " << mx.name << endl;

    cout << "Delete 10\n";
    tree.remove(10);
    cout << "Inorder after deletion: ";
    tree.printInorder();

    cout << "Preorder traversal:\n";
    vector<Employee> emp = tree.preorderTraversal();

    for (int i = 0; i < emp.size(); i++) {
        cout << emp[i].id << " ";
    }

    cout << endl;

    return 0;
}
