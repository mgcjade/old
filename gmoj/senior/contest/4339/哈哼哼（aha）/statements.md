# 哈哼哼（aha）

## 题目描述

哈哼哼有一个排列。

人是在不断变化的，排列也是。有 $q$ 次修改，每次修改会将一个区间 $[l,r]$ 循环移位 $k$ 位，即对于新的排列 $p$ 和原排列 $p'$ 有区间 $[l,r]$ 内 $p_x=p'_{(x-l+k) \space \bmod (r-l+1)+l}$，其它位置 $p_x=p'_x$。

每次修改后，哈哼哼想将找到一个 $k$，使得整个排列按照刚才的定义循环移位 $k$ 位后逆序对数最少。如有多种方案使得逆序对数最少，他会找到最小的 $k$。

但现在哈哼哼忘记了每次找到的 $k$，你能帮帮他吗？

需要注意的是，他只是找到了 $k$，却没有真的将整个排列循环移位 $k$ 位。

## 输入

第一行两个正整数 $n$ 和 $q$，表示排列长度和修改个数。

接下来一行 $n$ 个正整数，表示这个排列。

接下来 $q$ 行，每行三个正整数 $l,r,k$，表示一次修改。

## 输出

输出 $q$ 行，每行一个正整数，表示哈哼哼找到的 $k$。

## 样例数据

### 样例输入 1

```
7 5
1 2 3 4 5 6 7
2 7 2
1 5 1
3 6 3
1 5 4
1 7 5

```

### 样例输出 1

```
5
4
5
3
0

```


## 数据范围限制

对于所有数据，$1 \leq k < r-l+1$。


| 测试点编号 |    $n \leq$    |    $q \leq$    |
| :---------: | :-------------: | :-------------: |
| $1 \sim 2$ |      $100$      |      $100$      |
| $3 \sim 4$ |     $2000$     |     $2000$     |
| $5 \sim 7$ | $3 \times 10^5$ |     $2000$     |
| $8 \sim 10$ | $3 \times 10^5$ | $3 \times 10^5$ |

## 提示


