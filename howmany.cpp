#include <bits/stdc++.h>


std::vector<std::tuple<int, int, int>> cubes;
bool sortbysec(const std::tuple<int, int, int> a, const std::tuple<int, int, int> b)
{
    return std::get<1>(a) < std::get<1>(b);
}
bool sortbythird(const std::tuple<int, int, int> a, const std::tuple<int, int, int> b)
{
    return std::get<2>(a) < std::get<2>(b);
}
int main()
{
    int n;
    std::cin >> n;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            for (int c = 0; c < n; c++){
               char p;
               std::cin>>p;
               if(p=='G'){
                cubes.push_back({a,b,c});
               }

            }
        }
    }
sort(cubes.begin(),cubes.end());
int m;
std::cin>>m;
for(int p=0;p<m;p++){


    
}
    return 0;
}