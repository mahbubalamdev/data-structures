#include<bits/stdc++.h>
using namespace std;

class Node{
    char label;
    vector<Node*> subtrees;

};

void postOrder(Node* root, vector<char> &result){
    if (root == NULL){
        return;
    }
    for (Node *st: root->subtrees ){
        postOrder(st, result);
    }
    result.push_back(root->label);
}

void level(Node* root, int current_level, int target_level, vector<char> &result){
    if(root == NULL){
        return;
    }
    if(current_level == target_level){
        result.push_back(root->label);
        return;
    }
    for(Node *st : root->subtrees){
        level(st, current_level+1, target_level, result);
    }
}

int main(){

    return 0;
}