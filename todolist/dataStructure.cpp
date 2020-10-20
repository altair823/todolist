//
//  dataStructure.cpp
//  todolist
//
//  Created by 김태현 on 2020/10/20.
//

#include "dataStructure.hpp"
#include <iostream>

work::work(int number, std::string todo, int urgency, int importance){
    work_number = number;
    work_string = todo;
    work_urgency = urgency;
    work_importance = importance;
}

void work::set_num(int num){ work_number = num; }
void work::set_urgency(int urgency_num){ work_urgency = urgency_num; }
void work::set_importance(int importance_num){work_importance = importance_num; }
void work::set_todo(std::string todo){ work_string = todo; }

void work::test_print(){
    std::cout<<work_number<<" - "<<work_string<<" - "<<work_urgency<<" - "<<work_importance<<std::endl;
}

