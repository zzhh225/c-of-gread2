#include <iostream>
#include <cstdlib>
#include <fstream>
#define InitialValue 10
struct NodeLinkedList{
    double coefficient;
    int exponent;
    struct NodeLinkedList *next;
};

class Polynomial{
public:
    Polynomial();
    void CreatePolynomialA(const int *exponent,const double *coefficient,int n);
    void polynomialAddtion();
    void OutputToFile();
    void Output();
private:
    NodeLinkedList *PolynomialA;
    NodeLinkedList *PolynomialB;
};

Polynomial::Polynomial() {
    PolynomialA = (NodeLinkedList*)malloc(sizeof(NodeLinkedList));
    PolynomialB = (NodeLinkedList*)malloc(sizeof(NodeLinkedList));
}

void Polynomial::CreatePolynomialA(const int *exponent,const double *coefficient,int number) {
    for(int i = number - 1; i >= 0; i--){
        NodeLinkedList *NewNode;
        NewNode = (NodeLinkedList*)malloc(sizeof(NodeLinkedList));
        NewNode->exponent = exponent[i];
        NewNode->coefficient = coefficient[i];
        NewNode->next = PolynomialA->next;
        PolynomialA = NewNode;
    }
}
//todo 多项式加减
void Polynomial::polynomialAddtion() {

}
//todo 输出到文件
void Polynomial::OutputToFile() {

}
//todo 输出
void Polynomial::Output() {

}

int main() {
    int n = 2,Number;
    int *Exponent[n];
    double *Coefficient[n];
    for (int i = 0; i < n; i++) {
        Exponent[i] = (int *) malloc(InitialValue * sizeof(int));
        Coefficient[i] = (double *) malloc(InitialValue * sizeof(double));
    }
    Polynomial Polynomial;
    Polynomial.CreatePolynomialA(Exponent[0], Coefficient[0],Number);
    Polynomial.polynomialAddtion();
    Polynomial.Output();
    Polynomial.OutputToFile();
}
