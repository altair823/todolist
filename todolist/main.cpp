//
//  main.cpp
//  todolist
//
//  Created by 김태현 on 2020/10/20.
//

#include <iostream>
#include "handler.hpp"


int main(int argc, const char * argv[]) {
    
    handler program;
    program.read_todo();
    program.input_handle();

}
