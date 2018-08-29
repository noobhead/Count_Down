#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QPixmap>
#include "thirddialog.h"

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::SecDialog *ui;
    QString word1, word2, dispword1, dispword2;
    int flag, counter;
    static int score1, score2;

    void play();

    // to set the level of the players
    void setlevelpic();

    //level pictures of player1 
    QPixmap level0a, level0b, level1a, level1b, level2a, level2b, level3a, level3b,
    level4a, level4b, level5a, level5b, level6a, level6b, level7a, level7b;

public:
    explicit SecDialog(QWidget *parent = 0);
    ~SecDialog();

    //for entering the words
    void enter_words();

private slots:
    void on_pl1word_returnPressed();

    void on_pl2word_returnPressed();


    void on_char1_returnPressed();

    void on_char2_returnPressed();
};

#endif // SECDIALOG_H
