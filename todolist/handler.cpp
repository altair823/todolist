//
//  handler.cpp
//  todolist
//
//  Created by 김태현 on 2020/10/21.
//

#include "handler.hpp"

handler::handler(){
}

void handler::read_todo(){
    
    list_size = save_file.read_list_size();
    ioconsole.print_info(list_size);
    
    for (int i=0; i<list_size; i++){
        todo_list[i] = new work;
        *todo_list[i] = save_file.readline_todo();
        //todo_list[i]->test_print();
    }
}

void handler::print_todo_withnumber(){
    for(int i=0; i<list_size; i++){
        ioconsole.print_todo_default(*todo_list[i]);
    }
}

void handler::print_todo_withurgen(){
    std::cout<<"긴급한 정도 >> "<<std::endl;
    for(int urgency_level=3; urgency_level>0; urgency_level--){
        for(int i=0; i<list_size; i++){
            if (todo_list[i]->put_urgency() == urgency_level){
                ioconsole.print_todo_urgency(*todo_list[i]);
            }
        }
    }
}

void handler::print_todo_withimport(){
    std::cout<<"중요한 정도 >> "<<std::endl;
    for(int importance_level=3; importance_level>0; importance_level--){
        for(int i=0; i<list_size; i++){
            if (todo_list[i]->put_importance() == importance_level){
                ioconsole.print_todo_importance(*todo_list[i]);
            }
        }
    }
}

void handler::remove_todo(int number){
    //범위체크
    if(number >= list_size || number < 0){
        std::cout<<"범위오류!"<<std::endl;
        exit(10);
    }
    
    for(int i=number; i+1<list_size; i++){
        todo_list[i] = todo_list[i+1];
        todo_list[i]->set_num(i+1);
    }
    
    list_size--;
}

void handler::add_todo(std::string new_todo){
    todo_list[list_size] = new work(list_size+1, new_todo);
    
    while (true) {
        
        std::cout<<"중요한 정도를 입력하십시오. (1에서 3까지 입력 가능합니다.) >> ";
        int buffer = 0;
        std::cin>>buffer;
        
        if(buffer<1 || buffer>3){
            cout<<"잘못된 입력입니다. "<<endl;
            continue;
        }
        else{
            todo_list[list_size]->set_importance(buffer);
            //cout<<todo_list[list_size]->put_importance()<<endl;
            break;
        }
    }
    
    while (true) {
        
        std::cout<<"긴급한 정도를 입력하십시오. (1에서 3까지 입력 가능합니다.) >> ";
        int buffer = 0;
        std::cin>>buffer;
        
        if(buffer<1 || buffer>3){
            cout<<"잘못된 입력입니다. "<<endl;
            continue;
        }
        else{
            todo_list[list_size]->set_urgency(buffer);
            //cout<<todo_list[list_size]->put_urgency()<<endl;
            break;
        }
    }
    
    list_size++;
}

void handler::input_handle(){
    std::cout<<"할 일을 중요도 순으로 나열하려면 \"중요\"를, 긴급한 순으로 나열하려면 \"긴급\"을 입력하십시오. 다시 번호순으로 나열하려면 \"번호\"를 입력하시오. "<<std::endl;
    std::cout<<"할 일 리스트에서 삭제하려면 해당 요소의 번호를 입력하시오. "<<std::endl;
    std::cout<<"할 일을 추가하려면 할 일을 입력하시오. "<<std::endl;
    std::cout<<"프로그램을 저장하고 종료하려면 0을 입력하시오"<<std::endl;
    std::cout<<"\">>\" 표시가 나타난 이후에 입력하시오. 표시가 나타나지 않는다면 엔터를 입력하시오."<<std::endl;
    
    print_todo_withnumber();
    
    while (true) {
        
        std::cout<<">>";
        std::string buffer;
        getline(cin, buffer);
        
        
        //문자열이 입력된다면
        if(atoi(buffer.c_str()) == 0 && buffer.compare("0") != 0 && buffer != ""){
            if(buffer == "importance"){
                print_todo_withimport();
            }
            else if (buffer == "urgency"){
                print_todo_withurgen();
            }
            else if (buffer == "number"){
                print_todo_withnumber();
            }
            else{
                //할 일이 입력됨.
                add_todo(buffer);
                print_todo_withnumber();
            }
        }
        //입력된 번호가 범위 내 번호라면
        else if(buffer.compare("0") != 0 && (atoi(buffer.c_str()) <= list_size && atoi(buffer.c_str()) > 0)){
            remove_todo(atoi(buffer.c_str())-1);
            std::cout<<atoi(buffer.c_str())<<"번 할 일이 삭제되었습니다."<<std::endl;
            print_todo_withnumber();
        }
        else if(buffer == "0"){
            save_file.write_initial_file(list_size);
            for(int i=0; i<list_size; i++){
                save_file.write_todo_flie(*todo_list[i]);
            }
            std::cout<<"프로그램을 종료합니다."<<std::endl;
            break;
        }
        else{
            std::cout<<"잘못된 입력입니다."<<std::endl;
            print_todo_withnumber();
        }
        cin.clear();
        cin.ignore();
        continue;
    }
}
