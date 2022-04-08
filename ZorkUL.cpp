#include <iostream>
#include <QString>

using namespace std;
#include "ZorkUL.h"

/*int main(int argc, char argv[])
{
	ZorkUL temp;
	temp.play();
	return 0;
}*/
Room* allrooms[7];
ZorkUL::ZorkUL() {
	createRooms();
}



void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i,*j;

    a = new Room("Spawn");
        a->addItem(new Item("The Ring Of Marvolo Gaunt",1,11));
    b = new Room("Bite");
        b->addCharacter(new Lion("Lion",200,20));
        b->addItem(new Item("The Locket Of Salazar Slytherin",2,22));
    c = new Room("Life Question Room");
        c->addItem(new Item("The Cup Of Helga Hufflepuff",3,33));
    d = new Room("Hall");
        d->addItem(new Item("Dobby",4,44));
    e = new Room("Queen's Wardrobe");
        e->addItem(new Item("The Diadem Of Rowena Ravenclaw",5,55));
    f = new Room("Lake");
        f->addItem(new Item("Sword of Gryffindor",6,66));
    g = new Room("Gare Atéfaice");
    h = new Room("Chambre of Secrets");
        h->addItem(new Item("Philosopher's Stone",7,77));
        h->addItem(new Item("The Diary of Tom Riddle",8,88));
    i = new Room("Corridor");
        i->addItem(new Item("Courage Gatherer",10,1010));
    j = new Room("Room of Requirement");
        j->addCharacter(new Character("Nagini",50,10));
        j->addItem(new Item("Nagini",9,99));

//             (N, E, S, W)
	a->setExits(f, b, d, c);
	b->setExits(NULL, NULL, NULL, a);
	c->setExits(NULL, a, NULL, NULL);
	d->setExits(a, e, NULL, i);
	e->setExits(NULL, NULL, NULL, d);
	f->setExits(NULL, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
	h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, j);
    j->setExits(NULL,i,NULL,NULL);

    allrooms[0]=a;
    allrooms[1]=d;
    allrooms[2]=e;
    allrooms[3]=f;
    allrooms[4]=h;
    allrooms[5]=i;


        currentRoom = a;
}
void ZorkUL::teleport()
{
   int a=rand()%6;
   if (allrooms[a]!=currentRoom)
   {
       currentRoom=allrooms[a];
   }
   else
   {
       teleport();
   }
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

//	bool finished = false;
//	while (!finished) {
//		// Create pointer to command and give it a command.
//		Command* command = parser.getCommand();
//		// Pass dereferenced command and check for end of game.
//		finished = processCommand(*command);
//		// Free the memory allocated by "parser.getCommand()"
//		//   with ("return new Command(...)")
//		delete command;
//	}
    // cout << endl;
    //cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    //cout << "start"<< endl;
    //cout << "info for help"<< endl;
    //cout << endl;
    //cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

    string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "             [Chamber of Secrets] --- [Lake] --- [Gare Atéfaice]" << endl;
        cout << "                                        |         " << endl;
        cout << "                                        |         " << endl;
        cout << "            [Life Question Room] --- [Spawn] --- [Bite]" << endl;
        cout << "                                        |         " << endl;
        cout << "                                        |         " << endl;
        cout << "[Room of Requirement]--[Corridor] --- [Hall] --- [Queen's Wardrobe]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "" << endl;
        else
            cout << "" << endl;
            //cout << "index number " << + location << endl;
            //cout << endl;
            //cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

    string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
        return("direction null\n"+currentRoom->longDescription());
	else
	{
        currentRoom = nextRoom;
        return currentRoom->longDescription();
	}
}

