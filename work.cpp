#include <bits/stdc++.h>
const int maxn = 1e7, maxk = 1e12;
double squrts[maxk], diffics[maxn], prod;
std::priority_queue<std::pair<double, int>> i;
int programmers[maxn];
int main()
{   std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, k;
    std::cin >> n >> k;
    for (int a = 1; a <= maxk; a++)
    {
        squrts[a] = std::sqrt(a);
    }
    for (int a = 0; a < n; a++)
    {
        std::cin >> diffics[a];
    //    programmers[a] += 1;
      i.push({1/diffics[a],a});
    }
   // k -= n;
   double gainz,newgainz;
   int project;
    while (k-- > 0)
    {
    gainz=i.top().first;
    project=i.top().second;
        i.pop();
        
        programmers[project]++;
        prod += gainz;
        newgainz=(squrts[programmers[project]+1]-squrts[programmers[project]])/diffics[project];
        i.push({newgainz,project});
    }

for(int a=0;a<n;a++){
    std::cout<<programmers[a]<<" ";
}
//std::cout<<prod;
    return 0;
}