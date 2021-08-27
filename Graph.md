# 图

## 定义：

### 图G由顶点集V和边集E组成，记为G=(V,E)。

### 其中V(G)表示图G中顶点的有限非空集，E(G)表示图G中顶点之间的关系集合。

### 若$V=\{v_1, v_2,... , v_n\}$​​​​​，则用==|V|==表示图G中顶点的个数，也称==图G的阶==

### $E= {(u, v) | u\in V,v\in V}$​，用==|E|==表示图G中==边的条数==。

>  **注意:线性表可以是空表，树可以是空树，但图不可以是空，即V一定是非空集**



## 无向图：

**若E是==无向边==(简称==边==)的有限集合时，则G为==无向图==，边是顶点的无序对，==记为(v,w)或(w,v)==,因为==(v,w)=(w,v)==,其中v,w是顶点可以说顶点w和顶点v互为邻接点**

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817162055674.png" alt="image-20210817162055674" style="zoom:50%;" />

## 有向图：

**若E是==有向边==(简称==弧==)的有限集合时，则G为==有向图==，弧是顶点的有序对，==记为<v,w>==,其中v,w是顶点,v称为==弧尾==，w称为==弧头==。<v,w>称为从顶点v到顶点w的弧，也称v邻接到w,或w邻接自v.==<v,w>≠<w,v>==**

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817162106599.png" alt="image-20210817162106599" style="zoom:50%;" />

## 顶点的度，入度，出度

### **对于无向图：**

​	**顶点v的度是指依附于该顶点的边的条数，记为TD(v)。**

​	**在具有n个顶点、e条边的无向图中，$\sum\limits_{i=1}^{n}TD(v_i)= 2e$​**
​	**即无向图的全部顶点的度的和等于边数的2倍**



### **对于有向图：**

​	**入度是以顶点v为终点的有向边的数目，记为ID(v);**

​	**出度是以顶点v为起点的有向边的数目，记为OD(v)。**
​	**顶点v的度等于其入度和出度之和，即TD(v)= ID(v)+OD(v)。**

​	**在具有n个顶点、e条边的无向图中，$\sum\limits_{i=1}^{n}ID(v_i)= \sum\limits_{i=1}^{n}OD(v_i)=e$​**



## 顶点-顶点之间的关系描述：

- **路径――顶点$v_p$,到顶点$v_q$之间的一条路径是指顶点序列，$v_p,v_{i1},v_{i2},... ,v_{im} , v_q$**
- **回路――第一个顶点和最后一个顶点相同的路径称为回路或环**
- **简单路径――在路径序列中，顶点不重复出现的路径称为简单路径。**
- **简单回路――除第一个顶点和最后一个顶点外，其余顶点不重复出现的回路称为简单回路。**
- **路径长度――路径上边的数目**
- **点到点的距离――从顶点u出发到顶点v的==最短路径==若存在，则==此路径的长度称为从u到v的距离==。**
  **若从u到v根本不存在路径，则记该距离为无穷( ∞)**
- **无向图中，若从顶点v到顶点w有路径存在，则称v和w是==连通==的**
- **有向图中，若从顶点v到顶点w和从顶点w到顶点v之间都有路径，则称这两个顶点是==强连通==的**



## 连通图与强连通图

### 连通图(无向图)：

**定义：若图G中任意两个顶点都是连通的，则称图G为连通图，否则称为非连通图。**

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817165635346.png" alt="image-20210817165635346" style="zoom: 67%;" />

**常见考点:**

**对于n个顶点的无向图G，**

1. **若G是连通图，则最少有n-1条边**

> **任取一个顶点出来，与其余顶点各连一条线**

2. **若G是非连通图，则最多可能有$C^2_{n-1}$条边**

> **任取一个顶点出来，其余顶点随意连线，两两相连，其边数为$C^2_{n-1}$,**
>
> **再多加一条就要与取出来的顶点连接，就构成了连通图**



### 强连通图(有向图):

