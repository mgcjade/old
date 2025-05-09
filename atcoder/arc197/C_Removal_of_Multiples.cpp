#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

#ifndef TREAP
#define TREAP
template <typename T>
class treap
{
private:
    struct node
    {
        T data;
        unsigned fix;
        int s;
        node *ch[2];
        node(const T &d) : data(d), s(1) {}
        node() : s(0) { ch[0] = ch[1] = this; }
    } *nil, *root;
    unsigned x;
    inline unsigned ran()
    {
        return x = x * 0xdefaced + 1;
    }
    inline void rotate(node *&a, bool d)
    {
        node *b = a;
        a = a->ch[!d];
        a->s = b->s;
        b->ch[!d] = a->ch[d];
        a->ch[d] = b;
        b->s = b->ch[0]->s + b->ch[1]->s + 1;
    }
    void insert(node *&o, const T &data)
    {
        if (!o->s)
        {
            o = new node(data), o->fix = ran();
            o->ch[0] = o->ch[1] = nil;
        }
        else
        {
            o->s++;
            bool d = o->data < data;
            insert(o->ch[d], data);
            if (o->ch[d]->fix > o->fix)
                rotate(o, !d);
        }
    }
    node *merge(node *a, node *b)
    {
        if (!a->s || !b->s)
            return a->s ? a : b;
        if (a->fix > b->fix)
        {
            a->ch[1] = merge(a->ch[1], b);
            a->s = a->ch[0]->s + a->ch[1]->s + 1;
            return a;
        }
        else
        {
            b->ch[0] = merge(a, b->ch[0]);
            b->s = b->ch[0]->s + b->ch[1]->s + 1;
            return b;
        }
    }
    bool erase(node *&o, const T &data)
    {
        if (!o->s)
            return 0;
        if (o->data == data)
        {
            node *t = o;
            o = merge(o->ch[0], o->ch[1]);
            delete t;
            return 1;
        }
        if (erase(o->ch[o->data < data], data))
        {
            o->s--;
            return 1;
        }
        else
            return 0;
    }
    void clear(node *&o)
    {
        if (o->s)
            clear(o->ch[0]), clear(o->ch[1]), delete o;
    }

public:
    treap(unsigned s = 20150119) : nil(new node), root(nil), x(s) {}
    ~treap() { clear(root), delete nil; }
    inline void clear() { clear(root), root = nil; }
    inline void insert(const T &data)
    {
        insert(root, data);
    }
    inline bool erase(const T &data)
    {
        return erase(root, data);
    }
    inline bool find(const T &data)
    {
        for (node *o = root; o->s;)
            if (o->data == data)
                return 1;
            else
                o = o->ch[o->data < data];
        return 0;
    }
    inline int rank(const T &data)
    {
        int cnt = 0;
        for (node *o = root; o->s;)
            if (o->data < data)
                cnt += o->ch[0]->s + 1, o = o->ch[1];
            else
                o = o->ch[0];
        return cnt;
    }
    inline const T &kth(int k)
    {
        for (node *o = root;;)
            if (k <= o->ch[0]->s)
                o = o->ch[0];
            else if (k == o->ch[0]->s + 1)
                return o->data;
            else
                k -= o->ch[0]->s + 1, o = o->ch[1];
    }
    inline const T &operator[](int k)
    {
        return kth(k);
    }
    inline const T &preorder(const T &data)
    {
        node *x = root, *y = 0;
        while (x->s)
            if (x->data < data)
                y = x, x = x->ch[1];
            else
                x = x->ch[0];
        if (y)
            return y->data;
        return data;
    }
    inline const T &successor(const T &data)
    {
        node *x = root, *y = 0;
        while (x->s)
            if (data < x->data)
                y = x, x = x->ch[0];
            else
                x = x->ch[1];
        if (y)
            return y->data;
        return data;
    }
    inline int size() { return root->s; }
};
#endif

treap<int> T;

const int N = 2750200;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

void init()
{
    rep(i, 1, N) T.insert(i);
}

void dlt(int x)
{
    for (int i = x; i <= N; i += x)
    {
        // if (T. != T.end())
        T.erase(i);
    }
}
void solve(int x)
{
    cout << T.kth(x) << '\n';
}

signed main()
{
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _Tp;
    cin >> _Tp;
    while (_Tp--)
    {
        int x;
        cin >> x;
        dlt(x);
        cin >> x;
        solve(x);
        // rep(i, 1, 10) cerr << T.kth(i) << " ";
        // cerr << '\n';
    }
    return 0;
}

// 平衡树