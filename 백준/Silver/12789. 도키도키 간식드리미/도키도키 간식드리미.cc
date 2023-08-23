#include <iostream>
#include <deque>

using namespace std;

int N;
deque<int> input;
deque<int> temp;

bool Check()
{
    int nextNum = 1;
    while(nextNum <= N)
    {
        if(!input.empty() && input.front() == nextNum)
        {
            nextNum++;
            input.pop_front();
            continue;
        }
        else if(!temp.empty() && temp.back() == nextNum)
        {
            nextNum++;
            temp.pop_back();
            continue;
        }

        while(!input.empty() && input.front() != nextNum)
        {
            temp.push_back(input.front());
            input.pop_front();
        }
        if(input.empty())
        {
            if(temp.back() == nextNum)
            {
                nextNum++;
                temp.pop_back();
            }
            else
            {
                return false;
            }
        }
        else
        {
            nextNum++;
            input.pop_front();
        }
    }
    return true;
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>N;

    for(int i=0; i<N; i++)
    {
        int k;
        cin>>k;
        input.push_back(k);
    }

    if(Check()) cout<<"Nice\n";
    else        cout<<"Sad\n";
}