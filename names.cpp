        #include <bits/stdc++.h>
        const int mod=199993;
        uint64_t hesh[200000];
        int main(){
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(0);
            std::cout.tie(0);
        std::string name,maxname;
        int n,max=0;
        int a,b,c;
        std::cout<<a<<" "<<b<<" "<<c;
                std::cin>>n;
        while(n-->0){
        std::cin>>name;
        int hash=0;
        for(int a=0;a<name.size();a++)
        {hash*=53;
        if(name[a]>'a'){
        hash-=5;
        }

        hash+=name[a]-'A';
        hash=hash%mod;
        }
        hesh[hash]++;
        if(hesh[hash]>max){
        
        max=hesh[hash];

        maxname=name;
        }
        }
        std::cout<<maxname;
            return 0;
        }
        /*
        11
        Rich
        Rich
        Bruck
        Rich
        Eric
        Stephanie
        Rich
        Rich
        Sally
        Tailor
        Rich

        */