# string

## 题目描述

给定 $n$ 个长度为 $m$ 的**不同的** $01$ 字符串 $s_1,s_2,…,s_n$。

一个长度为 $nm$ 的 $01$ 字符串 $S$ 是好的，当且仅当 $S[1:m],S[m+1:2m],…,S[(n-1)m+1:nm]$ 这 $n$ 个子串**两两不同**，且每个子串均为 $s_1,s_2,…,s_n$ 中的一个。

例如 $s_1=00,s_2=01$，那么好的字符串有 $0001,0100$，容易发现好的字符串共有 $n!$ 个。

梦梦给出了一台 $01$ 编码机，当梦梦按下 $0$ 时有 $p$ 的概率编码机打出 $0$，$1-p$ 的概率打出 $1$；当梦梦按下 $1$ 时有 $p$ 的概率编码机打出 $1$，$1-p$ 的概率打出 $0$。

编码机最多打出 $nm$ 个字符，因此梦梦希望其恰能打出一个好的字符串，已知梦梦绝顶聪明，会根据当前编码机打出的结果动态调整自身策略，请问梦梦最终能打出一个好的字符串的胜率。

## 输入

输入第一行，包含 $2$ 个正整数 $n,m$ 和一个**至多六位**小数 $p$。

之后 $n$ 行，每行给出一个 $m$ 个字符的 $01$ 串 $s_i$。

## 输出

输出一行，表示答案，如果你的答案与标准答案的绝对误差不超过 $10^{-9}$，则会被认为答案正确，否则答案错误。

## 样例数据

### 样例输入 1

```
3 2 0.5
00
01
10

```

### 样例输出 1

```
0.093750000000

```
### 样例输入 2

```
2 5 0.1234
01000
10100

```

### 样例输出 2

```
0.305642115411

```
### 样例输入 3

```
5 5 0.999
00000
00001
00010
00011
00100

```

### 样例输出 3

```
0.984112560855

```
### 样例输入 4

```
5 5 0.001
00000
00001
00010
00011
00100

```

### 样例输出 4

```
0.984112560855

```
### 样例输入 5

```
5 5 0.1
00000
00001
01010
01011
00100

```

### 样例输出 5

```
0.163155870461

```


## 数据范围限制

对于 $30\%$ 的数据，$n \leq 2$。

对于 $60\%$ 的数据，$n \leq 18$。

对于所有测评数据，$1 \leq n,m \leq 1000,0 \leq p \leq 1$。

## 提示