**定义：若图中任何一对顶点都是强连通的，则称此图为强连通图。**

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817171149010.png" alt="image-20210817171149010" style="zoom:67%;" />

**常见考点:**

**对于n个顶点的有向图G，**

1. **若G是==强连通图==，则==最少有n条边==（形成回路)**

   > **顶点绕一圈**



## 子图和生成子图

**设有两个图G = (V, E)和G'= (V',E')，若V'是V的子集，且E'是E的子集，则称G'是G的子图。**
**若有满足V(G')= V(G)的子图G'，则称其为G的生成子图(含有图的全部顶点，不一定要有全部的边)**

![image-20210817171726109](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817171726109.png)

![image-20210817172013720](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817172013720.png)



## 连通分量：

**无向图中的==极大连通子图==称为==连通分量==**

> **极大连通子图：子图必须联通，且包含尽可能多的边和顶点**

![image-20210817172359713](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817172359713.png)



## 强连通分量：

**有向图中的==极大强连通子图==称为有向图的==强连通分量==**

> **极大强连通子图：子图必须强联通，同时保留尽可能多的边**

![image-20210817173201520](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817173201520.png)

## 生成树：

**==连通图==的生成树是==包含图中全部顶点的一个极小连通子图==。**

> **极小连通子图：边尽可能的少，但要保持连通**



**若图中顶点数为n，则它的生成树含有n-1条边。**

对生成树而言，若砍去它的一条边，则会变成非连通图，若加上一条边则会形成一个回路

![image-20210817174428184](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817174428184.png)



## 生成森林：

在==非连通图==中，==连通分量的生成树==构成了非连通图的生成森林。

![image-20210817175526233](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817175526233.png)



## 几种特殊形态的图：

### 无向完全图：

无向图中任意两个顶点之间都存在边

若有n个顶点，则边的总数为$C^2_n$



<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817175927322.png" alt="image-20210817175927322" style="zoom: 50%;" />



### 有向完全图：

有向图中任意两个顶点之间都存在方向相反的两条弧

若有n个顶点，则边的总数为$2C^2_n$

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817180255659.png" alt="image-20210817180255659" style="zoom:67%;" />

### 稀疏图：

边数很少的图称为稀疏图

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817180447076.png" alt="image-20210817180447076" style="zoom:50%;" />

### 稠密图：

反之称为稠密图

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817180523360.png" alt="image-20210817180523360" style="zoom:50%;" />



### 树：

==不存在回路==，且==连通==的无向图

n个顶点的树，必有n-1条边

**常见考点**

n个顶点的图，若边数＞n-1，则一定有回路

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817180719160.png" alt="image-20210817180719160" style="zoom:50%;" />



### 有向树：

一个顶点的入度为0，其余顶点的入度为1的有向图，称为有向树

有向树并不是强连通的 

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210817181059060.png" alt="image-20210817181059060" style="zoom:50%;" />

## 图的存储

### 邻接矩阵法(顺序存储)

#### 不带权图

![image-20210818151006686](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210818151006686.png)

#### 带权图：

![image-20210818151714800](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210818151714800.png)

#### **求结点的度**

1. **无向图：**

   > **第i个结点的度===第i行（或第i列)==的非零元素个数**

2. **有向图：**

   > **第i个结点的出度=第i行的非零元素个数**
   >
   > **第i个结点的入度=第i列的非零元素个数**
   >
   > **第i个结点的度=第i行、第i列的非零元素个数之和**

**邻接矩阵法求顶点的度/出度/入度的时间复杂度为O(|V|)**



#### 性能分析：

空间复杂度：O(|v|^2^) ——只和顶点数有关，与实际的边数无关

适合存储稠密图

对称矩阵，可用压缩存储（上/下三角存储）



#### 性质：

**设图G的邻接矩阵为A（矩阵元素为0/1），则A^n^的元素A^n^\[i\]\[j\]等于由顶点i到顶点j的长度为n的路径的数目**

