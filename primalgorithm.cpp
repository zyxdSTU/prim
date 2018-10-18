#ifndef PRIMALGORITHM_CPP
#define PRIMALGORITHM_CPP
#include "primalgorithm.h"

QString primInfo;

QList<TreeNode> primalgorithm(QString fileName) {
    /*节点信息*/
    QList<TreeNode> treeList;

    /*邻接矩阵*/
    QVector<QVector<int>> matrix;

    /*读取文件信息*/
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream out(&file); out.setCodec(QTextCodec::codecForName("UTF-8"));
    bool flag = false;
    while (!out.atEnd()) {
        QString strReadLine = out.readLine();
        /*第一行节点信息, 其他行是距离*/
        QStringList strList = strReadLine.split(' ', QString::SkipEmptyParts);

        if(flag == false) {
            for(QString element : strList) treeList.append(TreeNode(element));
            flag = true;
        }else{
            QVector<int> vector;
            for(QString element : strList) vector.push_back(element.toInt());
            matrix.push_back(vector);
        }
    }

   qDebug() << "ok" << endl;

   int n = treeList.size();

   /*初始化标志数组*/
   bool visited[n];
   for(int i = 0; i < n; i++) visited[i] = false;

   visited[0] = true;

   int distance[n];

   /*记录加入边记录*/
   QMap<int, int> M;

   /*最小生成树大小*/
   int count = 0;

   /*初始化距离*/
   for(int i = 1; i < n; i++)  {
       distance[i] = matrix[0][i];
       M.insert(i, 0);
   }

   /*找到n-1个点*/
   for(int i = 1; i < n; i++) {

       int min = INT_MAX;
       int w = 0;

       for(int j = 0; j < n; j++) {
           if(visited[j]) continue;
           if(distance[j] < min) {
               min = distance[j];
               w = j;
           }
       }
       count += min;
       visited[w] = true;

       primInfo += QString("第 %1 条边: %2->%3 距离: %4\n").arg(QString::number(i)).arg(treeList[M[w]].label).arg(treeList[w].label)
               .arg(QString::number(min));

       treeList[M[w]].next.append(QPair<int, double>(w, min));


       /*更新距离*/
       for(int j = 1; j < n; j++){
           if(visited[j]) continue;
           if(matrix[w][j] < distance[j]) {
               distance[j] = matrix[w][j];
               M[j] = w;
           }
       }
   }

   primInfo += QString("最小生成树 %1 \n").arg(QString::number(count));

   return treeList;
}


#endif // PRIMALGORITHM_CPP
