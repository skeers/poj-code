#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
const int N = 100010;
int arr[N], st[N], l[N], r[N];
int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
        int k = 0;
        for(int i = 1; i <= n; i++)
        {
            while(k > 0 && arr[st[k-1]] >= arr[i]) k--;
            if(k == 0) l[i] = 1;
            else l[i] = st[k-1] + 1;
            st[k++] = i;
        }
        k = 0;
        for(int i = n; i >= 1; i--)
        {
            while(k > 0 && arr[st[k-1]] >= arr[i]) k--;
            if(k == 0) r[i] = n;
            else r[i] = st[k-1] - 1;
            st[k++] = i;
        }
        ll res = -1;
        for(int i = 1; i <= n; i++) res = max(res, (ll)arr[i] * (r[i] - l[i] + 1));
        printf("%lld\n", res);
    }
    return 0;
}