![image-20210818153458893](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210818153458893.png)







### 邻接表(顺序+链式)

![image-20210818153941782](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210818153941782.png)

**边结点的数量是2|E|,整体空间复杂度为O(|V|+2|E|)**

**![image-20210818172953088](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210818172953088.png)**

**边结点的数量是|E|,整体空间复杂度为O(|V|+|E|)**



图的邻接表表示方式并不唯一

![image-20210818190444152](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210818190444152.png)



### 十字链表：

==只用于存储有向图==

![image-20210818215121301](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210818215121301.png)

#### 性能分析：

空间复杂度:O(|V|+|El)

如何找到指定顶点的所有出边?—―顺着绿色线路

找如何找到指定顶点的所有入边?――顺着橙色线路找

 

### 邻接多重表：

==只用来存储无向图==

![image-20210818221331193](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210818221331193.png)

#### 性能分析：

空间复杂度:O(|V|+|El)

删除边、删除节点等操作很方便



### 总体总结：



|              |                邻接矩阵                |                    邻接表                     |    十字链表    |   邻接多重表   |
| ------------ | :------------------------------------: | :-------------------------------------------: | :------------: | :------------: |
| 空间复杂度   |              O(\|V\|^2^)               | 无向图O(\|V\|+2\|E\|)    有向图O(\|V\|+\|E\|) | O(\|V\|+\|E\|) | O(\|V\|+\|E\|) |
| 找相邻边     |   遍历对应行或列，时间复杂度O(\|V\|)   |       找有向图的入边必须遍历整个邻接表        |     很方便     |     很方便     |
| 删除边或顶点 | 删除边很方便，删除顶点需要大量移动数据 |         无向图中删除边或顶点都不方便          |     很方便     |     很方便     |
| 适用于       |                 稠密图                 |                 稀疏图和其他                  |     有向图     |     无向图     |
| 表示方式     |                  唯一                  |                    不唯一                     |     不唯一     |     不唯一     |

![image-20210818222618945](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210818222618945.png)







# 图的基本操作

## Adjacent(G,x,y):

**判断图是否存在边<x,y>或(x,y)**

### 无向图：

邻接矩阵：直接判断是否为1，O(1)

邻接表：需要遍历，最好O(1)，最坏O(|v|)

> 最好O(1)是第一个连接点就是y，最坏是最后一个才是y

### 有向图：

同上



## Neighbors(G,x):

**列出G中与x邻接的边**

### 无向图：

邻接矩阵：遍历一行或一列，O(|v|)

邻接表：需要遍历，最好O(1)，最坏O(|v|)

> 最好O(1)是这一行只有一个元素，最坏O(|v|)是这一行有尽可能多的元素

### 有向图：

邻接矩阵：出边遍历一行，入边一列，O(|v|)

邻接表：出边 需要遍历一行，最好O(1)，最坏O(|v|)；

​			  入边 需要遍历所有边结点，O(|E|)



## InsertVertex(G,x):

**在图中插入顶点x**

### 无向图：

邻接矩阵：直接插入，O(1)

邻接表：直接插入，O(1)

### 有向图：

同上

## DeleteVertex(G,x):

**在图中删除顶点x**

### 无向图：

邻接矩阵：将删除的顶点一行与一列置0，O(|v|)

邻接表：需要遍历，最好O(1)，最坏O(|E|)

> 最好O(1)是这一行没有任何元素，也就是说这个顶点与其他顶点没有关系，最坏O(|E|)是这一行有尽可能多的元素，就需要遍历所有结点将其删除

### 有向图：

邻接矩阵：出边遍历一行，入边一列，O(|v|)

邻接表：出边 需要遍历一行，最好O(1)，最坏O(|v|)；

​			  入边 需要遍历所有边结点，O(|E|)



## AddEdge(G,x,y):

**若边(x,y)或<x,y>不存在，则向图中添加这个边**

### 无向图：

邻接矩阵：将(x,y)置1，O(1)

