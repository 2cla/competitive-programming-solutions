#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll MOD = 1e9+7;
ll d[60][90][90];
ll st[90];
ll st2[90];

int main() {
    ll a,b,ans;
    scanf("%llu%llu", &a,&b);
    for (int i=0;i<90;i++) {
        for (int j=0;j<10;j++) {
            if (j==i%10) continue;
            d[0][i][((i/10+j)%9)*10+j]++;
        }
    }
    for (int z=1;z<60;z++) {
        for (int i1=0;i1<90;i1++) {
            for (int i2=0;i2<90;i2++) {
                for (int i3=0;i3<90;i3++) {
                    d[z][i1][i2] += d[z-1][i1][i3]*d[z-1][i3][i2] % MOD;
                }
                d[z][i1][i2] %= MOD;
            }
        }
    }
    memset(st, 0, sizeof(st)); st[0] = 1; ans = 0;
    if (a>2) {
        a -= 2; 
        for (int c=0;c<60;c++) {
            if (a&(1ULL<<c)) {
                memset(st2, 0, sizeof(st2));
                for (int i1=0;i1<90;i1++) {
                    for (int i2=0;i2<90;i2++) {
                        st2[i1] += st[i2]*d[c][i2][i1] % MOD;
                    }
                }
                for (int w=0;w<90;w++) {
                    st[w] = st2[w] % MOD;
                }
            }
        }
        for (int i1=0;i1<90;i1++) {
            for (int i2=0;i2<10;i2++) {
                for (int i3=0;i3<10;i3++) {
                    if (((i1/10)*100+i2*10+i3) % 225 == b) {
                        if (i1%10 == i2 or i2 == i3) continue;
                        ans += st[i1] % MOD;
                    }
                }
            }
        }
    } else if (a==2) {
        for (int i2=1;i2<10;i2++) {
            for (int i3=0;i3<10;i3++) {
                if ((i2*10+i3)%225 == b) {
                    if (i2 == i3) continue;
                    ans++;
                }
            }
        }
    } else {
        for (int i3=1;i3<10;i3++) {
            if (i3%225 == b) ans++;
        }
    }
    printf("%llu", ans % MOD);
    return 0;
}