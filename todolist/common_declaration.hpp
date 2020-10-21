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

//파일을 저장할 경로
#define file_path "./desktop/todo_save.txt"

//할 일의 최대 개수를 정의
#define MAX_TODO 200

class security{
    std::string password;
public:
    security();
    bool verify_password(std::string word);
};

#endif /* common_declaration_hpp */
