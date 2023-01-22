#include <iostream>
using namespace std;
int rebra[100][100],n,m,solution[100][100],brpath;
int main(){
cin>>n>>m;
for(int a=0;a<n;a++){
    for(int b=0;b<n;b++){
        if(a!=b){
        solution[a][b]=999999;}else{
            solution[a][b]=0;
        }
    }
}
for(int a=0;a<m;a++){
    int k,j;
    cin>>k>>j;
    cin>>rebra[k][j];
    solution[k][j]=rebra[k][j];
}
for(int a=0;a<n;a++){
    for(int b=0;b<n;b++){
for(int k=0;k<n;k++){

    if(solution[a][b]>(solution[a][k]+solution[k][b])){
        solution[a][b]=solution[a][k]+solution[k][b];
    }
}
    }
}
for(int a=0;a<n;a++){
    for(int b=0;b<n;b++){
cout<<solution[a][b]<<" ";
    }
    cout<<endl;
}
//cout<<brpath;
    return 0;
}
