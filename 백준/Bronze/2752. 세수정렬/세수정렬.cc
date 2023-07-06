#include <iostream>

int main(){
   int arr[3];
   for(int i=0; i<3; i++){
      std::cin>>arr[i];
   }

   for(int i=0; i<3; i++){
      int min=2147483647, minIdx;
      for(int j=i; j<3; j++){
         if(min >= arr[j]){
            min = arr[j];
            minIdx = j;
         }
      }
      int temp = arr[i];
      arr[i] = arr[minIdx];
      arr[minIdx] = temp;
   }

   for(int i : arr)  std::cout<<i<<' ';
   std::cout<<'\n';
}