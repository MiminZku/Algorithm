#include <iostream>

using namespace std;

int main(){
   int sum = 0;
   int min = 100;
   int n=7, k;
   while(n--){
      cin>>k;
      if(k%2){
         sum += k;
         if(min>k)   min = k;
      }
   }
   if(sum)  cout<<sum<<endl<<min<<endl;
   else     cout<<"-1\n";
}