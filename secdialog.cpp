#include "secdialog.h"
#include "ui_secdialog.h"

int SecDialog::score1=0;
int SecDialog::score2=0;

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    //adding arrow image
    QPixmap pic1(":/download1.jpg");
    ui->pl1turn->setPixmap(pic1);
    QPixmap pic2(":/download2.jpg");
    ui->pl2turn->setPixmap(pic2);

    //adding initial pl1level and pl2level image i.e of level 0
    level0a.load(":/0a.jpg");
    ui->pl1level->setPixmap(level0a);
    level0b.load(":/0b.png");
    ui->pl2level->setPixmap(level0b);

    //hiding player1 and player2 display initially
    ui->pl1disp->hide();
    ui->pl2disp->hide();
    ui->try1->hide();
    ui->try2->hide();
    ui->char1->hide();
    ui->char2->hide();

    flag=0; //flag is taken for termination of game
}

SecDialog::~SecDialog()
{
    delete ui;
}

//asking the users to enter the word
void SecDialog::enter_words()
{
    //hiding details of player 2
    ui->pl2turn->hide();
    ui->pl2text->hide();
    ui->pl2word->hide();

}


void SecDialog::on_pl1word_returnPressed()
{
    word1= ui->pl1word->text();  //storing player 1 word in word1

    //hiding details of player 1
    ui->pl1turn->hide();
    ui->pl1text->hide();
    ui->pl1word->hide();

    //showing details of player 2
    ui->pl2turn->show();
    ui->pl2text->show();
    ui->pl2word->show();
}

void SecDialog::on_pl2word_returnPressed()
{
    //storing player 2 word in word2
    word2= ui->pl2word->text();


    //hiding the entered words
    ui->pl1word->hide();
    ui->pl2word->hide();

    //hiding the arrows
    ui->pl1turn->hide();
    ui->pl2turn->hide();

    //changing the text of pl1text label and pl2text label
    ui->pl1text->setText("Your Challenge is: ");
    ui->pl1text->show();
    ui->pl2text->setText("Your Challenge is: ");
    ui->pl2text->show();

    this->play();

}

void SecDialog::play()
{
    //making display of both the players visible
    int a= word2.size();
    int b= word1.size();
    QChar c;

    //making initial word to display to player 1
    for(int i=0;i<a;i++)
    {
        c= word2.at(i);
        switch(c.unicode())
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':dispword1.insert((2*i),c.toUpper());
            break;
        default :dispword1.insert((2*i),"_");
        }

        dispword1.insert(((2*i)+1)," ");
    }

    //making initial word to display to player 2
    for(int i=0;i<b;i++)
    {
        c= word1.at(i);
        switch(c.unicode())
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':dispword2.insert((2*i),c.toUpper());
            break;
        default :dispword2.insert((2*i),"_");
        }

        dispword2.insert(((2*i)+1)," ");
    }

    //showing arrow on player1
    ui->pl1turn->show();

    //showing the word to display
    ui->pl1disp->setText(dispword1);
    ui->pl1disp->show();

    ui->pl2disp->setText(dispword2);
    ui->pl2disp->show();

    //showing the enter_word to display
    ui->try1->show();
    ui->char1->show();

}


void SecDialog::on_char1_returnPressed()
{
    // perform the operations necessary
    QString ch;
    ch= ui->char1->text();
    if(word2.contains(ch,Qt::CaseInsensitive))
    {
        int i=0;
        while(i<word2.size())
        {
            int k=word2.indexOf(ch,i,Qt::CaseInsensitive);
            if(k==-1) break;
            else
            {
                dispword1.replace((2*k),1,ch.toUpper());
                i=k+1;
            }
        }
    }
    else
    {
        score1=score1+1;
    }

    //show the final result
   if((score1>7)||(score2>7)||(!(dispword1.contains("_",Qt::CaseInsensitive)))||(!(dispword2.contains("_",Qt::CaseInsensitive))))
   {
       //show final result
       ThirdDialog third;
       third.setModal(true);
       third.setWindowTitle("Results!");
       if(score1<score2)  //player1 wins
       {
           third.winner(1);
       }

       else if(score2<score1) //player2 wins
       {
           third.winner(2);
       }
       third.show();
       third.exec();
   }

    //appending the pl1disp
    ui->pl1disp->setText(dispword1);

    //clearing the char1 for later use
    ui->char1->setText("");

    //hiding try1, char1 and arrow
    ui->try1->hide();
    ui->char1->hide();
    ui->pl1turn->hide();

     //showing the try2, char2 and arrow
     ui->pl2turn->show();
     ui->try2->show();
     ui->char2->show();


     // to update the corresponding level pic of the players
      setlevelpic();
}

