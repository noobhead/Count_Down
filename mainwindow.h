#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include "secdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //first page of the game
    void index();

private slots:
    void on_first_no_clicked();

    void on_first_yes_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
