#include <bits/stdc++.h>
const long long maxn = 1e5 + 4, maxk = 10, mod = 1e8 + 7, base = 30;
unsigned long long hesh[mod];
long long stepen[maxn];
int n, k;
std::string vhod[maxk];
int main()
{
    std::string nums;
    std::getline(std::cin,nums);
    int j=0;
    for(;isdigit(nums[j]);j++){
        n*=10;
        n+=nums[j]-'0';
    }
    j++;
    for(;isdigit(nums[j]);j++){
        k*=10;
        k+=nums[j]-'0';
    }
    stepen[0] = 1;
    for (int p = 1; p <= n; p++)
    {
        stepen[p] = stepen[p - 1] * base % mod;
    }
    for (int i = 0; i < k; i++)
    {
        std::getline(std::cin, vhod[i]);
        vhod[i] += vhod[i];
    }
    int r = n, l = 1, mid, beginind = 0, str = 0;
    bool works = false;
    while (true)
    {
      //  std::cout<<l<<" "<<r<<"\n";
        mid = (r + l) / 2;
        if(l==r-1){
            break;
        }
        for (int i = 0; i < k; i++)
        {
            long long hamsh = 0;
            for (int t = 0; t < mid; t++)
            {
                hamsh *= base;
                hamsh += vhod[i][t] - 'a' + 1;
                hamsh %= mod;
              //  std::cout<<vhod[i][t]<<"\n";
            }
            hesh[hamsh] |= (1 << i);
            if (hesh[hamsh] == (1 << (k + 1) - 1))
            {
                works = true;
                beginind = 0;
                str = i;
                std::cout<<str<<" "<<beginind<<" "<<mid<<" "<<hesh[hamsh]<<"\n";
            }
            //std::cout<<hamsh<<" ";
            for (int j = mid; (j + mid - 1) < (2 * n - 1); j++)
            {
                for(int o=j;o<mid+j-1;o++){
                    std::cout<<vhod[i][o];
                }
               // std::cout<<"\n";
                hamsh = (hamsh-stepen[mid] * (vhod[i][j - mid] - 'a' + 1)) % mod;
               
                if(hamsh<0){
                    hamsh+=mod;
                } std::cout<<" "<<hamsh<<"\n";
                hamsh *= base;
                hamsh += vhod[i][j] - 'a' + 1;
                hamsh %= mod;
              //  std::cout<<hamsh<<" ";
                hesh[hamsh] |= (1 << i);
                if (hesh[hamsh] == (1 << (k + 1) - 1))
                {
                    works = true;
                    beginind = j;
                    str = i;
                }
            }
        }
        if (works)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    for(int a=beginind;a<(mid+beginind);a++){
        std::cout<<vhod[str][a];
    }
    return 0;
}