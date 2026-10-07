#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    long long w,d,p;
    bool i = false;
    p = 2LL*2LL*2LL*2LL*3LL*3LL*5LL*5LL*7LL*11LL*13LL*17LL*19LL*23LL;
    w = 0;
    bool f = false;
    while(!i)
    {
        w+=p;
        for(d=50;d>=2;d--)
        {
            if (w % d != 0)
            {
                if (i)
                {
                    i = false;
                    break;
                }
                else if (f == true)
                {
                    f = false;
                    i = true;
                }
                else
                {
                    f = true;
                }

            }
            else
            {
                if (f == true)
                {
                    f = false;
                    break;
                }
            }
        }
    std::cout << w << '\n';
    }   
    std::cout << w << '\n';
    return 0;
}