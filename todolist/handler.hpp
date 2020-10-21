//
//  handler.hpp
//  todolist
//
//  Created by 김태현 on 2020/10/21.
//

#ifndef handler_hpp
#define handler_hpp

#include "dataStructure.hpp"
#include "fileRecord.hpp"
#include "consoleStream.hpp"

class handler{
    
    //할 일을 저장할 포인트 리스트
    work* todo_list[MAX_TODO];
    
    //할 일 리스트의 크기
    int list_size;
    
    //파일 입출력을 담당할 멤버
    file_stream save_file;
    
    //콘솔 입출력을 담당할 멤버
    console_stream ioconsole;
    
public:
    handler();
    
    //파일에 저장된 할 일 리스트를 모두 불러오는 함수
    void read_todo();
    
    //할 일 리스트를 인덱스 순으로 나열하는 함수
    void print_todo_withnumber();
    
    //할 일을 긴급도 순으로 나열하는 함수
    void print_todo_withurgen();
    
    //할 일을 중요도 순으로 나열하는 함수
    void print_todo_withimport();
    
    //할 일 리스트의 요소를 삭제하는 함수
    void remove_todo(int number);
    
    //할 일 리스트의 요소를 추가하는 함수
    void add_todo(std::string new_todo);
    
    //입력을 받는 함수
    void input_handle();
};

#endif /* handler_hpp */
