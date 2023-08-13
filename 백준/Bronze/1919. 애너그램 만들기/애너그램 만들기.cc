#include <iostream>

using namespace std;

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    int arr1[26]={};
    int arr2[26]={};
    for(char ch : s1)   arr1[ch-'a']++;
    for(char ch : s2)   arr2[ch-'a']++;
    int result = 0;
    for(int i=0; i<26; i++)
    {
        result += abs(arr1[i] - arr2[i]);
    }
    cout<<result<<endl;
}