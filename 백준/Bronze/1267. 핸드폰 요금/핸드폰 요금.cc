#include <iostream>

using namespace std;

int main(){
   cin.tie(nullptr); ios::sync_with_stdio(false);
   int n;
   cin>>n;

   int y=0,m=0;
   while(n--){
      int k;
      cin>>k;
      y += 10 * (k/30+1);
      m += 15 * (k/60+1);
   }

   if(y<m){
      cout<<"Y "<<y<<endl;
   }
   else if(y>m){
      cout<<"M "<<m<<endl;
   }
   else{
      cout<<"Y M "<<y<<endl;
   }
}