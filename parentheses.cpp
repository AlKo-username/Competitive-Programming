#include <bits/stdc++.h>
const int o=5e3+7,mod=1e9+7;
int dp[o][2];
int main(){
std::string vhod,i;
std::cin>>i;
vhod="."+i;

for(int a=1;a<vhod.length();a++){
    dp[a][a&1]=1;
    if(vhod[a]=='?'){
        for(int b=0;b<a;b++){
            if(b>0){
                dp[b][a&1]=dp[b+1][1-a&1]+dp[b-1][1-a&1];
                
            }else{
                dp[b][a&1]=dp[b+1][1-a&1];
            }
            dp[b][a&1]=dp[b][a&1]%mod;
        }
    }else{
          for(int b=0;b<a;b++){
        if(vhod[a]=='('){
            if(b>0){
            dp[b][a&1]=dp[b-1][1-a&1];
            }
        }else{
          dp[b][a&1]=dp[b+1][1-a&1];  
        }
            dp[b][a&1]=dp[b][a&1]%mod;

          }
    }
}
std::cout<<dp[0][(vhod.length()-1)&1];
    return 0;
}