#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 30 + 5;

char a[maxn];
int n, L, cnt = 0;

void dfs(int d){
    int flag = 0;
    for (int i = 0; i < d; i++){
        for (int j = i; j < d && j + j - i + 1 < d; j++){
            flag = 1;
            for (int k = 0; i + k <= j; k++){
                if (a[i + k] != a[j + 1 + k]){
                    flag = 0;
                    break;
                }
            }
            if (flag)   break;
        }
        if (flag)   break;
    }

    if (!flag){
        cnt++;
        // for (int i = 0; i < d; cout << a[i++] <<  ' ');
        // cout << endl;
        if (cnt == n){
            for (int i = 0; i < d; i++){
                if (i && i % 48 == 0)    cout << endl;
                else if (i && i % 4 == 0)    cout << " ";
                cout << a[i];
            }
            cout << endl;
            return;
        }
    }
    else if (flag == 1)
        return;

    for (int i = 0; i < L && cnt < n; i++){
        a[d] = 'A' + i;
        dfs(d + 1);
    }
}

int main(){
    while (cin >> n >> L && n && L){
        cnt = 0;
        for (int i = 0; i < L && cnt < n; i++){
            a[0] = 'A' + i;
            dfs(1);
        }
    }
    return 0;
}