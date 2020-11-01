#ifndef MAIN_H
#define MAIN_H 

using namespace std;

struct numberNode{
    double n;
    numberNode *next;
};

struct operatorNode{
    char n;
    operatorNode *next;
};

class number{
public:
    number();
    void getNumber(double &) ;
    void inputNumber(double);
private:
    numberNode *numberData;
};

class basicOperator{
public:
    basicOperator();
    void getOperator(char &);
    void inputOperator(char);
    bool isEmpty();
private:
    operatorNode *operatorData;
};

class basicCalculate : public number{
public:
    basicCalculate();
    void calculate();
    void sort();
    void add();
    void reduction();
    void multiply();
    void devide();
private:
    double result;
    string inputThing;
    basicOperator output;
};

class advancedCalculate: public basicCalculate{
public:
    void factorial();
    void power();
};
#endif