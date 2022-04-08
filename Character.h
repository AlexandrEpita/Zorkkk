#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <QString>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:

public:
    Character(QString name,int life,int attack);
    vector < QString > itemsInCharacter;
    int weight;
    QString name;
    int life;
    int attack;
    virtual QString nickname()
    {
        return ("Little "+name);
    }
    friend Character operator + (Character const &, Character const &);



    Character operator +(Character  &c1)
    {
         return Character(c1.name,c1.life+c1.life,c1.attack+c1.attack);
    }

};
class animal
{
    protected:
        virtual int hair()=0;
};

class Lion:public Character,animal
{
private:

public:
    void deleete(Character l);
    Lion(QString name,int life,int attack);
    vector < QString > itemsInCharacter;
    int hair(){return 500;};
    int weight;
    QString name;
    int life;
    int attack;
    QString nickname()
    {
        return ("Huge "+name);
    }

};

#endif /*CHARACTER_H_*/
