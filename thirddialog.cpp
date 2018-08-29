#include "thirddialog.h"
#include "ui_thirddialog.h"

ThirdDialog::ThirdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdDialog)
{
    ui->setupUi(this);
    QPixmap pic(":/final.jpg");
    ui->winpic->setPixmap(pic);
}

ThirdDialog::~ThirdDialog()
{
    delete ui;
}

void ThirdDialog::winner(int a)
{
    if(a==1)
    {
        ui->winlabel->setText("Player 1 wins!");
    }
    else if(a==2)
    {
        ui->winlabel->setText("Player 2 wins!");
    }
}

void ThirdDialog::on_quit_clicked()
{
    qApp->exit();
}

void ThirdDialog::on_playagain_clicked()
{
    QProcess::startDetached(qApp->arguments().at(0),qApp->arguments());
    qApp->exit();
}
