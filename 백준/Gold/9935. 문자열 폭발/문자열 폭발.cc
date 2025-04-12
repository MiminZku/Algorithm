#include <iostream>
#include <vector>

using namespace std;

string str;
string bomb;
vector<char> stack;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>str>>bomb;
    for(char ch : str)
    {
        stack.push_back(ch);

        bool isBomb = true;
        for(int i=0; i<bomb.size(); i++)
        {
            
            if(stack.size()-bomb.size()+i < 0
            || stack[stack.size()-bomb.size()+i] != bomb[i])
            {
                isBomb = false;
                break;
            }
        }

        if(isBomb)
        {
            for(int i=0; i<bomb.size(); i++)
            {
                stack.pop_back();
            }
        }
    }

    if(stack.size() == 0)    cout<<"FRULA\n";
    else
    {
        for(char ch : stack)    cout<<ch;
        cout<<endl;
    }

}