#include <cstdio>
using namespace std;

int main()
{
    int l, p;
    char s[5];
    while (scanf("%d", &l), l)
    {
        p = 1;
        l--;
        while (l--)
        {
            scanf("%s", s);
            if (s[0] != 'N')
                switch (p)
                {
                case 1:
                    if (s[1] == 'y')
                        p = s[0] == '+' ? 2 : -2;
                    else
                        p = s[0] == '+' ? 3 : -3;
                    break;
                case -1:
                    if (s[1] == 'y')
                        p = s[0] == '+' ? -2 : 2;
                    else
                        p = s[0] == '+' ? -3 : 3;
                    break;
                case 2:
                    if (s[1] == 'y')
                        p = s[0] == '+' ? -1 : 1;
                    break;
                case -2:
                    if (s[1] == 'y')
                        p = s[0] == '+' ? 1 : -1;
                    break;
                case 3:
                    if (s[1] == 'z')
                        p = s[0] == '+' ? -1 : 1;
                    break;
                case -3:
                    if (s[1] == 'z')
                        p = s[0] == '+' ? 1 : -1;
                    break;
                }
        }
        printf("%s\n", p == 1 ? "+x" : p == -1 ? "-x" : p == 2 ? "+y" : p == -2 ? "-y" : p == 3 ? "+z" : "-z");
    }
    return 0;
}