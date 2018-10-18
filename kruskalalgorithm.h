#ifndef KRUSKALALGORITHM_H
#define KRUSKALALGORITHM_H
#define MAX_VALUE 2000
#include "treenode.h"
#include <QList>
#include <QDebug>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>

extern QString kruInfo;

QList<TreeNode> kruskalalgorithm(QString fileName);

/*边类*/
 class Edge{
    public:
        int start; int end; int len;
        Edge() {}
        Edge(int start, int end , int len) {
            this->start = start; this->end = end; this->len = len;
        }
};
#endif // KRUSKALALGORITHM_H
