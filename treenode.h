#ifndef TREENODE_H
#define TREENODE_H

#include<QList>

class TreeNode{
public:
    QString label;
    QList<QPair<int, double>> next;

    /*节点的绝对位置*/
    int startX;
    int startY;

    TreeNode(QString label);
};

#endif // TREENODE_H
