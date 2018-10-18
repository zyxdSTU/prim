### 画最小生成树

- 功能‘

  - 根据输入文件的无向图信息，生成最小生成树，并把它画出来
  - 输入文件格式
    - 第一行是节点信息
    - 接下来是节点的**距离矩阵**

- 各个文件的说明

  - TreeNode(节点类)

    - label 是节点的标识
    - startX, startY是画最小生成树时，节点所处的左上顶点坐标 (具体可看treeshow.h)
    - **最重要的就是next**
      - QPair<int, double>:  int代表节点的索引， double代表两节点的距离
      - next代表的就是所有其子节点的索引和它们之间的距离

  - primalgorithm(prim算法)

    - fileName 是 输入的文件名参数

    - 其中最核心的就是用Map M来保存节点的前驱节点

      这样可以很方便得找到，节点的子节点

  - mainwindow是一些布局设置

    - 特别的KruEvent, primEvent用来调用相应的算法那

  - treeshow(**重点根据treelist来画最小生成树**)

    - 画的思路

    - >我们首先使初始点(index=0)为根节点，然后画其子节点
      >
      >子节点数量为偶数，两边画相同个数的子节点
      >
      >子节点数量为奇数，中间加一个子节点，两边相同个数的子节点

    - 广度遍历遍历个子节点

      ![](https://raw.githubusercontent.com/zyxdSTU/Image/master/IMG_0591(20181018-223329).jpg)

  - 最后的结果

    ![](https://github.com/zyxdSTU/Image/raw/master/prim%E6%88%AA%E5%9B%BE.PNG)

