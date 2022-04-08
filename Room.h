#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "Character.h"
using namespace std;
using std::vector;

class Room {

private:
	string description;
	map<string, Room*> exits;
	string exitString();



public:
    vector <Item> itemsInRoom;
    vector <Character> CharactersInRoom;
    int numberOfCharacters();
    int numberOfItems();
    void removeCharacterFromRoom(QString name);
    void addCharacter(Character *Character);
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(QString name);
};

#endif
