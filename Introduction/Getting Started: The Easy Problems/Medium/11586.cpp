#include <cstdio>
using namespace std;

int main()
{
    int n, i, f, m;
    char s[160];
    scanf("%d\n", &n);
    while (n--)
    {
        gets(s);
        f = m = 0;
        for (i = 0; s[i] == 'M' || s[i] == 'F' || s[i] == ' '; i++)
            s[i] == 'M' ? m++ : s[i] == 'F' && f++;
        printf("%sLOOP\n", f == m && f > 1 ? "" : "NO ");
    }
    return 0;
}