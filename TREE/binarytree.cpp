// H.W : Reverse Order Traversal
// H.W : Preorder,Postorder,Inorder ka iterative approach sa karna hain


#include <iostream>
#include<queue>
using namespace std;
class Node{
  public:
    int d;
    Node* l; //left
    Node* r; //right
    Node(int d){
        this->d=d;
        this->l=NULL;
        this->r=NULL;
    }
};
Node* builtTree(Node* root){
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter data for the left of "<<root->d<<endl;
    root->l=builtTree(root->l);
    cout<<"enter data for the right of "<<root->d<<endl;
    root->r=builtTree(root->r);
    return root;
    
}
void builtTreefromlevel(Node* &root){
    queue<Node*>q;
    cout<<"Enter data for the root"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"Enter The left Child For : "<<temp->d<<endl;
        int ld;
        cin>>ld;
        if(ld!=-1){
            temp->l=new node(ld);
            q.push(temp->l);
        }
        cout<<"Enter The right Child For : "<<temp->d<<endl;
        int rd;
        cin>>rd;
        if(rd!=-1){
            temp->r=new node(rd);
            q.push(temp->r);
        }
    }
}
void levelordertravs(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        cout<<temp->d<<" ";
        q.pop();
        if(temp->l){
            q.push(temp->l);
        }
        if(temp->r){
            q.push(temp->r);
        }
    }
}
void levelordertravn(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL); // NULL as a separator

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){//means phale wala level pura ho chuka hain
            cout<<endl;
            if(!q.empty()){// still child element hain
                q.push(NULL);
            }
        }
        else{
            cout<<temp->d<<" ";
            if(temp->l){
            q.push(temp->l);
        }
        if(temp->r){
            q.push(temp->r);
        }
        }
    }
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
int main() {
    Node* root=NULL;
    //creating a tree
    cout<<"enter the for the root node"<<endl;
    root=builtTree(root);

    // breadth first search // level order traversal using queue
    cout<<endl<<endl<<endl<<endl<<"printing in the line wise"<<endl;
    levelordertravs(root); // all element will be printed in the single line
    cout<<endl<<endl<<endl<<endl<<"printing in the level wise"<<endl;
    levelordertravn(root); // all element will be printed in the new line accoarding to the level to print in the new line we are using the separator for the every level

    // Inorder traversal is 
    cout<<endl<<endl<<" Inorder  "<<endl;
    inorder(root);
    // preorder traversal is 
    cout<<endl<<endl<<" pretorder  "<<endl;
    preorder(root);
    // postorder traversal is 
    cout<<endl<<endl<<" postorder  "<<endl;
    postorder(root);

    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1