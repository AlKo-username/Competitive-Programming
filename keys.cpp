#include <bits/stdc++.h>
std::string vhod[100000];
int main(){
int n;
std::cin>>n;
for(int a=0;a<n;a++){
    std::cin>>vhod[a];
}
sort(vhod, vhod+n-1);
    return 0;
}