#include <bits/stdc++.h>
float a, b, s, a1, b1, c1;
int main()
{

    std::cin >> a >> b;
    float hp = a * a + b * b, hyp = sqrt(hp);
    float h = a * b / hyp;
    // std::cout << hyp << "\n";

    for (int i = 0; i < 4; i++)
    {
        std::cin >> a1 >> b1 >> c1;

        if (a1 < hyp)
        {
            // std::cout << "a" << " " << h - h * a1 / hyp << "\n";
            if (c1 <= float(h - h * a1 / hyp))
            {
                std::cout << "1\n";
                continue;
            }
            if (b1 <= float(h - h * a1 / hyp))
            {

                std::cout << "1\n";
                continue;
            }
        }
        if (b1 < hyp)
        {
            // std::cout << "b"   << " " << h - h * b1 / hyp << "\n";
            ;
            if (c1 <= float(h - h * b1 / hyp))
            {
                std::cout << "1\n";
                continue;
            }
            if (a1 <= float(h - h * b1 / hyp))
            {
                std::cout << "1\n";
                continue;
            }
        }
        if (c1 < hyp)
        {
            // std::cout << "c"  << " " << h - h * c1 / hyp << "\n";
            ;
            if (a1 <= float(h - h * c1 / hyp))
            {
                std::cout << "1\n";
                continue;
            }
            if (b1 <= float(h - h * c1 / hyp))
            {
                std::cout << "1\n";
                continue;
            }
        }
        if (a1 < a)
        {
            if (b1 < float(b * (a - a1) / a))
            {
                std::cout << "1\n";
                continue;
            }
            if (c1 < float(b * (a - a1) / a))
            {
                std::cout << "1\n";
                continue;
            }
        }
        if (b1 < a)
        {
            if (a1 < float(b * (a - b1) / a))
            {
                std::cout << "1\n";
                continue;
            }
            if (c1 < float(b * (a - b1) / a))
            {
                std::cout << "1\n";
                continue;
            }
        }
        if (c1 < a)
        {
            if (a1 <= float(b * (a - c1) / a))
            {
                std::cout << "1\n";
                continue;
            }
            if (b1 <= float(b * (a - c1) / a))
            {
                std::cout << "1\n";
                continue;
            }
        }
        if (a1 < b)
        {
            if (b1 < float(a * (b - a1) / b))
            {
                std::cout << "1"
                          << "\n";
                continue;
            }
            if (c1 < float(a * (b - a1) / b))
            {
                std::cout << "1"
                          << "\n";
                continue;
            }
        }
        if (b1 < b)
        {
            if (a1 < float(a * (b - b1) / b))
            {
                std::cout << "1"
                          << "\n";
                continue;
            }
            if (c1 < float(a * (b - b1) / b))
            {
                std::cout << "1"
                          << "\n";
                continue;
            }
        }
        if (c1 < b)
        {
            if (a1 <= float(a * (b - c1) / b))
            {
                std::cout << "1"
                          << "\n";
                continue;
            }
            if (b1 <= float(a * (b - c1) / b))
            {
                std::cout << "1"
                          << "\n";
                continue;
            }
        }
        std::cout << "0\n";
    }

    return 0;
}