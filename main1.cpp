#include <iostream>
#include <string>
#include <vector>

int main(){
    std::vector<std::string> todolist;
    int choice = 0 ;

    while( choice != 4){
        std::cout << "1. Add a task" << std::endl;
        std::cout << "2. View tasks" << std::endl;
        std::cout << "3. Remove a task" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice){
            case 1:
                {
                    std::string task;
                    std::cout << "Whats task for today ?";
                    std::getline(std::cin , task);

                    todolist.push_back(task);
                    std::cout << "task is added successfully!"<<std::endl;
                    std::cout<<"press enter to continue on your new task "<< std::endl;
                }
            break;
            case 2:
                {
                    std::cout <<"Currently task u r working on : "<<std::endl;
                    if(todolist.empty()){
                        std::cout<<" ur list is empty currently "<<std::endl;
                    }
                    else{
                        for(int i = 0; i <todolist.size();i++)
                        {
                            std::cout<< i+1 << "." <<todolist[i]<<std::endl;
                        
                        }

                    }
                }
            break;
            case 3:
                {
                    if(todolist.empty()){
                        std::cout<<" ur list is empty currently "<<std::endl;
                    }
                    else{
                        std::cout<<"enter the task number u want to remove : "<<std::endl;
                        for(int i = 0; i< todolist.size();i++){
                            std::cout<< i+1 <<"." <<todolist[i] <<std::endl;
                        }
                        int taskno.;
                        std::cin >> taskno.;
                        if (taskno. < 1 || taskno. > todolist.size()){
                            std::cout<<" invalid task no. , please try again or else drop dead "<< std::endl;
                        }
                        else {
                            todolist.erase(todolist.begin() + taskno. -1);
                            std::cout<< "task successfully terminated , so forget about it returning to existence "<< std::endl;

                        }
                    }

                }
            break;
            case 4:
                 {
                  if(todolist.empty()){
                    std::cout<<" ur list is empty , just start the damn work already "<<std::endl;
                }
                 else 
                  {
                    std::cout<<" these r ur following tasks : "<<std::endl;
                    for(int i = 0; i < todolist.size();i++){
                        std::cout<< i+1 <<"." <<todolist[i] <<std::endl;
                    }
                  }
                  
                }
            break;
            default:
                {
                    std::cout<<" invalid user behaviour detected , are u fuckin idiot , didn't u read the instructions ?"<<std::endl;     
                }
            break;
        }
    } 
    return 0;
}
            

