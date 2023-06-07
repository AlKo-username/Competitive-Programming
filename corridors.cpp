    #include <bits/stdc++.h>
    #include <corridor.h>
    struct step {
    char action;
    int answer;
    };
    step solve(char CellValue){
        char st;
        int s=get_memory(0);
        
        if(s<203){
            if(CellValue=='1'){
            return {t,69};
        }
            set_memory(0,s+1);
            return {r,69};
        }
        int k=get_memory(1);
        if(k==0 && CellValue=='0'){
            return {t,69};
        }
        if(k!=0 && CellValue=='0'){
            set_memory(1,k+1);
            return {r,69};
        }
        if(CellValue=='1'){
            return {a,k};
        }
    }