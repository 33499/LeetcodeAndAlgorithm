#include<bits/stdc++.h>
using namespace std;
int iszhi(int t){
    int flag = 0;
    for(int i = 2; i<=sqrt(t); i++){
        if(t%i == 0 && t!= 2){
            flag =1;
            break;
        }
    }
    return flag;
}
int main(){
    int num=0;
    int i;
    for(i=2; i<100000; i++){
        if(iszhi(i)==0){
            num++;
            if(num==2019){
                break;
            }
            
        }
    }
    cout<<i;
    return 0;
}