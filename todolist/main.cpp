//
//  main.cpp
//  todolist
//
//  Created by 김태현 on 2020/10/20.
//

#include <iostream>
#include "handler.hpp"


int main(int argc, const char * argv[]) {
    
    handler a;
    a.read_todo();
    a.print_todo_withnumber();
    a.print_todo_withurgen();
    a.print_todo_withimport();

}
