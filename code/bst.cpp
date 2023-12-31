#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int label;
        Node* left;
        Node* right;
        Node(int label){
            this->label = label;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insert(Node* root, int label){
    if(root == NULL){
        root = new Node(label);
        return root;
    }
    if(label < root->label){
        root->left = insert(root->left, label);
    }
    else if(label > root->label){
        root->right = insert(root->right, label);
    }
    return root;
    
}

bool contains(Node* root, int label){
    if(root == NULL){
        return false;
    }
    if (root->label == label){
        return true;
    }
    else if (label < root->label){
        return contains(root->left, label);
    }
    else{
        return contains(root->right, label);
    }
}

void preOrder(Node* root, vector<int>& result){
    if(root == NULL){
        return;
    }
    result.push_back(root->label);
    preOrder(root->left, result);
    preOrder(root->right, result);
}

void postOrder(Node* root, vector<int>& result){
    if(root == NULL){
        return ;
    }
    postOrder(root->left, result);
    postOrder(root->right, result);
    result.push_back(root->label);
}

void inOrder(Node* root, vector<int>& result){
    if(root == NULL){
        return;
    }
    inOrder(root->left, result);
    result.push_back(root->label);
    inOrder(root->right, result);
}

Node* buildFromPreOrder(vector<int>&preOrder, int&index, int min, int max){
    if (index == preOrder.size() || preOrder[index] < min || preOrder[index]>max){
        return NULL;
    }
    Node* root = new Node(preOrder[index]);
    index++;
    root->left = buildFromPreOrder(preOrder, index, min, root->label);
    root->right = buildFromPreOrder(preOrder, index, root->label, max);
    return root;
}

Node* buildFromPostOrder(vector<int>& postOrder, int& index, int min, int max){
    if (index < 0 || postOrder[index] < min || postOrder[index] > max){
        return NULL;
    }
    Node* root = new Node(postOrder[index]);
    index--;
    root->right = buildFromPostOrder(postOrder, index, root->label, max);
    root->left = buildFromPostOrder(postOrder, index, min, root->label);
    return root;

}

Node* buildFromPreOrder(vector<int>& preOrder){
    int index = 0;
    return buildFromPreOrder(preOrder, index, INT_MIN, INT_MAX);
}

Node * buildFromPostOrder(vector<int>& postOrder){
    int index = postOrder.size() - 1;
    return buildFromPostOrder(postOrder, index, INT_MIN, INT_MAX);
}

void print(vector<int> v){
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]){
    vector<int> postOrderTraversal{5, 17, 11, 34, 42, 38, 20};

    cout << "Post order" << endl;
    print(postOrderTraversal);

    Node *root = buildFromPostOrder(postOrderTraversal);

    vector<int> inOrderTraversal;
    inOrder(root, inOrderTraversal);
    
    cout<< "In order"<<endl;
    print(inOrderTraversal);

    vector<int> preOrderTraversal;
    preOrder(root, preOrderTraversal);

    cout << "Pre order" << endl;
    print(preOrderTraversal);


    root = buildFromPreOrder(preOrderTraversal);
    vector<int> result;
    postOrder(root, result);
    
    cout<<"Post order" << endl;
    print(result);

    inOrderTraversal.clear();
    inOrder(root, inOrderTraversal);
    
    cout << "In Order" << endl;
    print(inOrderTraversal);

}
