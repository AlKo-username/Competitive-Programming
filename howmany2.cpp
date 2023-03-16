#include <iostream>
int cube[203][203][203];
int main()
{   std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;
    // int p=0;
    for (int a = 1; a <= n; a++)
    {
        for (int b = 1; b <= n; b++)
        {
            for (int c = 1; c <= n; c++)
            {
                char t;
                std::cin >> t;
               
                cube[a][b][c] = cube[a - 1][b][c] + cube[a][b - 1][c] + cube[a][b][c - 1] + cube[a - 1][b - 1][c - 1] - cube[a - 1][b][c - 1] - cube[a - 1][b - 1][c] - cube[a][b - 1][c - 1];
                 std::cout<<cube[a][b][c]<<" ";
                  if (t == 'G')
                {
                    cube[a][b][c]++;
                    // p++;
                }
            }
        }
    }
    // std::cout<<'\n'<<p;
    while (m-- > 0)
    {
        int a, b, c, x, y, z;
        std::cin >> a >> b >> c >> x >> y >> z;
        int a1 = std::min(a, x), b1 = std::min(b, y), c1 = std::min(c, z), x1 = std::max(a, x), y1 = std::max(b, y), z1 = std::max(c, z);
        std::cout << cube[x1][y1][z1] - (cube[a1 - 1][y1][z1] + cube[x1][b1 - 1][z1] + cube[x1][y1][c1 - 1] - cube[a1-1][b1 - 1][z1] - cube[a1-1][y1][c1 - 1]-cube[x1][b1-1][c1-1]+cube[a1-1][b1-1][c1-1]) << "\n";
    }
    // a1 b1 c1
    // a1 y1 z1
    // a1 y1 c1
    // a1 b1 z1
    // x1 y1 z1
    // x1 b1 z1
    // x1 b1 c1
    // x1 y1 c1
//GGGGGGGGGSSSSSSSSSSSSSSSSSS
    return 0;
}