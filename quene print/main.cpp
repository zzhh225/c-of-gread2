#include <iostream>
#include "main.h"

quenePrint::quenePrint(){
    this->printquene = (queneNode *) malloc (sizeof(queneNode));
    this->printquene->next = nullptr;
}

void quenePrint::getTrue(int num){
    queneNode *p =this->printquene;
    int length;
    this->getLength(length);
    num = length + 1 - num;
    int i = 0;
    while(i<num){
        p=p->next;
        i++;
    }
    p->isIt = true;
}

void quenePrint::push(int num){
    queneNode *newNode;
    newNode = (queneNode *)malloc(sizeof(queneNode));
    newNode->n = num;
    newNode->next = this->printquene->next;
    this->printquene->next = newNode;
}

void quenePrint::pop(int &num){
    queneNode *p =this->printquene;
    while(p->next->next){
        p = p->next;
    }
    num = p->next->n;
    p->next = nullptr;
}

void quenePrint::getLength(int &num){
    queneNode *p =this->printquene;
    num = 0;
    while(p->next){
        p = p->next;
        num++;
    }
    
}

int quenePrint::max(){
    queneNode *p =this->printquene;
    int num=1;
    while(p->next){
        p = p->next;
        if(num < p->n){
            num = p->n;
        }
    }
    return num;
}

bool quenePrint::isTrue(){
    queneNode *p = this->printquene;
    while(p->next){
        p = p->next;
    }
    return p->isIt;
}

bool quenePrint::isEmpty(){
    if(this->printquene->next){
        return false;
    }
    return true;
}

void inputModule(quenePrint &q){
    int num;
    char tmp[255];
    std::cout<<"输入打印队列"<<std::endl;
    std::cin.getline(tmp,255);
    int length = 0;
    while(tmp[length] != 0){
        length++;
    }
    for(int i = 0; i<length; i++){
        if(tmp[i] != 32){
            q.push(tmp[i]-48);
        }
    }
    std::cout<<"输入您感兴趣的位置"<<std::endl;
    std::cin>>num;
    q.getTrue(num);
}

void sort(quenePrint &q,quenePrint &r){
    int num,length,flag,max;
    while(!q.isEmpty()){
        max = q.max();
        q.getLength(length);
        for(int j = 0; j<length; j++){
            flag = 0;
            if(q.isTrue()){
                flag = 1;
            }
            q.pop(num);
            if(num == max){
                r.push(num);
                if(flag){
                    int length2;
                    r.getLength(length2);
                    r.getTrue(length2);
                }
                if(max != q.max()){
                    break;
                }
            }
            else{
                q.push(num);
                if(flag){
                    int length2;
                    q.getLength(length2);
                    q.getTrue(length2);
                }
            }
        }
        
    }
}

void solution(quenePrint &r){
    int count = 1;
    int tmp;
    while(!r.isTrue()){
        r.pop(tmp);
        count++;
    }
    std::cout<<count<<std::endl;
}

int main(){
    quenePrint print,result;
    inputModule(print);
    sort(print,result);
    solution(result);
    return 0;
}