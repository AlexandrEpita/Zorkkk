#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Room.h"
#include "item.h"
#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    void printWelcome();
	void printHelp();
    void goRoom(Command command);
    void displayItems();


public:
    ZorkUL();
    template<typename T>
    T myMax(T x,T y)
    {
        return (x>y)? x:y;
    }
	void play();
    void teleport();
    void createRooms();
    void createItems();
    bool processCommand(Command command);
    string go(string direction);
    string take(Item a);
    Room *currentRoom;

};

#endif /*ZORKUL_H_*/
