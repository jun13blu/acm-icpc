#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n, s, i, j, p[100][52], d[52], a[52];
    char x[5];
    scanf("%d", &n);
    while (n--)
    {
        for (i = 0; i < 52; i++)
        {
            d[i] = i;
        }
        scanf("%d", &s);
        for (i = 0; i < s; i++)
            for (j = 0; j < 52; j++)
                scanf("%d", &p[i][j]);
        scanf("\n");
        while (fgets(x, 5, stdin) && x[0] >= '1' && x[0] <= '9')
        {
            s = atoi(x) - 1;
            for (i = 0; i < 52; i++)
            {
                a[i] = d[p[s][i] - 1];
            }
            for (i = 0; i < 52; i++)
            {
                d[i] = a[i];
            }
        }
        for (i = 0; i < 52; i++)
        {
            switch (a[i] % 13)
            {
            case 12:
                printf("Ace of ");
                break;
            case 11:
                printf("King of ");
                break;
            case 10:
                printf("Queen of ");
                break;
            case 9:
                printf("Jack of ");
                break;
            default:
                printf("%d of ", (a[i] % 13) + 2);
                break;
            }
            switch (a[i] / 13)
            {
            case 0:
                printf("Clubs\n");
                break;
            case 1:
                printf("Diamonds\n");
                break;
            case 2:
                printf("Hearts\n");
                break;
            case 3:
                printf("Spades\n");
                break;
            }
        }
        if (n)
            printf("\n");
    }
    return 0;
}