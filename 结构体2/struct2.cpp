#include<iostream>
#include<string>
using namespace std;

struct hero
{
    string name;
    int age;
    string sex;
};

void bubbleSort(hero *hArr,int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-1; j++)
        {
            if (hArr[j].age > hArr[j+1].age)
            {
                hero temp = hArr[j];
                hArr[j] = hArr[j+1];
                hArr[j+1] = temp;
            }
        }
    }
}

void printHeros(hero *hArr,int len)
{
    for (int i = 0; i < len; i++)
    {
        /* code */
        cout<<"name:"<<hArr[i].name<<"sex:"<<hArr[i].sex<<"age:"<<hArr[i].age<<endl;
    }
    
}

int main()
{
    struct hero hArr[5]
    {
        {"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
    };

    int len = sizeof(hArr)/sizeof(hero);

    bubbleSort(hArr,len);
    printHeros(hArr,len);
    
    return 0;
}