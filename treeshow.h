#ifndef TREESHOW_H
#define TREESHOW_H

#include"treenode.h"
#include<QDialog>
#include<QPainter>
#include<QtMath>
#include<QDebug>
#include<QQueue>
#include<QPen>

class TreeShow:public QDialog
{
public:
    TreeShow(QWidget *parent = 0);
    /*最小生成树的邻接表*/
    QList<TreeNode> treeList;

    /*节点的圆直径*/
    int circleLength = 50;

    /*节点间连线的长度*/
    int lineLength = 80;

    /*直接连接的长度*/
    int strLineLength = 50;

    /*基本度数*/
    double angle = 85.0;

protected:
    void paintEvent(QPaintEvent *event);
private:
    double cos(double value);
    double sin(double value);
    void drawTree(QPaintEvent *event);
};

#endif // TREESHOW_H
