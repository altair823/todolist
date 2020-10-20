//
//  fileRecord.hpp
//  todolist
//
//  Created by 김태현 on 2020/10/21.
//

#ifndef fileRecord_hpp
#define fileRecord_hpp

#include <iostream>
#include <fstream>
#include "common_declaration.hpp"

//할 일을 저장할 파일과의 입출력을 담당하는 클래스
class file_stream{
    std::fstream save_file;
    
public:
    file_stream();
    
    //파일을 여는 함수
    std::fstream openfile();
    
    //파일을 열어 첫번째 줄에 있는 암호를 비교하는 함수
    void password_confirm();
};



#endif /* fileRecord_hpp */
