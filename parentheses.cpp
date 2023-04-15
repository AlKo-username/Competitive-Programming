#include <bits/stdc++.h>
const long long o=5e3+7,mod=1e9+7;
long long dp[o][2];
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
std::string vhod;
std::cin>>vhod;

dp[0][0]=1;
for(int a=1;a<=vhod.length();a++){
    dp[a][a&1]=1;
    int t=(a-1)%2;
    if(vhod[a-1]=='?'){
        for(int b=0;b<=a;b++){
         dp[b][a&1]=0;
            if(b>0){
                dp[b][a&1]+=(dp[b+1][t]+dp[b-1][t]);
                dp[b][a&1]=dp[b][a&1]%mod;}
            else{
            dp[b][a&1]+=dp[b+1][t];
        dp[b][a&1]=dp[b][a&1]%mod;}
        }

    }else{
          for(int b=0;b<=a;b++){
            dp[b][a&1]=0;
        if(vhod[a-1]=='('){
          if(b>0){
            dp[b][a&1]+=dp[b-1][t];}
            dp[b][a&1]=dp[b][a&1]%mod;

        }else{
     
          dp[b][a&1]+=dp[b+1][t];  
          dp[b][a&1]=dp[b][a&1]%mod;
        }dp[b][a&1]=dp[b][a&1]%mod;
          }
          
    }
}

std::cout<<dp[0][(vhod.length())&1]%mod;
    return 0;
}