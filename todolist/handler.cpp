//
//  handler.cpp
//  todolist
//
//  Created by 김태현 on 2020/10/21.
//

#include "handler.hpp"

handler::handler(){
    
}

void handler::read_todo(){
    
    
    for (int i=0; i<3; i++){
        todo_list[i] = new work;
        *todo_list[i] = save_file.readline_todo();
        todo_list[i]->test_print();
    }
}
