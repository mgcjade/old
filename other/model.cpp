// model
#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

signed main()
{

    return 0;
}

// read
template <class _Tp>
void read(_Tp &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
    if (last == '-')
        s = -s;
}

// write
template <class _Tp>
void write(_Tp s)
{
    if (s < 0)
        putchar('-'), s = -s;
    _Tp y = 10;
    int len = 1;
    while (y <= s)
        y *= 10, len++;
    while (len--)
    {
        y /= 10;
        putchar(s / y + 48);
        s %= y;
    }
}

// fastcin
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

// fastio
namespace fastio
{
    namespace IO
    {
#ifndef LOCAL
        constexpr auto maxn = 1 << 20;
        char in[maxn], out[maxn], *p1 = in, *p2 = in, *p3 = out;
#define getchar() (p1 == p2 && (p2 = (p1 = in) + fread(in, 1, maxn, stdin), p1 == p2) ? EOF : *p1++)
#define flush() (fwrite(out, 1, p3 - out, stdout))
#define putchar(x) (p3 == out + maxn && (flush(), p3 = out), *p3++ = (x))
        class Flush
        {
        public:
            ~Flush() { flush(); }
        } _;
#endif
        namespace usr
        {
            template <typename type>
            inline type read(type &x)
            {
                x = 0;
                bool flag(0);
                char ch = getchar();
                while (!isdigit(ch))
                    flag ^= ch == '-', ch = getchar();
                while (isdigit(ch))
                    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
                return flag ? x = -x : x;
            }
            template <typename type>
            inline void write(type x)
            {
                x < 0 ? x = -x, putchar('-') : 0;
                static short Stack[50], top(0);
                do
                    Stack[++top] = x % 10, x /= 10;
                while (x);
                while (top)
                    putchar(Stack[top--] | 48);
            }
            inline char read(char &x)
            {
                do
                    x = getchar();
                while (isspace(x));
                return x;
            }
            inline char write(const char &x)
            {
                return putchar(x);
            }
            inline void read(char *x)
            {
                static char ch;
                read(ch);
                do
                    *(x++) = ch;
                while (!isspace(ch = getchar()) && ~ch);
            }
            template <typename type>
            inline void write(type *x)
            {
                while (*x)
                    putchar(*(x++));
            }
            inline void read(std::string &x)
            {
                static char ch;
                read(ch), x.clear();
                do
                    x += ch;
                while (!isspace(ch = getchar()) && ~ch);
            }
            inline void write(const std::string &x)
            {
                for (int i = 0, len = x.length(); i < len; ++i)
                    putchar(x[i]);
            }
            template <typename type, typename... T>
            inline void read(type &x, T &...y)
            {
                read(x), read(y...);
            }
            template <typename type, typename... T>
            inline void write(const type &x, const T &...y)
            {
                write(x), putchar(' '), write(y...), sizeof...(y) ^ 1 ? 0 : putchar('\n');
            }
            template <typename type>
            inline void put(const type &x, bool flag = 1)
            {
                write(x), flag ? putchar('\n') : putchar(' ');
            }
        } // namespace usr
#ifndef LOCAL
#undef getchar
#undef flush
#undef putchar
#endif
    } // namespace IO
    using namespace IO::usr;
} // namespace fastio
using namespace fastio::IO::usr;

// time
fprintf(stderr, "#%.3lf", 1.0 * clock() / CLOCKS_PER_SEC);

