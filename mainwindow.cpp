#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//for thr first landing page
void MainWindow::index()
{
    this->show();

}

//when NO is pressed on first page
void MainWindow::on_first_no_clicked()
{
    QApplication::exit();
}

//when YES is pressed on first page
void MainWindow::on_first_yes_clicked()
{
    this->hide();
    SecDialog second;
    second.setModal(true);
    second.setWindowTitle("GAME_BEGINS!");
    second.show();
    second.enter_words(); //for entering the words
    second.exec();

}
