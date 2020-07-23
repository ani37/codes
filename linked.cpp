    #include <bits/stdc++.h>
    using namespace std;
     
    struct node {
        int data;
        node *left;
        node *right;
    };
     
    node *getNode(int val) {
        node *newNode = new node();
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
     
     
    node *findNode(node *root, int data) {
        if (root->data == data) 
            return root;
        if (root->left) findNode(root->left, data);
        if (root->right) findNode(root->right, data);
    }
     
    void display(node *root) {
        // displaying the tree
        queue<node*> Q;
        Q.push(root);
        while (!Q.empty()) {
            node *x = Q.front();
            Q.pop();
            if (x->left) Q.push(x->left);
            if (x->right) Q.push(x->right);
            cout << x->data << " ";
        }
        cout << endl;
    }
     
    node *copy(node *root) {
        if (!root) 
            return root;
        node *temp = new node();
        temp->data = root->data;
        temp->left = copy(root->left);
        temp->right = copy(root->right);
        return temp;
    }
     
    void mirror(node *root) {
        if (root) {
            mirror(root->left);
            mirror(root->right);
            node *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        return;
    }
     
    int findMirror(int target, node *left, node *right) {
        if (left == NULL || right == NULL) return 0;
        if (left->data == target) return right->data;
        if (right->data == target) return left->data;
        int mirrorValue = findMirror(target, left->left, right->right);
        if (mirrorValue) return mirrorValue;
        return findMirror(target, left->right, right->left);
    }
     
    int query(int target, node *root) {
        if (root == NULL) return 0;
        if (root->data == target) return target;
        return findMirror(target, root->left, root->right);
    }
     
    int main()
    {
        node *root = NULL;
        int n, q;
        cin >> n >> q;
        while (--n > 0) {
            int p, c;
            char ch;
            cin >> p >> c >> ch;
            if (root == NULL) {
                // this is the root node
                node *newNode = getNode(p);
                root = newNode;
                // create the child node
                node *newNode2 = getNode(c);
                if (ch == 'L') 
                    newNode->left = newNode2; // left child
                else 
                    newNode->right = newNode2; // right child
            }
            else {
                //find the parent node
                node *addr = findNode(root, p);
                node *newNode2 = getNode(c);
                if (ch == 'L') addr->left = newNode2;
                else addr->right = newNode2;
            }
        }
        // accepting the query
        //display(root);
        while (q--) {
            int n;
            cin >> n;
            int x = query(n, root) ;
            if (x == NULL) cout << "-1\n";
            else cout << x << endl;
        }
        return 0;
    }