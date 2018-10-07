#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    char d, q;
    char s[55];
    char r[] = {'S', 'W', 'N', 'E'};
    int i, j, p[4][13], v, k;
    while (scanf("%c\n", &d), d != '#')
    {
        fgets(s, 55, stdin);
        for (i = 0; i < 26; i++)
        {
            v = 0;
            switch (s[i * 2])
            {
            case 'D':
                v += 13;
                break;
            case 'S':
                v += 26;
                break;
            case 'H':
                v += 39;
                break;
            }
            switch (s[i * 2 + 1])
            {
            case 'A':
                v += 12;
                break;
            case 'K':
                v += 11;
                break;
            case 'Q':
                v += 10;
                break;
            case 'J':
                v += 9;
                break;
            case 'T':
                v += 8;
                break;
            default:
                v += s[i * 2 + 1] - '2';
                break;
            }
            p[i % 4][i / 4] = v;
        }
        fgets(s, 55, stdin);
        for (i = 26; i < 52; i++)
        {
            v = 0;
            switch (s[(i - 26) * 2])
            {
            case 'D':
                v += 13;
                break;
            case 'S':
                v += 26;
                break;
            case 'H':
                v += 39;
                break;
            }
            switch (s[(i - 26) * 2 + 1])
            {
            case 'A':
                v += 12;
                break;
            case 'K':
                v += 11;
                break;
            case 'Q':
                v += 10;
                break;
            case 'J':
                v += 9;
                break;
            case 'T':
                v += 8;
                break;
            default:
                v += s[(i - 26) * 2 + 1] - '2';
                break;
            }
            p[i % 4][i / 4] = v;
        }
        if (d == 'E')
            i = 0;
        else if (d == 'N')
            i = 1;
        else if (d == 'W')
            i = 2;
        else
            i = 3;
        for (k = 0; k < 4; k++)
        {
            sort(p[i], p[i] + 13);
            printf("%c:", r[k]);
            for (j = 0; j < 13; j++)
            {
                switch (p[i][j] / 13)
                {
                case 0:
                    q = 'C';
                    break;
                case 1:
                    q = 'D';
                    break;
                case 2:
                    q = 'S';
                    break;
                case 3:
                    q = 'H';
                    break;
                }
                printf(" %c", q);
                switch (p[i][j] % 13)
                {
                case 12:
                    q = 'A';
                    break;
                case 11:
                    q = 'K';
                    break;
                case 10:
                    q = 'Q';
                    break;
                case 9:
                    q = 'J';
                    break;
                case 8:
                    q = 'T';
                    break;
                default:
                    q = '2' + p[i][j] % 13;
                    break;
                }
                printf("%c", q);
            }
            printf("\n");
            i = (i + 1) % 4;
        }
    }
    return 0;
}