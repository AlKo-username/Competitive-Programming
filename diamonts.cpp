#include <bits/stdc++.h>
int prefs[200][200][200];
int main(){
int l,m,n;
std::ios_base::sync_with_stdio(0);
std::cout.tie(0);
std::cin.tie(0);
std::cin>>l>>m>>n;
for(int a=2;a <= n+1;a++){
    for(int b=2; b <= m+1 ; b++){
        for(int c=2; c <= l+1; c++){
            std::cin>>prefs[a][b][c];
        prefs[a][b][c]=prefs[a-1][b-1][c-1]+prefs[a][b][c]+prefs[a-1][b][c]+prefs[a][b-1][c]+prefs[a][b][c-1]-prefs[a][b-1][c-1]-prefs[a-1][b-1][c]-prefs[a-1][b][c-1];
        }
    }
}
int a,b,c,x,y,z;
//
//std::cout<<prefs[n+1][m+1][l+1];
while(std::cin>>c>>b>>a>>z>>y>>x ){
    c++;b++;a++;z++;y++;x++;
    std::cout<<prefs[x][y][z];//-(prefs[x][b-1][z]-prefs[a-1][b-1][z]-prefs[x][b-1][c-1]+prefs[a-1][b-1][c-1])-(prefs[x][y][c-1]-prefs[a-1][y][c-1]-prefs[x][b-1][c-1]+prefs[a-1][b-1][c-1])+prefs[a-1][y][z]<<"\n";
}
    return 0;
}