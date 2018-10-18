#include "treeshow.h"

TreeShow::TreeShow(QWidget *parent):
    QDialog(parent)
{
    /*设置窗口的大小等参数*/
    this->resize(QSize(800, 900));
    this->setWindowTitle("最小生成树");
}


/*画图事件*/
void TreeShow::paintEvent(QPaintEvent *event){
    /*设置字体*/
    QFont *font = new QFont();
    font->setPixelSize(12);

    /*设置线条格式*/
    QPen *pen = new QPen();
    pen->setStyle(Qt::SolidLine);
    pen->setColor(Qt::blue);
    QPainter *painter = new QPainter(this);
    painter->begin(this);

    painter->setFont(*font);
    painter->setPen(*pen);

    /*广度遍历画出最小生成树*/
    QQueue<TreeNode> queue;

    bool visited[treeList.size()];

    for(int i = 0; i < treeList.size(); i++) visited[i] = false;

    /*画起始节点*/
    treeList[0].startX = 350; treeList[0].startY = 0;


    painter->drawText(QRect(treeList[0].startX, treeList[0].startY, circleLength, circleLength), Qt::AlignCenter,  treeList[0].label);

    painter->drawEllipse(QRect(treeList[0].startX, treeList[0].startY, circleLength, circleLength));

    queue.enqueue(this->treeList[0]); visited[0] = true;

    int n = 0, times = 0, value = 0;
    int startX = 0, startY = 0;

    while(queue.size() > 0) {
        TreeNode element = queue.dequeue();

        /*剔除重复的点*/
        QList<QPair<int,double>> list;
        for(QPair<int, double> elementTemp : element.next) {
            if(visited[elementTemp.first] != true) list.append(elementTemp);
        }

        element.next = list;

        startX = element.startX + circleLength / 2; startY = element.startY + circleLength;

        n = element.next.size(); times = n/2; value = angle / times;

        QString labelStr, weight;



        for(int i = 0; i < times; i++) {

            labelStr = treeList[element.next[i].first].label;

            weight = QString::number(element.next[i].second);

            pen->setColor(Qt::red);
            painter->setPen(*pen);
            painter->drawLine(startX, startY, startX-lineLength*sin(angle-i*value), startY+lineLength*cos(angle-i*value));

            /*权重坐标*/
            double middleX = (startX + startX-lineLength*sin(angle-i*value)) / 2;
            double middleY = (startY + startY+lineLength*cos(angle-i*value)) / 2;
            painter->drawText(QRect(middleX, middleY, 20, 20), Qt::AlignCenter,  weight);

            /*左上顶点坐标*/
            double tempX = startX-lineLength*sin(angle-i*value) - circleLength / 2;
            double tempY = startY+lineLength*cos(angle-i*value);
            treeList[element.next[i].first].startY = tempY;
            treeList[element.next[i].first].startX = tempX;

            pen->setColor(Qt::blue);
            painter->setPen(*pen);

            painter->drawText(QRect(tempX, tempY, circleLength, circleLength), Qt::AlignCenter, labelStr);

            painter->drawEllipse(QRect(tempX, tempY, circleLength, circleLength));
        }


        for(int i = 0; i < times; i++) {

            /*左上顶点坐标*/
            double tempX = startX+lineLength*sin(angle-i*value) - circleLength / 2;
            double tempY = startY+lineLength*cos(angle-i*value);

            if(n % 2 == 0) {
                labelStr = treeList[element.next[i+times].first].label;
                weight = QString::number(element.next[i+times].second);
                treeList[element.next[i+times].first].startX = tempX;
                treeList[element.next[i+times].first].startY = tempY;
            }else{
                labelStr = treeList[element.next[i+times+1].first].label;
                weight = QString::number(element.next[i+times+1].second);
                treeList[element.next[i+times+1].first].startX = tempX;
                treeList[element.next[i+times+1].first].startY = tempY;
            }

            pen->setColor(Qt::red);
            painter->setPen(*pen);

            painter->drawLine(startX, startY, startX+lineLength*sin(angle-i*value), startY+lineLength*cos(angle-i*value));

            double middleX = (startX + startX+lineLength*sin(angle-i*value)) / 2;
            double middleY = (startY + startY+lineLength*cos(angle-i*value)) / 2;
            painter->drawText(QRect(middleX, middleY, 20, 20), Qt::AlignCenter, weight);

            pen->setColor(Qt::blue);
            painter->setPen(*pen);

            painter->drawText(QRect(tempX, tempY, circleLength, circleLength), Qt::AlignCenter, labelStr);

            painter->drawEllipse(QRect(tempX, tempY, circleLength, circleLength));

        }

        if(n % 2 != 0) {

            labelStr = treeList[element.next[n/2].first].label;
            weight = QString::number(element.next[n/2].second);

            pen->setColor(Qt::red);
            painter->setPen(*pen);

            painter->drawLine(startX, startY, startX+ strLineLength*sin(0), startY+ strLineLength*cos(0));

            double middleX =  startX;
            double middleY = (startY + startY+strLineLength*cos(0)) / 2;
            painter->drawText(QRect(middleX, middleY, 20, 20), Qt::AlignCenter, weight);

            /*左上顶点坐标*/
            double tempX = startX+strLineLength*sin(0) - circleLength / 2;
            double tempY = startY+strLineLength*cos(0);

            treeList[element.next[n/2].first].startX = tempX;
            treeList[element.next[n/2].first].startY = tempY;

            pen->setColor(Qt::blue);
            painter->setPen(*pen);

            painter->drawText(QRect(tempX, tempY, circleLength, circleLength), Qt::AlignCenter, labelStr);

            painter->drawEllipse(QRect(tempX, tempY, circleLength, circleLength));
        }
        for(QPair<int, double> elementTemp : element.next) {
            if (visited[elementTemp.first] != true) {
                queue.enqueue(treeList[elementTemp.first]);
                visited[elementTemp.first] = true;
            }
        }

    }
    for(int i = 0; i < treeList.size(); i++) qDebug() << visited[i] << " ";
    painter->end();

}

/*求cos值*/
double TreeShow::cos(double value){
     return qCos(value * M_PI / 180);
}

/*求sin值*/
double TreeShow::sin(double value) {
    return qSin(value * M_PI/ 180);
}
