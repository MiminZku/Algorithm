#include <iostream>
#include <deque>

using namespace std;

int main(){
    cin.tie(nullptr);   ios::sync_with_stdio(false);
    int n,k;
    cin>>n;
    deque<int> deq;
    while(n--){
        string command;
        cin>>command;
        if(!command.compare("push_front")){
            cin>>k;
            deq.push_front(k);
        }
        else if(!command.compare("push_back")){
            cin>>k;
            deq.push_back(k);
        }
        else if(!command.compare("pop_front")){
            if(deq.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<deq.front()<<'\n';
            deq.pop_front();
        }
        else if(!command.compare("pop_back")){
            if(deq.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<deq.back()<<'\n';
            deq.pop_back();
        }
        else if(!command.compare("size")){
            cout<<deq.size()<<'\n';
        }
        else if(!command.compare("empty")){
            if(deq.empty()) cout<<"1\n";
            else            cout<<"0\n";
        }
        else if(!command.compare("front")){
            if(deq.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<deq.front()<<'\n';
        }
        else if(!command.compare("back")){
            if(deq.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<deq.back()<<'\n';
        }
    }
}