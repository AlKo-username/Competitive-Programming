#include <bits/stdc++.h>
struct Point
{
    int x;
    int y;
};
int area(Point &a, Point &b)
{
      std::cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<"\n";
    return (a.y + b.y) * (a.x - b.x) / 2;
}
int main()
{
    std::vector<Point> polygon = {{0, 0}};

    std::string a;
    std::cin >> a;
    int x = 0, y = 0;
    int sh = 1;
    int cnt = 0;
    for (int k = 0; k < a.size(); k++)
    {
        int coord = 0;

        if (a[k - 1] == '+')
        {
            cnt++;
            cnt = cnt % 4;
        }
        else
        {
            cnt--;
            cnt = cnt % 4;
        }
        // std::cout<<a[k]<<"\n";
        while (isdigit(a[k]) && k < a.size())
        {
            coord *= 10;
            coord += a[k] - '0';
            k++;
        }

        if (cnt & 1)
        {
            if (cnt == 3)
            {
                sh = -1;
            }
            else
            {
                sh = 1;
            }
            y += (coord * sh);
            polygon.push_back({x, y});
        }
        else
        {
            if (cnt == 0)
            {
                sh = 1;
            }
            else
            {
                sh = -1;
            }
            x += (coord * sh);
            polygon.push_back({x, y});
        }
    }

    int otg=0;// = area(polygon[polygon.size() - 1], polygon[0]);
    for (int a = 0; a < polygon.size() - 1; a++)
    {
        otg += area(polygon[a], polygon[a + 1]);
    }
    std::cout << std::abs(otg);
    return 0;
}