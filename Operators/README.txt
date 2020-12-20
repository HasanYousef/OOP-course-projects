Operators
#########################################################################################

authors:
	Omar Yousef
	Hasan Yousef

about the program:
	This program is about the operators the program make a image and this image can have more than one color
               (black ,white, gray) and the image have a height and width the image is a pixels array every alement have a pixel
               the pixel can have one of three colors (black ,white, gray), the pixels array we saved it on the imagedatastructure
               we can add image to other image and chang image to another image by operator+ we also can change th white
               to black and black to white by operator ~ and many operators that we did can make a diffrent things in the image.

Design:
              in this program we have a three objects that we use first of all the image this object that build the image we want by
              give him at least Height and Width of the image and the object will creat it in this object we can do many things by
              the operators we did like add image to aother and else the image object have a object that call ImageDataStructure
              this object have the array of pixels this aary is the present the image its be H*W and every elment is a pixrl that have a 
              color this class do all the allocate and free memories the object we use in this class is the pixels this object have a member
              from unsignd int that we give him a color (in iur program can be BLACK or WHITE or GRAY) in this pixel class we can also
              do something by the operators that we did like operator & and else
    
About the files:
              Image.h/.cpp:
                       in this files we have the Image class that its present the image and have the operators + and else this is the primary
                       class becuse its the onlay class that use the differents classes.
              Macros.h:
                       this file have the consts that we used in the program its have a (BLACK,WHITE,GRAY).
              ImageDataStructure.h/.cpp:
                       this file have the ImageDataStructure that by this class we do all the allocate and free memory also in this class we 
                       have the array pixels of the image.
               Pixel.h/.cpp:
                       this file have the pixel class that we use it on the array that its present a color its have ome operators.

Data Structures:
               we used an array that from Pixel type its be on the Height and the Width that we chose and the elments is a 
               pixels that every pixel can present one of this color (BLAC,WHITE,GRAY).

Notable Algorithms:
               
Bug:

Another Notes:
