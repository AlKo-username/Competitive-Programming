#include <bits/stdc++.h>
const int maxn=2e5+7;
const long long mod=1e8+7,base=28,base2=31;
long long hash[mod],hash2[mod],prefixhash[maxn][10]/*prefixhash2[maxn][10]*/,currmaxind=-1,leftend=0,rightend=0;
long long n,k;
int main(){
    std::string nums;
    std::getline(std::cin,nums);
    int j=0;
    for(;isdigit(nums[j]);j++){
        n*=10;
        n+=nums[j]-'0';
    }
    j++;
    for(;isdigit(nums[j]);j++){
        k*=10;
        k+=nums[j]-'0';
    }
   // std::cout<<n<<" "<<k;
std::string vhod[10];
//std::cin.ignore();
for(int t=0;t<k;t++){
std::getline(std::cin,vhod[t]);
long long hesh=0,hesh2=0;
vhod[t]=vhod[t]+vhod[t];
for(int a=0;a<=(2*n-1);a++){
hesh*=base;
hesh+=vhod[t][a]-'a'+1;
//hesh2*=base2;
//hesh2+=vhod[a]-'a'+1;
hesh=hesh%mod;
//hesh2=hesh2%mod;
//prefixhash2[a][t]=hesh2;
prefixhash[a][t]=hesh;
}
}
int sh;
for(int a=0;a<n;a++){
   // std::cout<<a<<"\n";
    for(int b=0;b<=n;b++){

        for(int i=0;i<k;i++){
            if(a>0){
            hash[prefixhash[a+b][i]-prefixhash[a-1][i]]|=(1<<i);
            sh=hash[prefixhash[a+b][i]-prefixhash[a-1][i]];
           // continue;
            }else{
                hash[prefixhash[a][i]]|=(1<<i);
                sh=hash[prefixhash[a][i]];
            }  
              std::cout<<a<<" "<<b<<" "<<i<<" "<<vhod[i]<<" "<<sh<<"\n";
            if((b+1)>(rightend-leftend+1) && sh==(1<<(k+1)-1)){
                leftend=a;
                rightend=a+b;
                currmaxind=i;
            
                
            }
        }
    }
}
for(;leftend<=rightend;leftend++){
    std::cout<<vhod[leftend][currmaxind];
}
    return 0;
}