#include <bits/stdc++.h>
const int maxn=1e6;
int parents[maxn],height[maxn],root;

void init (int n, std::vector< std::pair<int,int> > e){
    for(int a=1;a<=n;a++){
        parents[a]=a;
    }
for(int a=0;a<n-1;a++){
    parents[e[a].second]=e[a].first;
    height[e[a].second]=height[e[a].first]+1;
   /// std::cout<<e[a].first<<" "<<e[a].second<<" | ";
}
// std::cout<<"\n";
// for(int a=1;a<=n;a++){
//     std::cout<<height[a]<<" ";
// }
}

bool question (int u, int v){
while(parents[u]!=u){
    u=parents[u];
}

while(parents[v]!=v){ 
       //std::cout<<v<<"\n";
    v=parents[v];

}
//std::cout<<v<<" "<<u<<"\n";
return v==u;
}
void close (int u, int v){
if(height[u]>height[v]){
    parents[v]=v;
    std::cout<<parents[v]<<"a";
}else{
parents[u]=u;
std::cout<<parents[u];}
}
int main(){
init(7, { {1,2}, {1,3},
{1,4}, {4,6}, {4,5},
{6,7} } );
close(1,4);
for(int a=1;a<=7;a++){
    std::cout<<parents[a]<<" ";
}
std::cout<<question(3,5)<<" "<<question(4,7);
close(4,5);
std::cout<<" "<<question(1,2)<<" "<<question(5,7);

    return 0;
}