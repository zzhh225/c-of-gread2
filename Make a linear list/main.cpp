#include<iostream>
#include<string>
#include<cstdlib>
#define MAXNUM 100
#define ADDNUM 10
using namespace std;
typedef struct {
    int no;
    string name;
    int sex;
    int age;
    string major;
}student_data;

typedef struct student_table{
    student_data *data;
    int length;
    int listSize;
}student_table;

//初始化
void InitList_table(student_table &table_data)
{
    table_data.data = (student_data *)malloc(MAXNUM * sizeof(student_data));
    if(!table_data.data)
    {
        cout<<"something wrong!"<<endl;
        return;
    }
    table_data.listSize = MAXNUM;
    table_data.length = 0;
}
//创建新表
void CreatList_table(student_table &table_data, student_data data[], int n)
{
    InitList_table(table_data);
    for(int i =0; i < n; i++)
    {
        table_data.data[table_data.length++] = data[i];
    }
}
//遍历
void ergodic(student_table &table_data)
{
    for(int i=0; i < table_data.length; i++)
    {
        cout<<table_data.data[i].no<<"\n";
        cout<<table_data.data[i].name<<"\n";
        cout<<table_data.data[i].sex<<"\n";
        cout<<table_data.data[i].age<<"\n";
        cout<<table_data.data[i].major<<"\n";
    }
    cout<<endl;
}
//输出单个数据
void output_one(student_table &table_data, int index)
{
    cout<<table_data.data[index - 1].no<<"\n";
    cout<<table_data.data[index - 1].name<<"\n";
    cout<<table_data.data[index - 1].sex<<"\n";
    cout<<table_data.data[index - 1].age<<"\n";
    cout<<table_data.data[index - 1].major<<"\n";
    cout<<endl;
}
//求长度
int get_table_length(student_table &table_data)
{
    return table_data.length;
}
//查询
int search_table(student_table &table_data,int no )
{
    for(int i = 0; i<table_data.length; i++)
    {
        if(table_data.data[i].no == no)
        {
            return i+1;
        }
    }
    return 0;
}
//删除
void Delete_table(student_table &table_data, int index)
{
    if ( index < 1 || index > table_data.length)
    {
        cout<<"index is not allowed";
    }
    for( int j = index; j < table_data.length; j++)
    {
        table_data.data[j - 1] = table_data.data[j];
    }
    table_data.length--;
}
//增加
void Add_table(student_table &table_data, int index, student_data add_data)
{
    if(index < 1 || index>table_data.length + 1)
    {
        cout<<"index is not allowed";
        return;
    }
    if(table_data.length >= table_data.listSize)
    {
        table_data.data = (student_data *)realloc(table_data.data, (table_data.listSize + ADDNUM) * sizeof(student_data) );
    }
    for(int j = table_data.length - 1; j>= index - 1; j--)
    {
        table_data.data[j+1] = table_data.data[j];
    }
    table_data.data[index - 1] = add_data;
    table_data.length++;
}
//输出
void Output_table()
{

}
int main()
{
    student_table student_tableData;
    student_data data[3];
    int index;
    int length;
    data[0].no = 1;
    data[0].name = "Jack";
    data[0].sex = 1;
    data[0].age = 18;
    data[0].major = "CS";
    data[1].no = 2;
    data[1].name = "anna";
    data[1].sex = 0;
    data[1].age = 15;
    data[1].major = "CS";
    data[2].no = 3;
    data[2].name = "aumtun";
    data[2].sex = 1;
    data[2].age = 17;
    data[2].major = "CS";
    CreatList_table(student_tableData, data, 2);
    //Add_table(student_tableData, 2, data[2]);
    ergodic(student_tableData);
    //length = get_table_length(student_tableData);
}
