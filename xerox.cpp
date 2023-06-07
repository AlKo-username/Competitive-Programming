    #include <bits/stdc++.h>
    const int maxn=1e5+7;
    long long minutes[maxn],n,b;
    int main(){
    std::cin>>n>>b;
    for(int a=0;a<n;a++){
        std::cin>>minutes[a];
    }
    long long minutesSpent=0,currPeople=0,zero=0;
    for(int a=0;a<n;a++){
        currPeople+=minutes[a];
        minutesSpent+=currPeople;
        currPeople=std::max(zero,currPeople-b);
    }
    std::cout<<minutesSpent+currPeople;
        return 0;
    }