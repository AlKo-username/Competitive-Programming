#include <bits/stdc++.h>
int parent[1000000], size[1000000];
int get(int a)
{/*finding the root of the set*/
    //std::cout << a << "\n";
    if (parent[a] != a)
    {
        parent[a] = get(parent[a]);
    }

    return parent[a];
}
void uni(int a, int b)
{/*merging the disjointed sets*/
    a = get(a);
    b = get(b);
    if (size[a] > size[b])
    {
        parent[b] = parent[a];
        size[a] += size[b];
        return;
    }
    parent[a] = parent[b];
    size[b] += size[a];
}
int main()
{
    int n, edges;
    std::cin >> n >> edges;
    for (int a = 0; a < 1000; a++)
    {
        size[a] = 1;
        parent[a] = a;
    }
    for (int c = 0; c < edges; c++)
    {
        int a, b;
        std::cin >> a >> b;
       // std::cout << parent[a] << " " << parent[b] << "\n";
        uni(a, b);
    }
    int queries;
    std::cin >> queries;
    while (queries-- > 0)
    {//queries about whether or not two nodes are in the same set
        int a, b;
        std::cin >> a >> b;
    //   std::cout << get(a) << " " << get(b) << "\n";
        if (get(a) == get(b))
        {
            std::cout << "They are in the same component \n";
        }
        else
        {
            std::cout << "Thet are not in the same component \n";
        }
    }
    return 0;
}
