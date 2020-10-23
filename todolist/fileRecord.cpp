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

int file_stream::read_list_size(){
    std::string buffer;
    std::getline(save_file, buffer, ':');
    
    int size;
    save_file>>size;
    //std::cout<<size<<std::endl;
    return size;
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
    a_todo.set_importance(number);
    save_file>> number;
    a_todo.set_urgency(number);
    
    //a_todo.test_print();
    
    return a_todo;
}



void file_stream::write_initial_file(int list_size){
    save_file.close();
    save_file.open(file_path, std::ios::out);
    
    //비밀번호를 파일에 저장
    save_file.write(security().put_password().c_str(), security().put_password().size());
    save_file.write("\n", 1);
    
    //리스트의 개수를 저장
    save_file.write("list size: ", 11);
    save_file.write(std::to_string(list_size).c_str(), 1);
    save_file.write("\n", 1);
    
    /*
    save_file.close();
    save_file.open(file_path);
     */
}

void file_stream::write_todo_flie(work todo){
    /*
    save_file.close();
    save_file.open(file_path, std::ios::out);
     */
    
    save_file.write(std::to_string(todo.put_num()).c_str(), 1);
    save_file.write(". <", 3);
    save_file.write(todo.put_todo().c_str(), todo.put_todo().size());
    save_file.write("> ", 2);
    save_file.write(std::to_string(todo.put_importance()).c_str(), 1);
    save_file.write(" ", 1);
    save_file.write(std::to_string(todo.put_urgency()).c_str(), 1);
    save_file.write("\n", 1);
    
    
}
