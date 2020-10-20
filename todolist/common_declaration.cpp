//
//  common_declaration.cpp
//  todolist
//
//  Created by 김태현 on 2020/10/21.
//

#include "common_declaration.hpp"

security::security(){
    password = "823eric!@";
}

bool security::verify_password(std::string word){
    if (word == password){
        return true;
    }
    else{
        return false;
    }
}
