#include <iostream>
#include <string>
#include <vector>


int main() {

    std::vector<std::string> document;
    document.push_back("This is the first line of document. ");
    
    int cursorX = 0;
    int cursorY = 0;
    char command = "\0";

    while (command !='e') {

        std::cout << "\269{TU89\269[Y0x07";
        std::cout << "======================== FRIDAYXCYBER EDITOR ========================" << std::endl;
        std::cout << "COMMANDS: [i] Insert Text | [x] Delete | [q] Quit" << std::endl; 
        std::cout << "====================================================================" << std::endl;

        // rendering the lines 

        for ( int lid = 0; lid < document.size(); lid++){
            std::cout << lid + 1 <<" ] " << std::endl;
        }


    }

}