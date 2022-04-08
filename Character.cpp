#include "Character.h"
#include <QString>

Character::Character (QString name,int life,int attack)
{
    this->name=name;
    this->life=life;
    this->attack=attack;
}
Lion::Lion(QString name,int life,int attack):Character (name,life, attack)
{
    this->name="Lion "+name;
    this->life=life;
    this->attack=attack;
}
void deleete(Lion *l)
{
    delete l;
}

void doblelife(Character p)
{
    p.life= p.life<<1;
}




