#include <iostream>

using namespace std;

struct Node{
    char ch;
    Node* left;
    Node* right;

    Node(char ch) : ch(ch),left(nullptr),right(nullptr) {}
};
Node* strHead;
Node* cursor;

void AddNode(char ch){
    if(cursor){
        Node* newNode = new Node(ch);
        newNode->left = cursor->left;
        newNode->right = cursor;
        if(cursor->left)    cursor->left->right = newNode;
        cursor->left = newNode;
    }
    else{
        strHead = new Node(ch);
        cursor = new Node('I');
        strHead->right = cursor;
        cursor->left = strHead;
    }
}
void Delete(){
    if(cursor->left){
        Node* temp = cursor->left;
        if(temp->left)  temp->left->right = temp->right;
        cursor->left = temp->left;
        delete temp;
    }
}
void MoveCursorLeft(){
    if(cursor->left){
        if(cursor->right) cursor->right->left = cursor->left;
        cursor->left->right = cursor->right;
        cursor->right = cursor->left;
        cursor->left = cursor->left->left;
        if(cursor->left)    cursor->left->right = cursor;
        cursor->right->left = cursor;
    }

}
void MoveCursorRight(){
    if(cursor->right){
        if(cursor->left) cursor->left->right = cursor->right;
        cursor->right->left = cursor->left;
        cursor->left = cursor->right;
        cursor->right = cursor->right->right;
        if(cursor->right)    cursor->right->left = cursor;
        cursor->left->right = cursor;
    }
}
void PrintStr(){
    Node* temp = cursor;
    while(temp->left)   temp=temp->left;
    while(temp){
        if(temp->ch != 'I')
            cout<<temp->ch;
        temp = temp->right;
    }
    cout<<'\n';
}

char str[500001];
int m;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>str;
    for(int i=0; str[i]!=0; i++){
        AddNode(str[i]);
    }
    
    cin>>m;
    while(m--){
        char ch;
        cin>>ch;
        if(ch == 'L'){
            MoveCursorLeft();
        }
        else if(ch == 'D'){
            MoveCursorRight();
        }
        else if(ch == 'B'){
            Delete();
        }
        else if(ch == 'P'){
            char ch2;
            cin>>ch2;
            AddNode(ch2);
        }
    }
    PrintStr();
}