//
//  main.cpp
//  BinarySearchTree
//
//  Created by YunHua Tung on 2019/4/4.
//  Copyright © 2019 YunHua Tung. All rights reserved.
//

#include <iostream>
class Node{
public:
    Node(int _key){
        key=_key;
        left=right=NULL;
    }
    int key;
    Node* left;
    Node* right;
};
class BST{
public:
    BST(){
        root=NULL;
    }
    void insertion(int _key){
        if(root==NULL){
            root=new Node(_key);
            root->key=_key;
        }else{
            insert(_key, root);
        }
    }
    bool searching(int _key){
        if(root==NULL){
            return false;
        }else{
            return search(_key,root);
        }
    }
    void deletion(int _key){}
    void printInOrder()const{}
    void printPreOrder()const{}
    void printPostOrder()const{}
    
protected:
    Node* root;
    void insert(int _key, Node* _root){
        if(_root->key >= _key){
            if(_root->left==NULL){
                _root->left=new Node(_key);
                _root->left->key=_key;
            }else{
                insert( _key, _root->left);
            }
        }else if(_root->key < _key){
            if(_root->right==NULL){
                _root->right=new Node(_key);
                _root->right->key=_key;
            }else{
                insert(_key, root->right);
            }
        }
    }
    bool search(int _key, Node* _root){
        if(_root->key > _key){
            if(_root->left==NULL){
                return false;
            }else{
                return search(_key, _root->left);
            }
        }else if(_root->key<_key){
            if(_root->right==NULL){
                return false;
            }else{
                return search(_key, _root->right);
            }
        }else{
            return true;
        }
    }
    
};


int main(int argc, const char * argv[]) {
    BST a;
    a.insertion(3);
    a.insertion(5);
    return 0;
}
