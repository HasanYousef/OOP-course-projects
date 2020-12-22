Lode Runner Map Editor
#########################################################################################

authors:
	Omar Yousef
	Hasan Yousef

about the program:
               this program is about Load Runner Map, it will let the user to design a map in 
               the way he wanst or edit a map the user can add and remove objects like players coins...
               the user can save the map and this map we can use it in the load runner game so this
               make something good to the final project that we can add that the user can add and 
               design level that he prefer.

Design:
               first of all the class of the editor its like the main this class that run the program and every
               something that we want its connect to editor another thing botton class we used the heredity
               for botton classes this class make it esier to make bottons like add remove bottons also we
               have the board class this class we save the objects and the info for the window to print it on 
               the file when the user press save botton also we have panel class this is the menu of the window
               that let us to controlle on changes also we have WorldObject class this make it easier to make changes
               and save the objects on the array becuse we save a texturse.
        
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
               Board.cpp\.h:
                          this class we save on it the array of the objects and this object make all changes on the file
                          board and save every object where its have to be and wich type....
                Editor.cpp\.h:
                          its like the main this class that run the program and every something that we want its connect to editor.


Data Structures:
               we used 2d array (vector) of the objects of the board and its from WorldObject type that we create it.

Notable Algorithms:
       
Bug:
	The editor window has some limitations: if the board is bigger than the window then the user can't edit the blocks those
	are out of the window range. window size can be resized in macros.h

Another Notes:
	Deleting or removin an object in the map can be done by adding the "space" block which has a black texture.
      