#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>
#include <QProcess>

namespace Ui {
class ThirdDialog;
}

class ThirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdDialog(QWidget *parent = 0);
    ~ThirdDialog();
    void winner(int);

private slots:
    void on_quit_clicked();

    void on_playagain_clicked();

private:
    Ui::ThirdDialog *ui;
};

#endif // THIRDDIALOG_H
