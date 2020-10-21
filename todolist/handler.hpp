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
    
    //파일 입출력을 담당할 멤버
    file_stream save_file;
    
    //콘솔 입출력을 담당할 멤버
    console_stream ioconsole;
    
public:
    handler();
    
    void read_todo();
};

#endif /* handler_hpp */
