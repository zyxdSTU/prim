#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "treeshow.h"
#include "treenode.h"
#include "primalgorithm.h"
#include "kruskalalgorithm.h"
#include<QMainWindow>
#include<QLabel>
#include<QPushButton>
#include<QTextEdit>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QFileDialog>
#include<QLineEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    /*文件名称*/
    QString fileName;

    QLabel *titleLable;
    QLabel *attentionLabel;
    QLineEdit *fileNameEdit;
    QPushButton *selectFileButton;
    QTextEdit *infoTextEdit;
    QPushButton *primButton;
    QPushButton *kruButton;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;

private slots:
    void primEvent();
    void kruEvent();
    void selectFileEvent();
};

#endif // MAINWINDOW_H
