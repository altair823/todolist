//
//  common_declaration.cpp
//  todolist
//
//  Created by 김태현 on 2020/10/21.
//

#include "common_declaration.hpp"

security::security(){
    password = PASSWORD;
}

bool security::verify_password(std::string word){
    if (word == password){
        return true;
    }
    else{
        return false;
    }
}

std::string security::put_password(){
    return password;
}
