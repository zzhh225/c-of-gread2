#include <iostream>
#include <string>
#include <cstdlib>
#define MAXNUM 3
#define ADDNUM 10
using namespace std;

struct StudentData{
    int ID;
    int sex;
    string name;
    int age;
    string major;
};

class StudentTableData{
public:
    StudentTableData();
    void CreatStudentTableData(StudentData dataPublic[],int lengthPublic);
    void OutputLength(); //输出长度
    void OutputData(); //输出所有数据
    void SearchData(int s); //通过ID查找数据
    void SearchData(const string& s); //通过name查找数据
    void InsertToList(StudentData AddData, int index); //增加数据
    void DeleteFromList(int index);//删除数据
    StudentData *datatest;
private:
    int lengthPrivate;
    StudentData DataPrivate[MAXNUM];
    StudentData *ImproveDataPrivate;
};

StudentTableData::StudentTableData() {
    ImproveDataPrivate=(StudentData*) malloc(MAXNUM * sizeof(StudentData));
    lengthPrivate = 0;
}

void StudentTableData::CreatStudentTableData(StudentData dataPublic[], int lengthPublic) {
//    ImproveDataPrivate = (StudentData *) malloc(sizeof(StudentData) * MAXNUM);
//    for(int i = 0; i<lengthPublic; i++){
//        cout<<i;
//        DataPrivate[lengthPrivate++] = dataPublic[i];
//        ImproveDataPrivate[lengthPrivate++] = dataPublic[i];
//    }
    ImproveDataPrivate = datatest;
    ImproveDataPrivate[0] = dataPublic[0];
    cout<<2;
    ImproveDataPrivate[1] = dataPublic[1];
    cout<<2;
}


void StudentTableData::OutputLength() {
    cout<<lengthPrivate<<endl;
}

void StudentTableData::OutputData() {
    for(int i = 0; i<lengthPrivate; i++){
//        cout<<DataPrivate[i].ID<<endl;
//        if(DataPrivate[i].sex){
//            cout<<"man"<<endl;
//        }
//        else{
//            cout<<"women"<<endl;
//        }
//        cout<<DataPrivate[i].name<<endl;
//        cout<<DataPrivate[i].age<<endl;
//        cout<<DataPrivate[i].major<<endl;
        cout<<ImproveDataPrivate[i].ID<<endl;
        if(ImproveDataPrivate[i].sex){
            cout<<"man"<<endl;
        }
        else{
            cout<<"women"<<endl;
        }
        cout<<ImproveDataPrivate[i].name<<endl;
        cout<<ImproveDataPrivate[i].age<<endl;
        cout<<ImproveDataPrivate[i].major<<endl;
        cout<<endl;
    }
}

void StudentTableData::SearchData(int s) {
//    for(int i=0; i<lengthPrivate; i++){
//        if(DataPrivate[i].ID == s){
//            cout<<"Get it!"<<endl;
//            cout<<DataPrivate[i].ID<<endl;
//            cout<<DataPrivate[i].sex<<endl;
//            cout<<DataPrivate[i].name<<endl;
//            cout<<DataPrivate[i].age<<endl;
//            cout<<DataPrivate[i].major<<endl;
//            cout<<endl;
//            return;
//        }
//    }
    for(int i=0; i<lengthPrivate; i++){
        if(ImproveDataPrivate[i].ID == s){
            cout<<"Get it!"<<endl;
            cout<<ImproveDataPrivate[i].ID<<endl;
            cout<<ImproveDataPrivate[i].sex<<endl;
            cout<<ImproveDataPrivate[i].name<<endl;
            cout<<ImproveDataPrivate[i].age<<endl;
            cout<<ImproveDataPrivate[i].major<<endl;
            cout<<endl;
            return;
        }
    }
    cout<<"未找到";
}
void StudentTableData::SearchData(const string& s) {
//    for(int i=0; i<lengthPrivate; i++){
//        if(DataPrivate[i].name == s){
//            cout<<"Get it!"<<endl;
//            cout<<DataPrivate[i].ID<<endl;
//            cout<<DataPrivate[i].sex<<endl;
//            cout<<DataPrivate[i].name<<endl;
//            cout<<DataPrivate[i].age<<endl;
//            cout<<DataPrivate[i].major<<endl;
//            cout<<endl;
//            return;
//        }
    for(int i=0; i<lengthPrivate; i++){
        if(DataPrivate[i].name == s){
            cout<<"Get it!"<<endl;
            cout<<ImproveDataPrivate[i].ID<<endl;
            cout<<ImproveDataPrivate[i].sex<<endl;
            cout<<ImproveDataPrivate[i].name<<endl;
            cout<<ImproveDataPrivate[i].age<<endl;
            cout<<ImproveDataPrivate[i].major<<endl;
            cout<<endl;
            return;
        }
    }
    cout<<"IDt found";
}

