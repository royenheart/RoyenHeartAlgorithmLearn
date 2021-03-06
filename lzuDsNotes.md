<center style="font-size:30px;"><b>数据结构章节整理</b></center>

- - -

> 数据结构课堂大作业  
> 章节整理  
> 作者: RoyenHeart  
> 使用Markdown编写  
> 最后编辑于 2021.7.14  

- - -

**编写任务清单**
- [x] 目录
- 代码整理
- 标点符号规范
- 文字整理 
- 语言纠错
- 注释

- - -

<center style="font-size:28px;"><b>目录</b></center>

- [第一章：绪论](#第一章绪论)
	- [主要术语、概念](#主要术语概念)
		- [数据结构](#数据结构)
		- [算法](#算法)
	- [主要模型、原理、方法](#主要模型原理方法)
		- [数据结构的选择与评价](#数据结构的选择与评价)
- [第二章：线性表](#第二章线性表)
	- [主要术语、概念](#主要术语概念-1)
		- [线性表](#线性表)
	- [主要模型、原理、方法](#主要模型原理方法-1)
		- [算法（程序）的处理以及书写策略](#算法程序的处理以及书写策略)
- [第三章：栈和队列](#第三章栈和队列)
	- [主要术语、概念](#主要术语概念-2)
		- [栈（别称为堆栈或堆阵）](#栈别称为堆栈或堆阵)
		- [递归](#递归)
		- [队列](#队列)
	- [主要模型、原理、方法](#主要模型原理方法-2)
		- [多栈共存问题](#多栈共存问题)
		- [栈满的判定](#栈满的判定)
		- [多个栈共存第i个栈假溢出的处理](#多个栈共存第i个栈假溢出的处理)
		- [栈的应用](#栈的应用)
- [第四章：串](#第四章串)
	- [主要术语、概念](#主要术语概念-3)
		- [串](#串)
	- [主要模型、原理、方法](#主要模型原理方法-3)
		- [串的运算在计算机中的实现](#串的运算在计算机中的实现)
		- [串的模式匹配](#串的模式匹配)
	- [主要算法：](#主要算法)
		- [朴素字符串匹配算法（布鲁特夫斯算法）](#朴素字符串匹配算法布鲁特夫斯算法)
		- [KMP算法（字符串模式匹配算法）](#kmp算法字符串模式匹配算法)
- [第五章：数组与广义表](#第五章数组与广义表)
	- [主要术语、概念](#主要术语概念-4)
		- [数组](#数组)
		- [广义表](#广义表)
	- [主要模型、原理、方法](#主要模型原理方法-4)
		- [二维数组（默认行主序）地址计算](#二维数组默认行主序地址计算)
		- [n维数组（默认行主序）地址计算](#n维数组默认行主序地址计算)
		- [数组元素的地址访问](#数组元素的地址访问)
- [第六章：树和二叉树](#第六章树和二叉树)
	- [主要术语、概念](#主要术语概念-5)
		- [树](#树)
		- [二叉树](#二叉树)
	- [主要模型、原理、方法](#主要模型原理方法-5)
		- [二叉树遍历](#二叉树遍历)
		- [二叉排序树的构造](#二叉排序树的构造)
		- [树、森林、二叉树的转换](#树森林二叉树的转换)
	- [主要算法](#主要算法-1)
		- [二叉树的前序（先根）遍历](#二叉树的前序先根遍历)
		- [二叉树的中序（中根）遍历](#二叉树的中序中根遍历)
		- [二叉树的后序（后根）遍历](#二叉树的后序后根遍历)
		- [二叉树遍历实现非递归过程](#二叉树遍历实现非递归过程)
		- [树的遍历](#树的遍历)
		- [森林的遍历](#森林的遍历)
		- [按中序序列线索化二叉树](#按中序序列线索化二叉树)
		- [中序线索树寻找每一个结点的直接后继](#中序线索树寻找每一个结点的直接后继)
		- [中序线索树插入结点](#中序线索树插入结点)
		- [交换二叉树左右子树](#交换二叉树左右子树)
		- [求树的高度](#求树的高度)
		- [二叉排序树中删除结点](#二叉排序树中删除结点)
		- [哈夫曼树的构造](#哈夫曼树的构造)
- [第七章：图](#第七章图)
	- [主要术语、概念](#主要术语概念-6)
		- [图](#图)
	- [主要模型、原理、方法](#主要模型原理方法-6)
		- [图的邻接表构造](#图的邻接表构造)
		- [拓扑排序在计算机中的实现](#拓扑排序在计算机中的实现)
	- [主要算法](#主要算法-2)
		- [图的遍历](#图的遍历)
		- [普里姆（Prim）算法](#普里姆prim算法)
		- [Kruskal算法](#kruskal算法)
- [第九章：查找](#第九章查找)
	- [主要术语、概念](#主要术语概念-7)
		- [排序](#排序)
	- [主要算法](#主要算法-3)
		- [排序算法分析](#排序算法分析)
- [注释](#注释)

- - -

# 第一章：绪论
## 主要术语、概念
### 数据结构
文字概念：给定[^a1]数据对象及其上面定义的操作[^a2]（运算）所形成的系统。  
数学描述：Data Structure = (Class，Operation)  
研究内容：各数据元素的性质和之间的逻辑关系[^a3]以及数据元素在计算机中的存放方式即物理关系。[^a4]
总的来说分为：  
- 逻辑关系（结构）  
- - 自然形态：数据元素之间的一种联系。[^a5]
- - 文字概念：数据元素之间的关系的描述。
- - - 逻辑结构：联系的集合。
- - - 文字描述：数据元素之间逻辑关系的集合。
- - - 数学描述：B = (K，R) {K：数据元素的有限集合 R：数据元素关系集合(K->K，即<K，K>)
- - 逻辑关系(结构)分类：
- - 1. 线性关系（结构），1对1，线性。
- - 2. 树形关系（结构），1对n，非线性。（集合也可属于树形关系，也是1对n）
- - 3. 图关系（结构），m对n，非线性。
- - - 集合：
- - - 1. 序关系，则为线性关系，元素有其唯一直接前驱和直接后继。（头部和尾部分别只有直接后继和直接前驱）
- - - 2. 树型关系，则为非线性关系。
- - 逻辑关系（结构）与数据结构的对比：
- - 逻辑结构：B = (K，R)
- - 数据结构：DS = (C，O)
- - 逻辑结构不同，数学模型不同，数据结构不同。
- 存储关系（结构）
- - 文字概念：在计算机存储空间下，数据元素逻辑关系在存储器中的体现。即数据元素在存储器中的映射。
- - 文字描述：存储关系的集合。
- - 计算机中的实现方法：映射关系[^a6]S，即数据对象K根据S映射关系投影至计算机存储集合M，存储的对象即对象K的像。
- - 存储关系（结构）分类：
- - 分类依据：根据映射关系S的不同进行区分。
- - 1. 顺序关系（结构），存储空间中对应内容的存储地址连续分布。
- - - 构造方法：在存储空间中按连续地址空间顺序依次存放对应数据元素。
- - 2. 链接关系（结构），使用指针[^a7]，实际内容分布离散。
- - - 构造方法：结点存储单元分两部分，一部分存储结点本身信息（数据项），另一部分存放该节点关联的其他结点的地址信息（指针项），即结点（数据元素）再加入指针数据项。
- - 3. 索引关系（结构）
- - - 构造方法：索引区+数据区。数据区—所有存储结点连续存放；索引区—索引指向的存储节点。
- - 4. 散列关系（结构），Hash结构为代表。
- - - 构造方法：根据结点关键字值，由一定函数关系（f）确定对应数据元素的存储地址。
- - - 散列方法数学描述：取K（数据元素、结点、记录）的某一数据项或多个数据项，构成关键字Wik，K对应的存储地址由函数loc（K） = f（Wik） 求得。
- 运算关系  
- - 文字概念：定义在逻辑关系上，其具体实现需要根据对应使用的存储结构。
- - 运算集合：有增、删、改、查等运算。  
### 算法
文字概念：是运算的方法，具体为问题[^a8]的一个具体解决方案，即将输入进行运算得出对应输出的过程。  
文字定义：算法是解决某个问题的指令的有限集。  
算法准则：
- 有穷性：
- - 算法必需在有限时间内做完，即算法能在执行有限个步骤之后终止。
- 确定性：
- - 算法的每一步必须是明确定义，对每一个情况，执行行动需做明确规定。
- 可行性：
- - 算法可行，每条指令应由指令集中（已经实现）的指令构成。
- 输入输出准则：
- - 至少一个输入，可以没有输出。 

算法内涵：是解决问题的策略机制，解决问题过程[^a9]的完整描述。
算法分类：
分类依据：根据信息处理要求和目的性，过程可分为一般过程和函数过程。
1. 一般过程：强调计算的过程本身。
2. 函数过程：强调计算的“值”，即结果。

基于计算的内涵：算法是通过时间表征的指令序列，整个算法是时间上的状态序列（本源性）。  
算法与程序的异同：
| 算法                                                         | 程序                                                                 |
| ------------------------------------------------------------ | -------------------------------------------------------------------- |
| 算法是解决问题的过程，有具体步骤的方法（过程）。             | 程序是算法（思想）的具体实现，即在计算机程序设计语言中的实现。       |
| 算法是概念语言，用以描述解决问题的思想，是抽象化的运算过程。 | 程序需借助特定的程序设计语言进行描述，是对解决问题思想的具体化描述。 |
## 主要模型、原理、方法
### 数据结构的选择与评价
评价标准：实际过程中常需要进行综合考察
1. 作为函数问题的参数的函数计算时间效率。
2. 作为问题的参数的函数计算存储需要量。

算法描述和设计原则：
- 常见描述形式：
- - 1. 具体计算机程序设计语言。
- - 2. 自然语言，基于自然界的语言。但往往具有二义性，难以完全精确表达。优点是可以进行快速描述。
- - 3. PDL语言，伪程序设计语言或伪码语言。
- - 4. 流程图，框图，N-S图，算法思想的图形表示的一种，更加直观。
- 遵循的一般准则：
- - 1. 正确性：能满足具体问题的需求。
- - 2. 易读性：为交流和供他人阅读，其次才是给机器执行。
- - 3. 健壮性（鲁棒性）：当环境变化的时候（例如非法输入），能做出适当的处理或者反映，不会产生多余结果。

算法分析及有效算法：  
文字概念：算法分析是一种目的，用于比较不同算法并选取对相应情况相对高效的算法进行问题的解决。  
分析所用的指标：
- 时间复杂度：
- - 利用某算法处理问题规模为n的输入所需要的时间，数学语言表示为T（n）。
- 空间复杂度：
- - 利用某算法处理问题规模为n的输入所需要花费的空间（对于计算机的存储空间而言），数学语言表示为S（n）。 
- 算法复杂性阶：
- - 指对不同算法的时间和空间复杂度不进行精确值计算，仅考虑其所在的档次即位阶。
- 位阶：
- - 对一正常数C，若算法能在 Cn^2^ 时间内处理问题规模为n的问题，则此算法的时间复杂度为O(n^2^)，即n^2^阶或与n^2^同阶。
- - O(2^n^)，算法与2^n^同阶，为指数时间；O(n^k^)，算法与n^k^同阶，多项式时间。

有效算法：  
文字概念：在通常情况下以多项式时间为界阶的算法成为有效算法，在某些特定问题或者领域上可能有所不同。[^a10]

算法分析具体思路：
- 最坏情况下的时间/空间复杂度。
- 平均情况下的时间/空间复杂度。

原因：规模为n的输入在不同情况下出现的概率是不同的。且实现起来也有一定的困难，主要体现在
1. 输入量分布要进行假设量化。
2. 实现起来也一般考虑算术平均。

通常考虑上述两个参数，选取对特定问题较为合适的算法。也可以考虑复杂度的加权平均特性  

时间复杂性分析：
1. 根据该类问题特点合理选择一种或者n种操作作为标准操作即基础操作。
2. 确定每个算法在给定输入下总执行的标准操作次数，根据次数和问题规模推导得出时间函数。
3. 确定函数的阶，即次数的最大项。

空间复杂度分析：  
即在标准存储上，比较算法所需要的附加存储数据复杂度。

算法设计方法：  
概述：采用系统科学观点。  
方法：自顶[^a11]而下，逐步**求精**。  

如何求精：
1. 分而治之：将问题划分为不相交的子问题，通过子问题的解决以及优化达到整体的解决和优化。
2. 逐步逼近：通过对一个方向的解的研究，反复应用，逼近最佳解。
3. 全面分析：对问题的各种情况进行分析，选择最佳方案或当前最佳方案。

总方向：将复杂问题在不破坏原问题性质的情况下将划分为若干个相对明确的子问题，通过对子问题的解决优化达到整体的解决和优化。  
基本技术：穷举法、分治法、回溯法、分技界限法、动态规划法、贪心法。

PDL描述算法：  
文字概念：是算法（思想）的一种描述形式，为伪码语言。  
作用：描述算法及其思想，书写软件代码规范。  
地位：介于自然语言和具体程序设计语言之间的一种语言。  
文字描述：  
1. 保留具体计算机程序设计语言的框架和描述形式。
2. 去其特异性和技术要求。
3. 结合自然语言的一种用于描述算法处理逻辑语言。

描述优势：
1. 表达能力强。
2. 类似自然语言表达习惯。结构清晰、简单、可读性好。
3. 易于转化为任一种程序设计语言代码。

PDL书写格式及要求：
1. 算法书写框架
2. 词的定义及说明
3. 基本语句
4. 拓展语句

算法书写框架：
- 一般过程：
> PROC 过程名（I/O参数：类名）；
> BEGIN
> {语句组}
> END;

- 函数过程：
> FUNC 函数名（I/O参数:类名）：类型名；
> BEGIN
> {语句组}
> END;

词的定义及说明：
计算机语言中的词汇是一种标识符[^a12]。
PDL的命名规则（词）：
1. 一个以字母开始的字母数字集。
2. 词能传递出有关信息及意义且是对人而言。

标识符：分为过程名和变量或常量名，过程名调用前需及进行定义 ； 变量/常量名调用前需说明，即给出实际的意义。

- 常量说明：
> CONST 常量名=常量值;

- 变量说明：
> VAR 变量名表：数据类型名;

常见数据类型：
1. BOOLEAN：布尔型。
2. CHAR：字符型，针对单字符描述。
3. 子介型：下界……上界，有范围的子集。
4. 构造类型：从基本类型中构造。
5. 数组型：ARRAY [下标类型] OF 成分类型。下标类型一般使用子介型，一个下标符号对应一个内容。
6. 记录型：
>P = RECORD
>域标识符1：类型1;
>……
>域标识符2：类型2;
>END;
7. 指针型：
>TYPE A = ↑类型名;{定义一个新指针类型}
>VAR A：↑类型名

基本语句语法：
- 赋值语句：为符号、语句赋予实际含义。
- - 对计算机：能够解释并执行处理。
- - 对人：表示具体事物的特征，用来表达具体现实事物的含义。
- 格式：
>变量名[^a13]$\leftarrow$表达式[^a14]。
- 条件语句：选择语句，基于一定条件进行指令，语句的选择。
- - 对计算机：根据不同条件选定不同的方法（过程）。
- 格式：
>IF 条件 THEN 语句组
>条件1：IF 条件 THEN 语句组
>条件2：
>IF 条件 THEN 语句组1
>&emsp;&emsp;&emsp;&nbsp; ELSE 语句组2
>条件3：
>IF 条件1 THEN 语句组1
>&emsp;&emsp;&emsp;&emsp; ELSE IF 条件2 THEN 语句组2
>&emsp;&emsp;&emsp;&emsp; ELSE 语句组3

- 循环语句：若条件满足，则重复执行指令组
- - 当型循环：当条件满足时，执行语句组
- 格式：
>WHILE 条件 DO {语句组}
- - 直到型循环：执行语句组直到条件满足
- 格式：
>REPEAT {语句组}； UNTIL 条件
- - 从……到循环：从状态1开始到状态2，每次重复执行语句组
- 格式1：
>FOR 变量$\leftarrow$初值 TO 终值 [STEP 步长值] DO {语句组}
- 格式2：
>FOR 变量$\leftarrow$初值 DOWNTO 终值 [STEP 步长值] DO {语句组}
- 输入语句：接受外界信息
- 格式：
>READ（变量名表）；
- 输出语句：对信息做出处理并输出
- 格式：
>WRITE（表达式[^a15]表）

拓展语句：
- 情况语句：
- 格式：
>CASE
>条件1：语句组1；
>……
>条件n：语句组n；
>[ELSE 语句组n+1]
>ENDCASE
- 一般过程调用：
- 格式：
>CALL 过程名；
- 函数过程调用：通过在表达式中引用函数名完成
- 出错提示语句：
- 格式：
>ERROR（错误信息）；
- 算法终结语句：退出当前操作过程
- 格式:
>EXIT / RETURN 值 / ABORT
>\\EXIT表示直接退出，RETURN表示携带并返回一些信息
>\\ABORT表示前面所作的操作全部废弃
- 复合语句的组织：若干个基本语句组组合形成一个表达具体意义的语句
- 格式：
>[简单语句1；简单语句2……简单语句n；]

指针及相关用法：
使用背景：动态使用数据，运用指向性信息[^a16]来表征需要使用的信息。
指针的用法：
1. 动态分配空间：NEW（P），为P指针分配指向空间。
2. 存储单元引用：指针变量名↑，使用P指针指向的信息。
3. 动态回收空间：DISPOSE（P）。
4. 空地址表示：NIL。

- - -

# 第二章：线性表
## 主要术语、概念
### 线性表  
文字定义：  
1. n>=0个数据元素a1，a2，a3……an组成的有限序列。
2. 除第一、最后元素，其余元素有且仅有一个直接前驱和直接后继。
3. 第一个元素无之间前驱，最后一个元素无直接后继。

数学定义：即表，A = (a1,a2,a3……an)；空表，A = ()  
ai的定义：数据元素，形式化为DATATYPE，表示其数据类型，要根据不同的具体情况选择合适的数据类型，这里的DATATYPE泛指元素的数据类型。  
特性：  
1. 是数据元素的有限序列，且线性表长度≠表中元素个数。  
2. 元素之间呈线性关系，位置取决于自己的逻辑顺序号。  
3. 元素呈线性关系（结构）。  

运算：分表内，表间运算  
1. 确定线性表的长度n（统计运算）。
2. 取线性表第i个数据元素，检验或改变数据项的值。  
3. 在第i-1和i个元素之间插入一个新的数据元素。  
4. 删除第i个数据元素。  
5. 将两个线性表合并成为一个线性表。  
6. 将一个线性表拆成两个及以上的线性表。  
7. 复制线性表。  
8. 对线性表以特定关系、规律通过关键字等进行排序。  

存储结构：  
向量存储结构：  
内涵：线性表最自然与简便的存储方法。  
方法：顺序地分配存储单元，每个数据元素占据相同大小的存储空间。  
数据访问方法：若访问ai，即计算其存储的地址。设A = (a1，a2……an)，每个元素占用一个单元，则
> Loc(ai) = Loc(ai-1) + l = Loc(a1) + l * (i-1)  

特性：  
1. 存储分配呈现出线性结构。  
2. 属于随机存储结构，可以随机进行访问存储。  

与顺序存储的关系：是顺序存储的特例，每个元素占用空间等长。

形式化描述：首地址+偏移量，地址分布连续，元素占用空间大小一样，具体实现为一维数组（静态结构，空间规模调用前需进行定义）。  

数据元素的插入方法：

**本质** 定义在向量存储结构上的一种运算关系。

**含义** 在线性表 A = (a1，a2……an) 第i-1和第i个元素之间插入新元素b，属于一般过程。

**符号表示** INSQLIST（A，B，i，i+1) : A = (a1，a2……an) -> (a1，a2……ai，B，ai+1……an)

计算机存储中的运算：  

异常情况分析：

1. 对异常问题进行总结
2. 得到问题的边界约束
3. 考虑问题的完备性

考虑情况：存储空间已满（伪溢出），插入位置不存在，存储空间为空时的插入。

**分析总结：**
优点：简单，可以进行随机访问数据元素，存储密度高。  
缺点：属于静态分配，插入删除等操作需要移动大量数据元素。

链表表示：  
含义：使用链表存储结构来表达线性表。  
定义：通过指针联系起来的结点的整体。  

类型：  
1. 单链表表示  
```
带表头的单链表表示：
表头结点：head node，增加一个附加结点，放置于链表最前面，不存储信息或存储与链表存储元素无关信息用以辅助计算，即不存储数据元素，此结点被称为头节点
头指针：指向性信息，指向链表第一个结点，第一个结点不等于表头结点
```
```
带表头结点的循环单链表表示：
形式：即在带表头结点的单链表上将最后一个结点指针的指向为NIL改为指向表头结点，达到循环（圈）的形式
优点：在单链表插入数据元素的时候不在需要判断是否为链表第一个元素，可利用表头结点临时存储待插入的数据元素达到优化插入判断
```
2. 图表示

链表中插入元素(运算关系)：  
操作定义：将数据元素B插入链表H中元素a之前
符号表示：INSERT（H，a，B）

运算过程分析：
1、为数据元素B申请空间，进行数据存储
2、以数据元素a为依据获取插入位置，即获得H链表头授权进行数据的查找
3、对应位置在不破坏链表结构的前提下进行插入

操作分析：

常规情况：
1、搜索授权，PH
2、从链表头顺序搜索a
3、在对应位置插入元素B（P空间存储）

边界情况：
1、H = NIL，即链表为空表时，将P作为链表的最后一个结点
2、当链表H的第一个结点即头节点元素值与B相等时，无需搜索，将B作为链表的第一个结点

链表中删除元素(运算关系)：
操作定义：单链表H中删除第一个数据元素为a的结点
符号表示：DELLINKLIST（H，a）

优化后算法PDL表示：

	PROC INSCILINKLIST(VAR H:LINK;A,B:DATATYPE)
	BEGIN
	NEW(S);S↑.DATAB;
	H↑.DATAA;SAVEH;PH↑.NEXT;
	WHILE P↑.DATA ≠ A DO
	[SAVEP;PP↑.NEXT];
	S↑.NEXT  p; SAVE↑.NEXTS;
	END;

带表头结点的双向循环链表表示：
形式：即每个结点增加一个指针项，指向链表表示的序列逆向后对应结点的下一个直接后继结点
优点：可实现逆向查找

静态链表：
形式：以整型变量值作为存储链接指针值（地址）相关联的结点
地址：地址的本质也是整数型数值

图形表示：
链表存储结构分析和总结
优缺点：链表结构存储密度低，不能实现随机访问，存储管理复杂，适合频繁进行插入删除操作的情况下使用。适合数据规模动态变化情况（属于动态分配）
复杂度：时间复杂度主要由查找运算操作构成，空间复杂度为O（n）

## 主要模型、原理、方法
### 算法（程序）的处理以及书写策略
前提：在对问题已经进行抽象，概念化的情况下，对算法（思想）通过多种方式进行形式化表达

形式化表达：可以使用图像、流程图、符号等对抽象的概念进行表达

设计步骤：
1. 分析常规即正常情况下数据处理过程
2. 异常情况处理
3. 将边界情况叠加到常规情况进行约束
4. 对算法过程所使用的参数进行说明

主要算法：
利用线性表解决多项式相加问题：

使用数据结构：线性表
问题分析：
前提：多项式本质也是一个线性表，其数据元素为多项式中每一项中的系数和指数构成的偶对
数据结构模型：
数据元素：（fac，index，next），fac为系数项，index为指数项，next为指针，指向由多项式表示的线性序列中当前结点的下一个结点
逻辑关系：线性关系
存储结构：带表头的双向循环单链表
运算处理：
1、初始化，读取多项式HA和多项式HB，Pa，Pb指针授权
2、（循环）Pa和Pb指向的结点的指数项进行比较， 循环条件为两者指向的结点均不为空（NIL），当两者指数项数值相同时进行相加存放至构造的新多项式中
3、处理HA剩余项或HB剩余项

- - -

# 第三章：栈和队列
## 主要术语、概念
### 栈（别称为堆栈或堆阵）
文字定义：栈为一种抽象的数据结构，在计算机应用中，常指一个特定的存储区域

逻辑定义：栈（STACK）为一个下限为常量，上限可变化的向量，是线性表的一种特殊数据结构

符号表达：LIFO（LAST IN FIRST OUT）结构，是一种抽象数据结构，后进先出数据结构，受限于线性表

图形表示：
与线性表的比较：
栈是线性表数据结构中的一种，拥有自己的逻辑关系和运算关系
栈继承了线性表部分基本关系
相同之处：数据对象（同类事物的集合）和逻辑关系（线性关系）相同
不同之处：操作关系不同，体现在栈是线性表的子集，有所限制

综上，可以得出栈由线性表的比较得出的定义：
1. 栈的运算是线性表的子集
2. 该子集也需要加以限制

栈的运算：
1. 入栈，PUSH(S)，往栈顶插入数据元素
2. 出栈，POP(S)，从栈顶取出元素，删除操作

出入栈：只需要调整栈顶指针指向的位置
栈存储与运算在计算机中的实现：
向量存储结构：
图形表示：
向量存储结构下的运算表示

入栈：
常规情况下即top < max
top <- top + 1;
s[top] <- x;
由于是静态存储结构，需要考虑满栈的问题

出栈：
常规情况下即top >= bottom
y <- s[top]; top <- top-1;
静态存储结构，需要考虑栈空的情况

链式存储结构：即链栈，实际应用过程中往往由于存储密度等原因而较少使用

### 递归

递归定义：被定义项调用自身定义自己，同时有诱导项和基本项。即用早先的值定义新值

递归问题：一个过程问题定义中使用其自身来定义，称为递归

递归类型：直接引用，函数过程中直接调用自身；间接引用，函数过程A中先调用另一函数B，此函数B再调用函数A

递归定义的条件：1、每一次调用的函数规模应比上一次小2、有基本项，即当规模小到一定程度时无需再使用递归定义定义自身，自身已被完整定义可直接利用，成为最小项（基本项）

特征条件：  
1. 被定义项在定义中的应用必有最小尺度
2. 被定义项在最小尺度上无需递归定义

如何使用递归算法：
1. 基本项，列出一个或者几个被定义的函数
2. 诱导项如何由已知结论或规则求出未知函数

一般结构：

	IF 由问题参数构成的条件	THEN 基本函数
						   ELSE 诱导函数

递归算法的优缺点：  
优点：设计方法和实际问题的自然表述形式更接近，易于理解、设计、程序语言进行设计  
缺点：费时费空间  

递归问题非递归化：即将递归过程中隐形的栈空间显性，由计算机管理交给管理者自行建构管理

### 队列

定义：抽象数据结构，是受限的线性表子集，且该子集本身也受到限制。是先进先出线性表

符号表示：先进先出结构，FIFO

逻辑定义：队列（queue）是一个下限和上限只能增加而不能减少的向量

队列和线性表的关系：  
同：逻辑关系，数据对象上相同，存储结构上都可使用向量或者链接表示  
异：运算关系上有所不同--  
1. 是线性表的运算关系的子集
2. 该子集受限

队列运算：
1、ADDQ(X,Q)，入队，即插入数据元素
2、DELQ(S)，出队，即取出数据元素

存储和运算在计算机中的实现：
**存储结构：**  
1. 链式存储
考虑到存储密度和读取速度，显示应用中较少使用
图形表示：
2. 向量存储
即使用向量存储结构存放队列，使用队头和队尾指针指向队头队尾，一般指定下标较小的为队头，较大的为队尾进行插入

**向量存储的优化：**  
1、处理队头和队尾相同时产生的二义性，可以将队首指针指向的位置留空，前移一个位置存储队首元素，则当队首指针=队尾指针时，才表示为空队列
2、假溢出问题，即分配的空间不足时，此时我们可以将之前被删除的队首元素中留下的空位利用，可将线性表模拟成逻辑环，即当队尾、队首指针指到线性表尾时，可以重新换至线性表头，形成逻辑上的环，但实际存储结构仍未向量存储结构
循环链表图形表示：
受限的栈和队列：
概念：栈和队列运算受限于端点，称为限制存取点的表
类型：
1、双端队列，所有插入删除操作限制在表的两端进行
2、双栈，从一端进入的元素只能在该端进行删除，从逻辑上看类似双端队列
3、超队列，一端删除，两端插入的队列
4、超栈，一端插入，两端删除的栈
## 主要模型、原理、方法
### 多栈共存问题
背景：实际应用过程中，往往需要多个栈进行运算，因此怎么样在这些栈中进行互相切换并运算是需要进行解决的问题
解决方式：
情景1：两个栈共存
问题：若最初分配的空间不当，则当栈1空间满的时候会出现假溢出问题，假溢出问题实际上就是分配问题
解决：可将两个栈空间相对存储，即栈1栈顶对栈2栈顶，可以动态分配空间。但实际上当两个栈的栈顶相遇时，仍会出现假溢出问题
情景2：多个栈共存
解决：即在情景1的基础上将多个栈的存储空间串联起来，同时设置每个栈的栈底和栈顶指针。栈底和栈顶指针可用两个线性表来进行存储
弹出时判断栈空
背景：当栈顶指针等于栈底指针时，会出现二义性，即无法判定此时栈空亦或是只有一个元素
解决方式：
引入栈基的概念，栈基BASE（i） = BOTTOM（i）-1
此时判断栈空即可判断base（i）是否等于top（i），即等于当前栈的栈顶
### 栈满的判定
背景：栈满时栈顶的位置需要额外进行依次判断，需要进行优化
解决方式：
1，改变判定方式：第1-n-1个栈， top（i） = base（i+1）；第n个栈，top（i） = m
2、增加一个分量，即虚设一个n+1栈，则只需判定top（i） = base（i+1）即可
### 多个栈共存第i个栈假溢出的处理
解决方式：寻找最近的未满的栈，通过左右移动其空间留出空位，实际情况中需要根据具体的结构寻找合适的移动方法
自然语言描述：
1、估计n个栈所需空间容量：SUM = Σ(i=1 to n)(top(i)-base(i))
2、若sum = m，则溢出停机
3、从第i+1个栈到第n个栈寻找未满的栈
4、若存在，设第j个栈未满：i<j<=m,将栈中top（i+1）到top（j）中的元素右移一个位置，并对应改变受影响的栈的堆底和堆顶指针
5、若不存在，若第j个栈未满：1<=j<i，将栈中base（j+1）+1到top（i）之间的分量左移一个位置
6、元素存储至top（i）+1的存储位置
### 栈的应用
表达式求值
解决方式：表达式实际中可以有三种表示方式，前缀，中缀以及后缀表示法由于栈结构的后进先出特性，适合根据表达式求值
表达式运算定义：
表达式由操作数和算符组成，不同算符之间有运算优先级
使用栈进行表达式的运算
分两个栈，一个为操作数栈，另一个为运算符栈
对一个表达式（中缀表示法），当查找到操作数是一律进操作数栈；当查找到算符时，与运算符栈栈顶元素进行比较优先级：1、当其优先级小于等于堆顶元素时，堆顶元素（运算符）出栈，同时操作数栈出两个元素和弹出的运算符进行运算，得到的结果再次压入操作数栈。2、重复1过程直到算符优先级高于运算符栈栈顶元素

- - -

# 第四章：串
## 主要术语、概念
### 串
概念：字符串，早期作为输入输出的常量
地位：信息处理的基础
定义：一个由零个或多个字符组成的有穷序列称为串
数学描述：A = ‘a1a2a3……an‘
特性：
1、串中所包含的字符个数尾串的长度
长度：串长尾0的串为空串，字符串相等时，两个字符串串长相等且对应位置上的字符相等
2、子串/主串：一个串中，任意个连续字符组成的子序列为该串的子串
运算：
1、ASSIGN(S,CHAR S)，赋值，
2、CONCATENATON(S,T)，联结S,T字符串
3、SUBSTR(S,START,LEN)，取子串
4、STRINDEX(S,T)，求子串序号，确定串T在串S中出现的第一个子串
5、STRINSERT(S,T,I)，串的插入
6、STRDELETE(S,M,N)，串的删除，删除从m到n位置的子串
7、COPY(S,T)，串的复制
8、REPLACE(S,M,N,T)，串的置换
串的存储结构：
顺序存储：
一般使用向量存储结构表示
格式：
1、非压缩格式，存取以字为单位进行字符运算
字：对特定计算机而言，字表示自然的数据单位的术语。字是计算机用于处理事务的一个固定长度的位数
优点是存取方便，运算便利，缺点是空间浪费较大
2、压缩格式，存取时以字节为单位
优点是空间较为节约，缺点是存取较困难
索引存储：
一般用于对多个字符串常量和变量组织
用于对数据库中一个记录的多个字符中的组织
可看成是一个由多行字符组成的文本，每行为一个字符串L
类似目录结构
链接存储：
用单链表或者循环链表，每个结点存储一个字符或者多个字符，需要根据实际应用情况进行选择，使存储空间得到尽可能地节约
## 主要模型、原理、方法
### 串的运算在计算机中的实现
插入运算：把串T插入到S的第i个字符后，具体实现即是将主串拆成两个子串，再分别与串T一起进行构造，异常情况为i<0,S串长=0，T串长=0时
联结运算：串S和串T联结成串R
联结运算情况：1、Ls+Lt <= Lr 2、Ls > Lr 3、Ls < Lr 且 Ls + Lt > Lr
后两种为异常情况
每种情况的解决方式
1、m  Ls ; n  Ls + Lt
2、m  Lr ; n  0;
3、m  Ls ; n  Lr
### 串的模式匹配
概念：
设串：
P = ‘P1P2……Pn‘
S = ‘S1S2……Sn‘
|P| = m ; |S| = n
0 < m < n，且m<<n
S：目标（正文）
P：模式
模式匹配，即在目标中查找模式的过程称为模式匹配
模式的信息类型决定该模式匹配为何种类型的模式匹配
字符串模式匹配：在目标字符串中查找模式字符串的过程
## 主要算法：
### 朴素字符串匹配算法（布鲁特夫斯算法）
即一个字符一个字符进行比较查找，每次对模式移动一位进行比较
### KMP算法（字符串模式匹配算法）
在保证模式匹配的情况下，模式移动的最大位数只与模式字符串本身的性质有关，可以由P的性质得出函数next（j），表示当前位指定的下一次移动的位数
时间复杂度为O（m+n），避免了回退带来的时间的浪费

- - -

# 第五章：数组与广义表
## 主要术语、概念
### 数组
定义：
1、1维数据是一个向量，每个元素是该结构中不可分割的最小单位；n，n>1维数组是向量，每个元素是n-1维数组且具有相同上限/下限
2、从宏观上来看，数组是线性结构，即只关注各个元素的线性排列；从微观上来看，数组是树状结构，即考虑每个元素的具体构成
与向量关系：
向量：是标量，符号表示为VECTOR，即只有量值而无方向的量的一维的有序集合（a1，a2……an）
向量特性：
1、均匀性，各元素具有相同的结构形式，即元素的类型长度相同
2、有序性，各元素有序，有序性通过标号标识，所有标号为整数，此标号是考虑到元素间的先后地位，并使用阿拉伯数字进行标识。即向量存储结构中，各个数据元素之间存在先后地位，并非完全平等
物理关系：向量是数组的特征
逻辑关系：数组是向量的扩充，数组规定同一层的数据元素必须要有相同的结构即相同的上限与下限
为什么？：因为不同的上限与下限会导致非规则空间的生成，计算机将无法处理
运算：
1、给定一组下标，存取对应位置的数据元素
2、给定下标，修改对应数据元素中数据项的值
数组的拓展：
数组本身在逻辑上可拓展为矩阵，常用二维数组表示矩阵
特殊数组（指元素分布规律的矩阵）：
概念：元素分布具有某些性质的矩阵，例如对称性，自反性等
三角矩阵：矩阵呈对角线对称
稀疏矩阵：
定义：
1、稀疏数组：在一个数组中和某元素比较，不相同的元素很少时，称此数组为稀疏数组
某元素：泛指符合条件的数据元素，在讨论中一般采用0代表
2、稀疏矩阵：符号表示为SPARSE-MATRIX，与特殊矩阵如三角矩阵的区别在于矩阵中0元素（即多数元素）分布是否有规律
稀疏矩阵在计算机中的存储：
顺序存储：地址连续
1、三元组表示（triad）
概念：将矩阵全部非0元素线性排列抽象成一个线性表，每个元素包含行、列、只三个数据项，一个元素即一个元素的记录
图形表示：
2、抽象为具有3列的2维数组
概念：本质上也是一个三元组，每一列代表一个数据项
符号表示：A = （0……n，1……3）
解释：一行代表一个元素记录，每一行的每一列可分别存储 原矩阵行值，列值，元素值，n表示非零元个数
三元组缺陷：1、不利于矩阵元素的变化2、插入，删除元素时不利于进行更新
3、索引表示
图形表示
概念：类似目录结构，以行为关键字分类
缺点：要事先计算出每一行的非0元素个数，即不能存储过程中同步进行计算
4、伪地址表示（PSEUDO-ADDRESS）
概念：按照非0元素在矩阵中出现的相对次序作为元素的地址映射关系来组织元素次序
链接存储：
1、单链表表示
概念：矩阵每行非0元素组织在一个单链表中，链表结点保留列号+元素值，
图形表示：
优化：每一行的头指针也可排列呈一个线性表，方便进行访问
2、十字链表表示
概念：对于非空元素根据其行、列，对每一行，每一列建立一个循环链表
数据元素图形表示：
十字链表图形表示：

优化：
1、行表头和列表头共享
2、对表头结点再建立头节点，即整个表的表头结点
3、散列存储：
概念：以元素的行列下标值作为参数构成矩阵非0元素的访问检索
稀疏矩阵的运算：
运算关系主要种类：矩阵转置，矩阵相乘，矩阵相加
特殊矩阵：要考虑结构的一致性，使存储结构的性质不会被破坏
### 广义表
概念：符号表示为GENERALIZED LIST，是0个或者多个原子或者子表所组成的有限序列
数学表达：A = (A1,A2……AI……AN)
表元素Ai：可以是原子即单个数据元素或者一个子表
原子：数据对象中的一个数据元素，是所要描述的某类型对象，是一个确定概念
子表：作为构成元素的表称为构成表的子表，是数据元素的集合
广义表长度：最上层包含的元素个数，不包含递归定义的元素个数
广义表深度：一个表中元素的层次数的最大值
层次：在括号表示中指包含某元素的括号数量
特性：
1、广义表的定义是递归的，即需要通过调用自身来定义自身。是线性表的推广（线性表的数据对象为单个数据元素即原子的集合），元素也可以看作一个广义表
2、广义表的定义没有限制元素的共享性和递归性
共享性：允许共享其他广义表，对其他广义表可通过表名的直接引用
递归性：广义表可使用自身作为元素使用
广义表存储在计算机中的实现：
1、顺序存储
2、链表存储（适用于等长或者非等长情况）
链表等长结点组织
atom ： 0表示该结点为子表，info存储该子表首元素地址值，即作为指向性信息，指针
1表示该节点为原子，info存储有效信息或者地址
link ： 同层下一个元素的地址，指向性信息，指针
广义表的运算：
建立表、增加元素，删除元素
运算复杂度较高，需要考虑递归性质还有共享性质
## 主要模型、原理、方法
### 二维数组（默认行主序）地址计算
设数组A = （c1……d1，c2……d2）,首地址为loc（c1，c2） = AO（A），元素长度为L（表示存储空间的大小）则
LOC(I,J) = AO(A) + [(I-C1)*(D2-C2+1) + (J-C2)]
### n维数组（默认行主序）地址计算
LOC(J1,J2……JN) = AO(A) + Σ(I=1 TO N)(AI*(JI-CI))
AI = L*∏(K=I+1 TO N)(DK-CK+1)    (1<= I <= n)
### 数组元素的地址访问
概念：数组在存储器中的组织结构为静态结构
静态结构：数组定义的时候须给出数组的规模即大小，且数组数据元素的类型相同
元素访问方式：通过给定的下标变量，与数组存放的地址进行计算得出对应下标元素的存储地址并进行访问
下标次序组织：分为行主序和列主序，表示存储的顺序不同。行主序若以图形表达，相当于在一个矩阵中，数据元素的存储以行为单位进行存储，而列主序则以列为单位进行存储
地址计算：按照下标变量实现元素的访问，首先必须获取元素在给定存储结构中存放的地址，再进行访问

- - -

# 第六章：树和二叉树
## 主要术语、概念
### 树
含义：是一种不同于线性结构的抽象数据结构，与线性结构的差异是元素不成线性排列
地位：计算机中最重要的非线性结构
原因：计算机中嵌套结构为资源的组织提供了较为自然的表示方式，在实际生活中树形结构是解决问题的有效工具
讨论内容：
从逻辑角度讨论树形结构的基本概念和运算关系
讨论的结构是树和二叉树
树：
定义：树（tree），是满足如下性质的有限结点构成的非空集合
1、树中有且只有一个称为根的结点，称为根节点，是整棵树的起点
2、除根结点外有多个不相交的结点或者集合（即子树）
数学描述：根结点无前驱，其下的其他每个节点仅有一个前驱
树的特殊种类：
有序树，若树T中子树T1，T2……Tn有相对的次序且被考虑，则T为有序树，T1为第一子树，T2为第二子树直至Tn为第n子树
森林：0棵或者多棵不相交的树的集合
树作为一种抽象数据结构与图论中的树有所不同
图论中的树：
1、树是连通且无回路的无向图
2、生成树，指包含原图中所有结点，但路径有所限制的图
3、最小生成树，指生成树中路径长度（带权图表示路径权值之和，否则为路径条数）中最小的生成树
4、有向树，表示路径有方向
5、根树，一个有向树，若有一个结点入度为0，其余结点都为1，则该树为根数
树作为数据结构而言对应图论中有向有序树中的根树的一种特殊情况，即子集，是限制的子集
树形结构有关术语、概念：
结点度：出度，对一个结点而言其子树的个数
终端结点：出度为0的结点
非终端结点：度非0结点，内点
树的度：树中结点度的max值
父节点，子节点：若<k,k’> ∈ N，则称k是k‘的父节点或者是双亲结点
兄弟结点：若<k,k’> ∈ N 且<k,k’’> ∈ N，则k’和k’’互为兄弟结点
树高度：树中结点的最大层次数，深度
结点层次：递归定义，根节点在第一层，若结点x不是根节点，其父节点在第i层，则x在i+1层
边：树形结构中两个结点的偶对为联结这两个顶点的边，图形表达中用一个线段（无向图）或者箭头（有向图）表示
树形结构的逻辑表示：
1、图形表示：
2、文代图（Venn Diagram）表示法
闭合区域表示集合
3、括弧嵌套表示法
（a（b（d）（e（i）（j））（f））（c（g）（h））））
4、凹入表示法
a1---------
a2-----
a3-
a4-
a5-----
a6-
a7-----
a8---------
树形结构的运算：
1、访问树种具有特性性质的结点
2、对树进行遍历
3、确定某结点的子结点
4、确定某结点的父节点
5、删除某结点的子树
6、用某棵树替换子结点
树的存储在计算机中的实现
1、双亲表示法：
概念：一个结点由其值还有位置决定
数据元素：结点，以<自身性质，双亲>表示
存储文字说明：以一组地址连续的存储结构存储每个结点，对每个空间又存储一个指针指向其双亲位置，类似于静态链表
2、孩子表示法：
概念：一个结点对应的数据元素增加孩子项，即表示其孩子的个数以及位置，反映每一个结点其孩子的性质，由于每一个结点的孩子个数的不同，可采用定长/变长结点进行存储
定长结点：取每个结点孩子的个数的相对最大值作为孩子项的个数
变长结点：依据实际孩子的个数确定孩子项的个数
实际应用中，可使用链表的形式对孩子表示法变形
3、孩子兄弟表示法
概念：一个结点对应的数据元素增加一个孩子项和本层次结点（兄弟）的项
图形表示法：
### 二叉树
概念：是满足如下性质的结点的有限集合
性质：T是空集；或者T包含一个根结点且其余结点分成两个不相交的集合，递归定义，每个集合的根结点同样满足上述性质
与树的异同：
二叉树的子树的个数是确定的（两个），且每棵子树是有序的
基本形态包括具有左右子树，只具有左或右子树，两个子树都没有，空集
特性：
1、第i层最多结点为2^(i-1)个
2、深度为k的树最多有2^k – 1个结点
满二叉树是深度为k且有2^k – 1个结点的二叉树
完全二叉树是深度为k，有n个结点的二叉树，每个结点与k满二叉树，从1到n结点一一对应
3、对任意一棵二叉树，终端结点数为n0，度为2的结点数为n2，则n0 = n2 + 1
4、一个有n结点的完全二叉树深度为⌊log2 n⌋ + 1
5、n结点的完全二叉树，对结点以从根节点为起点进行顺序编号，则对结点i而言，若2*I < n，则结点有左子树而没有右子树，反之两者都有
二叉树存储在计算机中的实现
1、顺序存储（向量）
一维数组存储二叉树的结点，适合完全二叉树，否则一定程度上会造成空间的浪费
2、链表表示
主要以链表表示的孩子表示法进行存储
3、三重（三叉）链表表示，即数据项再加上双亲指针指向双亲结点				线索树：
概念/前置思想：
给定一棵二叉树和给定的遍历规则可以确定一个唯一的遍历线性序列，意味着二叉树的非线性结构中蕴含着线性关系。其确定的线性序列中每个结点即可根据学列得到直接前驱和直接后继
即通过某些线性次序可确定一棵二叉树
一般是先序/后序+中序序列可唯一确定一棵二叉树，因为中序序列中对一个结点作为根结点，则其左右子树正好分布在其两端
序列确定二叉树规则：
1、由先序序列确定树（子树）的根结点
2、由中序序列确定左右子树（根结点的左右）
3、每个子树在确定根结点，即重复1，2操作
线索数的作用/目的：
树中一些结点没有左右子树时，其结点的数据元素对应的数据项将会留空，线索数即利用这些无效指针来表达树在特定遍历线性序列中得到的对应结点的直接前驱和直接后继，使空间利用率提高。这种指向性信息即指针被称为线索
线索二叉树即带线索的二叉树（要给定特定的遍历规则）
二叉树根据特定的遍历规则即遍历线性序列进行添加线索的过程被称为线索化
线索：
在给定的二叉树和给定的遍历规则下
空的左指针域表示直接前驱
空的右指针域表示直接后继
二叉排序树：
概念：符号表示为Binary Sort Tree，即对一个树来说，左子树的所有结点值小于根结点，右子树的所有结点值大于根结点（或者互换）
特性：在中序遍历中的线性序列为有序序列（递增或递减），即排序树中蕴含着有序线性序列
哈夫曼树：
前置概念：两路径的长度为一个结点到另一个结点之间的边的数量；扩充二叉树指的是对原二叉树进行扩充，使原二叉树每个结点都有左右孩子，内节点为原二叉树的孩子，外结点为扩充结点即变换后的二叉树的叶子结点；给定n个结点，构造成顺序二叉树，该二叉树内外路径长度和最小；加权路径下路径长度为一个结点到另一个结点的路径的长度之和
概念：哈夫曼树即给定n个结点，以这几个结点为外结点构造外路径长度之和最小的二叉树
应用：
1、最佳组织结构。由其外结点路径长度最小特性，可将测试判断过程看作对二叉树的查找，可根据每个结果的预测出现概率作为值，构造哈夫曼树形成最佳判断过程（所需走的路径即判定路线长度最小），即分类和判定树的最佳情况
2、可用于构造通讯及数据传输的二进制编码，节省存储空间
## 主要模型、原理、方法
### 二叉树遍历
遍历：符号表示为TRAVERSAL，是一种操作，属于运算关系。其定义是对于给定的数据结构，系统地访问该结构中每个结点，且每个结点仅被访问一次，
系统：依据给定的规则或性质
访问：对元素做的某种处理
概念：对于一个给定的二叉树，对其进行遍历操作
遍历次序：order，即遍历种类
1、层次策略（层序遍历）
自上而下：从左至右或从右至左
自下而上：从左至右或从右至左
2、深度策略：
对一个子树，设定其根（双亲结点）为D，左孩子L，右孩子R
按DLR顺序遍历：前序（先根）遍历
按LDR顺序遍历：中序（中根）遍历
按LRD顺序遍历：后序（后根）遍历
### 二叉排序树的构造
插入结点：当插入一个结点时，由根结点出发，依据左右子树和根结点的特性，逐步向下遍历找到插入结点的合适位置进行插入
删除结点：由中序线性序列的性质，删除结点P分为P结点线性序列后结点前移即P的直接后继代替P；P结点线性序列前结点后移即P的直接前驱代替P（直接前驱代替P的过程同样也是一个删除操作，即需要进行递归操作）
### 树、森林、二叉树的转换
概念：为什么要将树转换为二叉树进行表示？因为二叉树具备一些比较优良的特性：
1、二叉树的访问比较遍历，规定只有左子树和右子树，等长，无需判断孩子个数再进行遍历
2、存储上，树形结构多采取链表结构进行存储，若由K叉树且有n个结点，则会浪费K*n – (n-1)个空间，K越大，则空间利用率会越低，因此采取二叉树能最大化利用存储空间
树转换为二叉树：
前提：约定树为有序树
转换规则：
1、入栈，兄弟结点入栈
2、抹线，抹去兄弟关系，使K叉树分解得以形成二叉树
3、调整子树，兄弟结点作为右子树，同时取消每个结点和右子树的联结
二叉树还原为树：
还原规则：（递归过程）
1、加线，对x，其为双亲结点的最左端孩子，将x的所有右子树上的右孩子结点按顺序与x的双亲结点建立关系（作为孩子）
2、抹线，抹去x所有右子树右孩子之间的关系
3、调整子树
森林转换为二叉树：
前提：森林是0或多个不相交的树的集合
转换规则：
1、树转换，森林中每一棵树转换为二叉树
2、二叉树连接，按照森林中每棵树排列的顺序，即后一棵二叉树作为前一棵二叉树根结点的右子树（因为转换后根结点无右子树）
二叉树还原为森林：
转换规则：
1、抹线，将根结点的右子树所有右孩子（包括根结点与右孩子）之间的连接全部取消，生成n个互不相交的二叉树。
2、还原，对所有二叉树分别进行二叉树还原为树的转换，生成得到的集合即为原森林
## 主要算法
### 二叉树的前序（先根）遍历
方法：递归算法
诱导项：访问根节点，遍历左子树，遍历右子树
（左右子树又可以看成是一个新的树，再次进行先根遍历，即递归）
基本项：规模最小情况下，即当前子树为空集，则执行前一个动作。当左右结点被遍历完后，算法结束
### 二叉树的中序（中根）遍历
方法：递归算法
诱导项：遍历左子树，访问根节点，遍历右子树
基本项：规模最小情况下，即当前子树为空集，则执行前一个动作。当左右结点被遍历完后，算法结束
### 二叉树的后序（后根）遍历
方法：递归算法
诱导项：遍历左子树，遍历右子树，访问根节点
基本项：规模最小情况下，即当前子树为空集，则执行前一个动作。当左右结点被遍历完后，算法结束
### 二叉树遍历实现非递归过程
本质：将计算器管理的栈交由程序员自行构建管理
过程分析：（基本过程，对中序遍历生效）
1、数据结构的搭建，初始化
搜索指针授权 P  T
栈置空（top  0）
2、当栈非空或者P有指向的内容时
P不空，将P入栈并遍历其左子树
P空且栈非空，栈顶元素退栈并进行访问，遍历该元素右子树
3、当栈空且P无指向内容时，遍历完毕，算法结束
PDL描述
PROC INODER(VAR T: BINARYTREE;VAR S: ARRAY[1……MAX] OF BINARYTREE_NODE_TYPE)
BEGIN
I  0; P  T;
REPEAT
WHILE P ≠ NIL DO
[
I  I+1; S[I]  P;
P  P↑.lson;
];
IF I ≠ 0 THEN
[
P  S[I]; I  I-1;
WRITE(P↑.data); {输出p结点}
P P↑.lson;
];
UNTIL (I = 0) AND (P = NIL)
END;
先根，后根分析：
先根只需更改元素访问的顺序即可，即当遍历到某元素时，先进行访问，入栈，退栈的时候无需再进行访问
后根遍历由于对于一个子树来说根节点最后进行访问，所以需要在中序遍历算法的基础上引入辅助结构来记录栈中的结点当前是否可以被访问，可以被访问的条件是当前结点被遍历到第二次，即其右子树已经遍历完的时候可被访问，为此可以将栈的数据元素由单一的树的数据元素再加上一个数据项标记tag当前结点是否可以被访问，例如1表示只访问到第一次，2表示可以访问，若数据项为2，则弹出该元素并进行访问，若为1则遍历其右子树
### 树的遍历
树的遍历不等于二叉树的遍历
层次遍历仍可以使用队列/栈结构进行存储并访问
深度优先遍历先遍历第一棵子树，再访问根结点，最后依次遍历剩余的所有子树（可改变顺序）
### 森林的遍历
第一种：按存储次序对每一棵树进行遍历
第二种：森林转换为二叉树进行遍历
### 按中序序列线索化二叉树
在遍历运算中同时进行，设置两个指针P，PRE，PRE表示为P的直接前驱，P为当前遍历到的结点且由线性序列可知P为PRE的直接后继
即在对P的访问中，添加操作：
若P的左指针域为空，P↑.lson  pre;
若Pre的右指针域为空，Pre↑.rson  P;
算法过程分析：
初始化：pre为nil，p授权为二叉树根结点，pre要独立于中序递归/非递归算法外
进行中序遍历，在中序遍历算法操作的基础上加入如下操作：
1、对P的访问时，若pre的右指针域为空，则pre右指针指向p。若p的左指针域为空，则p的左指针指向pre。要同步更新ltag和rtag（表明对应指针域是指向左右子树还是线索）
2、访问完一个结点进入下一个结点时，p 指向下一个要被访问的结点，同时pre指向当前被访问的结点（符合中序序列的直接前驱和直接后继）
### 中序线索树寻找每一个结点的直接后继
在中序遍历的递归/非递归过程中进行查找
1、若遍历到的P右子树为空（rtag  = 1），则其指向的结点即为其直接后继
2、若P非空，则由中序遍历的特性，其直接后继为右子树左链第一个左指针域为空即左指针域是存放直接前驱的结点，方法为从P结点的右孩子出发，沿其左子树左链往下一直查找指针直至找到符合条件的指针
依据中序遍历遍历中序线索树
1、中序遍历直到结点右指针域存放直接后继的结点
2、访问P并以其存放的直接后继的结点作为起点作为下一步遍历的结点
3、重复1、2直至遍历完毕
### 中序线索树插入结点
本质：插入结点的过程中保持线索正确
概念：由先序序列可知，插入节点只会改变两个结点的直接前驱和后继，而被插入的结点的直接前驱和直接后继为这两个结点
假设P插入S结点后
1、S右子树为空，直接插入，同时P的直接前驱指向S，P的直接后继指向S的直接后继，S直接后继指向P（线索移动，加线索，孩子连接）
2、寻找S的直接后继Q，S的右子树连接至P的右子树，S的右子树改为以P为根结点的子树，P的左孩子改为S，Q的左孩子指向P
### 交换二叉树左右子树
本质：即交换二叉树中所有结点的左右子树，可以在遍历的过程（递归算法中）进行交换，即左右指针域指向交换
### 求树的高度
递归算法
诱导项：结点有子树，则该节点高度为1加上左右子树中最大的高度
基本想：结点为空，则其高度为0
### 二叉排序树中删除结点
1、若删除结点P无左右子树，直接删除（叶子结点）
2、若P只有左或右子树，直接将其左、右子树代替P
3、若P有左和右子树：
找到直接前驱结点S
执行删除S的操作（递归调用，基本项为S无左子树，同时保留结点S）
将S代替P
### 哈夫曼树的构造
两个基本操作：排序、生成
操作分析：
1、将给定的结点序列依据结点关键字排序
2、选定最小的两个结点依次作为左和右孩子连接至构造的双亲节点上，其双亲结点的值为两个结点值相加，从序列中删去这两个结点（不是真正删去），同时双亲结点加入序列
3、再次对序列排序
4、重复上述步骤直至剩下一个结点，此时生成的树即为哈夫曼树

- - -

# 第七章：图
## 主要术语、概念
### 图
概述：
1、与树形结构和线性结构相比，其元素之间的关系为n对n，结点之间无层次关系，也无直接前驱和直接后继
2、地位上是重要的非线性数据结构
讨论内容：
1、计算机中如何选用恰当的存储结构表示图结构
2、图的遍历思想和方式
3、根据图形成生成树
4、找最短路径
5、拓扑排序，根据拓扑排序求关键路径
概念：
文字描述：图（graph）是由n（n>=1）个结点v1，v2……vn构成的数据G(集合)为图,且结点集V = {v1,v2……vn}上定义的每个结点的关系为反自反
数学表达:G = (V,E),V为顶点集合,E为边的集合
逻辑关系:注重元素之间的实际关系,即自然界中实际的关系而并非组织关系
组织关系:组织关系是为了更方便地对数据整理、增删、管理而认为增加的关系
研究对象：简单图，图反自反且非多重图
有向图：
事物，元素之间的地位不平等
概念：图G中，若每个关系是顶点的有序对，则G为有向图
数学定义：有向图为<Vi，Vj>，若<Vi,Vj>∈E（G），则Vi被称作边始点，Vj被称作边终点；或称Vi链接到Vj，Vj是从Vi链接起来的；或称<Vi,Vj>关联Vi，Vj
无向图：
概念：每个关系都是顶点的无序对，为无向图
推论：若n个结点的无向图，有n*(n-1)/2条边，则该无向图被称为无向完全图
由边的条数可区分稀疏图和稠密图（依据具体情况）
顶点的度、入度、出度：
概念：在图中，顶点的度即与该顶点关联的边的数目/邻接和被邻接的边数之和
入度出度：G为有向图（入度出度是在有向图中讨论的），以Vi为终点的边数目被称为Vi的入度；以Vi为起点的边数目被称为Vi的出度；Vi的度为Vi出度和 入度两者之和
推论：1、若Di是Vi的度，则边数count（E）= (1/2)*Σ(i=1 to n)Di;出度为0的顶点为终端顶点
子图：
概念：若G‘ = （V’，E‘），V’是V的子集，E‘是E的子集，有图G = （V，E），则称G’是G的子图
路径，回路，图跟：
路径：
概念：点、边的交替序列
数学定义：对G（V，E），存在（Vp，Vi1，Vi2……，Vq）使（Vp，Vi1）（Vi1，Vi2）……（Vin，Vq）∈E（G），则可以说Vp到Vq存在一条路径
特殊：简单路径是指路径仅会经过同一点，同一边一次
回路：
概念：简单回路指Vp=Vq，仅Vp和Vq（同一顶点）经过两次，其余性质与简单路径相同
图根：
若有向图中存在Vo，从Vo有路径使其可抵达图中其他所有顶点，则Vo为图根，G为有根图
连通图：
无向图：对任意两个顶点，都存在一条路径连接两点，则称该无向图连通
有向图：对图内任意两个顶点V1，V2，都存在路径以V1为起点V2为终点以及V2起点V1终点，则称该有向图强连通
连通分量：若图的子集不与剩下部分连通/强连通，则称该子集为图的连通分量（也是一个图）
网：
概念：在图的基础上每一条边添加对应的权值（数值），即网是带权的图
图的存储在计算机中的实现：
1、邻接矩阵
定义：表示顶点之间邻接关系的矩阵
数学定义：（非网）
Mij = 1 ， 当<Vi,Vj> 或 (Vi，Vj) ∈ E（G）； 0，非1的情况下
对无向图来说为对称矩阵，结点度等于Σ(j=1 to n)Mij
对有向图当非有向完全图时，为非对称矩阵，Σ(j=1 to n)Mij+Σ(i=1 to n)Mij是一个结点的度（入度+出度）
特性：矩阵与结点标定次序有关；便于随机访问结点状态
网的邻接矩阵：（n阶方针）Mij = Wij，<Vi,Vj>或(Vi,Vj)∈E(G)；0，非Wij情况
2、邻接表
概念：对图的每一个顶点建立链表，n个结点有n个链表，每个链表头以线性表存储，第i个结点（指组织关系中的编号）为线性表中第i个元素
无向图：与Vi邻接结点的收集
特性：Vi的链表长度（不包括自身）为Vi的度；总表的结点数是2e，即边数的二倍
有向图：以Vi为起点的结点的收集
特性：Vi的链表长度（不包括自身）为Vi的出度（非逆邻接表）；总表的结点数等于e即边的数量；总空间为n+e，结点数+边数
3、邻接多重表
概念：以边为单位，同时关注边两个邻接顶点，即以边作为一个数据元素
数据元素图形表示：
连通性及最小生成树：
求图的连通分量：
对无向图而言，即输出依次遍历过程中所有被访问过的顶点和边
对有向图而言，输出两次遍历（遍历和逆向遍历）过程中均被访问过的顶点和边
输出的图即为连通分量/强连通分量
生成树：
概念：对G的遍历过程中，每次访问过的边和顶点构成的图即G的生成子图
求生成树：
通过图的遍历可获取其生成子图，而对每一个生成子图实际上是树结构（有n-1条边和n个顶点且构成连通图，是原图的极小连通子图）
其生成子图可以构成一棵树称为生成树，生成树是图的最小结构因为有n-1条边，n个顶点且构成连通图
非连通情况：对非连通图和非强连通图（有向图），任一结点出发遍历只能生成森林
结果不唯一：生成子图（生成树）很大程度上依赖图选取的存储结构、遍历时的出发顶点，故条件不同生成树有一定的不同
由遍历方法可构造极小连通子图
生成过程中
生成过程的情况：
1、图连通 2、图强连通（有向图的概念） 3、出发点Vo为图根
最小生成树：
概念：最小生成树是边的权值之和最小的由网络生成的生成树
有向无环图及应用：
概念：无环的有向图称为有向无环图，DAG即directed acyclic graph
拓扑排序：
前置概念：
AOV-网：若在有向图 G 中, 顶点表示活动或任务, 有向边表示活动或任务之间的优先关系, 则此有向图称为顶点表示活动的网络，AOV-网，Activity On Vertex
Network。一个 AOV-网要能够表达一个可执行的工程则其优先关系应当是反自反的
提出背景：当AOV-网存在回路即存在以相同顶点为始点和终点的路径，则说明某项活动的能否进行是要以自身任务的完成作为先决条件。这种情况对于工程而言可以说出现了有悖于工程进行的逻辑，对一个程序来说相当于出现了死循环。因此对于一个给定的 AOV-网, 当分析该网所表示的工程是否可以实现时, 需通过检查其是否有回路来进行。一种有效的方法就是拓扑排序 (寻找图的偏序序列的过程)
概念：对于有向图 G=(V,E),V 中的顶点的线性序列 (Vi1, Vi2, …, Vin)，称作一个拓扑序列，若此结点序列满足如下条件：在 G 中从顶点 u 到顶点 v 有一条路径，则在序列中 u 必在 v 之前。拓扑序列不唯一任何无环的有向图，其顶点都可以在一个拓扑序列中。而拓扑排序则是根据给定的图找到其拓扑序列的过程
基本思想：
1、 在图中选择一个入度为零的顶点
2.、访问该顶点，从图中删除此顶点及其所有的出边
3、重复1、2步骤，直至所有顶点都被输出，此时表明拓扑排序结束，已生成拓扑序列；若图中再无入度为0的顶点且未输出所有顶点，则表示该图非DAG图，即存在环/回路，拓扑排序过程无法正常完成
关键路径：
前置概念：
AOE-网：与 AOV-网对应的是 AOE 网。AOE-网在企业管理、工程计划等当中有广泛的应用。其定义为若带权有向图中顶点表示事件，有向边表示活动，权表示活动持续的时间，则该有向图称为边表示活动的网络 ，AOE-网，Activity On Edge Network，表示实际工程的 AOE-网，应该是无环的，且存在唯一入度为零的起始顶点 (始点)，以及唯一的出度为零的完成顶点 (终点)
关注内容：
1、利用事件 AOE-网可以进行工程安排估算，研究完成整个工程至少需要多少时间
2、为缩短整个工程的完成时间，应该加快哪些活动的速度
可采取的技术：（用以解决上述问题）
1 PERT(Program Evaluation and Review Technique)(程序评价和审定技术)
2 CPM(Critical Path Method)(关键路径法)
3 RAMPS(Resources Allocation and Multi-Project Scheduling )(资源分配和多项目调度)
最短路径：
单源最短路径：单源最短路径是指从一个顶点到其它各顶点之间的最短路径 (Single-sourceshortest Path)。
迪杰斯特拉算法：迪杰斯特拉于1959年提出了一个寻找单源最短路径的方法。其基本思想是：设置一个顶点集合 S，并不断地作贪心选择扩充这个集合						算法分析：迪杰斯特拉算法属于算法设计方法中的贪心算法类，即总是作出当前看来最好的选择，通过实现局部最优达到整体最优
## 主要模型、原理、方法
### 图的邻接表构造
建立邻接表：
1、给出图的所有顶点
2、逐步给出图的所有边
3、对每一条边，给出其关联结点u，v
4、为每一条边申请存储空间
5、插入链表，无向图插入以u和以v为头结点的链表，直接插入链表表头后
### 拓扑排序在计算机中的实现
1、使用邻接矩阵
过程分析：
1、选择入度为0的顶点u，即u所在列均为0（均无结点与之关联）
2、访问顶点（输出），删除出边，即将u所在行所有元素置0
输出：可利用辅助数组S[i]表示每个结点在拓扑序列中的顺序，i位置为0表示当前结点未输出，n表示其在对应拓扑序列中的次序
具体算法步骤：
1、初始化：辅助数组S置零
2、寻找未被输出的且所在列全为0的结点 u，如果没有，则算法终止。若 S 中所有元素都有输出编号（或者添加辅助变量存储已输出顶点数，若顶点数等于n），则拓扑排序完成；否则有环，拓扑排序失败
1. 将输出次序号赋给 S[u]
2. 把第 u 行置零
3. 重复2-4动作直至算法结束
2、使用邻接表：
前置条件：
存储结构优化：拓扑排序过程需要获取结点入度需使用逆邻接表，但若要删除所有出边，需对邻接表本身进行运算，而两个邻接表将无法保持结构一致。因此在邻接表存储结构中每一个数据元素添加入度项，用于存储计算每个结点的入度
设置缓存区存储所有可以进行输出的结点：拓扑排序中需要选择入度为0的结点，但每次进行重新运算将会消耗资源，因此可以设置一个辅助结构存储一次计算后可以进行输出的结点，减少计算。实际中S 可以采用栈存储结构（缓冲区）
基本思想：
1、 初始化：搜索邻接表中入度为零的顶点，使其入栈
2.、当栈非空时，进行拓扑排序：
(a) 退栈，输出栈顶元素 u
(b)（循环）在邻接表中扫描 u 的直接后继顶点 k
– 将 k 入度减一
– 若此时 k 的入度为零，则 k 入栈
3、若栈空，输出元素不足 n 存在回路，否则拓扑排序完成
栈结构优化：邻接表中的入度域参与运算，而在拓扑排序后，该域将失去实际意义；同时入度为 0 的顶点的入度域是不会参与运算的, 因此为节省空间，S 可借用这些单元作为栈的存储空间；这样可以将入度为零的顶点的入度域组织成一个静态链表
## 主要算法
### 图的遍历
定义：建立在图基础上的遍历操作
1、给出给定图G和一个顶点Vo（出发点）
2、从Vo出发系统地访问图G中每一个顶点，每个顶点仅被访问一次
怎么实现访问一次：添加辅助结构visited[1……n]，表示对应编号顶点（组织关系中给出的编号），1表示已经访问过，0表示未被访问过
搜索策略：
1、深度优先搜索，DFS即depth-first search
概念：搜索过程中结点拓展（访问）次序向某一分支纵深推进，到底后回溯
2、广度优先搜索，BFS即breadth-first search
概念：搜索过程中，对当前所在层次的所有结点逐个进行拓展（访问），再推进到下一层次拓展
图的深度优先遍历：
基本思想
1、初始：访问出发结点Vo
2、诱导项：选择一个Vo邻接到且未被访问过的结点u，再从u开始深度优先搜索（即重复1、2）
3、基本项：若一个结点无法再访问到未被访问过的结点，则此次深度优先搜索（一条路径）结束
4、算法结束：任意顶点都无法再访问到其他未被访问的顶点，则整个深度优先搜索过程结束，算法结束
图的广度优先遍历：
基本思想：
1、初始：访问出发结点Vo
2、访问Vo邻接到的所有未被访问过的结点
3、再依次以上一步访问的所有结点为起始点进行广度优先遍历即重复1和2步骤
4、基本项：若一个结点再无法访问到未被访问的结点，则此次广度优先遍历结束
5、算法结束：任意顶点都无法再访问到其他未被访问的顶点，则整个广度优先遍历结束
计算机实现：
可使用队列：
1、先访问，再入队
2、先入队，再访问
### 普里姆（Prim）算法
基本思想：设G = （V，E），其中V = （V1，V2，……，Vn）是图G的顶点集合，Prim算法由一个初始顶点Vo开始，每次依据当前情况选择一条边加入生成树，最终生长成一棵具有最小代价的生成树
初始建立两个集合U，V，V存储原图，U加入出发点Vo并从V中删去每一步找出一个权值最小的边（u，v），u∈U，v∈（V-U）
即从一点出发找到已加入的点集到未加入的点集中权值最小的一条路径不断进行生成
### Kruskal算法
基本思想：设图 G = （V，E），初始化从集合T = （V，Ø）开始，此时生成树是一个n个孤立顶点组成的一个子图，生成过程即使得n个连通分量通过原图逐渐成为一个连通分量并使权值和最小
基本步骤：
1、初始化集合T = （V，Ø）
2、按照权值递增的顺序对原图E中所有边进行判断：若边连通了T中两个不同连通分量的顶点即两个互不连通的顶点，将边加入T直至T集合已包含n-1条边，此时算法结束，T所表示的图形即为原图的最小生成树

- - -

# 第九章：查找
## 主要术语、概念
### 排序
概述：
1、排序是数据结构运算关系层面的问题，研究其相关的运算关系
2、排序 (sorting) 是计算机程序设计中的一种重要的运算关系，其作用是对数据元素的任意序列，按照要求重新排列成按一定规则有序的序列
有序：是相对概念，是相对于某一特定规则或者关系的，日常生活中所使用的大小排序即是建立在大小关系（实质上是一个偏序关系）上的
3、排序通常可以理解为：根据与对象中所包含的关键字和其上的相关规则，对数据对象进行排列整理的过程
相关概念：
1、关键字 (key)
如果数据元素中特定数据项可以标识一个数据元素，则将该数据项称为该数据元素的关键字。关键字不反映事物的本质，用于指示对应事物
2、主、次关键字
主关键字：若关键字可以唯一地标识一个记录，则此关键字称为主关键字（Major key/Primary Key），实际应用中关键字默认都指主关键字
Major key:在一个记中的最主要的关键字
Primary key:在文件组织中, 进行大量访问时所用关键字
次关键字：可以识别若干记录的关键字称次关键字
3、排序：设含有 n 个记录的集合为 R=r1,r2,…,rn, 其对应的关键字集合为 K=k1,k2,…,kn, 若给定关系 α，按照关系 α 针对关键字集合 K 对 R 进行运算，使得 R 有如下
序列:(rα1, rα2 ,…, rαn)，则这个操作过程称为排序
排序的本质：本质是在关系 α 下寻找 R 的一种排列的过程
4、排序的稳定性：在排序关系下，假设排序前 ri 在 rj 之前，排序之后领先关系不变，则称此排序过程和排序方法是稳定的，否则是不稳定的。即根据排序关系ri和rj的关键字等价，若排序后两者间领先关系不变，则该排序称为稳定的
排序分类：
排序一般涉及大量数据，而大规模数据一般都存放于外部存储器上且以文
件的形式出现。因此，依据排序过程中数据所处位置（或数据规模），可将排序分为两大类：
1、内 (部) 排序:
将整个待排序的文件装入内存，并在其中进行排序, 这种排序过程称为内(部) 排序 (internal sorting)
2、外 (部) 排序:
由于数据规模过大，排序过程不能在内存中一次完成，需要不断进行内外存数据交换才能完成排序，这样的排序过程称外 (部) 排序 (external sorting)
排序的应用：
1、作为检索的辅助手段
2、作为数据项匹配的手段
排序运算在计算机中借助的存储结构：
1、向量：
待排序的初始文件各记录依其自然顺序存放在连续的一块地址空间中
2、链表结构：
记录以结点形式按记录中的原始次序链接起来
3、地址向量结构：
将要排序文件的各个记录存储到内存的各个块中，这些块的地址一般是不连续的。按各记录的原始次序，将这些的块的首地址依次存入内存的一块连续单元
中，由各块的首地址组成了一个向量，即地址向量
地址向量的引入可实现局部连续, 整体不连续的组织模式，这种模式与索引结构类似
## 主要算法
### 排序算法分析
插入排序：
基本思想：
1、每次只考虑一个待排记录 r
2、将 r 依据给定的排序关系插入到一个已经有序的文件中符合有序的位置
3、重复上述过程直到全部记录已进行排序为止
直接插入排序 (straight insertion sort)：
1、将要排序的源文件F=R1,R2,…,Rn,视为两部分：F’=R1; F”= R2,…,Rn
2、对 F’ 和 F’’ 重复如下工作：
(a)从 F’’ 中取出一个记录 Ri，并将 Ri 从 F’’ 中删除
(b)将 Ri 插入到 F’ 并使 F’ 线性有序
第 i 个记录的插入过程：
1、进行插入准备：先取出第 i 个元素放入 x 临时存储（x<-R[i]; j<-i-1）
2、寻找插入位置：向前进行比较, 条件：(x.key<R[j].key) and (1 ≤ j)
3、插入元素：R[j+1]<-x
二分插入排序 (dichotomising insertion sort)：
概念：也称折半插入排序。即采用二分策略搜索插入的位置
算法改进：仅对比较次数有改善，移动次数无影响
算法过程：即在插入已有序的序列时，对序列进行二分查找寻找插入位置
2-路插入排序：
概念：在二分插入排序的基础上再改进。即将有序序列分成头和尾插入排序，结束后进行连接即可得到有序序列
目的：减少排序过程中记录的移动次数
算法改进：需借助辅助空间 D[1..n]
表插入排序 (list inserting sort)：
概念：采用链式结构来组织待排序的数据元素。是一种较为古典的算法且仅适用于链式结构下进行排序分类。即利用链式结构的特点，通过变更记录指针来调整记录的逻辑顺序，从而在不发生记录迁移的情况下完成排序
希尔排序 (Shell sort)：
又称缩小增量法 (diminishing increment sort), 是一种快速的排序方法
快速：指在同类型算法中平均次数较少
基本思想：
把对源文件 F 的排序分成多步来完成，算法在每步中取一个步长 d并将 F 逻辑上看成 d 个文件
1、按照插入排序的办法把这 d 个文件分别排序
2、然后缩小 d
3、重复 1-2步骤直至 d=1 的一次排序完成为止
交换排序算法分析：
基本思想：
每次考虑两个待排序的记录。依据排序关系两两比较待排序记录，并交换不满足顺序要求的那些偶对，直到全部满足为止
起泡排序 (bubble sort)：
基本思想：初始比较 R1 与 R2, 如果 R1 依据给定规则/关系小/大, 则交换 R1 和 R2，然后对 R2 和 R3 做同样的处理，重复此过程直到处理完 Rn-1 和 Rn 的比较与交换。从 (R1, R2), (R2, R3), 直到 (Rn-1, Rn) 的 n-1 次比较和交换过程称为一趟起泡。一趟起泡的结果是将关系下最大/小的元素移到序列中最后已排序部分之前（若进行反向判断则最终结果相反）。而第二趟起泡只需进行 (R1, R2), (R2, R3),…,(Rn-2, Rn-1) 的比较和交换。使得最多做 n-1 次起泡过程即可得到最终有序序列。若一趟起泡中没有发现元素交换，则可认为序列有序，可终止算法过程输出对应有序序列
分析：
1、算法是稳定的;
2、算法时间复杂性分析：
3、算法空间复杂性分析：O(1)
快速排序 (quick sort)：
概述：快速排序也称分区交换排序，或 Hoare 排序。1962 年首先由霍尔提出。是至今为止内部 (比较) 排序中较快的一种。它有广泛的应用，典型的应用是UNIX 系统调用库函数例程中的 qsort 函数。但快速排序往往由于最差时间代价的性能而在某些应用中无法采用。越接近有序性能越差。主要特点是采取了分治的思想
基本思想：
(以下比较指关键的比较，关键字指排序关键字)
1、在待排序的 n 个记录中任取一个记录 r，作为轴心元素，可取序列区间中的第一个
2、以 r 为标准将所有记录分为左右两组。第 1 组中各记录的关键字都小于 r 的关键字；第 2 组中各记录的关键字都大于 r 的关键字（依据给定关系）
3、将 r 排在这两组中间 (最终位置)，这一过程称为一趟快排
4、然后对这两组分别重复1、3过程，直到所有记录都已被排序
算法分析：初始化：创建额外空间 x 存放取出来的元素；设置两个指针 i和j。i初始赋值为序列的下限，j赋值为序列的上限，x初始赋值为序列的第一个元素
处理：
1、当 (i < j) 且 R[j].key ＞ x.key 时，j 指针前进（jj-1）
2、当 i ＜ j，则：
(a) R[j]R[i]; i+1i
(b) 当 (i<j) 且 R[i].key ＜ x.key 时，i 指针前进(ii+1)
(c) 如果 i ＜ j ，则：R[i]R[j]; j-1j
3、i=j ，则本趟结束；R[i]  x；同时再次递归调用，序列范围为l-i-1和j+1-u
快速排序图形表示：

选择排序算法分析：
概念：每次考虑一个数据元素的最终位置。每步从待排序的记录中挑选一个当前依据关系针对关键字最小 (或最大) 的结点，将其放在应有位置，直到全部记录排完为止
直接选择排序 (straight selection sort)：
基本思想：
1、首先在所有记录中选出最小的记录；
2、将选出的记录与第一记录交换；
3、在剩下的记录中再送出 (全局) 次最小的记录与第二个记录进行交换；
4、依次类推，直到全部记录已被排序为止。
树形选择排序 (tree selection sort)：
概念：即保留上一次排序的结果，类似选拔赛，可以减少比较的次数
堆排序 (heap sort)：
概念：设 L 是长度为 n 的表，当 1≤i≤⌊n/2⌋时，其数据元素满足：L(i)≤L(2i)且 L(i)≤L(2i+1)（或可进行反转）则称 L 是一个堆。其中将 L(1)称为堆顶（树根），L(n)称为堆底。堆在存储结构上是顺序表，在逻辑结构上是树
堆排序：即构造堆，每次插入删除堆保持堆结构，由堆的定义我们可以得出堆的根结点必为最小/最大的元素，因此每次输出堆顶，并通过运算重新生成堆，由此得到的输出序列即为有序序列
合并排序算法分析：
概念：合并排序或归并排序，要求待排序文件已经部分排序。首先把一个集合中的数据元素分成若干个子集，对每个子集中的元素进行排序，再将所得到的有序子集进行合并
二路归并排序：
概念：如果文件中有 n 个记录，可将文件看成 n 个有序的子文件，使文件“部分有序”的状态，因而可以使用合并排序
通常可以先将每两个子文件进行合并，得到 n/2（向上取整）个部分有序的较大子文件，每个子文件含有两个记录；再将这些子文件合并，反复进行该过程合并成一个文件，此时排序结束，得到的序列有序
枚举排序：利用统计的方法，即统计小于 (或大于) 关键字 K 的个数。由此可见，计数排序 (或枚举排序,merge sort) 的基础在于比较关键字和计数。为此，每个记录需带一个计数器 (count, 存放小于该记录的排序关键字的记录个数)

# 注释
[^a1]:**给定**：即具体化，限定对象的范围和性质。  
[^a2]:**操作**：处理的需求，即运算。  
[^a3]:**逻辑关系**：对数据间关系的人为理解和解释，侧重人的理解。    
[^a4]:**物理关系**：对数据的运算（操作），数据的运算关系。  
[^a5]:**联系**：事物的关联方式或邻接关系。反映人对数据、现实的理解。  
[^a6]:**映射关系**：是逻辑关系在计算机中的表现，表现现实中的逻辑关系。  
[^a7]:**指针**：存储指向元素在存储空间中分配的空间的地址的信息（值）。
[^a8]:**问题**：对于计算而言是需要完成的任务，即对应一组输入至一组或多组输出的过程。
[^a9]:**过程**：事物发展或事物进行所经过的程序即次序，基于时间表征程：事物发展或事物进行所经过的程序即次序，基于时间表征。
[^a10]:**难解性问题**：不存在多项式时间为界限的算法可以进行解决，则称这个算法是难解的。
[^a11]:**顶**：表述问题的综合以及问题抽象全貌 ; **底**：问题的具体化，包含问题实现的细节。
[^a12]:**标识符**：语言中的字符按一定规则形成具有特定含义的词。
[^a13]:**变量名**：一个符号，赋予其含义可表示具体事物。
[^a14]:**表达式**：具有具体事物的意义。
[^a15]:**表达式**：输出信息的含义、讯息，表征特定事物的意义。
[^a16]:**指向性信息**：即指针，表示包含的信息指向另一个信息。