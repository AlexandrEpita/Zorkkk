#include <iostream>
#include <QString>
#include <QChar>
#include <QFile>

using namespace std;

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include "item.h"
#include "Room.h"
#include "wordle.h"

vector<QString>PotentialWordsToGuess;
QString c="_____";
QString contener="";
QString Nickname="";
ZorkUL Game;
int life = 100;
int attack = 10;
int found =0;
bool ChrisTriggered=false;
int current=0;
int wordchosen=rand()%19;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hideall();
    readfile();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Up_clicked()
{
    //Game.go("north");
    ui->textEdit->setText(QString::fromStdString(Game.go("north"))+"\nLife = "+QString::number(life)+"\nAttack = "+QString::number(attack));
    ui->comboBox->clear();
    for(int i=0;i<Game.currentRoom->numberOfItems();i++)
    {
        ui->comboBox->addItem(Game.currentRoom->itemsInRoom[i].name());
    }
}



void MainWindow::on_pushButton_Left_clicked()
{
    ui->pushButton_attack->hide();
    //if(Game.currentRoom->name())
    //Game.go("west");
    if(Game.currentRoom->shortDescription()=="Spawn" && !ChrisTriggered)
    {
      ui->pushButton_Maps->hide();
      ui->pushButton_yes->show();
      ui->pushButton_yeschris->show();
      ui->lineEdit_4->show();
      ui->pushButton_teleport->hide();
      ui->label->hide();
    }
    else if(Game.currentRoom->shortDescription()=="Corridor" && ui->comboBox_2->findText("Courage Gatherer")==-1)
    {
      ui->textEdit->setText("Nagini affraid you because you didn't manage to gather your courage\n"+QString::fromStdString(Game.currentRoom->longDescription()));
    }
    else
    {
        ui->textEdit->setText(QString::fromStdString(Game.go("west"))+"\nLife = "+QString::number(life)+"\nAttack = "+QString::number(attack));
        ui->comboBox->clear();
        if(Game.currentRoom->CharactersInRoom.size()!=0)
        {
            ui->textEdit->setText((Game.currentRoom->CharactersInRoom[0].nickname()+" is ready to fight\nLife = "+(QString::number(Game.currentRoom->CharactersInRoom[0].life)+"\nAttack = "+QString::number(Game.currentRoom->CharactersInRoom[0].attack)+"\nLife = "+QString::number(life)+"\nAttack = "+QString::number(attack))));
            ui->pushButton_attack->show();
        }
        else
        {
            for(int i=0;i<Game.currentRoom->numberOfItems();i++)
            {
                ui->comboBox->addItem(Game.currentRoom->itemsInRoom[i].name());
            }
        }
    }
}


void MainWindow::on_pushButton_Down_clicked()
{
    ui->textEdit->setText(QString::fromStdString(Game.go("south"))+"\nLife = "+QString::number(life)+"\nAttack = "+QString::number(attack));
    ui->comboBox->clear();
    for(int i=0;i<Game.currentRoom->numberOfItems();i++)
    {
        ui->comboBox->addItem(Game.currentRoom->itemsInRoom[i].name());
    }
}


void MainWindow::on_pushButton_Right_clicked()
{

    ui->comboBox->clear();
    ui->pushButton_attack->hide();
    if(Game.currentRoom->shortDescription()=="Lake" && (ui->comboBox_2->findText("key that will allow you to fight the méchant très méchant")==-1 || found<10))
    {
        ui->textEdit->setText("This door is locked, you must have missed something...\n""Oh you forgot "+QString::number(10-found)+" items\n"+QString::fromStdString(Game.currentRoom->longDescription()));
    }
    else
    {
        ui->textEdit->setText(QString::fromStdString(Game.go("east"))+"\nLife = "+QString::number(life)+"\nAttack = "+QString::number(attack));
        if(Game.currentRoom->CharactersInRoom.size()!=0)
        {
            ui->textEdit->setText((Game.currentRoom->CharactersInRoom[0].nickname()+" is ready to fight\nLife = "+(QString::number(Game.currentRoom->CharactersInRoom[0].life)+"\nAttack = "+QString::number(Game.currentRoom->CharactersInRoom[0].attack)+"\nLife = "+QString::number(life)+"\nAttack = "+QString::number(attack))));
            ui->pushButton_attack->show();
        }
        else if(Game.currentRoom->shortDescription()=="Gare Atéfaice")
        {
            hideall();
            ui->textEdit->show();
            ui->lineEdit_5->show();
            ui->textEdit->setText("WORDLE GAME STARTED (Voldemort aka Le méchant très très méchant aka Sam GratleHuck) challenges you!!!\nYou have 3 tries to defeat him");
        }
        else
        {
            for(int i=0;i<Game.currentRoom->numberOfItems();i++)
            {
                ui->comboBox->addItem(Game.currentRoom->itemsInRoom[i].name());
            }
        }
    }
    //Game.go("east");
}




