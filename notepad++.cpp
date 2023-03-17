#include <bits/stdc++.h>
bool opo[2000000]; int k;
std::vector<int> occurences;

int fimd(int ind, int distancesofar, int taken,int  best){
if(taken==k){
    return best;
}
if(ind==occurences.size()-1){
    return -10000;
}

return std::max(fimd(ind+1, distancesofar+occurences[ind+1]-occurences[ind], taken,best),fimd(ind+1,0,taken+1));
}
int main()
{
    std::string vhod, pat;
   
    std::cin >> vhod >> pat >> k;
    int a = 1, t = 0;
    int mapt[1020];
    while (a < pat.length())
    {
        if (pat[a] == pat[t])
        {
            t++;
            mapt[a] = t;
            a++;
        }
        else
        {
            if (t != 0)
            {
                t = mapt[t - 1];
            }
            else
            {
                a++;
                mapt[a - 1] = 0;
            }
        }
    }
    int patcounter = 0, o = 0;
    
    while ((vhod.length() - o) >= (pat.length() - patcounter))
    {
        std::cout<<o<<" "<<patcounter<<"\n";
        if (vhod[o] == pat[patcounter])
        {
            o++;
            patcounter++;
        }
        if (patcounter == pat.length())
        {
            occurences.push_back(o-pat.length());
            patcounter = mapt[patcounter - 1];
        }
        else if (o < vhod.length() && pat[patcounter] != vhod[o])
        {
            if (patcounter > 0)
            {
                o++;
                patcounter = mapt[patcounter - 1];
            }
            else
            {
                o++;
            }
        }
    }
    int r=occurences.size(); 
    for(auto l:occurences){
        std::cout<<l<<" ";
    }
    // int currbest=occurences[r-1]-occurences[0],bestind;
    // while(r>(k+2)){
       
    //     for(int u=1;u<occurences.size()-1;u++){
    //         int p=u+1;
    //         while(opo[p]){
    //             p++;
    //         }
    //         p--;
    //         if(currbest>occurences[p]-occurences[u]){
    //             currbest=occurences[p]-occurences[u];
    //             bestind=p;
    //         }

    //     }
    //     r--;
    //     opo[bestind]=true;
    // }
    // std::cout<<currbest;
    return 0;
}