void SecDialog::on_char2_returnPressed()
{
    // perform the operations necessary
    QString ch;
    ch= ui->char2->text();
    if(word1.contains(ch,Qt::CaseInsensitive))
    {
        int i=0;
        while(i<word1.size())
        {
            int k=word1.indexOf(ch,i,Qt::CaseInsensitive);
            if(k==-1) break;
            else
            {
                dispword2.replace(2*k,1,ch.toUpper());
                i=k+1;
            }
        }
    }
    else
    {
        score2= score2+1;
    }

    //show the final result
    if((score1>7)||(score2>7)||(!(dispword1.contains("_",Qt::CaseInsensitive)))||(!(dispword2.contains("_",Qt::CaseInsensitive))))
    {
        //show final result
        ThirdDialog third;
        third.setModal(true);
        third.setWindowTitle("Results!");
        if(score1<score2)  //player1 wins
        {
            third.winner(1);
        }

        else if(score2<score1) //player2 wins
        {
            third.winner(2);
        }
        third.show();
        third.exec();
    }

    //appending the pl2disp
    ui->pl2disp->setText(dispword2);

    //clearing the char2 for later use
    ui->char2->setText("");

    //hiding try2, char2 and arrow
    ui->try2->hide();
    ui->char2->hide();
    ui->pl2turn->hide();

    //showing the try1, char1 and arrow
    ui->pl1turn->show();
    ui->try1->show();
    ui->char1->show();

    // to update the corresponding level pic of the players
    setlevelpic();
}


//to add corresponding pic of level of the players
void SecDialog::setlevelpic()
{
    //for updating player 1 level
    switch(score1)
    {

    case 1:
        level1a.load(":/1a.jpg");
        ui->pl1level->setPixmap(level1a);
        break;
    case 2:
        level2a.load(":/2a.jpg");
        ui->pl1level->setPixmap(level2a);
        break;
    case 3:
        level3a.load(":/3a.jpg");
        ui->pl1level->setPixmap(level3a);
        break;
    case 4:
        level4a.load(":/4a.jpg");
        ui->pl1level->setPixmap(level4a);
        break;
    case 5:
        level5a.load(":/5a.jpg");
        ui->pl1level->setPixmap(level5a);
        break;
    case 6:
        level6a.load(":/6a.jpg");
        ui->pl1level->setPixmap(level6a);
        break;
    case 7:
        level7a.load(":/7a.jpg");
        ui->pl1level->setPixmap(level7a);
        break;
    default:
        break;
    }

    //for updating player 2 level
    switch(score2)
    {
    case 1:
        level1b.load(":/1b.png");
        ui->pl2level->setPixmap(level1b);
        break;
    case 2:
        level2b.load(":/2b.png");
        ui->pl2level->setPixmap(level2b);
        break;
    case 3:
        level3b.load(":/3b.png");
        ui->pl2level->setPixmap(level3b);
        break;
    case 4:
        level4b.load(":/4b.png");
        ui->pl2level->setPixmap(level4b);
        break;
    case 5:
        level5b.load(":/5b.png");
        ui->pl2level->setPixmap(level5b);
        break;
    case 6:
        level6b.load(":/6b.png");
        ui->pl2level->setPixmap(level6b);
        break;
    case 7:
        level7b.load(":/7b.png");
        ui->pl2level->setPixmap(level7b);
        break;
    default:
        break;
    }

}
