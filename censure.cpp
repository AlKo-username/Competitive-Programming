    #include <bits/stdc++.h>
    int skips[100007];
    int main(){
        std::cin.tie(0);
        std::cout.tie(0);
        std::ios_base::sync_with_stdio(false);
        std::string in;
        std::cin>>in;
        std::string words[100007];
        int n;
        std::cin>>n;
        for(int a=0;a<n;a++){
            std::cin>>words[a];
        }
        n--;
        for(;n>=0;n--){
            int mapt[100007];
            int o=1,p=0;
            while(o<words[n].length()){
                if(words[n][o]==words[n][p]){
                    o++;  
                    p++;
                    mapt[o]=p;
                }else{
                    if(o!=0){
                        o=mapt[o-1];
                    }else{
                        p++;
                        mapt[p-1]=0;
                    }

                }
            }
            o=0;
            p=0;
            while((in.length()-o)>=(words[n].length()-p)){
                if(in[o]==words[n][p]){
                    p++;
                // o+=skips[o]+1;
                
                }
                if(p==words[n].length()){
                    skips[o-words[n].length()]+=words[n].length(); //std::cout<<words[n]<<o; break;
                }
                if(in[o]==words[n][p-1]){
                    o+=skips[o]+1;
                }
                if(in[o]!=words[n][p] && o<in.length()){
                    if(p>0){
                        o++;
                        p=mapt[p-1];
                    }else{
                        o+=skips[o]+1;;
                    }
                
            }

        }
    for(int a=0;a<in.length();a+=1+skips[a]){

    std::cout<<in[a];

    }
        return 0;
    }