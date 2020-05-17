string中find()返回值是字母在母串中的位置（下标记录），如果没有找到，那么会返回一个特别的标记npos。（返回值可以看成是一个int型的数）

返回子串出现在母串中的首次出现的位置，和最后一次出现的位置。
flag = "c";
position = s.find_first_of(flag);
printf("s.find_first_of(flag) is :%d\n",position);
position = s.find_last_of(flag);
printf("s.find_last_of(flag) is :%d\n",position);


查找某一给定位置后的子串的位置
//从字符串s 下标5开始，查找字符串b ,返回b 在s 中的下标
position=s.find("b",5);
cout<<"s.find(b,5) is : "<<position<<endl;


查找所有子串在母串中出现的位置
//查找s 中flag 出现的所有位置。
flag="a";
position=0;
int i=1;
while((position=s.find(flag,position))!=string::npos)
{
	cout<<"position  "<<i<<" : "<<position<<endl;
        position++;
        i++;
}


反向查找子串在母串中出现的位置，通常我们可以这样来使用，当正向查找与反向查找得到的位置不相同说明子串不唯一。
//反向查找，flag 在s 中最后出现的位置
flag="3";
position=s.rfind (flag);
printf("s.rfind (flag) :%d\n",position);
--------------------------------------------------------------------------------
atoi(vals[0].c_str()))  c++字符串转换为数字的方法