void MainWindow::on_pushButton_Info_clicked()
{
    /*Game.createRooms();
    ChrisTriggered=false;
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    for(int i=0;i<Game.currentRoom->numberOfItems();i++)
    {
        ui->comboBox->addItem(Game.currentRoom->itemsInRoom[i].name());
    }*/
    restart();
    ui->textEdit->setText((QString("Hi again ")+Nickname+("!\nYou look stronger now it is your moment go and beat \"The méchant très méchant\"\nGood luck!!\n")+QString::fromStdString(Game.currentRoom->longDescription())));

}

void MainWindow::on_pushButton_Leave_clicked()
{
    this->close();
}


/*void MainWindow::on_lineEdit_objectNameChanged(const QString &objectName)
{

}*/

void MainWindow::hideall()
{
    ui->pushButton_yes->hide();
    ui->pushButton_yeschris->hide();
    ui->pushButton_Down->hide();
    ui->pushButton_Up->hide();
    ui->pushButton_Right->hide();
    ui->pushButton_Left->hide();
    ui->pushButton_Info->hide();
    ui->pushButton_Down->hide();
    ui->pushButton_Leave->hide();
    ui->pushButton_Maps->hide();
    ui->comboBox->hide();
    ui->textEdit->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->pushButton_Leave_2->hide();
    ui->comboBox_2->hide();
    ui->pushButton_teleport->hide();
    ui->label->hide();
    ui->lineEdit_5->hide();
    ui->pushButton_attack->hide();
}
void MainWindow::showall()
{
    ui->pushButton_teleport->show();
    ui->pushButton_Down->show();
    ui->pushButton_Up->show();
    ui->pushButton_Right->show();
    ui->pushButton_Left->show();
    ui->pushButton_Info->show();
    ui->pushButton_Down->show();
    ui->pushButton_Leave->show();
    ui->pushButton_Maps->show();
    ui->comboBox->show();
    ui->textEdit->show();
    ui->lineEdit_3->show();
    ui->pushButton_Leave_2->show();
    ui->comboBox_2->show();
}

void MainWindow::restart()
{
    found=0;
    life=100;
    attack=10;
    c="_____";
    contener="";
    showall();
    current=0;
    ChrisTriggered=false;
    Game.createRooms();
    Nickname= ui->lineEdit->displayText();
    ui->pushButton_attack->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->setText(Nickname+"'s game");
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    for(int i=0;i<Game.currentRoom->numberOfItems();i++)
    {
        ui->comboBox->addItem(Game.currentRoom->itemsInRoom[i].name());
    }
    ui->textEdit->setText(("Hi ")+Nickname+("\nYou have to beat \"The méchant très méchant\"\nGood luck!!\n")+QString::fromStdString(Game.currentRoom->longDescription()));
}

void MainWindow::on_lineEdit_editingFinished()
{
   restart();
}


void MainWindow::on_pushButton_Leave_2_clicked()
{
    if(ui->comboBox->itemText(0)!="")
    {
        ui->comboBox_2->addItem(Game.currentRoom->itemsInRoom[0].name());
        ui->comboBox->removeItem(0);
        found++;
        Game.currentRoom->removeItemFromRoom(ui->comboBox->itemText(0));
        ui->textEdit->setText(QString::fromStdString(Game.currentRoom->longDescription()));
    }

    //ui->textEdit->setText("you removed"+ui->comboBox->itemText(0));
}



void MainWindow::on_pushButton_yes_clicked()
{
    ui->pushButton_yes->hide();
    ui->pushButton_yeschris->hide();
    ui->lineEdit_4->hide();
    restart();
    ui->textEdit->setText("Oh dear we are in trouble...\nChris punished you for your disrespectful behaviour\nYou'll have to restart now mouahahahahahahaha\n"+QString::fromStdString(Game.currentRoom->longDescription()));
}


