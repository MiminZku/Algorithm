#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    string str, word;
    getline(cin, str);
    getline(cin, word);

    int res = 0;
    for(int i=0; i<=int(str.length()) - int(word.length()); i++)
    {
        bool check = true;
        for(int j=0; j<word.length(); j++)
        {
            if(str[i+j] != word[j])
            {
                check = false;
                break;
            }
        }

        if(check)
        {
            res++;
            i += word.length() - 1;
        }
    }
    cout<<res<<endl;
}