邻接表：可选遍历，最好O(1)，最坏O(|E|)

> 最好O(1)是头插法，不遍历，直接插在头部，最坏O(|V|)是尾插法

### 有向图：

同上



## FirstNeighbor(G,x):

**求图G顶点x的第一个邻接点，若有则返回顶点号，没有返回-1**

### 无向图：

邻接矩阵：扫描第一个为1，O(1)-O(|V|)

> 最好O(1)是第一个就是1，最坏O(|V|)是都不是1

邻接表：扫描第一个,O(1)

### 有向图：

邻接矩阵：扫描第一个为1，O(1)-O(|V|)

> 最好O(1)是第一个就是1，最坏O(|V|)是都不是1

邻接表：出边  第一个元素就是，O(1)

​			  入边 可能需要遍历所有边结点，最好O(1),最坏O(|E|)

> 最好O(1)就是第一个元素就是指向当前顶点的一条边，





## NextNeighbor(G,x,y):

**假设图中顶点y是x的一个邻接点，返回除y之外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，返回-1**

### 无向图：

邻接矩阵：扫描第一个为1，O(1)-O(|V|)

> 最好O(1)是下一个就是1，最坏O(|V|)是都不是1

邻接表：扫描第一个的下一个,O(1)

### 有向图：

同上



## Get_edge_value(G,x,y):

**获取图G中边(x, y)或<x, y>对应的权值。**

与Adjacent(G,x,y)相同，核心在于找到边

## Set_edge_value(G,x,y,v):设

**置图G中边(x, y)或<x, y>对应的权值为v。**

与Adjacent(G,x,y)相同，核心在于找到边





# 图的遍历

## 广度优先遍历：

同一个图的邻接矩阵表示方式唯一，因此广度优先遍历序列推一,广度优先生成树也唯一

同一个图邻接表表示方式不唯一，因此广度优先遍历序列不唯一，广度优先生成树也不唯一

![image-20210820204316584](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210820204316584.png)



**对于无向图，调用BFS()的次数=连通分量数**



### 复杂度分析：

空间：

最坏情况下，辅助队列大小为O(|V|)

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210820204913838.png" alt="image-20210820204913838" style="zoom:50%;" />

时间：

​	邻接矩阵存储的图:

- 访问|V|个顶点需要O(|V|)的时间

- 查找每个顶点的邻接点都需要O(|V|)的时间，而总共有|V|个顶点

- 时间复杂度=O(|V^2^|)

  邻接表存储的图:

- 访问|V|个顶点需要O(|V|)的时间
- 查找各个顶点的邻接点共需要O(|E|)的时间，
- 时间复杂度=O(|V|+|E|)



### 广度优先生成树

通过广度优先遍历序列生成的树

![image-20210820205826909](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210820205826909.png)

广度优先生成树由广度优先遍历过程确定。

由于邻接表的表示方式不唯一，因此基于邻接表的广度优先生成树也不唯一。



### 广度优先生成森林

对非连通图的广度优先遍历，可得到广度优先生成森林





## 深度优先遍历：

同一个图的邻接矩阵表示方式唯一，因此深度优先遍历序列推一，深度优先生成树也唯一

同一个图邻接表表示方式不唯一，因此深度优先遍历序列不唯一，深度优先生成树也不唯一

![image-20210820213131384](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210820213131384.png)



### 复杂度分析：

**空间：**

来自函数调用栈，最坏O(|V|)

> ![image-20210820213401360](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210820213401360.png)

最好O(1)

> <img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210820213415278.png" alt="image-20210820213415278" style="zoom:50%;" />



**时间：**

​	邻接矩阵存储的图:

- 访问|V|个顶点需要O(|V|)的时间

- 查找每个顶点的邻接点都需要O(|V|)的时间，而总共有|V|个顶点

- 时间复杂度=O(|V^2^|)

  邻接表存储的图:

- 访问|V|个顶点需要O(|V|)的时间
- 查找各个顶点的邻接点共需要O(|E|)的时间，
- 时间复杂度=O(|V|+|E|)



