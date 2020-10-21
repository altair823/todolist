//
//  consoleStream.hpp
//  todolist
//
//  Created by 김태현 on 2020/10/21.
//

#ifndef consoleStream_hpp
#define consoleStream_hpp

#include <iostream>
#include "dataStructure.hpp"

using namespace std;

class console_stream{
    
public:
    console_stream();
    
    //정보를 보여주는 함수
    void print_info(int list_size);
    
    //할 일 리스트를 보여주는 함수
    void print_todo_default(work todo);
    
    //할 일 리스트를 긴급도와 함께 보여주는 함수
    void print_todo_urgency(work todo);
    
    //할 일 리스트를 중요도와 함께 보여주는 함수
    void print_todo_importance(work todo);
};

#endif /* consoleStream_hpp */
