#include <iostream>
#include <vector>

using namespace std;

char org[51];
vector<int> nums;
vector<char> opers;

int main(){
    cin>>org;
    char temp[51] = {};
    int idx = 0;
    for(char& c: org){
        if(c){
            if(c=='+' || c=='-'){
                opers.push_back(c);
                int k = 1;
                int n = 0;
                for(int i=idx-1; i>=0; i--){
                    n += (temp[i]-'0') * k;
                    k *= 10;
                }
                idx = 0;
                nums.push_back(n);
            }
            else{
                temp[idx++] = c;
            }
        }
        else{
            int k = 1;
            int n = 0;
            for(int i=idx-1; i>=0; i--){
                n += (temp[i]-'0') * k;
                k *= 10;
            }
            idx = 0;
            nums.push_back(n);
            break;
        }
    }
    for(int i=opers.size()-1; i>=0; i--){
        if(opers[i]=='+'){
            nums[i+1] = nums[i]+nums[i+1];
            nums.erase(nums.begin()+i);
            opers.erase(opers.begin()+i);
        }
    }
    int result = nums[0];
    for(int i=0; i<opers.size(); i++){
        result -= nums[i+1];
    }
    cout<<result<<endl;
}