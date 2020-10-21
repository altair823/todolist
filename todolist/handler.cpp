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
    
    list_size = save_file.read_list_size();
    ioconsole.print_info(list_size);
    
    for (int i=0; i<list_size; i++){
        todo_list[i] = new work;
        *todo_list[i] = save_file.readline_todo();
        //todo_list[i]->test_print();
    }
}

void handler::print_todo_withnumber(){
    for(int i=0; i<list_size; i++){
        ioconsole.print_todo_default(*todo_list[i]);
    }
}

void handler::print_todo_withurgen(){
    std::cout<<"긴급한 정도 >> "<<std::endl;
    for(int urgency_level=3; urgency_level>0; urgency_level--){
        for(int i=0; i<list_size; i++){
            if (todo_list[i]->put_urgency() == urgency_level){
                ioconsole.print_todo_urgency(*todo_list[i]);
            }
        }
    }
}

void handler::print_todo_withimport(){
    std::cout<<"중요한 정도 >> "<<std::endl;
    for(int importance_level=3; importance_level>0; importance_level--){
        for(int i=0; i<list_size; i++){
            if (todo_list[i]->put_importance() == importance_level){
                ioconsole.print_todo_importance(*todo_list[i]);
            }
        }
    }
}
