#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 100010;
int ph[N], hp[N];
int h[N];

int sz;

void heap_swap(int a, int b)
{
    swap(h[a], h[b]);
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= sz && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    if(u/2 && h[u] < h[u/2])
    {
        heap_swap(u, u / 2);
        up(u / 2);
    }
}

int main()
{
    int n, idx;
    scanf("%d", &n);
    while (n --)
    {
        char op[5];
        int x, k;
        scanf("%s", op);
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            sz ++;
            idx ++;
            h[sz] = x;
            ph[idx] = sz;
            hp[sz] = idx;
            up(sz);
        }
        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, sz);
            sz --;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, sz);
            sz --;
            down(k), up(k);
        }
        else if (!strcmp(op, "C"))
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
}