### 深度优先生成树;

通过广度优先遍历序列生成的树

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210820213909255.png" alt="image-20210820213909255" style="zoom: 50%;" />







### 深度优先生成森林：

深度优先遍历非连通图可得深度优先生成森林

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210820214247568.png" alt="image-20210820214247568" style="zoom:50%;" />

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210820214311673.png" alt="image-20210820214311673" style="zoom:50%;" />





## 图的遍历与图的连通性：



### 对==无向图==进行BFS/DFS遍历

调用BFS/DFS函数的次数===连通分量数==

对于连通图，只需调用==1次==BFS/DFS



### 对==有向图==进行BFS/DFS遍历

调用BFS/DFS函数的次数要具体问题具体分析

若起始顶点到其他各顶点都有路径，则只需调用1次BFS/DFS 函数

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210820214705120.png" alt="image-20210820214705120" style="zoom:67%;" />

对于强连通图，从任一结点出发都只需调用==1次==BFS/DFS

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210820214715932.png" alt="image-20210820214715932" style="zoom:67%;" />





# 最小生成树(最小代价树)：



## 定义：

​	**对于一个带权连通无向图G=(V,E)，生成树不同，每棵树的权〈即树中所有边上的权值之和)也可能不同。设R为G的所有生成树的集合，若T为R中边的权值之和最小的生成树，则T称为G的最小生成树(Minimum-Spanning-Tree,MST)**

## 特点：

- **最小生成树可能有多个，但边的权值之和总是唯一且最小的**
- **最小生成树的边数=顶点数–1。砍掉一条则不连通，增加一条边则会出现回路**
- **如果一个连通图本身就是一棵树，则其最小生成树就是它本身**
- **只有连通图才有生成树，非连通图只有生成森林**

![image-20210820215726888](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210820215726888.png)

## Prim算法：

**从某一个顶点开始构建生成树;每次将代价最小的新顶点纳入生成树，直到所有顶点都纳入为止。**

**时间复杂度:O(|V|^2^)**

**适合用于边稠密图**

![image-20210821141758852](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210821141758852.png)

==**最小生成树可能不同！**==

![image-20210821141844229](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210821141844229.png)

### 实现思想：

1. 循环遍历所有个结点，找到LowCast最低的，且还没有加入树的顶点

   > <img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210821143140416.png" alt="image-20210821143140416" style="zoom:50%;" />

2. 再次循环遍历，更新还没加入各个顶点的LowCast值 

   > <img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210821143205480.png" alt="image-20210821143205480" style="zoom:50%;" />

3. 循环



## Kruskal算法：

**每次选择一条权值最小的边，使这条边的两头连通(原本已经连通的就不选)，直到所有结点都连通**

**时间复杂度:$O(|E|log_2|E|)$**
**适合用于边稀疏图**

**<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210821142228921.png" alt="image-20210821142228921" style="zoom:67%;" />**

### 实现思想：

1. 将各条边按权值处理

   > <img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210821143454722.png" alt="image-20210821143454722" style="zoom:50%;" />

2. 第1轮:检查第1条边的两个顶点是否连通（是否属于同一个集合)
3. 第2轮:检查第2条边的两个顶点是否连通（是否属于同一个集合)
4. 循环

共执行e轮，每轮判断两个顶点是否属于同一集合，需要$O(log_2e)$总时间复杂度$O(elog_2e)$





# 最短路径问题：



## 单源最短路径：

### BFS算法(无权图)：

**就是对BFS的小修改，在visit一个顶点时，修改其最短路径长度d[]并在path[]记录前驱结点**

![image-20210821152117071](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210821152117071.png)



### Dijkstra算法(带权图，无权图)

**带权路径长度――当图是带权图时，一条路径上所有边的权值之和，称为该路径的带权路径长度**

![image-20210821153041706](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210821153041706.png)

#### 算法步骤：

