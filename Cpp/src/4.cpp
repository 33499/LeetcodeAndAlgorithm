#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long f[100];
typedef long long ll;
map<char,ll>mp;

/**
 * 递归快速幂
 */
ll fastpow(ll a,ll n)
{
    if (n == 0) return 1;
    int result = fastpow(a, n >> 1);
    result *= result;
    return (n & 1) ==0 ? result : result * a;
}

/**
 * 非递归快速幂实现 
 */
ll fastPower(ll x, ll n)
{
    ll result = 1;
    while (n != 0){
        if((n & 1) ==1){
            result *= x;
        }
        x *= x;
        n >>= 1;
    }
    return result;
}

int main(){
    ll ans=0;
    char start = 'A';
    for(ll i=1; i<=26; i++){
        mp[start]=i;
        start=start+1;
    }
    string s;
    s="LANQIAO";
    int len=s.length();
    for(ll i=0; i<len; i++)
    {
        ans = ans+mp[s[i]]*fastpow(26,len-i-1);
    }
    cout<<ans;
    return 0;
}