#include <iostream>

using namespace std;

double n;

int main()
{
    while(true)
    {
        cin>>n;
        if(n == 0)  break;

        double res = 1;
        for(int i=1; i<=4; ++i)
        {
            double temp = 1;
            for(int j=0; j<i; ++j)
            {
                temp *= n;
            }
            res += temp;
        }
        printf("%.2lf\n", res);
    }    
}