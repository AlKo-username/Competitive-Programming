#include <bits/stdc++.h>
typedef long long ll;
const long long maxn=1e9;
int n,m;
long long pow(long long &a, long long st){
    ll otg=1;
    while(st-->0){
    otg*=a;
    }
    return otg;
}
long long cringeaah(long long p,ll element){
  // std::cout<<p<<" "<<element<<"\n";
    ll otg=1;
    if(element!=n){
    for(int a=2;pow(a,element+1)<=p;a++){
        
        otg+=cringeaah(a,element+1);
        //std::cout<<a<<" ";
    }
    }
    return otg;

}
int main(){
//std::cout<<pow(ll(2),ll(10));
std::cin>>n>>m;
long long truth=1;
for(int a=2;a<=m;a++){
truth+=cringeaah(a,1);
}
std::cout<<truth;
    return 0;
}