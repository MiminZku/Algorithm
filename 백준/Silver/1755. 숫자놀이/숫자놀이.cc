#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, int> dict;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin>>n>>m;
    
    for(int i=n; i<=m; i++)
    {
        vector<string> vec;
        int temp = i;
        while(temp > 0)
        {
            int k = temp % 10;
            temp /= 10;
            switch(k)
            {
            case 0:
                vec.push_back("zero");
                break;
            case 1:
                vec.push_back("one");
                break;
            case 2:
                vec.push_back("two");
                break;
            case 3:
                vec.push_back("three");
                break;
            case 4:
                vec.push_back("four");
                break;
            case 5:
                vec.push_back("five");
                break;
            case 6:
                vec.push_back("six");
                break;
            case 7:
                vec.push_back("seven");
                break;
            case 8:
                vec.push_back("eight");
                break;
            case 9:
                vec.push_back("nine");
                break;
            }
            vec.push_back(" ");
        }
        vec.pop_back();

        string name;
        while(!vec.empty())
        {
            name.append(vec[vec.size()-1]);
            vec.pop_back();
        }

        dict.insert({name, i});
    }

    int cnt = 0;
    for(auto iter = dict.begin(); iter != dict.end(); iter++)
    {
        cout<<iter->second<<' ';
        cnt++;
        if(cnt%10 == 0) cout<<'\n';
    }
    cout<<'\n';
}