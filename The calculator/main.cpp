#include <iostream>
#include <cstdlib>
#include "main.h"

number::number(){
    numberData = (numberNode *) malloc(sizeof(numberNode));
    numberData->next = nullptr;
}

void number::inputNumber(double num){
    numberNode *newNode;
    newNode = (numberNode *)malloc(sizeof(numberNode));
    newNode->n = num;
    newNode->next = numberData->next;
    numberData->next = newNode;
}

void number::getNumber(double &num){
    if(!numberData->next){
        return;
    }
    num = numberData->next->n;
    numberData->next = numberData->next->next;
}

basicOperator::basicOperator(){
    operatorData = (operatorNode *)malloc(sizeof(operatorNode));
    operatorData->next = nullptr;
}

void basicOperator::getOperator(char &operatorA){
    if(!operatorData->next){
        return;
    }
    operatorA = operatorData->next->n;
    operatorData->next = operatorData->next->next;
}

void basicOperator::inputOperator(char inputOperator){
    operatorNode *newNode;
    newNode = (operatorNode *)malloc(sizeof(operatorNode));
    newNode->n = inputOperator;
    newNode->next = operatorData->next;
    operatorData->next = newNode;
}

bool basicOperator::isEmpty(){
    if(operatorData->next){
        return false;
    }
    return true;
}


basicCalculate::basicCalculate(){
    cout<<"input something"<<endl;
    cin>>inputThing;
}

void basicCalculate::add(){
    double a,b;
    getNumber(a);
    getNumber(b);
    a = a + b;
    inputNumber(a);
}

void basicCalculate::reduction(){
    double a,b;
    getNumber(a);
    getNumber(b);
    a = b - a;
    inputNumber(a);
}

void basicCalculate::multiply(){
    double a,b;
    getNumber(a);
    getNumber(b);
    a = a * b;
    inputNumber(a);
}

void basicCalculate::devide(){
    double a,b;
    getNumber(a);
    getNumber(b);
    a = a / b;
    inputNumber(a);
}

void basicCalculate::sort(){
    basicOperator sortIt;
    char tmp;
    int length;
    length = inputThing.length();
    for(int i = 0; i<length; i++){
        if(inputThing[i] >= '0' && inputThing[i] <= '9'){
            output.inputOperator(inputThing[i]); 
        }
        else{
            if(sortIt.isEmpty()){
                sortIt.inputOperator(inputThing[i]);
                continue;
            }
            switch(inputThing[i]){
            case '+':
                while(!sortIt.isEmpty()){
                    sortIt.getOperator(tmp);
                    if(tmp == '('){
                        sortIt.inputOperator(tmp);
                        break;
                    }
                    output.inputOperator(tmp);
                }
                sortIt.inputOperator(inputThing[i]);
                break;
            case '-':
                while(!sortIt.isEmpty()){
                    sortIt.getOperator(tmp);
                    if(tmp == '('){
                        sortIt.inputOperator(tmp);
                        break;
                    }
                    output.inputOperator(tmp);
                }
                sortIt.inputOperator(inputThing[i]);
                break;
            case '*':
                while(!sortIt.isEmpty()){
                    sortIt.getOperator(tmp);
                    if(tmp == '(' || tmp == '+' || tmp == '-'){
                        sortIt.inputOperator(tmp);
                        break;
                    }
                    output.inputOperator(tmp);
                }
                sortIt.inputOperator(inputThing[i]);
                break;
            case '/':
                while(!sortIt.isEmpty()){
                    sortIt.getOperator(tmp);
                    if(tmp == '(' || tmp == '+' || tmp == '-'){
                        sortIt.inputOperator(tmp);
                        break;
                    }
                    output.inputOperator(tmp);
                }
                sortIt.inputOperator(inputThing[i]);
                break;
            case '(':
                sortIt.inputOperator(inputThing[i]);
                break;
            case ')':
                sortIt.getOperator(tmp);
                while(tmp!='('){
                    output.inputOperator(tmp);
                    sortIt.getOperator(tmp);
                }
                break;
            default:
                break;
            }
        }
    }
    while(!output.isEmpty()){
        output.getOperator(tmp);
        sortIt.inputOperator(tmp);
    }
    output = sortIt;
}

void basicCalculate::calculate(){
    char tmp;
    while(!output.isEmpty()){
        output.getOperator(tmp);
        if(tmp >= '0' && tmp <= '9'){
            inputNumber(tmp-48);
            continue;
        }
        switch(tmp){
            case '+':
                this->add();
                break;
            case '-':
                this->reduction();
                break;
            case '*':
                this->multiply();
                break;
            case '/':
                this->devide();
                break;
        }
    }
    getNumber(result);
    cout<<result<<endl;
}

int main(){
    advancedCalculate things;
    things.sort();
    things.calculate();
    return 0;
}