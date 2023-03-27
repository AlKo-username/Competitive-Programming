#include <iostream>

int chisla[500002];
int segment[(1<<18)+1];

int gcd(int a,int b){
if(a<b){std::swap(a,b);}
int t;
while(b>0){
t=b;
b=a%b;
a=t;
}
    return a;
}

int main(){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);
int n,k;
std::cin>>n>>k;
//int t=n-1,step=0;
// while(t>0){
//    // std::cout<<t<<" "<<t<<"\n";
//     t=t>>1;
//     step++;
// }
//std::cout<<step;
//t=1<<step;
//std::cout<<gcd(0,13)<<" "<<gcd(85,289);
for(int a=1;a<=n;a++){
std::cin>>chisla[a];
}
int currnod=chisla[1],i;
for(int a=1;a<=n;a++){
if(chisla[a]>=k){
    i=gcd(chisla[a],currnod);
    //std::cout<<chisla[a]<<" "<<i<<" "<<currnod<<"\n";
    if(i>=k){
        currnod=i;
        segment[a]=segment[a-1]+1;
    }else{
        currnod=chisla[a];
        segment[a]=1;
    }
}else{
    currnod=10e9+7;
}
}
//std::cout<<segment[t];
// for(int a=n-1;a>0;a--){

// segment[a]=std::max(segment[a*2],segment[a*2+1]);
// }
//std::cout<<segment[t];
// for(int a=0;a<t+n;a++){
//     std::cout<<segment[a]<<" "<<a<<"\n";
// }
int q,l,r;
std::cin>>q;
for(int w=0;w<q;w++){
std::cin>>l>>r;
// l=r+t-1;
// r=r+t-1;
int currmax=0,f=l;
for(;  l<=r;l++){
    if(segment[l]==0){
        break;
    }
    if(segment[l]==1){
    break;
    }
currmax=std::max(currmax,(segment[l]-segment[f]+1));
}
for(;l<=r;l++){
    currmax=std::max(currmax,(segment[l]));
}
// for(; l<r;r<<1, l<<1)
// {
// if(l&1){currmax=std::max(currmax , (segment[l++]));}
// if(r&1){currmax=std::max(currmax , segment[--r]);}else{
//     currmax=std::max(currmax,segment[r-=2]);
    
// }

std::cout<<currmax<<"\n";
}
    return 0;
}