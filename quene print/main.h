
#ifndef MAIN_H
#define MAIN_H

struct queneNode{
    double n;
    bool isIt = false;
    queneNode *next;
};

class quenePrint{
public:
    quenePrint();
    void push(int );
    void pop(int &);
    void getTrue(int);
    void getLength(int &);
    int max();
    bool isTrue();
    bool isEmpty();
private:
    queneNode *printquene;
};

void inputModule(quenePrint &);
void solution(quenePrint &);
void sort(quenePrint &, quenePrint &);

#endif