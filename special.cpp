#include <bits/stdc++.h>
std::vector<long long> specials;

int main(){
    int i=1+1<<4+1<<9;
for(int a=0;a<1e18 && specials.size()<=250;a++){
int k=a*a,t=0;
while(k>0){
t|=1<<k%10;
k/=10;
}
if(t==i){
    specials.push_back(a);
}
}
for(auto p:specials){
    std::cout<<p<<" ";
}
    return 0;

}