1. **循环遍历所有结点，找到还没确定最短路径，且dist最小的顶点$V_i$,令final[i]=true**

2. **检查所有邻接自$V_i$i的结点，若其final值为false,则更新dist与path信息** n

   > 结果如下：
   >
   > <img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210821153624025.png" alt="image-20210821153624025" style="zoom:50%;" />

3. repeat

4. 结果：

   > <img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210821154406883.png" alt="image-20210821154406883" style="zoom: 50%;" />

5. 

## **各顶点间的最短路径：**

### Floyd算法(带权图，无权图)

![image-20210827153756145](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827153756145.png)



允许通过v0中转后：

![image-20210827153856647](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827153856647.png)

允许通过v0 ，v1中转后：

![image-20210827153930520](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827153930520.png)

允许通过v0 ，v1, v2中转后：

![image-20210827153947869](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827153947869.png)

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827154042069.png" alt="image-20210827154042069" style="zoom:67%;" />



#### **核心思想：**

​	**若	==A^(k-1)^\[i]\[j]>A^(k-1)^\[i][k]+A^(k-1)^\[k][j]==**

​	**则	==A^(k)^\[i][j]=A^(k-1)^\[i][k]+A^(k-1)^\[k][j];==**

​	**path^(k)^\[i]i]=k**

​	**否则A^(k)^和path^(k)^保持原值**



#### 复杂度分析：

​	时间复杂度：O(|V|^3^)

> 三次遍历

​	空间复杂度：O(|V|^2^)

> 两个矩阵





## 总结：

![image-20210827155940920](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827155940920.png)













# 有向无环图(DAG)

**有向无环图:若一个有向图中不存在环，则称为有向无环图，简称DAG图(Directed Acyclic Graph)**

![image-20210827160655323](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827160655323.png)

![image-20210827161333163](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827161333163.png)



# AOV网

**AOV网(Activity on vertex Network，用顶点表示活动的网):**
**用DAG图(有向无环图）表示一个工程。顶点表示活动，有向边$<V_i, V_j>$表示活动$V_i$必须先于活动$V_j$进行**

![image-20210827204326111](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827204326111.png)



## 拓扑排序:

**==找到做事的先后顺序==**

在图论中，由一个有向无环图的顶点组成的序列，当且仅当满足下列条件时，称为该图的一个拓扑排序:

**①每个顶点出现且只出现一次。**

**②若顶点A在序列中排在顶点B的前面，则在图中不存在从顶点B到顶点A的路径。**

或定义为︰

拓扑排序是对有向无环图的顶点的一种排序，它使得若存在一条从顶点A到顶点B的路径，则在排序中

顶点B出现在顶点A的后面。每个AOV网都有一个或多个拓扑排序序列。



### 拓扑排序的实现:

1. 从AOV网中选择一个没有前驱(入度为0)的顶点并输出。
2. 从网中删除该顶点和所有以它为起点的有向边。
3. 重复①和②直到当前的AOV网为空或当前网中不存在无前驱的顶点为止。

![image-20210827205033341](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827205033341.png)



### 代码：

![image-20210827205626767](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827205626767.png)



### 时间复杂度：

O(|V|+|E|)

若采用邻接矩阵则需要O(|V|^2^)



## 逆拓扑排序：

对一个AOV网，如果采用下列步骤进行排序，则称之为逆拓扑排序:

1. 从AOV网中选择一个没有后继(出度为0)的顶点并输出。
2. 从网中删除该顶点和所有以它为终点的有向边。
3. 重复①和②直到当前的AOV网为空。

### 代码实现(DFS):



![image-20210827210259790](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827210259790.png)







# AOE网

**在带权有向图中，以==顶点表示事件==，以==有向边表示活动==，以==边上的权值表示完成该活动的开销==（如完成活动所需的时间)，称之为用边表示活动的网络，简称==AOE网==(Activity On Edge NetWork)**

![image-20210827210551465](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827210551465.png)

## 性质：

