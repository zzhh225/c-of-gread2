#include <iostream>
#include <cstdlib>
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
    void sortArray(int *a, double *b, int n);
    void CreatePolynomial(const int *exponent, const double *coefficient, int number,int i);
    void polynomialAddtion();
    void sortPolynomial();
    void OutputToFile();
    void Output();

private:
    int getLength(int n);
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
//获取长度
int Polynomial::getLength(int n) {
    NodeLinkedList *p;
    int k;
    p = headPolynomial[n]->next;
    while(p->next){
        k++;
        p = p->next;
    }
    return k;
}
//对多项式排序
void Polynomial::sortPolynomial() {
//    NodeLinkedList *Node1,*Node2;
//    int number1,number2;
//    number2 = numberOfPolynomials;
//    while(number2--){
//        number1 = getLength(number2);
//        Node1 = headPolynomial[number2];
//        for(int i = 1; i < number1; i++){
//            for(int j = 1; j < number1 - i; j++){
//                if(Node1->next->exponent < Node1->next->next->exponent){
//                    Node2 = Node1->next;
//                    Node1->next = Node1->next->next;
//                    Node1->next = Node2;
//                }
//                Node1 = Node1->next;
//            }
//        }
//    }
//    free(Node1);
//    free(Node2);
}

//todo 多项式加减
void Polynomial::polynomialAddtion() {
    NodeLinkedList *Node1,*Node2,*Node3;
    Node1 = headPolynomial[0]->next;
    Node2 = headPolynomial[1]->next;
    Node3 = headPolynomial[0];
    while(Node1 && Node2){
        if(Node1->exponent < Node2->exponent){
            Node3->next = Node1;
            Node3 = Node1;
            Node1 = Node1->next;
        }
        else if(Node1->exponent == Node2->exponent){
            Node1->coefficient += Node2->coefficient;
            Node3->next = Node1;
            Node3 = Node1;
            Node1 = Node1->next;
            Node2 = Node2->next;
        }
        else{
            Node3->next = Node2;
            Node3 = Node2;
            Node2 = Node2->next;
        }
    }
    Node3->next = Node1 ? Node1:Node2;
    free(Node2);
}
//todo 输出到文件
void Polynomial::OutputToFile() {

}
//todo 输出
void Polynomial::Output() {
    NodeLinkedList *p;
    p = headPolynomial[0]->next;
    while(p)
    {
        cout<<p->exponent<<endl;
        p=p->next;
    }
}

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
//    Polynomial.sortPolynomial();
    Polynomial.polynomialAddtion();
    Polynomial.Output();
    Polynomial.OutputToFile();
    return 0;
}
