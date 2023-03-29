// #include <bits/stdc++.h>
// struct Node{
// Node* nexts[26]={nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
// int depth=0;
// bool iswordend=false;
// };
// int main(){
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     std::cout.tie(NULL);
//     std::string vhod,word;
//     std::cin>>vhod;
// int n;
// std::cin>>n;

// Node* root=new Node;
// for(int a=0;a<n;a++){
// std::cin>>word;
// Node* op=root;
// for(int b=0;b<word.length();b++){
//     if(op->nexts[word[b]-'a']==nullptr){
//         op->nexts[word[b]-'a']=new Node;
//         op->nexts[word[b]-'a']->depth=op->depth+1;
//     }
//     op=op->nexts[word[b]-'a'];
// }
// op->iswordend=true;
// }
// for(int a=0;a<vhod.length();a++){
// Node* op=root;
// int b=a;
// for(;b<vhod.length() && op->nexts[vhod[b]-'a']!=nullptr;b++){
// op=op->nexts[vhod[b]-'a'];
// }
// if(op->iswordend){
//     a=b;
// }else{
// std::cout<<vhod[a];
// }

// }
//     return 0;
// }
#include <bits/stdc++.h>
const int mod=1e9+7;
std::unordered_map<int,std::unordered_set<long long>> t;
long long st[100006];
int main(){
std::string vhod;std::cin>>vhod;
st[0]=1;
for(int a=1;a<=vhod.size();a++){
    st[a]=26*st[a-1]%mod;
}
int n;
std::cin>>n;
for(int a=0;a<n;a++){
    long long curr=0;
    std::string word;
    std::cin>>word;
    for(auto i:word){
        curr=curr*26+i-'a';
        curr=curr%mod;
    }
    //std::cout<<curr<<" ";
    t[word.length()].insert(curr);
}
std::string ans;
std::vector<long long> v(1,0);

for(auto u:vhod){
ans+=u;
v.push_back((v.back()*26+u-'a')%mod);
v[v.size()-1]=v[v.size()-1]%mod;
for(auto &y: t){
    
    if(y.first>v.size()){
        continue;
    }
    //std::cout<<y.first;
    
    long long curr=v[v.size()-1]-long(1)*v[v.size()-1-y.first]*st[y.first];
    curr=curr%mod;
    //std::cout<<curr<<"\n";
    if(curr<0){curr+=mod;}
    if(y.second.find(curr)!=y.second.end()){
        
        for(int o=0;o<y.first;o++){
            v.pop_back();
            ans.pop_back();
           // std::cout<<".";
        }
    }
}
}
std::cout<<ans;
    return 0;

}
// trumpisomegahugegaycringeaaaadfe
// 3
// trump
// dfe
// gah