1. 只有在某顶点所代表的事件发生后，从该顶点出发的各有向边所代表的活动才能开始;
2. 只有在进入某顶点的各有向边所代表的活动都已结束时，该顶点所代表的事件才能发生。
3. 另外，有些活动是可以并行进行的



## 关键路径

- **在AOE网中==仅有一个==入度为O的顶点，称为==开始顶点（源点)==，它表示整个工程的开始;**

- **也==仅有一个==出度为0的顶点，称为==结束顶点（汇点)==，它表示整个工程的结束。**

- **从源点到汇点的有向路径可能有多条，所有路径中，具有最大路径长度的路径称为==关键路径==，而把关键路径上的活动称为==关键活动==**

- **完我整个工程的最短时间就是关键路径的长度若关键活动不能按时完成，则整个工程的完成时间就会延长**

- **事件$v_k$的最早发生时间ve(k)——决定了所有从v开始的活动能够开工的最早时间活动**

- **$a_i$的最早开始时间e(i)——指该活动弧的起点所表示的事件的最早发生时间**
- **事件$v_k$的最迟发生时间vl(k)——它是指在不推迟整个工程完成的前提下，该事件最迟必须发生的时间。**
- **活动$a_i$的最迟开始时间l(i)——它是指该活动弧的终点所表示事件的最迟发生时间与该活动所需时间之差。**

> ![image-20210827211839220](C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827211839220.png)

### 关键路径推导方法：

#### 	思想：

1. 活动$a_i$的时间余量d(i)=l(i)-e(i)，表示在不增加完成整个工程所需总时间的情况下，活动$a_i$可以拖延的时间
2. 若一个活动的时间余量为零，则说明该活动必须要如期完成，i(i)=0即l(i)=e(i)的活动$a_i$是关键活动
3. 由关键活动组成的路径就是关键路径

#### 步骤：

<img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827213718366.png" alt="image-20210827213718366" style="zoom:50%;" />

1. 求所有事件的最早发生时间ve( )

   > **按==拓扑排序==序列，依次求各个顶点的ve(k):**
   >
   > **ve(源点)=0**
   >
   > **ve(k)= Max {ve(j)+Weight($v_j, v_k$)}，$v_j为v_k$的任意前驱**
   >
   > <img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827214049179.png" alt="image-20210827214049179" style="zoom: 50%;" />
   >
   > 

2. 求所有事件的最迟发生时间vl()

   >按==逆拓扑排序==序列，依次求各个顶点的vl(k):
   >
   >vl(汇点)=ve(汇点)
   >v(k)= Min{vl(j) - Weight($v_j, v_k$)}，$v_j为v_k$的任意后继
   >
   ><img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827214349903.png" alt="image-20210827214349903" style="zoom:50%;" />
   >
   >

3. 求所有活动的最早发生时间e()

   > 若边$<v_k,v_j>$表示活动$a_i$，则有e(i)= ve(k)
   >
   > <img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827214612962.png" alt="image-20210827214612962" style="zoom: 67%;" />

4. 求所有活动的最迟发生时间l()

   > 若边$<v_k,v_j>$表示活动$a_i$，则有l(i)= vl(j) - Weight($v_k,v_j$)
   >
   > <img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827214830193.png" alt="image-20210827214830193" style="zoom:67%;" />

5. 求所有活动的时间余量d()

   > d(i)= l(i) - e(i)
   >
   > <img src="C:\Users\22684\AppData\Roaming\Typora\typora-user-images\image-20210827214942358.png" alt="image-20210827214942358" style="zoom:67%;" />



## 关键活动 关键路径的特性：

- 若关键活动耗时增加，则整个工程的工期将增长
- 缩短关键活动的时间，可以缩短整个工程的工期
- 当缩短到一定程度时，关键活动可能会变成非关键活动
- 可能有多条关键路径，只提高一条关键路径上的关键活动速度并不能缩短整个工程的工期，只有加快那些包在所有关键路径上的关键活动才能达到缩短工期的目的。











