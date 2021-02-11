Lode Runner Game
#########################################################################################

authors:
	Omar Yousef
	Hasan Yousef

about the program:
              This program is about a classic game that call Lode Runner it's a 2D platformer
              video game, the player start on a map that have a Ladder and Rope the player have to
              collect all the coins that we have on the map to get to the next level but this is not
              that easy because the player will get chasing by the enemies every time if the player
              get hit from the enemy the health of the player will get low and there are a number
              of health also have a time(not necessary) if the player get hits many times that equal to his
              health the player will die and get lose, also you can edit on the map that you can male it how
              you want or to add a level on the game so you can design the levels that you want to try it,
              also the player can get gift that giv hime one of this: more time, helth, coins, add enemy(bad gift).

Design:
              the main object is the controller its start the game and connect between the menu and the game
              and the editorits shows a menu and we can use if we want to lunch the editor or the game, the
              game have all what he need to run the game (all the levels), its run the game and run every level
              there are a big loop that connect and check all the cases we have WorldObject that he have the type 
              of the object in the elment and his posistion and many classes inhertence from it also we have
              moveableobject class that this class inhertence from it the object that can move like enemy object that
              chase the player and there are many types of enemy (standart smart stupid) the diffrent between him is
              the movement also we have the player object that we contoll on it we can move it also he ca dig
              the floor, well object that save the place of diging well and close it after 5 sec also we have the 
 	ladder that the player can go up also the gift that the player can take it the wall that we cant 
	move throght it there are connect between the well and enemy + player when they fall in well
	they cant move until well get full and they go to left or right side of the well also there are a time
	that the player have to end the game befor its ending also the connect between the coin and the
	player that he have to get all the coins on the map, we disply the map by map class, there are a map
	class this is so important class that we use it on editor and in the game by this object we read the board
	text that we have and save every worldObject also we can change what in the elment (change type) also
	we creat a new map in the editor by using things from this object that we choose the hight and width of
	the map we can get the type that in the elment and alot of things, the editor is use map and worldObject
	and check if we have the file o we need to creat it its have a big loop that let us to choose wich object we
	want to add and what there are in every object.

File Levels:
	if you want to add level you just need to click on add level button and put the height and the width of
	the window (map) and put the time for the level if you dont want time you put -1 you dont need to 
	right level name or something and the new level will be the last level and when you finish you click save
	if you want to edit you just click on edit level button and choose the level that you want and start editing
	and when you finish you click save.
        
About the files:
	macros.h:
                          this file have the consts and the enum that we used in the program.
               Botton.cpp\.h:
                          this class let us to make a bottons like add remove bottons and we use this class to make it
                          the base of the text and textures botton class.
               TextBotton.cpp\.h:
                          this botton its a inheritance from botton class we add it to make the botton have a text.
               TextureBotton.cpp\.h:
                          this botton its a inheritance from botton class we add it to make the botton have a texture.  
               WorldObject.cpp\.h:
                          this class we use it to put it in the array of the bourd its have the texture and the possistion 
                          of location of the object and the type of the object.
               panel.cpp\.h:
                          this class have all the bottons that we want to use it and we make the menu from this class.
               Map.cpp\.h:
                          this class we save on it the array of the objects and this object make all changes on the file
                          board and save every object where its have to be and wich type....
                Editor.cpp\.h:
                          this class that run the editor that let us edit or add levels and save it.
	 Well.cpp\h:
	           this class is the wells from the player digging its have a time if the well fill and save the well points.
	 Texturse.cpp\h:
	           this is a singleton class that by it we get the Texture we want by give a func a typr of Texture.
	MoveableObject.cpp\h:
	           this class the dad if objects can move its have a virtual move func nd func check if the movement 
	           is legal.
	Player.cpp\h
	           class the player have the player movement and the digging have the score that he get and
	           his helth also have function that let us inforfation from him (his score, helth....).
	TakeableObject.cpp\h:
	           this class have a member istaken that check if the object get taken by the player or not
	           this class is the dad of the object that the pkayer can take it like coin and gift0
	Controller.cpp\h:
	           this class that connect between the editor and ga,e that display a panel and let us
	           to choose if we want to play or edit.
	Enemy.h/.cpp:
	        this the class of the Enemy by this class have the member we need for the types of enemies.	
	Money.h:
	        includes the Money struct that stores the coord of a specific money-pack and if it is taken by
                      the player or not.
	Sound.cpp\h:
	           this is a singleton class that by it we get the sound we want by give a func a type of Tsound.
	Game.cpp\h:
	           this class that rin the ga,e and the leve;s and check all the cases and move all object need
	           to move its like the connector between the objects to play the game.
	SmartEnemy.cpp\h:
	          this class inhertence from the enemy class the difirent is have a move func that have a good
	          algorthim that let him move smart.
	StupidEnemy.cpp\h:
	          this class inhertence from the enemy class the difirent is have a move func that have a BAD
	          algorthim that let him move jus left and right.

Data Structures:
               we use a 2d vector of pointers of a WorldObject (the elment is a pointer of a world object) that we point
	on the object that have to be in this elment also we use in the game a vector of well that we save the wells
	on it to know when its get fill also we have a vector of enemy that we put all the enemies inside it

Notable Algorithms:
       Only one algorithm we used is in Enemy class in movement the algorithm work in this way:
        wa have the coord of the enemy and the coords of the player that we want go to hit it
        we check if they in the same ground if yes we check the diffrent of the cols in the 
        coords if the col coord of the enemy is smaller than the player we check if the enemy 
        can go to the elment in cols + 1 if yes we go the same way in case that the cols of player 
        small than cols of the enemy but we go to cols - 1 instead cols + 1, if the enemy on the
        Ladder and the player on the ground the enemy will go down, if the enemy on a rope and the
        player on the ground (inder the enemy) the enemy will jump to the ground, this mean that
        the algorithm is a approximation.
        it is also good to mention that the enemy can jump from an edge or a rope if the player is
        lower than the enemy.

Bug:
	sometimes when the player move and in the same time he digging sometimse we get error.

Another Notes:
	
      