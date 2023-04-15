#include <bits/stdc++.h>
#define pp std::pair<int,int>
#define x first
#define y second
std::vector<pp> i;
pp p0={10000,10000};
int orientation(const pp &a,const pp &b,const pp &c){
    int s=(b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);
    if(s==0){ return 0;
    }
    if(s>0){return 1;}
    return -1;
}
bool compare(const pp b, const pp c){
int o=(orientation(p0,b,c));
if(o==0){
return (b.x-p0.x)*(b.x-p0.x)-(b.y-p0.y)*(b.y-p0.y)>=(c.x-p0.x)*(c.x-p0.x)-(c.y-p0.y)*(c.y-p0.y);
}else{
    if(o==1){
        return true;
    }
return false;
}
}

int main(){
int n,minind=0;
//std::cin>>n;
pp o;
int k=0;

// while(scanf("%d %d", &o.first,&o.second)==2){
 std::cin>>n;
 for(int a=0;a<n;a++){
    std::cin>>o.first>>o.second;
    if(o<p0){
p0=o; 
minind=k;
    }
    i.push_back(o);
    k++;
}
std::swap(i[minind],i[0]);
int m=1;for(int a=0;a<n;a++){
    std::cout<<i[a].first<<" "<<i[a].second<<"\n";
}
std::sort(i.begin()+1,i.end(),compare);
for(int k=1;k<i.size();k++){
    while(k<i.size()-1 && orientation(p0,i[k],i[k+1])==0){
        k++;
    }
    i[m]=i[k];
    m++;
}
std::cout<<m;

std::vector<pp> ans;
ans.push_back(i[0]);
ans.push_back(i[1]);
ans.push_back(i[2]);

for(int u=3;u<m;u++){
    while(ans.size()>1 && orientation(ans[ans.size()-1],ans[ans.size()-2],i[u])==-1){
        ans[ans.size()-1]=i[u];
    }   
}
for(auto u:ans){
    std::cout<<u.first<<u.second<<"\n";
}
int otg=0;
for(int q=1;q<ans.size();q++){
otg+=sqrt((ans[q].x-ans[q-1].x)*(ans[q].x-ans[q-1].x)-(ans[q].y-ans[q-1].y)*(ans[q].y-ans[q-1].y));
}
otg+=sqrt((ans[0].x-ans[ans.size()-1].x)*(ans[0].x-ans[ans.size()-1].x)-(ans[0].y-ans[ans.size()-1].y)*(ans[0].y-ans[ans.size()-1].y));
std::cout<<otg;
    return 0;
}