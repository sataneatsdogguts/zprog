#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    double x;
    int cel;
    double drb;
    int p;
    int m;
    std::string r = "";
    int n;

    printf("Введите число, новое основание и кол-во знаков после запятой:");
    std::cin >> x >> p >> m;
        drb = std::modf(x, &x);
        cel = static_cast<int>(x);
        while (cel > 0)
        {
            n = cel % p;
            if (n < 10)
            {
                r = static_cast<char>(n + '0') + r;
            }
            else
            {
                r = static_cast<char>(n+55) + r;
            }
            cel = cel / p;
        }
        if (m > 0 && drb > 0)
        {
            r += ',';
        
        while (m>0)
            {
                drb = drb * p;
                n = std::trunc(drb);
                if (n < 10)
                {
                    r += static_cast<char>(n + '0');
                }
                else
                {
                    r += static_cast<char>(n+55);
                }
                m--;
                    drb = drb - std::trunc(drb);
            }
        }
        std::cout << r << '\n';
    return 0;
}
