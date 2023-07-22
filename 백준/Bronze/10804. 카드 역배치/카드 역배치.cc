#include <iostream>

int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

void Flip(int a, int b){
    int len = b-a+1;
    for(int i=0; i<len/2; i++){
        int temp = arr[a+i];
        arr[a+i] = arr[b-i];
        arr[b-i] = temp;
    }
}

int main(){
    int t = 10;
    int a, b;
    while(t--){
        std::cin>>a>>b;
        a--; b--;
        Flip(a,b);
    }
    for(int i : arr)
        std::cout<<i<<' ';
    std::cout<<'\n';
}