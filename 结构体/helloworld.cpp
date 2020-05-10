#include<iostream>
#include<string>
#include<ctime>
using namespace std;

struct Student
{
    string name;
    int score;
};

struct Teacher
{
    string name;
    Student stu[5];
};

void allocateSpace(Teacher *tArray,int len)
{
    string tName = "teacher";
    string sName = "student";
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++)
    {
        tArray[i].name = tName + nameSeed[i];

        for (int j = 0; j < 5; j++)
        {
            tArray[i].stu[j].name = sName + nameSeed[j];
            tArray[i].stu[j].score = rand() % 61 + 40;
        }
    }
}

void printTeachers(Teacher *tArray,int len)
{
    for (int i = 0; i < len; i++)
    {
        cout<<"teacher is:"<<tArray[i].name<<endl;
        cout<<"the students belong to this teacher and their scores:"<<endl;
        for (int j = 0; j < 5; j++)
        {
            cout<<"name:"<<tArray[i].stu[j].name<<"    score:"<<tArray[i].stu[j].score<<endl;
        }
        cout<<"-------------------------------------------";
    }
    
}

int main()
{
    srand((unsigned int)time(NULL));  //随机数种子

    struct Teacher tArray[3]; //3个老师
    int len = sizeof(tArray)/sizeof(Teacher); //得到长度

    allocateSpace(tArray,len);
    printTeachers(tArray,len);

    return 0;
}