#include <bits\stdc++.h>
int parents[10000], size[10000];
struct edge
{
    int from;
    int to;
    int w;
};
bool operator>(const edge &a, const edge &b)
{
    return a.w > b.w;
}
bool operator<(const edge &a, const edge &b)
{
    return a.w < b.w;
}
int get(int a)
{   /*finding the root of the set*/
    //   std::cout << parents[a]<< "\n";
    if (parents[a] != a)
    {
        parents[a] = get(parents[a]);
    }

    return parents[a];
}
void uni(int a, int b)
{ /*merging the disjointed sets*/
    a = get(a);
    b = get(b);
    if (size[a] > size[b])
    {
        parents[b] = parents[a];
        size[a] += size[b];
        return;
    }
    parents[a] = parents[b];
    size[b] += size[a];
}
std::vector<edge> edges;
int main()
{

    int numedges, numnodes;

    std::cin >> numnodes >> numedges;
    for (int a = 0; a < numedges; a++)
    {
        parents[a] = a;
        // std::cout<<parents[a];
        size[a] = 1;
    }
    for (int a = 0; a < numedges; a++)
    {
        edge k;
        std::cin >> k.from >> k.to >> k.w;
        edges.push_back(k);
    }
    sort(edges.begin(), edges.end());
    std::vector<edge> ans;
    for (auto i : edges)
    {
        //   std::cout<<get(i.to)<<" "<<get(i.from)<<" "<<i.w<<"\n";
        if (get(i.from) == get(i.to))
            continue;

        uni(i.from, i.to);
        ans.push_back(i);
        // traverse backwards for max spanning tree
    }
    for (auto o : ans)
    {
        std::cout << o.from << " " << o.to << "\n";
    }
    return 0;
}