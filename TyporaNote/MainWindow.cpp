#include <QMessageBox>
#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/logo32.png"));

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    textEdit->append(tr("Hello, TyporaNote"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onFileNew()
{
    textEdit->clear();
    QMessageBox::information(this, tr("info"), tr("go here"));
}
