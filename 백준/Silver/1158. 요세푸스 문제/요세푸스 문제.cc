#include <iostream>

using namespace std;

class Queue{
public:
    struct Node{
        int data;
        Node* prev;
        Node* next;
        Node(int data) : data(data), prev(nullptr), next(nullptr) {}
    };
    Queue() : size(0),front(nullptr),end(nullptr) {}

    void Push(int data){
        size++;
        if(front){
            end->next = new Node(data);
            end->next->prev = end;
            end = end->next;
        }
        else{
            front = new Node(data);
            end = front;
        }
    }
    void Pop(){
        if(size){
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }
    int Front(){
        return front->data;
    }
    bool Empty(){
        if(size)    return false;
        else        return true;
    }
private:
    Node* front;
    Node* end;
    int size;
};

int main(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    Queue q;
    for(int i=1; i<=n; i++) q.Push(i);
    cout<<'<';
    while(!q.Empty()){
        for(int i=1; i<k; i++){
            int front = q.Front();
            q.Pop();
            q.Push(front);
        }
        int pop = q.Front();
        q.Pop();
        cout<<pop;
        if(q.Empty())   cout<<">\n";
        else            cout<<", ";
    }
}