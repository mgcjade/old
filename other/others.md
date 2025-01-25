$g_0=1,f_0=1$
$$
g_i=g_{i-1}\times (1-v) + g_{i-1} + (2^{i-1}-g_{i-1})(1-v) \\
g_i = g_{i-1} - g_{i-1} \times v + g_{i-1} + 2^{i-1} - 2^{i-1} \times v - g_{i-1} + g_{i-1} \times v\\
g_i = g_{i-1} + 2^{i-1} - 2^{i-1} \times v \\
g_i = g_{i-1} + 2^{i-1}(1- v) \\
g_i = (2^0 + 2^1 + \dots + 2^{n-1})(1-v) +1\\
g_i = (2^n-1)(1-v)+1
$$

$$
f_i=f_{i-1} \times (1-v) + v^{i-1} \times (g_{i-1} \times v + (2^{i-1}-g_{i-1})(1-v))\\
经过了一系列的繁琐推导得到：\\
f_i = f_{i-1}\times (1-v) + (2v)^i\times (1-v) + v^i \times (2v-1)\\
f_n = \left ( \sum\limits_{i=1}^{n}(1-v)^{n-i} \times [(2v)^i\times (1-v) + v^i \times (2v-1)] \right ) +(1-v)^n \\
f_n = (1-v)^n \left(\left(\sum\limits_{i=1}^{n} (\frac{2v}{1-v})^i \times (1-v) + (\frac{v}{1-v})^i\times(2v-1)\right) +1\right) \\
然后就发现求和中的两个可以分开求，并且每一个都是等比数列 \\
f_n=v(v^n+p)+p+2v(1-v)\frac{(2v)^n-p}{3v-1} \left ( 此处p为\frac{p}{q}中的p \right)
$$
