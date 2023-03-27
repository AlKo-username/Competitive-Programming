#include <bits/stdc++.h>
int step=0,p;
int chisla[100000];
int t(int rangei,int rangej,int ind, int stop){
//if(ind*2+2 ind*2+1)
int otg=-1000;
if(rangei=>(ind-1<<stop+1) && rangej<=(ind+1<<(step-stop)-1){
    return chisla[ind];
}
if(rangei=>(ind-1<<stop+1) && !rangej<=(ind+1<<(step-stop)-1){
    return std::max(chisla[ind],t());
}
}
int main(){
int n;
std::cin>>n;
int k=n-1;
while(k>0){
    k=k>>1;
    step++;
}
// std::cout<<k;
// std::cout<<step;
p=1<<step;
for(int a=0;a<p*2-1;a++){
    chisla[a]=-10000;
}
for(int a=0;a<n;a++){
std::cin>>chisla[a+p-1];
}
for(int a=2*p-1-1;a>1;a-=2){
chisla[a/2-1]=std::max(chisla[a],chisla[a-1]);
}
int i,j;
std::cin>>i>>j;


    return 0;
}