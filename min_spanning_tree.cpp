#include <bits/stdc++.h>
struct edge
{
    int from;
    int to;
    int w;
};
bool operator>(const edge &a, const edge &b)
{
    return a.w > b.w;
}
bool operator<(const edge &a, const edge &b)
{
    return a.w < b.w;
}
bool isnodein[1000000];
std::vector<edge> edges[1000000];

int main(){
std::priority_queue<edge> operational;
std::vector<edge> ans;
int numedges,numnodes;
//std
std::cin>>numnodes>>numedges;
for(int a=0;a<numedges;a++){
    edge k;
    std::cin>>k.from>>k.to>>k.w;
    edges[k.from].push_back(k);
  //  edges[k.to].push_back({k.to,k.from,k.w});

}
for(edge k:edges[0]){
operational.push(k);
}
isnodein[0]=true;
int numin=1;
while(numin<numnodes){
    edge q=operational.top();
    operational.pop();
   std:: cout<<numin;
if(!isnodein[q.to]){
    isnodein[q.to]=true;
    ans.push_back(q);
    numin++;
    for(edge g: edges[q.to]){
      operational.push(g);  
    }
}

}
for(edge p: ans){
    std::cout<<p.from<<" "<<p.to<<"\n";
}
    return 0;
}