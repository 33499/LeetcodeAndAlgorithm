#include <bits/stdc++.h>
using namespace std;
int num;
int Fibonacci(int n)
{
    if(n==1||n==2)
        return 1;
    else
        return Fibonacci(n-1)+Fibonacci(n-2);
}
int main()
{
    // printf("%d", num);
    // printf(numeric_limits<char>);
    // cout<<"char    :"<<numeric_limits<char>::min()<<'-'<<numeric_limits<char>::max()<<'\n';
    // cout<<sizeof(num);
    int n;
    // scanf("%d",&n);
    // printf("%d",Fibonacci(n));
    printf("%d\n",INT_MAX);
    printf("%d\n",INT_MIN);
    printf("%lld\n",pow(2,32));
    for(int i=2; i<30; i++){
        printf("%d值为%.8lf\n",i,Fibonacci(i)*1.0/Fibonacci(i+1));
    }
    
    return 0;
}