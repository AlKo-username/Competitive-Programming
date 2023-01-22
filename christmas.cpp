#include <iostream>
#include <vector>
using namespace std;
bool otg[500001];
int fromto[500001];
vector<pair<int, int>> typetwodiabetes;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, r;
    cin >> n >> r;
    while (r-- > 0)
    {
        int from, to, c;
        cin >> from >> to >> c;
        from++;
        to++;
        if (c == 1)
        {
            // cout<<from<<to<<endl;
            fromto[from] = max(fromto[from], to);

            continue;
        }
        if(from==to){cout<<0<<endl;}
        typetwodiabetes.push_back({from, to});
        /*7 3
        0 4 1
        2 5 1
        5 6 2*/
    }
    int the = 0;
    otg[0]=0;
    for (int a = 1; a <= n; a++)
    {
        // cout<<the;
        // cout<<fromto[a];
        if (the != 0)
        {otg[a] = otg[a - 1];
           
        }
        else
        {
            otg[a] = !otg[a - 1]; 
        }
        if (the < fromto[a])
        {
            the = fromto[a];
            //   isitsub.push_back({a,the});
        }
        if (the == a)
        {
            the = 0;
        }
    }
    the = 0;
    for (int i = 1; i <= n; i++)
    {
        if (the != 0)
        {
            if (otg[i] != otg[i - 1])
            {
                for (int b = i - 1; b >= the; b--)
                {
                    fromto[b] = i - 1;
                }
                the = 0;
            }
            else if (i == n)
            {
                for (int b = i; b >= the; b--)
                {
                    fromto[b] = i;
                }
            }
        }
        else
        {
            the = i;
        }
    }

    for (auto p : typetwodiabetes)
    {
        if (fromto[p.first] >= p.second)
        {
            cout << "0" << endl;
            return 0;
        }
    }
    cout << "1" << endl;
    for (int a = 1; a <= n; a++)
    {
        if (otg[a])
        {
            cout << "Y";
            continue;
        }
        cout << "G";
    }
    return 0;
}