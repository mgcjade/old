// model
#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

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