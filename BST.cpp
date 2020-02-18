#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
    BinaryTreeNode<int>* inOrderSuccessor(BinaryTreeNode<int> *root)
    {
        BinaryTreeNode<int> *temp = root;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    
    BinaryTreeNode<int>* insert(BinaryTreeNode<int> *root,int value)
    {
        if(root == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(int value);
            return newNode;
        }
        else if(value < root->data)
        {
            root->left = insert(root->left,value);
        }
        else if(value > root->data)
        {
            root->right = insert(root->right,value);
        }

        return root;
    }
    
    BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int> *root,int value)
    {
        if(root == NULL)
        {
            return NULL;
        }
        if(value < root->data)
        {
            root->left = deleteNode(root->left,value);
        }
        else if(value > root->data)
        {
            root->right = deleteNode(root->right,value);
        }
        else
        {
            if(root->left == NULL)
            {
                BinaryTreeNode<int> *temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right == NULL)
            {
                BinaryTreeNode<int> *temp = root->left;
                free(root);
                return temp;
            }
            else
            {
                BinaryTreeNode<int>* successor = inOrderSuccessor(root->right);
                root->data = successor->data;
                root->right = deleteNode(root->right,successor->data);
            }
        }
        return root;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
    q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
BinaryTreeNode<int> *abc(int *a, int s, int e){
    if(s>e) return NULL;
    int m = (s+e)/2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (a[m]);
    root -> left = abc(a, s, m-1);
    root -> right = abc(a, m+1, e);
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n){
    return abc(input, 0, n-1);
}

void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void inOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    
    preOrder(root -> left);
    cout << root -> data << " ";
    preOrder(root -> right);
}

void postOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    preOrder(root -> left);
    preOrder(root -> right);
    cout << root -> data << " ";
}

int main() {
    int size;
    cin>>size;
    int *input=new int[1+size];
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    
    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    
}
