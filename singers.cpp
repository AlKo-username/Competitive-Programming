#include <bits/stdc++.h>
const int maxn=2003;
std::bitset<maxn> students[maxn],example,dun;
int n,m;
int main(){
std::cin>>m>>n;
int currsongnum=0;
std::priority_queue<int,std::vector<int>,std::greater<int>> yes,no;
int k;
int b;
while(m-->0){
std::cin>>b;
while(b-->0){
    std::cin>>k;
    yes.push(k);
}
if(yes.top()==1){
    currsongnum++;
    yes.pop();
    example.set(currsongnum);
 //   dun.set(currsongnum);
    while(!yes.empty()){
        students[yes.top()].set(currsongnum);
        yes.pop();
    }
}else{
no=yes;
dun.reset();
while(!no.empty()){
dun|=students[no.top()];
//std::cout<<dun<<"\n";
no.pop();
}
while(!yes.empty()){
    students[yes.top()]|=dun;
    yes.pop();
}
}
}
int t=0;
std::vector<int> ans;
for(int a=2;a<=n;a++){
 //   std::cout<<students[a]<<" "<<example<<"\n";
    if(students[a]==example){
        t++;   
         ans.push_back(a);
    }

}
std::cout<<t<<"\n";
for(auto o:ans){
    std::cout<<o<<" ";
}
return 0;
}