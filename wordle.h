#ifndef WORDLE_H
#define WORDLE_H
#include <QString>

class Wordle
{
public:
    Wordle();
    int currenttry=0;
    int length=5;
private:
    int maxtries=3;
};

#endif // WORDLE_H