void StudentTableData::InsertToList(StudentData AddData, int index){
//    if(index > 99){
//        cout<<"wrong";
//        return;
//    }
//    for(int i = lengthPrivate; i > index;i--){
//        DataPrivate[i] = DataPrivate[i+1];
//    }
//    DataPrivate[index-1]=AddData;
    ImproveDataPrivate = (StudentData *)realloc(ImproveDataPrivate,(lengthPrivate+ADDNUM) * sizeof(StudentData));

    for(int i = lengthPrivate; i > index;i--){
        ImproveDataPrivate[i] = ImproveDataPrivate[i+1];
    }
    ImproveDataPrivate[index-1]=AddData;
    lengthPrivate++;
}

void StudentTableData::DeleteFromList(int index) {
    if(index > lengthPrivate){
        cout<<"wrong";
        return;
    }
    for(int i = index; i < lengthPrivate;i--){
        DataPrivate[i] = DataPrivate[i+1];
    }
    lengthPrivate--;
}

void InputDataInMain(StudentData &inputData){
    cout<<"ID of this student:";
    cin>>inputData.ID;
    cout<<"Choose the gender of this student(1:man, 0:woman): ";
    cin>>inputData.sex;
    cout<<"name of this student:";
    cin>>inputData.name;
    cout<<"age of this student:";
    cin>>inputData.age;
    cout<<"major of this student:";
    cin>>inputData.major;
}

int main() {
    int n,Operation,flag=1,index;
    char flag1;
    string search_name,sex;
    StudentTableData data;
    cout<<"welcome to use student system"<<endl;
    cout<<"Please input the number of student"<<endl;
    cin>>n;
    StudentData basedData[n],NewData;
    data.datatest = (StudentData*)malloc(3*sizeof(StudentData));
    for (int i=0; i<n; i++){
        cout<<"you are entering no."<<i+1<<" student information"<<endl;
        InputDataInMain(basedData[i]);
    }
    data.CreatStudentTableData(basedData,n);
    while(flag){
        cout<<"*************************************************"<<endl;
        cout<<"choose one operation:\n";
        cout<<"1.Output data\n"
            <<"2.Search \n"
            <<"3.Add data \n"
            <<"4.Delete data"<<endl;
        cin>>Operation;
        switch (Operation) {
            case 1:
                data.OutputData();
                break;
            case 2:
                cout<<"input the name of student you wanna find:";
                cin>>search_name;
                data.SearchData(search_name);
                break;
            case 3:
                InputDataInMain(NewData);
                cout<<"enter the index:";
                cin>>index;
                data.InsertToList(NewData,index);
                break;
            case 4:
                cout<<"enter the index:";
                cin>>index;
                data.DeleteFromList(index);
                break;
            default:
                continue;
        }
        cout<<"continue? (Y/N)";
        cin>>flag1;
        if(flag1 == 'N'){
            flag=0;
        }
        cout<<"***********************";
    }

}
