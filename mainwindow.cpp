#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->resize(QSize(800, 800));
    this->setWindowTitle("普里姆算法");


    titleLable = new QLabel;
    attentionLabel = new QLabel;
    fileNameEdit = new QLineEdit;
    selectFileButton = new QPushButton;
    infoTextEdit = new QTextEdit;
    primButton = new QPushButton;
    kruButton = new QPushButton;
    hLayout = new QHBoxLayout;
    vLayout = new QVBoxLayout;

    connect(this->primButton, SIGNAL(clicked(bool)), this, SLOT(primEvent()));
    connect(this->kruButton, SIGNAL(clicked(bool)), this, SLOT(kruEvent()));
    connect(this->selectFileButton, SIGNAL(clicked(bool)),this, SLOT(selectFileEvent()));

    /*文字大小*/
    QFont *font = new QFont;
    font->setPixelSize(30);


    titleLable->setFont(*font);
    titleLable->setStyleSheet("color:blue");
    titleLable->setText(QString("普里姆算法"));
    titleLable->setAlignment(Qt::AlignCenter);

    font->setPixelSize(20);
    attentionLabel->setText(QString("注意事项:输入第一行是节点信息, 之后接一个邻接矩阵"));
    attentionLabel->setAlignment(Qt::AlignLeft);
    attentionLabel->setStyleSheet("color:red");
    attentionLabel->setFont(*font);

    font->setPixelSize(20);
    fileNameEdit->setFont(*font);
    fileNameEdit->setMinimumSize(300, 50);

    selectFileButton->setText("选择文件");
    selectFileButton->setMinimumSize(100,50);
    selectFileButton->setMaximumSize(100,50);

    hLayout->addWidget(fileNameEdit);
    hLayout->addWidget(selectFileButton);

    font->setPixelSize(25);
    infoTextEdit->setFont(*font);

    primButton->setText(QString("prim算法"));
    primButton->setMinimumSize(200, 80);
    primButton->setMaximumSize(200, 80);

    kruButton->setText(QString("kruskal算法"));
    kruButton->setMinimumSize(200, 80);
    kruButton->setMaximumSize(200, 80);


    QHBoxLayout *tempLayout = new QHBoxLayout;
    tempLayout->addWidget(primButton); tempLayout->addWidget(kruButton);

    vLayout->addWidget(titleLable);
    vLayout->addWidget(attentionLabel);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(infoTextEdit);
    vLayout->addLayout(tempLayout);
    vLayout->setSpacing(20);

    /*mainwindow不能直接设置layout*/
    QWidget *widget = new QWidget(this);
    widget->setLayout(vLayout);
    this->setCentralWidget(widget);

}

void MainWindow::primEvent() {
   QList<TreeNode> treeList = primalgorithm(fileName);

   infoTextEdit->append(primInfo);
   //infoTextEdit->setText(primInfo);

   TreeShow *treeShow = new TreeShow();

   treeShow->treeList = treeList;

   treeShow->show();

}

void MainWindow::kruEvent() {

   QList<TreeNode> treeList = kruskalalgorithm(fileName);

   infoTextEdit->append(kruInfo);

   TreeShow *treeShow = new TreeShow();

   treeShow->treeList = treeList;

   treeShow->show();

}

/*获取文件名*/
void MainWindow::selectFileEvent() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), "", tr("Allfile(*.*));;mp3file(*.mp3)"));
    fileNameEdit->setText(fileName);
    this->fileName = fileName;
}


MainWindow::~MainWindow()
{

}
