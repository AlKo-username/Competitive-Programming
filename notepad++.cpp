#include <bits/stdc++.h>
#pragma gcc optimize("03")
int k;
// std::vector<int> occurences;
int a = 1, t = 0;
int mapt[1020], occurences[500000], numocs;
std::string vhod, pat;
int patcounter = 0, o = 0;
int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> vhod >> pat >> k;

    int  m = vhod.length();
    while (a < pat.length())
    {
        if (pat[a] == pat[t])
        {
            t++;
            mapt[a] = t;
            a++;
        }
        else
        {
            if (t != 0)
            {
                t = mapt[t - 1];
            }
            else
            {
                a++;
                mapt[a - 1] = 0;
            }
        }
    }

    while ((m - o) >= (pat.length() - patcounter))
    {
        // std::cout<<o<<" "<<patcounter<<"\n";
        if (vhod[o] == pat[patcounter])
        {
            o++;
            patcounter++;
        }
        if (patcounter ==pat.length())
        {
            occurences[numocs] = o;
            numocs++;
            patcounter = mapt[patcounter - 1];
        }
        else if (o < m && pat[patcounter] != vhod[o])
        {
            if (patcounter != 0)
            {

                patcounter = mapt[patcounter - 1];
            }
            else
            {
                o++;
            }
        }
    }
    int l = 0, r = 50000, mid = 70;
    // std::cout<<numocs;
    // for(int p=0;p<numocs;p++){
    //     std::cout<<occurences[p]<<"\n";
    // }
    while (true)
    {
        // std::cout<<l<<" "<<r<<" "<<mid<<"\n";
        mid = (r + l) / 2;
        if (r == l + 1)
        {
            break;
        }
        int last = 0, acc = 1;
        bool doeswork = false;
        for (int a = 1; a < numocs; a++)
        {
          //  std::cout<<"gay balls";
            if ((occurences[a] - occurences[last]-pat.length()) >= mid)
            {
                acc++;
                last = a;
            }
            if (acc == k)
            {
                doeswork = true;
                break;
            }
        }
        if (doeswork)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    std::cout << mid;
    return 0;
}