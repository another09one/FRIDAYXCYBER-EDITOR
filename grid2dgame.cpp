#include<iostream>
#include<string>

template<typename T>
T input(std::string prompt = ""){
    T value;
    std::cout << prompt;
    std::cin >> value;
  return value;
}
int getGridSizeFromUser(){
    int size = input<int>("Enter the desired grid size (Choose any number): ");
    
    char command = input<char>("give an initialising character variable : ");
    
    std::cout << "Control your character (X) using w, a, s, d. Press 'q' to quit." <<std::endl;

    while (size < 2) {
        std::cout << "A grid must be at least 2x2. Please enter a valid number: ";
        std::cin >> size;
    }
    return size;
}

int main(){

    int gridSize = getGridSizeFromUser();
    
    char** grid = new char*[gridSize];
    for (int i = 0; i < gridSize; ++i) {
        grid[i] = new char[gridSize];
    }
    
    // Initialize the grid with empty spaces
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            grid[i][j] = ' ';
        }
    }
    
    // Place the character 'X' at the starting position
    int xPos = 0;
    int yPos = 0;
    grid[xPos][yPos] = 'X';
    
    char command;
    while (true) {
        // Display the grid
        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < gridSize; ++j) {
                std::cout << "[" << grid[i][j] << "]";
            }
            std::cout << std::endl;
        }
        
        std::cout << "Enter command (w/a/s/d to move, q to quit): ";
        std::cin >> command;
        
        if (command == 'q') {
            break;
        }
        
        // Clear the current position
        grid[xPos][yPos] = ' ';
        
        // Update position based on command
        if (command == 'w' && xPos > 0) {
            --xPos;
        } else if (command == 's' && xPos < gridSize - 1) {
            ++xPos;
        } else if (command == 'a' && yPos > 0) {
            --yPos;
        } else if (command == 'd' && yPos < gridSize - 1) {
            ++yPos;
        }
        
        // Place the character 'X' at the new position
        grid[xPos][yPos] = 'X';
    }
    
    // Clean up memory
    for (int i = 0; i < gridSize; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
