#include<iostream>
using namespace std;
int main(){
    long long sum=0;
    for (long long i=1; i<=2019; i++)
    {
        if(i%10==2||i%10==0||i%10==1||i%10==9)
        {
            cout<<i<<endl;
            sum = sum+ i*i*i;
            continue;
        }

        if(i>=10){
            if((i/10)%10==2||(i/10)%10==0||(i/10)%10==1||(i/10)%10==9)
            {
                sum = sum +i*i*i;
                cout<<i<<endl;
                continue;
            }
        }
        if(i>100){
            if((i/100)%10==2||(i/100)%10==0||(i/100)%10==1||(i/100)%10==9)
            {
                sum = sum +i*i*i;
                cout<<i<<endl;
                continue; 
            }
        }
        if(i>=1000)
        {
            if((i/1000)%10==2||(i/1000)%10==0||(i/1000)%10==1||(i/1000)%10==9)
            {
                sum = sum +i*i*i;
                cout<<i<<endl;
                continue; 
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}