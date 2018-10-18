#ifndef PRIMALGORITHM_H
#define PRIMALGORITHM_H

#include "treenode.h"
#include <QList>
#include <QDebug>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>

QList<TreeNode> primalgorithm(QString fileName);

/*提供prim算法输出来的信息*/
extern QString primInfo;

#endif // PRIMALGORITHM_H
