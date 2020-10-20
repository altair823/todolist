//
//  main.cpp
//  todolist
//
//  Created by 김태현 on 2020/10/20.
//

#include <iostream>
#include "dataStructure.hpp"
#include "consoleStream.hpp"
#include "fileRecord.hpp"


int main(int argc, const char * argv[]) {
    work a(1, "tsetname");
    a.set_num(1);
    a.set_todo("test");
    a.test_print();
    
    std::fstream my;
    my.open("test.txt");
    my<<"this is test message";
    my.close();
}
