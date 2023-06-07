                #include <bits/stdc++.h>
                //const int mod=199993;
                //uint64_t hesh[200000];
                std::unordered_map<std::string,int> t;
                int main(){
                    std::ios_base::sync_with_stdio(false);
                    std::cin.tie(0);
                    std::cout.tie(0);
                std::string name,maxname;
                int n,max=0,i;
                std::cin>>n;
        std::getline(std::cin,name);
                while(n-->0){
            
                    std::getline(std::cin,name);
                    i=++t[name];

                    if(i>max){
                        max=i;
                        maxname=name;
                    }
                }

                std::cout<<maxname;
                    return 0;
                }
             