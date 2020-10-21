//
//  dataStructure.cpp
//  todolist
//
//  Created by 김태현 on 2020/10/20.
//

#include "dataStructure.hpp"
#include <iostream>

work::work(){
    work_number = 0;
    work_string = "";
    work_urgency = 0;
    work_importance = 0;
}

work::work(int number, std::string todo, int urgency, int importance){
    work_number = number;
    work_string = todo;
    work_urgency = urgency;
    work_importance = importance;
}

work::work(const work &ref){
    work_number = ref.work_number;
    work_string = ref.work_string;
    work_urgency = ref.work_urgency;
    work_importance = ref.work_importance;
}

void work::set_num(int num){ work_number = num; }
void work::set_urgency(int urgency_num){ work_urgency = urgency_num; }
void work::set_importance(int importance_num){work_importance = importance_num; }
void work::set_todo(std::string todo){ work_string = todo; }

void work::test_print(){
    std::cout<<work_number<<" - "<<work_string<<" - "<<work_urgency<<" - "<<work_importance<<std::endl;
}