// fangwei
class PQTree
{
public:
    PQTree() {}
    void Init(int n)
    {
        n_ = n, rt_ = tot_ = n + 1;
        for (int i = 1; i <= n; i++)
            g_[rt_].emplace_back(i);
    }
    void Insert(const std::string &s)
    {
        s_ = s;
        Dfs0(rt_);
        Work(rt_);
        while (g_[rt_].size() == 1)
            rt_ = g_[rt_][0];
        Remove(rt_);
    }
    std::vector<int> ans()
    {
        DfsAns(rt_);
        return ans_;
    }
    ~PQTree() {}

private:
    int n_, rt_, tot_, pool_[100001], top_, typ_[100001] /* 0-P 1-Q */, col_[100001] /* 0-black 1-white 2-grey */;
    std::vector<int> g_[100001], ans_;
    std::string s_;
    void Fail()
    {
        std::cout << "NO\n";
        std::exit(0);
    }
    int NewNode(int ty)
    {
        int x = top_ ? pool_[top_--] : ++tot_;
        typ_[x] = ty;
        return x;
    }
    void Delete(int u) { g_[u].clear(), pool_[++top_] = u; }
    void Dfs0(int u)
    {
        if (u >= 1 && u <= n_)
        {
            col_[u] = s_[u] == '1';
            return;
        }
        bool c0 = false, c1 = false;
        for (auto &&v : g_[u])
        {
            Dfs0(v);
            if (col_[v])
                c1 = true;
            if (col_[v] != 1)
                c0 = true;
        }
        if (c0 && !c1)
            col_[u] = 0;
        else if (!c0 && c1)
            col_[u] = 1;
        else
            col_[u] = 2;
    }
    bool Check(const std::vector<int> &v)
    {
        int p2 = -1;
        for (int i = 0; i < static_cast<int>(v.size()); i++)
            if (col_[v[i]] == 2)
            {
                if (p2 != -1)
                    return false;
                p2 = i;
            }
        if (p2 == -1)
            for (int i = 0; i < static_cast<int>(v.size()); i++)
                if (col_[v[i]])
                {
                    p2 = i;
                    break;
                }
        for (int i = 0; i < p2; i++)
            if (col_[v[i]])
                return false;
        for (int i = p2 + 1; i < static_cast<int>(v.size()); i++)
            if (col_[v[i]] != 1)
                return false;
        return true;
    }
    std::vector<int> Split(int u)
    {
        if (col_[u] != 2)
            return {u};
        std::vector<int> ng;
        if (typ_[u])
        {
            if (!Check(g_[u]))
            {
                std::reverse(g_[u].begin(), g_[u].end());
                if (!Check(g_[u]))
                    Fail();
            }
            for (auto &&v : g_[u])
                if (col_[v] != 2)
                {
                    ng.emplace_back(v);
                }
                else
                {
                    auto s = Split(v);
                    ng.insert(ng.end(), s.begin(), s.end());
                }
        }
        else
        {
            std::vector<int> son[3];
            for (auto &&x : g_[u])
                son[col_[x]].emplace_back(x);
            if (son[2].size() > 1)
                Fail();
            if (!son[0].empty())
            {
                int n0 = NewNode(0);
                g_[n0] = son[0];
                ng.emplace_back(n0);
            }
            if (!son[2].empty())
            {
                auto s = Split(son[2][0]);
                ng.insert(ng.end(), s.begin(), s.end());
            }
            if (!son[1].empty())
            {
                int n1 = NewNode(0);
                g_[n1] = son[1];
                ng.emplace_back(n1);
            }
        }
        Delete(u);
        return ng;
    }
    void Work(int u)
    {
        if (col_[u] != 2)
            return;
        if (typ_[u])
        {
            int l = 1e9, r = -1e9;
            for (int i = 0; i < static_cast<int>(g_[u].size()); i++)
                if (col_[g_[u][i]])
                    min(l, i), max(r, i);
            for (int i = l + 1; i < r; i++)
                if (col_[g_[u][i]] != 1)
                    Fail();
            if (l == r && col_[g_[u][l]] == 2)
            {
                Work(g_[u][l]);
                return;
            }
            std::vector<int> ng;
            for (int i = 0; i < l; i++)
                ng.emplace_back(g_[u][i]);
            auto s = Split(g_[u][l]);
            ng.insert(ng.end(), s.begin(), s.end());
            for (int i = l + 1; i < r; i++)
                ng.emplace_back(g_[u][i]);
            if (l != r)
            {
                s = Split(g_[u][r]);
                std::reverse(s.begin(), s.end());
                ng.insert(ng.end(), s.begin(), s.end());
            }
            for (int i = r + 1; i < static_cast<int>(g_[u].size()); i++)
                ng.emplace_back(g_[u][i]);
            g_[u] = ng;
        }
        else
        {
            std::vector<int> son[3];
            for (auto &&x : g_[u])
                son[col_[x]].emplace_back(x);
            if (son[1].empty() && son[2].size() == 1)
            {
                Work(son[2][0]);
                return;
            }
            g_[u].clear();
            if (son[2].size() > 2)
                Fail();
            g_[u] = son[0];
            int n1 = NewNode(1);
            g_[u].emplace_back(n1);
            if (son[2].size() >= 1)
            {
                auto s = Split(son[2][0]);
                g_[n1].insert(g_[n1].end(), s.begin(), s.end());
            }
            if (son[1].size())
            {
                int n2 = NewNode(0);
                g_[n1].emplace_back(n2);
                g_[n2] = son[1];
            }
            if (son[2].size() >= 2)
            {
                auto s = Split(son[2][1]);
                std::reverse(s.begin(), s.end());
                g_[n1].insert(g_[n1].end(), s.begin(), s.end());
            }
        }
    }
    void Remove(int u)
    {
        for (auto &&v : g_[u])
        {
            int tv = v;
            while (g_[tv].size() == 1)
            {
                int t = tv;
                tv = g_[tv][0];
                Delete(t);
            }
            v = tv, Remove(v);
        }
    }
    void DfsAns(int u)
    {
        if (u >= 1 && u <= n_)
        {
            ans_.emplace_back(u);
            return;
        }
        for (auto &&v : g_[u])
            DfsAns(v);
    }
} T;