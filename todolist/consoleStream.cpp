//
//  consoleStream.cpp
//  todolist
//
//  Created by 김태현 on 2020/10/21.
//

#include "consoleStream.hpp"

console_stream::console_stream(){
    cout<<"투ㅡ두 리스트"<<endl<<"Made by kth"<<endl;
}

void console_stream::print_info(int list_size){
    cout<<"저장된 할 일의 총 개수는 "<<list_size<<"개 입니다."<<endl;
    
    cout<<">>"<<endl;
}

void console_stream::print_todo_default(work todo){
    cout<<todo.put_num()<<". "<<todo.put_todo()<<endl;
}

void console_stream::print_todo_urgency(work todo){
    if (todo.put_urgency() == 3){
        cout<<"긴급";
    }
    else if (todo.put_urgency() == 2){
        cout<<"보통";
    }
    else{
        cout<<"여유";
    }
    cout<<" - "<<todo.put_todo()<<endl;
}

void console_stream::print_todo_importance(work todo){
    if (todo.put_importance() == 3){
        cout<<"중요";
    }
    else if (todo.put_importance() == 2){
        cout<<"보통";
    }
    else{
        cout<<"사소";
    }
    cout<<" - "<<todo.put_todo()<<endl;
}
