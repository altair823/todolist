//
//  fileRecord.cpp
//  todolist
//
//  Created by 김태현 on 2020/10/21.
//

#include "fileRecord.hpp"

//파일을 열고 닫을 인스턴스가 처음 만들어지면 파일의 존재여부와 그 비밀번호를 체크한다.
file_stream::file_stream(){
    save_file = openfile();
    password_confirm();
    
}

std::fstream file_stream::openfile(){
    std::fstream save;
    
    while (true) {
        save.open("./desktop/todo_save.txt");
        
        if (!save.is_open()){
            std::cout<<"no_file_error!"<<std::endl;
            std::cout<<"make a new save file"<<std::endl;
            std::ofstream make_file("./desktop/todo_save.txt");
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
