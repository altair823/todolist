//
//  fileRecord.cpp
//  todolist
//
//  Created by 김태현 on 2020/10/21.
//


#include "fileRecord.hpp"

//파일을 열고 닫을 인스턴스가 처음 만들어지면 파일의 존재여부와 그 비밀번호를 체크한다.
file_stream::file_stream(){
    current_cursor = 0;
    save_file = openfile();
    password_confirm();
    
}

std::fstream file_stream::openfile(){
    std::fstream save;
    
    while (true) {
        save.open(file_path);
        
        if (!save.is_open()){
            std::cout<<"no_file_error!"<<std::endl;
            std::cout<<"make a new save file"<<std::endl;
            std::ofstream make_file(file_path);
        }
        else{
            std::cout<<"file opened successfully"<<std::endl;
            break;
        }
    }
    return save;
}

void file_stream::password_confirm(){
    std::string pass;
    save_file >> pass;
    //std::cout<<pass<<std::endl;
    
    if (!security().verify_password(pass)){
        std::cout<<"password incorrect!"<<std::endl;
        exit(10);
    }
}

work file_stream::readline_todo(){
    
    work a_todo;
    
    int number;
    std::string buffer;
    
    //할 일의 인덱스 번호를 저장
    save_file>> number;
    a_todo.set_num(number);
    
    //할 일을 문자열로 저장
    std::getline(save_file, buffer, '<');
    std::getline(save_file, buffer, '>');
    a_todo.set_todo(buffer);
    
    //할 일의 중요도와 긴급도를 저장
    save_file>> number;
    a_todo.set_urgency(number);
    save_file>> number;
    a_todo.set_importance(number);
    
    //a_todo.test_print();
    
    return a_todo;
}
