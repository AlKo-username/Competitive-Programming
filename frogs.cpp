#include <bits/stdc++.h>
const int maxN=1e6;
int towers[maxN],jumps[maxN],lds[maxN],ldsref[maxN];
//std::vector<short int> cringe[maxN];
bool iscurrmax[maxN];
long long read(){
    long long res=0;
    char w=getchar();
    while(!isdigit(w)){
        w=getchar();
    }
    while(isdigit(w)){
        res*=10;
        res+=w-'0';
        w=getchar();
    }
    return res;
}
int main(){
std::ios_base::sync_with_stdio(false);
std::cin.tie(0);
std::cout.tie(0);
int n;
std::cin>>n;
for(int a=1;a<=n;a++){
    std::cin>>towers[a];
}
for(int a=1;a<=n;a++){
    std::cin>>jumps[a];
}
int pt=2;
towers[n+1]=-1;
ldsref[n]=1;
for(int i=n;i>0;i--){
for(int o=i;o<=n;i++){
if(towers[i]<towers[o]){
    
}
}
}
towers[0]=-1;

for(int i=1;i<=n;i++){

}
    

std::cout<<"\n";
// for(int a=1;a<=n;a++){
//     std::cout<<ldsref[a]<<" ";
// }
    return 0;

}