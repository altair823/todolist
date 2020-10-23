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

//프로그램을 열 때 확인할 비밀번호를 정의
#define PASSWORD "823eric!@"

class security{
    std::string password;
public:
    security();
    
    //암호를 체크하는 함수
    bool verify_password(std::string word);
    
    //암호를 변경하는 함수
    
    //암호를 반환하는 함수
    std::string put_password();
};

#endif /* common_declaration_hpp */
