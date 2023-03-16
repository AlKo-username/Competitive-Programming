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
    int m;
std::cin>>m;
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
for(auto cp: cubes){
    std::cout<<std::get<0>(cp)<<std::get<1>(cp)<<std::get<2>(cp);
}
for(int k=0;k<m;k++){
int a,b,c,a1,b1,c1;
std::cin>>a>>b>>c>>a1>>b1>>c1;
if(a*a+b*b+c*c>a1*a1+b1*b1+c1*c1){
    std::swap(c,c1);
    std::swap(a,a1);
    std::swap(b,b1);

}
int l1=0,r1=n-1,mid1;
    while(true){
        mid1=(l1+r1)/2;
        if(l1==r1){
            break;
        }
        if(std::get<0>(cubes[mid1])<std::min(a,a1)){
            l1=mid1;

        }else{
            r1=mid1;
        }

    }
    int p=mid1;
    l1=0;
    r1=n-1;
        while(true){
        mid1=(l1+r1)/2;
        if(l1==r1){
            break;
        }
        if(std::get<0>(cubes[mid1])>=std::max(a,a1)){
            l1=mid1;

        }else{
            r1=mid1;
        }

    }
    int p1=mid1;
    std::cout<<p<<" "<<p1;
}
    return 0;
}