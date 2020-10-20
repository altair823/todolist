//
//  common_declaration.hpp
//  todolist
//
//  Created by 김태현 on 2020/10/21.
//

#ifndef common_declaration_hpp
#define common_declaration_hpp

#include <stdio.h>
#include <iostream>

class security{
    std::string password;
public:
    security();
    bool verify_password(std::string word);
};

#endif /* common_declaration_hpp */
