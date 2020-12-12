Lode Runner
#########################################################################################

authors:
	Omar Yousef
	Hasan Yousef

about the program:
	This program is about a classic game that call Lode Runner it's a 2D platformer
        video game, the player start on a map that have a Ladder and Rope the player have to
        collect all the coins that we have on the map to get to the next level but this is not
        that easy because the player will get chasing by the enemies every time the player get
        hit from the enemy the health of the player will will get low and there are a number
        of health (in this game will be 3) if the player get hits many times that equal to his
        health the player will die and get lose, in the game will be two levels the player have
        to pass this two levels to win in the game.

Design:
        First object its the player by this object we can move the player and get some info like
        (coord health...) second is the enemy we move the enemies by this object and also get some 
        info third the board we save the map on it (in vector) and do some changes on it and get 
        some info, fourth the coord we creat a struct of vertexs and the last is the controller
        the controller its like the main we run the game by the controller and connect all other 
        objects for example we get stream from the board we do that by the controller and print the
        map after that we move the player by player object the move will return the new coord that
        we have to be on by coord object after that we move the enemies by enemies object also we get
        new coord after that we want to put the eniems and player on new elment we use the board object
        to set char and use get char to check if the new elment are valued so by the controller we connect
        all the objects.
    
About the files:
	Player.h/.cpp:
                this class of the Player we can move the player by this class and get his helth also we
                can get his coord and when he git hit by enemy there are a func that minus his helth.
        Marcos.h:
                this file have all the consts that we used in the game
        Enemy.h/.cpp:
	        this the class of the Enemy by this class we move the enemy and we can get his coord.
        Coord.h/.cpp:
                in this file we did a struct of coord (vertexs) and we did some operator to write a 
                simple code and shorter.
        Controller.h/.cpp:
                this file that use all the classes this that run the game, this file its the administrator
                about the game becuse its connect every thing we have to use (players, enemies .....).
        Board.h/.cpp:
                this class of the Board (map) of the game by this class we stream the map of the game and we can
                get char of elemet and size of array also set char on elment and many things help us on anthor classes.
		Money.h:
				includes the Money struct that stores the coord of a specific money-pack and if it is taken by
				the player or not.
        Board.txt: 
                in this file we have the map of the game and the levels.
        main.cpp:
                the main just call to the controller.


Data Structures:
        the Data Structures that we have on the program its the vector of the board (map of the level)
        we use a 2d vector (have rows and cols) that let us to do the size we want, we have a vector
        for the enemies that we put the enemies on it becuse we dont know how many enemies there are so 
        we save him on a vector (objects of enemies), the controller also has a vector of the Money-packs
		that stores for each money-pack it's coord and if it is taken or not.

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
        if the player is in not in the enemy's row and the enemy is in a ladder, the enemy will
		keep going up and down or left and right (if there is floor) in the same 2 blocks, until
		the player will be in the same row again.

Another Notes:
      