void MainWindow::on_pushButton_yeschris_clicked()
{
    ui->pushButton_Maps->show();
    ui->pushButton_yes->hide();
    ui->pushButton_yeschris->hide();
    ui->lineEdit_4->hide();
    ChrisTriggered=true;
    life+=100;
    attack+=150;
    ui->textEdit->setText(QString::fromStdString(Game.go("west"))+"\nLife = "+QString::number(life)+"\nAttack = "+(QString::number(attack))+"\nExcellent you will go far!\nI give you the key that will allow you to fight the méchant très méchant.\nI also give you a little boost that will allow you to defeat the Lion\n"+(QString::fromStdString(Game.currentRoom->longDescription())));
    ui->comboBox->clear();
    for(int i=0;i<Game.currentRoom->numberOfItems();i++)
    {
        ui->comboBox->addItem(Game.currentRoom->itemsInRoom[i].name());
    }
    ui->comboBox_2->addItem("key that will allow you to fight the méchant très méchant");
}


void MainWindow::on_pushButton_teleport_clicked()
{
    ui->pushButton_attack->hide();
    Game.teleport();
    ui->textEdit->setText(QString::fromStdString(Game.currentRoom->longDescription()));
    ui->comboBox->clear();
    for(int i=0;i<Game.currentRoom->numberOfItems();i++)
    {
        ui->comboBox->addItem(Game.currentRoom->itemsInRoom[i].name());
    }
}


void MainWindow::on_lineEdit_5_editingFinished()
{
    QString a=ui->lineEdit_5->displayText();
    QString b=PotentialWordsToGuess[wordchosen];
    if(a==b)
    {
        c[0]=b[0];
        ui->lineEdit_5->hide();
        ui->textEdit->setText("YOU ARE A boss! WOWOWOWOWOW! ssod A 3яA UOY\nYour best stat is "+QString::number(Game.myMax<int>(life,attack)));
        ui->pushButton_Info->show();
        ui->pushButton_Leave->show();
    }
    else if(a.length()==b.length())
    {
        for(int i = 0; i<b.length();i++)
        {
            if(a[i]== b[i])
            {
                c[i]=b[i];
            }
            else if(b.contains(a[i]) && !c.contains(a[i]) && (c[i].isUpper() or c[i]=='_'))
            {
                c[i]=(a[i].toUpper());
            }
        }
        current++;
        if(current==3)
        {
            restart();
            ui->lineEdit_5->hide();
            ui->textEdit->setText("\nYou can cheat and look for 5 letters word in internet for next wordle if it is too hard :)");
        }
        else
        {
            contener+=QString(c+"\n");
            ui->textEdit->setText(contener+QString("  \nTake care you only have "+QString::number(3-current))+" left (if you have an uppercase in your word it means that the letter is in the wrong place)");
        }
    }
    else
    {
        ui->textEdit->setText("word length must be "+QString::number(b.length()));
    }
}


void MainWindow::on_pushButton_attack_clicked()
{
    if(Game.currentRoom->CharactersInRoom[0].life-attack>0)
    {
        Game.currentRoom->CharactersInRoom[0].life-=attack;
        life-=Game.currentRoom->CharactersInRoom[0].attack;
        if(life==0)
        {
            restart();
        }
        else
        {
            ui->textEdit->setText((Game.currentRoom->CharactersInRoom[0].nickname()+" reposts\nLife = "+(QString::number(Game.currentRoom->CharactersInRoom[0].life)+"\nAttack = "+QString::number(Game.currentRoom->CharactersInRoom[0].attack)+"\nLife = "+QString::number(life)+"\nAttack = "+QString::number(attack))));
        }
    }
    else
    {
        ui->textEdit->setText((Game.currentRoom->CharactersInRoom[0].nickname()+" is dead!\nYou defeated him so you're free to pick items up"+"\nLife = "+QString::number(life)+"\nAttack = "+QString::number(attack))+"\n"+QString::fromStdString(Game.currentRoom->longDescription()));
        ui->pushButton_attack->hide();
        Game.currentRoom->removeCharacterFromRoom(Game.currentRoom->CharactersInRoom[0].name);
        for(int i=0;i<Game.currentRoom->numberOfItems();i++)
        {
            ui->comboBox->addItem(Game.currentRoom->itemsInRoom[i].name());
        }
    }
}


void MainWindow::on_pushButton_Maps_clicked()
{
    if(ui->label->isVisible())
    {
        ui->label->hide();
    }
    else
    {
        ui->label->show();
    }
}

void MainWindow::readfile(){
    QString filename="test.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "NO existe el archivo de la salchicha del bambino"<<filename;
    }else{
        qDebug() << filename<<" encontrado... muchacho de la patata";
    }
    QString line;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            PotentialWordsToGuess.push_back(line);
        }
    }
    file.close();
}


