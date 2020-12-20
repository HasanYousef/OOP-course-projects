#include "00-WindowExample.h"
#include "01-CloseEventExample.h"
#include "02-ClearDisplayExample.h"
#include "03-DrawExample.h"
#include "04-MouseClickExample.h"
#include "05-DrawManyExample.h"
#include "06-TextureAndFontExample.h"
#include "07-SetOriginExample.h"
#include "Vertex.h"

#include <thread>
#include <iostream>
#include <fstream>
#include <string>

#include <filesystem>
namespace fs = std::filesystem;

std::ofstream CreateAndOpenBoardFile();
Vertex getBoardVertex(std::ofstream* ofile);

int main()
{
    Vertex size;

    {
        // if we just open a window, nothing happens with it
        // and it's closed when it's destructed
        auto example = WindowExample();

        // wait a bit before destruction so we can see what happens (or doesn't)
        using namespace std::chrono_literals;
        //std::this_thread::sleep_for(30s); // 30 seconds
    }

    /* try to open file to read */
    fs::path p = "C:resources";
    fs::path fileName = "Board.txt";
    p /= fileName;
    std::ifstream ifile(fs::absolute(p));
    std::ofstream ofile;

    // if file exists
    if (ifile) {
        std::cout << "file exists\n";
        // here print file input to window
    }
    // if file does exists
    else {
        std::cout << "file doesn't exist\n";
        ifile.close();
        ofile = CreateAndOpenBoardFile();
        size = Vertex(getBoardVertex(&ofile));
        // here open window and let user build board
        // setBoard(&ofile, size);
    }
    
    //closeEventExample();
    
    
    //clearDisplayExample();

    //drawExample();

    //auto mouseClickExample = MouseClickExample();
    //mouseClickExample.run();

    //DrawManyExample().run();

    //textureAndFontExample();

    //SetOriginExample().run();
    
}

std::ofstream CreateAndOpenBoardFile() {

    // get new file path
    fs::path p = "C:resources";
    fs::path fileName = "Board.txt";
    p /= fileName;

    // open new file
    std::ofstream file(fs::absolute(p)); //open in constructor

    return file;
}

Vertex getBoardVertex(std::ofstream* ofile) {
    Vertex size;
    std::cin >> size.m_row >> size.m_col;

    std::cout << size;
    *ofile << size.m_row << " " << size.m_col << std::endl;

    return size;
}