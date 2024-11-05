#include<iostream>
#include<string>
#include<memory>
#include <stdexcept>
#include<vector>


std::string findTillSpace(const std::string& command) {
    size_t pos = command.find(' ');
    if (pos == std::string::npos) {
        return command;
    }
    return command.substr(0, pos);
}


bool checkCommand(const std::string& firstcommand, const std::string& secondcommand) {
    if (firstcommand.compare(secondcommand) != 0) {
        throw std::invalid_argument("Unrecognizable tool: " + firstcommand);
    }
    return true; 
}


std::vector<std::string>commandList{"list","find","disk_usage"};







int main(){
    //parser first word is the command and anything after - is my parameter
    //list + space + -
    std::unique_ptr<std::string>user_command = std::make_unique<std::string>();
    std::cout<<"--->";
    std::cin>>*user_command;
    while (user_command != nullptr)
    {
        std::string command = findTillSpace(*user_command); //give me the string from the begining till the first space of the command

        if(checkCommand(*user_command,commandList[0])){
            std::cout<<"i will list everything\n"; //TODO:write a class for listing all the files in the current directory
        }else{
            std::cerr<<"error in command checking";
        }
        std::cout<<"--->";
        std::cin>>*user_command;
        
    }
    





//   std::unique_ptr<std::string> answer = std::make_unique<std::string>("hello");

//     std::string user_input = "hello -la";
//     std::string command = checkCommand(user_input);

//     if (command.compare(*answer) == 0) {
//         std::cout << "I'm gonna list it";
//     } else {
//         std::cout << "Command does not match";
//     }

//     return 0;


    


    return 0;
}