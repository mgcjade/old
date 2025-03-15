template <typename _Tp>
class Tree_Array
{
private:
    _Tp t1[N], t2[N], n;
    _Tp lowbit(_Tp x) { return x & (-x); }
    void _add(_Tp k, _Tp v)
    {
        _Tp v1 = k * v;
        while (k <= n)
            t1[k] += v, t2[k] += v1, k += lowbit(k);
    }
    _Tp _getsum(_Tp *t, _Tp k)
    {
        _Tp ret = 0;
        while (k)
            ret += t[k], k -= lowbit(k);
        return ret;
    }

public:
    void add(_Tp l, _Tp r, _Tp v) { _add(l, v), _add(r + 1, -v); }
    long long sum(_Tp l, _Tp r) { return (r + 1ll) * _getsum(t1, r) - 1ll * l * _getsum(t1, l - 1) - (_getsum(t2, r) - _getsum(t2, l - 1)); }
};