#include <iostream>
using namespace std;

template <typename T>
class Tree{
public:
    struct Node{
        T value;
        Node* leftChild;
        Node* rightChild;

        Node(T v){
            value = v;
            leftChild = nullptr;
            rightChild = nullptr;
        }
    };
    Tree() {root = nullptr;}
    void Insert(T v){
        if(root){
            Node* temp = root;
            while(true){
                if(v < temp->value){
                    if(temp->leftChild) temp = temp->leftChild;
                    else{
                        temp->leftChild = new Node(v);
                        break;
                    }
                }
                else{
                    if(temp->rightChild) temp = temp->rightChild;
                    else{
                        temp->rightChild = new Node(v);
                        break;
                    }

                }
            }
        }
        else{
            root = new Node(v);
        }
    }
    void PostorderTraverse(Node* node){
        if(node == nullptr) return;
        PostorderTraverse(node->leftChild);
        PostorderTraverse(node->rightChild);
        cout<<node->value<<'\n';
    }
    Node* GetRoot(){
        return root;
    }
private:
    Node* root;
};

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n;
    Tree<int> tree;
    while(cin>>n){
        tree.Insert(n);
    }
    tree.PostorderTraverse(tree.GetRoot());
}