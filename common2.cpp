#include <bits/stdc++.h>
const long long maxn = 1e5 + 4, maxk = 10, mod = 47460409, base = 30;
unsigned long long hesh[mod][4];
long long stepen[maxn];
long long n, k;
std::string vhod[maxk],nums;
int main()
{

    std::getline(std::cin, nums);
    int j = 0;
    for (; isdigit(nums[j]); j++)
    {
        n *= 10;
        n += nums[j] - '0';
    }
    j++;
    for (; isdigit(nums[j]); j++)
    {
        k *= 10;
        k += nums[j] - '0';
    }
    stepen[0] = 1;
    for (int p = 1; p <= n; p++)
    {
        stepen[p] = stepen[p - 1] * base % mod;
    }
    for (int i = 0; i < k; i++)
    {
        std::getline(std::cin, vhod[i]);
    }
    int r = n + 1, l = 0, mid, beginind = 0, str = 0;
    bool works = false;
    int cnt=0;
    while (true)
    {

        mid = (r + l) / 2;
        if (l == r - 1)
        {
            break;
        }
        works = false;
        for (int i = 0; i < k; i++)
        {
            long long hamsh = 0;
            for (int t = 0; t < mid; t++)
            {
                hamsh *= base;
                hamsh += vhod[i][t] - 'a' + 1;
                hamsh %= mod;
            }
            if (i == 0 or hesh[hamsh][cnt]> 0)
            {
                hesh[hamsh][cnt] |= (1 << i);
            }

            if (hesh[hamsh][cnt] == (long long)((1 << k) - 1))
            {
                works = true;
            }

            for (int j = 1; j < n; j++)
            {

                hamsh = (hamsh - stepen[mid - 1] * (long long)(vhod[i][j - 1] - 'a' + 1)) % mod;

                if (hamsh < 0)
                {
                    hamsh += mod;
                }
                hamsh *= base;
                hamsh += vhod[i][(j + mid - 1) % n] - 'a' + 1;
                hamsh %= mod;

                if (i == 0 or hesh[hamsh][cnt] > 0)
                {
                hesh[hamsh][cnt] |= (1 << i);
                }

                if (hesh[hamsh][cnt] == (long long)((1 << k) - 1))
                {

                    works = true;
                }
            }
        }
        if (works)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
        if(cnt<10) cnt++;
    }
    if (mid != 0)
    {
        std::cout << mid;
    }
    else
    {
        std::cout << -1;
    }
    return 0;
}