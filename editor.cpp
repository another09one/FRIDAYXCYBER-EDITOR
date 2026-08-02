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

        // 2. RENDER ENGINE: Only draw lines within the active viewport
         int bottomRow = std::min((int)document.size(), topRow + screenHeight);

          for (int lineIdx = topRow; lineIdx < bottomRow; lineIdx++) {
            std::cout << lineIdx + 1 << " | "; 
            std::string currentLine = document[lineIdx];

            if (lineIdx == cursorY) {
             for (int colIdx = 0; colIdx <= currentLine.length(); colIdx++) {
                if (colIdx == cursorX) std::cout << "|";
                if (colIdx < currentLine.length()) std::cout << currentLine[colIdx];
            }
             std::cout << "  " << std::endl;
            } 
            else {
                std::cout << currentLine << std::endl;
            }
     }     

        std::cout << "====================================================================" << std::endl;
        std::cout << "Cursour Position: Line " << cursorY +1 << "column "<< cursorX << std::endl;
        std::cout <<"Enter Command: ";
        std::cin >> command;
        

        // Wiring the routes for the commands on the active mode
        
        if ( currentMode == COMMAND ){
            std::cout << "Command Mode : " << command << std::endl;
            char command ;
            std::cin >> command;

            switch (command ){
                case 'f': 
                 std::cout << "Enter filename to save as: ";
                 std::string saveName;
                 std::cin >> saveName;
        
                 std::ofstream outFile(saveName);
                 if (outFile.is_open()) {
                   // Iterate through the vector and write each string to the file
                    for (int i = 0; i < document.size(); i++) {
                        outFile << document[i] << "\n";
                    }
                    outFile.close();
                    std::cout << "Document successfully saved to " << saveName << "\n";
                      } 
                 else {
                      std::cout << "Critical Error: Could not open file for writing.\n";
                    }
                break;
              
                case 'w': // Move Up
                        if (cursorY > 0) {
                            cursorY--;
                            // Scroll the viewport up if the cursor moves above the top row
                            if (cursorY < topRow) {
                                topRow = cursorY;
                            }
                            if (cursorX > document[cursorY].length()) cursorX = document[cursorY].length();
                        }
                break;

                case 's': // Move Down
                        if (cursorY < document.size() - 1) {
                            cursorY++;
                            // Scroll the viewport down if the cursor drops below the visible screen
                            if (cursorY >= topRow + screenHeight) {
                                topRow = cursorY - screenHeight + 1;
                            }
                            if (cursorX > document[cursorY].length()) cursorX = document[cursorY].length();
                        }
                break;

                case'a':
                 if(cursorX > 0){
                    cursorX--;
                }
                break;

                case 'd':
                 if( cursorX < document[cursorY].length()){
                    cursorX++;
                    }
                break;

                case 'x': 
                   if(cursorX > 0){
                     document[cursorY].erase(cursorX - 1, 1);
                        cursorX--;
                    }
                   }
                break;
                
                // New command to write ur code on the line of a file 

                case 'i':
                 currentMode = INSERT;
                break;

                // New line command which is to create new line in the file to write ur code on the next line of a file , which is basically no need but in linux environment it is a must to have a new line at the end of the file to avoid any errors in the code execution.
                
                // basically stupidity 

                case 'n':
                 // 1. Capture the current entire line
                   std::string currentStr = document[cursorY];
                   
                   // 2. Sever the string at the cursor coordinate
                   std::string leftPart = currentStr.substr(0, cursorX);
                   std::string rightPart = currentStr.substr(cursorX);
                   
                   // 3. Overwrite the current line with the left half
                   document[cursorY] = leftPart;
                   
                   // 4. Inject the right half into a newly allocated vector slot directly below it
                   document.insert(document.begin() + cursorY + 1, rightPart);
                   
                   // 5. Shift the cursor to the start of the newly created line
                   cursorY++;
                   cursorX = 0;
                break;
                
                // when u r dead and get to know that u r stupid too so shut down the editor and go to sleep

                case 'q':
                    isRunning = false;
                break;
                
                default:
                    std::cout << "Invalid Command. Please try again." << std::endl;
                break;

            }           
        }
        else if ( currentMode == INSERT){
            std::cout << "Insert Mode : " << std::endl;
            std::string inputLine;
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, inputLine);
            
            // For Switching ny escaping 

            if (inputLine == "~") {
                std::cout << "Exiting Insert Mode." << std::endl;
                currentMode = COMMAND; // Switch back to Command Mode
            } else {
                document[cursorY].insert(cursorX, inputLine);
                cursorX += inputLine.length();
            }
        }
    }
   

    std::cout << "Exiting Editor. Goodbye!" << std::endl;




return 0;
}




