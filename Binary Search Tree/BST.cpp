// Online C++ compiler to run C++ program online
// Insertion TC=O(log(n))
// H.W:- Inorder producer and successor
#include <iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int d;
    Node* l;
    Node* r;
    Node(int d){
        this->d=d;
        l=NULL;
        r=NULL;
    }
};
void levelorder(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    cout<<" Going to print BST"<<endl;
    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->d<<" ";
            if(front->l){
                q.push(front->l);
            }
            if(front->r){
                q.push(front->r);
            }
        }
    }
    cout<<" Printed"<<endl;
}
Node* insertd(Node* root,int d){
    // if root is null
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d<root->d){
        root->l=insertd(root->l,d);
    }
    else{
        root->r=insertd(root->r,d);
    }
    return root;
    
}
void takeinput(Node* &root){
    int d;
    cin>>d;
    while(d!=-1){
        root=insertd(root,d);
        cin>>d;
    }
    cout<<"created"<<endl;
}
void postorder(Node* root){//LRN
    if(root==NULL){
        return;
    }
    postorder(root->l);
    postorder(root->r);
    cout<<root->d<<" ";
}
void preorder(Node* root){//NLR
    if(root==NULL){
        return;
    }
    cout<<root->d<<" ";
    preorder(root->l);
    preorder(root->r);
}
void inorder(Node* root){//LNR
    if(root==NULL){
        return;
    }
    inorder(root->l);
    cout<<root->d<<" ";
    inorder(root->r);
}
int maxValue(Node* root){
        //maximum value ka liya right ma jatha javo jab thak ki right NULL na ho jaya because sab sa bada element right ma hi milenga

    if(root==NULL){
        return NULL;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root-data;
}
int minValue(Node* root){
    //Minimum value ka liya left ma jatha javo jab thak ki left NULL na ho jaya because sab sa chota element left ma hi milenga
    if(root==NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}
int main() {
    // Write C++ code here
    cout<< "Hello world!";
    Node* root=NULL;
    cout<<"enter data to create a bst"<<endl;
    takeinput(root);
    levelorder(root);
     // Inorder traversal is 
    cout<<endl<<endl<<" Inorder  "<<endl;
    inorder(root);
    // preorder traversal is 
    cout<<endl<<endl<<" pretorder  "<<endl;
    preorder(root);
    // postorder traversal is 
    cout<<endl<<endl<<" postorder  "<<endl;
    postorder(root);
    // Max value
    cout<<endl<<endl<<" MaxValue  : "<<maxValue(root)<<endl;
    // Min value
    cout<<endl<<endl<<" MinValue  : "<<minValue(root)<<endl;

    return 0;
}