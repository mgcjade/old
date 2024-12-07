#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
#define int long long

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, Q;
struct Segment_Tree
{
    int start, end;
    int need;  // how many wight do we need for take out all the books from start to end
    int color; // if the color from start to end is the same, the color of it.else, 0
    int lson, rson;
};
Segment_Tree tree[N << 2];
int books[N];
int color[N];
int wight[N];
int cnt;

void pushup(int k)
{
    tree[k].color = tree[tree[k].lson].color == tree[tree[k].rson].color ? tree[tree[k].lson].color : 0;
    tree[k].need = tree[tree[k].lson].need + tree[tree[k].rson].need;
    if (color[tree[tree[k].lson].end] == color[tree[tree[k].rson].start])
        tree[k].need -= min(books[tree[tree[k].lson].end], books[tree[tree[k].rson].start]) * (wight[tree[tree[k].lson].end] + wight[tree[tree[k].rson].start]);
}
void build(int k)
{
    if (tree[k].start == tree[k].end)
    {
        tree[k].need = wight[tree[k].start] * books[tree[k].start] * 2;
        tree[k].color = color[tree[k].start];
        return;
    }
    tree[k].lson = ++cnt, tree[k].rson = ++cnt;
    int mid = (tree[k].start + tree[k].end) >> 1;
    tree[tree[k].lson].start = tree[k].start, tree[tree[k].lson].end = mid;
    tree[tree[k].rson].start = mid + 1, tree[tree[k].rson].end = tree[k].end;
    build(tree[k].lson), build(tree[k].rson);
    pushup(k);
}
void rebuild(int k)
{
    if (tree[k].start == tree[k].end)
    {
        tree[k].need = wight[tree[k].start] * books[tree[k].start] * 2;
        tree[k].color = color[tree[k].start];
        return;
    }
    rebuild(tree[k].lson), rebuild(tree[k].rson);
    pushup(k);
}
int count(int l, int r, int k)
{
    if (tree[k].start > r || tree[k].end < l)
        return 0;
    if (l <= tree[k].start && tree[k].end <= r)
        return tree[k].need;
    int a = count(l, r, tree[k].lson), b = count(l, r, tree[k].rson);
    int res = a + b;
    if (a != 0 && b != 0)
        if (color[tree[tree[k].lson].end] == color[tree[tree[k].rson].start])
            res -= min(books[tree[tree[k].lson].end], books[tree[tree[k].rson].start]) * (wight[tree[tree[k].lson].end] + wight[tree[tree[k].rson].start]);
    return res;
}
void change1(int x, int k)
{
    if (tree[k].start > x || tree[k].end < x)
        return;
    if (tree[k].start == x && tree[k].end == x)
    {
        tree[k].need = wight[x] * books[x] * 2;
        return;
    }
    change1(x, tree[k].lson), change1(x, tree[k].rson);
    pushup(k);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> Q;
    for (int i = 1; i <= n; i++)
        cin >> books[i] >> color[i] >> wight[i];
    ++cnt;
    tree[1].start = 1, tree[1].end = n;
    build(1);
    // for (int i = 1; i <= cnt; i++)
    //     cout << tree[i].start << ' ' << tree[i].end << ' ' << tree[i].color << ' ' << tree[i].need << ' ' << tree[i].lson << ' ' << tree[i].rson << '\n';
    int flag, a, b, c;
    while (Q--)
    {
        cin >> flag;
        if (flag == 1)
        {
            cin >> a >> b >> c;
            books[a] = b;
            wight[a] = c;
            change1(a, 1);
            // rebuild(1);
        }
        else if (flag == 2)
        {
            cin >> a >> b >> c;
            for (int i = a; i <= b; i++)
                color[i] = c;
            rebuild(1);
        }
        else
        {
            cin >> a >> b;
            cout << count(a, b, 1) << '\n';
        }
    }
    return 0;
}