#include <bits/stdc++.h>
std::stack<int> stak1,stak2,stak3,stak4;
int main(){
int k,n,ans=-1000;
//std::cout<<mt19937;
std::cin>>n>>k;
int currin=0;

for(int a=0;a<n;a++){
if(!stak3.empty()){
    stak3.pop();
}
    int o;
    std::cin>>o;
if(stak1.size()<k){
    stak1.push(o);
    if(stak2.empty()){
stak2.push(o);
    }else{
        stak2.push(std::min(o,stak2.top()));

    }
}
if(stak1.size()==k){
    while(!stak3.empty()){
    stak3.push(stak1.top());
    stak4.push(stak2.top());
    stak2.pop();
    stak1.pop();
    }
}

}


    return 0;
}