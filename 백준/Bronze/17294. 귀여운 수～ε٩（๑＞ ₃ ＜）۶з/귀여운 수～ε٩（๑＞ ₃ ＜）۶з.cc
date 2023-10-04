#include <iostream>

using namespace std;

int main()
{
    string str;
    cin>>str;
    bool cute = true;
    if(str.size() > 1)
    {
        int delta = int(str[1]-'0') - int(str[0]-'0');
        for( int i = 2; i<str.size(); i++)
        {
            if(delta != int(str[i]-'0') - int(str[i-1]-'0'))
            {
                cute = false;
                break;
            }
            
        }
    }
    if(cute)    cout<<"◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!\n";
    else        cout<<"흥칫뿡!! <(￣ ﹌ ￣)>\n";
}