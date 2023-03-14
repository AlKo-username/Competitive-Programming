#include <bits/stdc++.h>

int main()
{
    std::cout<<"help i need somebody";
    int n;
    std::cin>>n;
    std::string vhod;
    std::string list[100003];
    std::cin>>vhod;
    for(int a=1;a<=n;a++)
    {
        std::cin>>list[a];
    }
    while(n-->0){
        int mapk[100002];
        int k=0;
        mapk[0]=0;
        int i=1;
        while(i<list[n].length()){
            if(list[n][i]==list[n][k]){
                k++;
                i++;
                mapk[i]=k;
            }else{
                if(k!=0){
                    k=mapk[k-1];
                }else{
                   mapk[i]=0;
                    i++;
                }
            }
            std::cout<<mapk[i]<<" ";
        }


    }

    return 0;
}