#include <bits/stdc++.h>
const inline double pi=3.142;
struct Point{
double x;
double y;
};
std::vector<Point> points,up,down;
bool operator<(const Point &a, const Point &b){
if(a.x<b.x){
    return true;
} else if(a.x==b.x){
    return a.y<b.y;
}
return false;
}
inline double dist(const Point &a, const Point &b){
    return sqrt((double)(a.x-b.x)*(double)(a.x-b.x)+(double)(a.y-b.y)*(double)(a.y-b.y));
}
double oriented(const Point &a, const Point &b, const Point &c){
    return std::abs(a.x-b.x)*(a.y+b.y)+std::abs(b.x-c.x)*(a.y+b.y)-std::abs(a.x-c.x)*(a.y+c.y);
}
int main(){
int n,r;
std::cin>>n>>r;
Point p;
for(int a=0;a<n;a++){
std::cin>>p.x>>p.y;
//p.x+=20000.0;
//p.y+=20000.0;
points.push_back(p);
}
//std::cout<<"\n";
sort(points.begin(),points.end());
for(int a=0;a<n;a++){
   
    while(down.size()>=2 && oriented(down[down.size()-2],down[down.size()-1],points[a])>=0.0) {
        down.pop_back();
    }
    down.push_back(points[a]);
}
for(int a=n-1;a>=0;a--){
   
    while(up.size()>=2 && oriented(up[up.size()-2],up[up.size()-1],points[a])<=0.0) {
        up.pop_back();
    }
    up.push_back(points[a]);
}
// for(int a=0;a<down.size();a++){
//     std::cout<<down[a].x<<" "<<down[a].y<<"\n";
// } 
// std::cout<<"\n";
// for(int a=0;a<up.size();a++){
//     std::cout<<up[a].x<<" "<<up[a].y<<"\n";
// }
double area=2.0*r*pi;
up.insert(up.end(),down.rbegin(),down.rend());
for(int a=0;a<up.size()-1;a++){
    area+=dist(up[a],up[a+1]);
    std::cout<<dist(up[a],up[a+1])<<" "<<up[a].x<<" "<<up[a].y<<"\n";
}

std::cout<</*<<std::fixed<<std::setprecision(3)<<*/area<<"\n";
    return 0;
}
