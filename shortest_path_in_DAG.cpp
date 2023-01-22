#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int rebra[100][100], rebra1, vurhove, k;
bool pushed[100];
vector<int> red;
void funct()
{
   int shee=vurhove;
    for (int a = 0; a < vurhove; a++)
    {
        int b;
        for (b = 0; b < vurhove; b++)
        {
            if (rebra[b][a] != 9999 && !pushed[b])
            {
                break;
            }
        
        if (b ==shee-1)
        {
            
           red.push_back(a);
            pushed[a] = true;
            k++;
         //   cout<<red.back()<<" ";
        }
            }    }
    if (k<vurhove)
    {
        funct();
    }
}
int main()
{

    cin >> vurhove >> rebra1;
    for (int a = 0; a < vurhove; a++)
    {
        for (int b = 0; b < vurhove; b++)
        {
            rebra[a][b] = 9999;
        }
    }
    for (int a = 0; a < rebra1; a++)
    {
        int c, b;
        cin >> c >> b ;
        cin>> rebra[c][b];
        // cout<<"fa";
    }
    funct();
    /*for (int a = 0; a < vurhove; a++)
    {
      cout << red[a]<<" ";
    }*/

    return 0;
}