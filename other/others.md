### 问题重述

在三角形 $ABC$ 中，已知：
- $\angle A = 30^\circ$
- 边 $BC = a$

求三角形 $ABC$ 的最大面积 $S_{\triangle ABC}$。

### 解题思路

我们需要在固定一个角（$\angle A = 30^\circ$）及其对边（$BC = a$）的情况下，找到三角形面积的最大值。这类问题通常可以通过以下方法解决：

1. **利用正弦定理**：表达其他边与角的关系。
2. **面积公式**：利用两边及其夹角的正弦来表示面积。
3. **最大化面积**：通过调整其他角来使面积最大化。

### 具体步骤

#### 1. 利用正弦定理

在三角形 $ABC$ 中，根据正弦定理：
$$
\frac{BC}{\sin A} = \frac{AC}{\sin B} = \frac{AB}{\sin C} = 2R
$$
其中 $R$ 是三角形的外接圆半径。

已知 $BC = a$，$\angle A = 30^\circ$，所以：
$$
2R = \frac{BC}{\sin A} = \frac{a}{\sin 30^\circ} = \frac{a}{0.5} = 2a
$$
因此：
$$
AC = 2R \sin B = 2a \sin B
$$
$$
AB = 2R \sin C = 2a \sin C
$$

#### 2. 面积公式

三角形的面积可以用以下公式表示：
$$
S = \frac{1}{2} \times AB \times AC \times \sin A
$$
代入已知：
$$
S = \frac{1}{2} \times 2a \sin C \times 2a \sin B \times \sin 30^\circ = \frac{1}{2} \times 4a^2 \sin B \sin C \times 0.5 = a^2 \sin B \sin C
$$

#### 3. 角度关系

在三角形中，三个内角之和为 $180^\circ$：
$$
B + C = 180^\circ - A = 150^\circ
$$

#### 4. 最大化 $\sin B \sin C$

我们需要最大化 $\sin B \sin C$，其中 $B + C = 150^\circ$。

利用积化和差公式：
$$
\sin B \sin C = \frac{1}{2} [\cos(B - C) - \cos(B + C)] = \frac{1}{2} [\cos(B - C) - \cos 150^\circ]
$$
因为 $\cos 150^\circ = -\frac{\sqrt{3}}{2}$ 是固定的，所以最大化 $\cos(B - C)$ 即可最大化 $\sin B \sin C$。

$\cos(B - C)$ 的最大值为 1，当 $B - C = 0$ 时取得，即 $B = C$。

因此：
$$
B = C = \frac{150^\circ}{2} = 75^\circ
$$

此时：
$$
\sin B \sin C = \sin^2 75^\circ
$$

#### 5. 计算 $\sin 75^\circ$

利用角度和公式：
$$
\sin 75^\circ = \sin(45^\circ + 30^\circ) = \sin 45^\circ \cos 30^\circ + \cos 45^\circ \sin 30^\circ
$$
$$
= \frac{\sqrt{2}}{2} \times \frac{\sqrt{3}}{2} + \frac{\sqrt{2}}{2} \times \frac{1}{2} = \frac{\sqrt{6}}{4} + \frac{\sqrt{2}}{4} = \frac{\sqrt{6} + \sqrt{2}}{4}
$$

因此：
$$
\sin^2 75^\circ = \left( \frac{\sqrt{6} + \sqrt{2}}{4} \right)^2 = \frac{6 + 2 + 2 \sqrt{12}}{16} = \frac{8 + 4\sqrt{3}}{16} = \frac{2 + \sqrt{3}}{4}
$$

#### 6. 最大面积

代入面积公式：
$$
S_{\text{max}} = a^2 \times \frac{2 + \sqrt{3}}{4} = \frac{a^2 (2 + \sqrt{3})}{4}
$$

### 验证

另一种方法是利用几何直观：固定边 $BC = a$ 和角 $A = 30^\circ$，点 $A$ 的轨迹是以 $BC$ 为弦，对应圆周角为 $30^\circ$ 的圆弧。面积最大的情况是点 $A$ 到 $BC$ 的距离最大，即高最大。这发生在 $A$ 位于圆弧的最高点，此时 $AB = AC$，即三角形为等腰三角形。这与之前的推导一致。

### 结论

三角形 $ABC$ 的最大面积为：

$$
\boxed{\dfrac{a^2 (2 + \sqrt{3})}{4}}
$$
