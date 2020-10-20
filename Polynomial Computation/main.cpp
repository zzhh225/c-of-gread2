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
    void sortPolynomial(int);
    void CreatePolynomial(const int *, const double *, int ,int );
    void add();
    void OutputToFile();
    void Output();
    void product();
    void product(int,double);
private:
    int getLength(int);
    void deleteNode(int);
    void polynomialAddtion(int);
    void combineExponent();
    NodeLinkedList *headPolynomial[InitNumber],*resultHeadPolynomial;
    int numberOfPolynomials;
};

Polynomial::Polynomial() {}

Polynomial::Polynomial(int n) {
    numberOfPolynomials = n;
    resultHeadPolynomial = (NodeLinkedList *)malloc(sizeof(NodeLinkedList));
    resultHeadPolynomial->next = nullptr;
    for(int i = 0; i < 10; i++){
        headPolynomial[i] = (NodeLinkedList *)malloc(sizeof(NodeLinkedList));
        headPolynomial[i]->next = nullptr;
    }
}

//the module of inputing
void Polynomial::inputNumber(){
    int Number;
    int *Exponent[numberOfPolynomials];
    double *Coefficient[numberOfPolynomials];
    for (int i = 0; i < numberOfPolynomials; i++) {
        Exponent[i] = (int *) malloc(InitialValue * sizeof(int));
        Coefficient[i] = (double *) malloc(InitialValue * sizeof(double));
    }
    for(int i = 0; i < numberOfPolynomials; i++) {
        cout<<"input the number of terms of this polynomial:";
        cin >> Number;
        for (int j = 0; j < Number; j++) {
            cout<<"input the no."<<j+1<<" coefficient:";
            cin >> Coefficient[i][j];
            cout<<"input the no."<<j+1<<" exponent:";
            cin >> Exponent[i][j];
        }
        this->CreatePolynomial(Exponent[i], Coefficient[i], Number, i);
        this->sortPolynomial(i);
    }
}

//creat the linked list to storage the polynomial
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

void Polynomial::add(){
    for(int i = 0; i < numberOfPolynomials; i++){
        this->polynomialAddtion(i);
    }
    this->combineExponent();
}
//basic operation about deleting node 
void Polynomial::deleteNode(int n) {
    NodeLinkedList *p,*q;
    p = resultHeadPolynomial->next;
    int j = 1;
    while(p && j < n - 1){
        p = p->next;
        j++;
    }
    q = p->next;
    p->next = q->next;
}

// part one of polynomial add: merge linked list
void Polynomial::polynomialAddtion(int n) {
    NodeLinkedList *Node1,*Node2,*Node3;
    Node3 = resultHeadPolynomial;
    Node1 = resultHeadPolynomial->next;
    Node2 = headPolynomial[n]->next; 
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
// part two of polynomial add: combine the same exponent
void Polynomial::combineExponent(){
    NodeLinkedList *Node;
    int j=1;
    Node = resultHeadPolynomial->next;
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
// output the result to a txt
void Polynomial::OutputToFile() {
    fstream out("result",ios::out|ios::in);
    NodeLinkedList *p;
    p = resultHeadPolynomial->next;
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
//output result to terminal
void Polynomial::Output() {
    NodeLinkedList *p;
    p = resultHeadPolynomial->next;
    while(p)
    {
        if(!p->next){
            cout << p->coefficient << "X^" << p->exponent;
        }
        else{
            cout << p->coefficient << "X^" << p->exponent << "+";
        }
        p=p->next;
    }
    cout<<endl;
}
//sort polynomial
void Polynomial::sortPolynomial(int n){
    NodeLinkedList *node1,*node2;
    int k,e;
    double c;
    if( n == 10){
        node1 = resultHeadPolynomial;
    }
    else{
        node1 = headPolynomial[n];
    }
    k = getLength(n);
    for(int i = 0 ; i < k - 1 ; i++){
        node2 = node1->next;
        for(int j = 0 ; j < k - i - 1 ; j++){
            if(node2->exponent < node2->next->exponent){
                e = node2->exponent;
                c = node2->coefficient;
                node2->exponent = node2->next->exponent;
                node2->coefficient = node2->next->coefficient;
                node2->next->exponent = e;
                node2->next->coefficient = c;
            }
            node2 = node2->next;
        }
    }
}
//product module
void Polynomial::product(){
    NodeLinkedList *polynomialProduct;
    polynomialProduct = headPolynomial[1];
    while(polynomialProduct->next){
        polynomialProduct = polynomialProduct->next;
        this->product(polynomialProduct->exponent,polynomialProduct->coefficient);
    }
    this->sortPolynomial(10);
    this->combineExponent();
}
//son moudule of product
void Polynomial::product(int e, double c){
    NodeLinkedList *p,*q;
    p = headPolynomial[0];
    q = headPolynomial[9];
    while(p->next){
        NodeLinkedList *newNode;
        p = p->next;
        newNode = (NodeLinkedList *)malloc(sizeof(NodeLinkedList));
        newNode->coefficient = p->coefficient * c;
        newNode->exponent = p->exponent + e;
        newNode->next = nullptr;
        q->next = newNode;
        q = q->next;
    }
    this->polynomialAddtion(9);
}
//basic operition of getting polynomial length
int Polynomial::getLength(int n){
    NodeLinkedList *node;
    int k = 0;
    if(n == 10){
        node = resultHeadPolynomial;
    }
    else{
        node = headPolynomial[n];
    }
    while(node->next){
        k++;
        node = node->next;
    }
    return k;
}

int main() {
    int n;
    cout<<"choose way: 1.add  2.product";
    cin>>n;
    Polynomial Polynomial(2);
    Polynomial.inputNumber();
    if(n == 1){
        // cout<<"output the number of polynomial(n<10):";
        // cin>>n;
        Polynomial.add();
    }
    else{
        Polynomial.product();
    }
    Polynomial.Output();
    Polynomial.OutputToFile();
    return 0;
}
