//
//  dataStructure.hpp
//  todolist
//
//  Created by 김태현 on 2020/10/20.
//

#ifndef dataStructure_hpp
#define dataStructure_hpp

#include <stdio.h>
#include <string>

class work {
private:
    
    //할 일을 순서대로 저장하기 위한 인덱스 숫자
    int work_number;
    
    //할 일의 긴급성을 세 단계로 나누어 저장하기 위한 변수
    int work_urgency;
    
    //할 일의 중요성을 세 단계로 나누어 저장하기 위한 변수
    int work_importance;
    
    //할 일을 저장하는 문자열
    std::string work_string;
public:
    
    work();
    work(int number, std::string todo, int urgency = 2, int importance = 2);
    work(const work &ref);
    
    //할 일을 분류하기 위한 기본적인 정보를 저장하는 함수
    void set_num(int);
    void set_urgency(int);
    void set_importance(int);
    void set_todo(std::string);
    
    //테스트용 함수들
    void test_print();
};
#endif /* dataStructure_hpp */
