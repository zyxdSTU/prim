#include"kruskalalgorithm.h"
QString kruInfo;
/*并查集*/
int visited[MAX_VALUE];

/*并查集*/
int Find(int x) {
    if(visited[x] != x) visited[x] = Find(visited[x]);
    return visited[x];
}

void Union(int x, int y){
    int xParent = Find(x);
    int yParent = Find(y);
    if(xParent == yParent) return;

    visited[yParent] = xParent;
}

QList<TreeNode> kruskalalgorithm(QString fileName) {
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

    /*初始化并查集*/
    for(int i = 0; i < MAX_VALUE; i++) visited[i] = i;

    QVector<Edge> edge;

    for(int i = 0; i < treeList.size(); i++)
        for(int j = 0; j < i; j++) {
            if(matrix[i][j] >= MAX_VALUE) continue;
            edge.push_back(*(new Edge(i, j, matrix[i][j])));
        }

    /*插入排序*/
    for(int i = 1; i < edge.size(); i++) {
        Edge key = edge[i];
        while(i > 0 && edge[i-1].len > key.len) {
            edge[i] = edge[i-1];
            i--;
        }
        edge[i] = key;
    }

    int m = treeList.size(), n = treeList.size(), count = 0, index = 0;

    while(true) {
        int x = edge[index].start, y = edge[index].end;
        int len = edge[index].len;
        int xParent = Find(x), yParent = Find(y);

        index++;

        if(xParent == yParent) {
            continue;
        }else{
            Union(x, y);
            count += len;  n--;
            kruInfo += QString("第 %1 条边: %2->%3 距离: %4\n").arg(QString::number(m-n)).arg(treeList[x].label).arg(treeList[y].label)
                    .arg(QString::number(len));

            treeList[x].next.append(QPair<int, double>(y, len));
            treeList[y].next.append(QPair<int, double>(x, len));
        }
        if(n == 1) break;
    }

    for(TreeNode temp : treeList) {
        qDebug() << temp.label << " ";
        for(QPair<int, double> elementTemp : temp.next)
            qDebug() << treeList[elementTemp.first].label << " ";
        qDebug() << endl;
    }

    kruInfo += QString("最小生成树 %1 \n").arg(QString::number(count));

    qDebug() << kruInfo << endl;
   return treeList;

}
