//Approach : First we will build the tree
//Now we will Traverse all the boundary node and will give alternative color to them
//Now will give  Green color to the remaining node which do not have any color

//Time Complexity = O(N)
//Space Complexity = O(N)


//Code will start from here

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    Node* Left;
    Node* Right;
    char Color;
    int Number;

    Node(int d) {
        this->Number = d;
        this->Left = nullptr;
        this->Right = nullptr;
        this->Color = 'U';
    }

    void setColor(char C) {
        this->Color = C;
    }
};

static void TreeColor(Node *tree) {

    queue<Node*> q;
    q.push(tree);
    q.push(nullptr); // nullptr as a separator

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == nullptr) { // means the previous level is complete
            cout << endl;
            if (!q.empty()) { // still child elements are there for the next levels
                q.push(nullptr);
            }
        } else {
            cout << temp->Number << "-"<<temp->Color<<" "; // to Add a space after each number
            if (temp->Left) {
                q.push(temp->Left);
            }
            if (temp->Right) {
                q.push(temp->Right);
            }
        }
    }
}

void builtTreefromlevel(Node* &root) {
    queue<Node*> q;
    cout << "Enter data for the root (or -1 for no child)" << endl;
    int data;
    cin >> data;
    if(data==-1){
        root=nullptr;
        return ;
    }
    root = new Node(data);
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << "Enter the left child for: " << temp->Number << " (or -1 for no child)" << endl;
        int ld;
        cin >> ld;
        if (ld != -1) {
            temp->Left = new Node(ld);
            q.push(temp->Left);
        }
        cout << "Enter the right child for: " << temp->Number << " (or -1 for no child)" << endl;
        int rd;
        cin >> rd;
        if (rd != -1) {
            temp->Right = new Node(rd);
            q.push(temp->Right);
        }
    }
}



void Paint_center(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp->Color=='U')
                temp->setColor('G');

        if (temp && temp->Left) {
            q.push(temp->Left);
        }
        if (temp && temp->Right) {
            q.push(temp->Right);
        }
        }
}



void left(Node* root,vector<Node*>&ans){

        if(root==NULL || (root->Left==NULL && root->Right==NULL)){
            return;
        }
        ans.push_back(root);
        if(root->Left){
         left(root->Left,ans);
        }
        else{
            left(root->Right,ans);
        }
    }
    void right(Node* root,vector<Node*>&ans){
        if(root==NULL || (root->Left==NULL && root->Right==NULL)){
            return;
        }
        if(root->Right){
         right(root->Right,ans);
        }
        else{
            right(root->Left,ans);
        }
        ans.push_back(root);
    }
    void leaf(Node* root,vector<Node*>&ans){
        if(root==NULL){
            return;
        }
        if(root->Left==NULL && root->Right==NULL){
            ans.push_back(root);
            return;
        }
        leaf(root->Left,ans);
        leaf(root->Right,ans);
        //only leaf ko hi store karna hain jo ki hum already store kar chuka hain jub hamna is function ko return kiya hain
    }
vector <Node*> boundary(Node *root)
    {
        vector<Node*>ans;
        ans.push_back(root);
        if(root==NULL || (root->Left==NULL && root->Right==NULL)){// case when root is null or single node in a tree
            return ans;
        }
        left(root->Left,ans);
        leaf(root,ans);
        right(root->Right,ans);
        return ans;

    }
int main() {
    Node* root = nullptr;
    cout << "First, we will build the tree" << endl;
    builtTreefromlevel(root);
    if(root!=nullptr){
        cout <<endl<< "Going to traverse the tree" << endl << endl;

        vector<Node*> corner = boundary(root);

        for(int i=0; i<corner.size(); i++){
            if ((i+1) % 2 == 0)
                corner[i]->setColor('R');
            else
                corner[i]->setColor('B');

        }
        Paint_center(root);

        TreeColor(root);

    }
    else
        cout<<"No Tree";
    return 0;
}

