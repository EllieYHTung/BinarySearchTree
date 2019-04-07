//
//  main.cpp
//  BinarySearchTree
//
//  Created by YunHua Tung on 2019/4/4.
//  Copyright © 2019 YunHua Tung. All rights reserved.
//


#include <iostream>
using namespace std;
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
            _insert(_key, root);
        }
    }
    bool searching(int _key)const{
        if(root==NULL){
            return false;
        }else{
            return _search(_key,root);
        }
    }
    void deletion(int _key){
        if(searching(_key)){
            _delete(getNode(_key));
        }else{
            cout<<_key<<" not exist"<<endl;
        }
    }
    void printInOrder()const{
        if(root==NULL){
            cout<<endl;
        }else{
            _printInOrder(root);
        }
    }
    void printPreOrder()const{
        if(root==NULL){
            cout<<endl;
        }else{
            _printPreOrder(root);
        }
    }
    void printPostOrder()const{
        if(root==NULL){
            cout<<endl;
        }else{
            _printPostOrder(root);
        }
    }
    Node* getParentNode(int _key)const{
        if(searching(_key)){
            return _getParentNode(_key, root);
        }else{
            return NULL;
        }
    }
    Node* getNode(int _key)const{
        if(searching(_key)){
            return _getNode(_key, root);
        }else{
            return NULL;
        }
    }
protected:
    Node* root;
    void _insert(int _key, Node* n){
        if(searching(_key)){
            cout<<"key already exist!"<<endl;
        }else{
            if(n->key >= _key){
                if(n->left==NULL){
                    n->left=new Node(_key);
                    n->left->key=_key;
                }else{
                    _insert( _key, n->left);
                }
            }else if(n->key < _key){
                if(n->right==NULL){
                    n->right=new Node(_key);
                    n->right->key=_key;
                }else{
                    _insert(_key, n->right);
                }
            }
        }
    }
    bool _search(int _key, Node* n)const{
        if(n->key > _key){
            if(n->left==NULL){
                return false;
            }else{
                return _search(_key, n->left);
            }
        }else if(n->key<_key){
            if(n->right==NULL){
                return false;
            }else{
                return _search(_key, n->right);
            }
        }else{
            return true;
        }
    }
    void _delete(Node* n){
        Node* _parentNode=getParentNode(n->key);
        if(n->left==NULL && n->right==NULL){
            if(_parentNode->left==n){
                _parentNode->left=NULL;
            }else{
                _parentNode->right=NULL;
            }
            
            n=NULL;
            delete n;
        }else if(n->left==NULL || n->right==NULL){
            Node* _newChildNode=n->left!=NULL?n->left:n->right;
            if(_parentNode->left==n){
                _parentNode->left=_newChildNode;
            }else{
                _parentNode->right=_newChildNode;
            }
            n=NULL;
            delete n;
            
        }else{
            Node* _nextLeftNode=_getLeftmostEndNode(n->right);
            int _nextLeftKey=_nextLeftNode->key;
            _delete(_nextLeftNode);
            n->key=_nextLeftKey;
        }
        
    }
    void _printInOrder(Node* n)const{
        if(n->left!=NULL){
            _printInOrder(n->left);
        }
        cout<<"->"<<n->key;
        if(n->right!=NULL){
            _printInOrder(n->right);
        }
    }
    void _printPreOrder(Node* n)const{
        cout<<"->"<<n->key;
        if(n->left!=NULL){
            _printPreOrder(n->left);
        }
        if(n->right!=NULL){
            _printPreOrder(n->right);
        }
    }
    void _printPostOrder(Node* n)const{
        if(n->left!=NULL){
            _printPostOrder(n->left);
        }
        if(n->right!=NULL){
            _printPostOrder(n->right);
        }
        cout<<"->"<<n->key;
    }
    Node* _getParentNode(int _key,Node* pn)const{
        Node* subNode=NULL;
        if(pn->key==_key){
            return NULL;
        }else{
            subNode=pn->key>_key?pn->left:pn->right;
            if(subNode->key==_key){
                return pn;
            }else{
                return _getParentNode(_key, subNode);
            }
        }
    }
    Node* _getNode(int _key, Node* n)const{
        if(n->key==_key){
            return n;
        }else{
            n=n->key>_key?n->left:n->right;
            if(n->key==_key){
                return n;
            }
            return _getNode(_key, n);
            
        }
    }
    //n->right must exist in 2-children node, no neeed to take find sibling in consideration.
    Node* _getLeftmostEndNode(Node* n)const{
        if(n->left==NULL){
            return n;
        }
        return _getLeftmostEndNode(n->left);
        
    }
    
};


int main(int argc, const char * argv[]) {
     BST a;
     a.insertion(11);
     a.insertion(6);
     a.insertion(13);
     a.insertion(8);
     a.insertion(3);
     a.insertion(2);
     a.insertion(5);
     a.insertion(7);
     a.insertion(14);
     a.insertion(9);
     a.insertion(12);
     a.insertion(15);
     cout<<"origin tree:"<<endl;
     a.printInOrder();
     cout<<endl;
     a.printPreOrder();
     cout<<endl;
     a.printPostOrder();
     cout<<endl;
 
     cout<<"delete  root:"<<endl;
     a.deletion(11);
     a.printInOrder();
     cout<<endl;
     a.printPreOrder();
     cout<<endl;
     a.printPostOrder();
     cout<<endl;
    
    cout<<"delete  6:"<<endl;
    a.deletion(6);
    a.printInOrder();
    cout<<endl;
    a.printPreOrder();
    cout<<endl;
    a.printPostOrder();
    cout<<endl;
 
    
    return 0;
}

