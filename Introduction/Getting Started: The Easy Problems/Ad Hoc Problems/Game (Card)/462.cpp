#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int i, j, l, point, extra, stop, _stop, max, m;
    char s[5];
    vector<vector<char>> deck(4, vector<char>());
    while (scanf("%s", s) != EOF)
    {
        for (i = 0; i < 4; i++)
            deck[i].clear();
        i = 13;
        while (i--)
        {
            if (s[1] == 'S')
                deck[0].push_back(s[0]);
            else if (s[1] == 'H')
                deck[1].push_back(s[0]);
            else if (s[1] == 'D')
                deck[2].push_back(s[0]);
            else
                deck[3].push_back(s[0]);
            if (i)
                scanf("%s", s);
        }
        point = extra = stop = _stop = max = 0;
        m = 3;
        for (i = 0; i < 4; i++)
        {
            _stop = 0;
            l = deck[i].size();
            if (l >= max)
            {
                if (!(l == max && i > m))
                    m = i;
                max = l;
            }
            for (j = 0; j < l; j++)
            {
                if (deck[i][j] == 'A')
                {
                    point += 4;
                    _stop = 1;
                }
                else if (deck[i][j] == 'K')
                {
                    point += l < 2 ? 2 : 3;
                    if (l > 1)
                        _stop = 1;
                }
                else if (deck[i][j] == 'Q')
                {
                    point += l < 3 ? 1 : 2;
                    if (l > 2)
                        _stop = 1;
                }
                else if (deck[i][j] == 'J' && l > 3)
                    point++;
            }
            stop += _stop;
            if (l == 2)
                extra++;
            else if (l < 2)
                extra += 2;
        }
        if (point > 15 && stop == 4)
            printf("BID NO-TRUMP\n");
        else if (point + extra < 14)
            printf("PASS\n");
        else
            printf("BID %c\n", m == 0 ? 'S' : m == 1 ? 'H' : m == 2 ? 'D' : 'C');
    }
    return 0;
}
