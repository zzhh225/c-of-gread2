#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
using namespace std;
#define InitialValue 100
#define InitNumber 10
struct NodeLinkedList{
    double coefficient;
    int exponent;
    struct NodeLinkedList *next;
};

class Polynomial{
public:
    Polynomial();
    Polynomial(int);
    void inputNumber();
    void sortArray(int *, double *, int n);
    void CreatePolynomial(const int *exponent, const double *coefficient, int number,int i);
    void polynomialAddtion();
    void combineExponent();
    void OutputToFile();
    void Output();

private:
    void deleteNode(int);
    NodeLinkedList *headPolynomial[InitNumber],*resultHeadPolynomial;
    int numberOfPolynomials;
};

Polynomial::Polynomial() {}

Polynomial::Polynomial(int n) {
    numberOfPolynomials = n;
    for(int i = 0; i < n; i++){
        headPolynomial[i] = (NodeLinkedList *)malloc(sizeof(NodeLinkedList));
        headPolynomial[i]->next = NULL;
    }
}

void Polynomial::inputNumber(){
    int Number;
    int *Exponent[numberOfPolynomials];
    double *Coefficient[numberOfPolynomials];
    for (int i = 0; i < numberOfPolynomials; i++) {
        Exponent[i] = (int *) malloc(InitialValue * sizeof(int));
        Coefficient[i] = (double *) malloc(InitialValue * sizeof(double));
    }
    for(int i = 0; i < numberOfPolynomials; i++) {
        cout<<"输入该多项式项数";
        cin >> Number;
        for (int j = 0; j < Number; j++) {
            cout<<"输入第"<<j+1<<"项的系数";
            cin >> Coefficient[i][j];
            cout<<"输入第"<<j+1<<"项的次数";
            cin >> Exponent[i][j];
        }
        this->sortArray(Exponent[i], Coefficient[i], Number);
        this->CreatePolynomial(Exponent[i], Coefficient[i], Number, i);
    }
}

//构建多项式
void Polynomial::CreatePolynomial(const int exponent[], const double coefficient[], int number, int n) {
    for(int i = number - 1; i >= 0; i--){
        NodeLinkedList *NewNode;
        NewNode = (NodeLinkedList*)malloc(sizeof(NodeLinkedList));
        NewNode->exponent = exponent[i];
        NewNode->coefficient = coefficient[i];
        NewNode->next = headPolynomial[n]->next;
        headPolynomial[n]->next = NewNode;
    }
}

void Polynomial::deleteNode(int n) {
    NodeLinkedList *p,*q;
    p = headPolynomial[0]->next;
    int j = 1;
    while(p && j < n - 1){
        p = p->next;
        j++;
    }
    q = p->next;
    p->next = q->next;
}

// 多项式加减
void Polynomial::polynomialAddtion() {
    NodeLinkedList *Node1,*Node2,*Node3;
    Node1 = headPolynomial[0]->next;
    Node2 = headPolynomial[1]->next;
    Node3 = headPolynomial[0];
    while(Node1 && Node2){
        if(Node1->exponent >= Node2->exponent){
            Node3->next = Node1;
            Node3 = Node1;
            Node1 = Node1->next;
        }
        else{
            Node3->next = Node2;
            Node3 = Node2;
            Node2 = Node2->next;
        }
    }
    Node3->next = Node1 ? Node1:Node2;
}
// 整合同次数项
void Polynomial::combineExponent(){
    NodeLinkedList *Node;
    int j=1;
    Node = headPolynomial[0]->next;
    while(Node && Node->next){
        if(Node->exponent == Node->next->exponent){
            Node->coefficient += Node->next->coefficient;
            deleteNode(j+1);
        }
        else{
            j++;
            Node = Node->next;
        };

    }
}
// 输出到文件
void Polynomial::OutputToFile() {
    fstream out("result.txt",ios::out|ios::in);
    NodeLinkedList *p;
    p = headPolynomial[0]->next;
    while(p)
    {
        if(!p->next){
            out<<p->coefficient<<"X^"<<p->exponent;
        }
        else{
            out << p->coefficient << "X^" << p->exponent << "+";
        }
        p=p->next;
    }
}
//输出到终端
void Polynomial::Output() {
    NodeLinkedList *p;
    p = headPolynomial[0]->next;
    while(p)
    {
        if(!p->next){
            cout<<p->coefficient<<"X^"<<p->exponent;
        }
        else{
            cout << p->coefficient << "X^" << p->exponent << "+";
        }
        p=p->next;
    }
}
//对输入的数组排序
void Polynomial::sortArray(int *a,double *b,int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0;j < n- i - 1; j++){
            if(*(a+j)<*(a+j+1)){
                int temp1 = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp1;
                double temp2 = *(b+j);
                *(b+j) = *(b+j+1);
                *(b+j+1) = temp2;
            }
        }
    }
}

int main() {
    int n = 2;
    Polynomial Polynomial(n);
    Polynomial.inputNumber();
    Polynomial.polynomialAddtion();
    Polynomial.combineExponent();
    Polynomial.Output();
    Polynomial.OutputToFile();
    return 0;
}
