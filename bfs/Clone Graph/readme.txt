c++之数据的深拷贝和浅拷贝:
深拷贝是指源对象与拷贝对象互相独立，其中任何一个对象的改动都不会对另外一个对象造成影响。举个例子，一个人名叫张三，后来用他克隆（假设法律允许）了另外一个人，叫李四，不管是张三缺胳膊少腿还是李四缺胳膊少腿都不会影响另外一个人。比较典型的就是Value（值）对象，如预定义类型Int32，Double，以及结构（struct），枚举（Enum）等。

考虑以下写法

       int source = int.MaxValue;//(1)初始化源对象为整数的最大值2,147,483,647

       int dest = source;//(2)赋值，内部执行深拷贝

       dest = 1024;//(3)对拷贝对象进行赋值

       source = 2048;//(4)对源对象进行赋值

       首先（2）中将source赋给dest，执行了深拷贝动作，其时dest和source的值是一样的，都是int.MaxValue；（3）对dest进行修改，dest值变为1024，由于是深拷贝，因此不会运行source，source仍然是int.MaxValue；（4）对source进行了修改，同样道理，dest仍然是1024，同时int.MaxValue的值也不变，仍然是2,147,483,647；只有source变成了2048。
--------------------------------------------------------------------------------------------
浅拷贝是指源对象与拷贝对象共用一份实体，仅仅是引用的变量不同（名称不同）。对其中任何一个对象的改动都会影响另外一个对象。举个例子，一个人一开始叫张三，后来改名叫李四了，可是还是同一个人，不管是张三缺胳膊少腿还是李四缺胳膊少腿，都是这个人倒霉。比较典型的就有Reference（引用）对象，如Class（类）。
考虑以下写法
        class Point
        {
            public int X;
            public int Y;
            public Point(int x, int y)
            {
                X = y;
                Y = x;
            }
        }
        Point source = new Point(10, 20);
        Point dest = source;
   dest.X = 20;
由于Point现在是引用对象，因此Point dest=source的赋值动作实际上执行的是浅拷贝，最后的结果应该是source的X字段值也变成了20。即它们引用了同一个对象，仅仅是变量明source和dest不同而已。
--------------------------------------------------------------------------------------------------------------
数据结构指针:
struct movies_t {
char title [50];
int year;
};
movies_t amovie;
movies_t * pmovie;
这里 amovie 是一个结构类型movies_t 的对象，而pmovie 是一个指向结构类型movies_t 的对象的指针。所以，同基本数据类型一样，以下表达式正确的：
pmovie = &amovie;
上面的代码中引入了一个重要的操作符：->。这是一个引用操作符，常与结构或类的指针一起使用，以便引用其中的成员元素，这样就避免使用很多括号。例如，我们用：
pmovie->title
来代替：
(*pmovie).title
以上两种表达式pmovie->title 和 (*pmovie).title 都是合法的，都表示取指针pmovie 所指向的结构其元素title 的值。
--------------------------
(*pmovie).title与*pmovie.title区别:
*pmovie.title它相当于*(pmovie.title)
表示取结构pmovie 的元素title 作为指针所指向的值，这个表达式在本例中没有意义，因为title本身不是指针类型。


表达式	描述	等价于
pmovie.title	结构pmovie 的元素title	 
pmovie->title	指针pmovie 所指向的结构其元素title 的值	(*pmovie).title
*pmovie.title	结构pmovie 的元素title 作为指针所指向的值	*(pmovie.title)
----------------------------------------------------------------------------------
结构体的嵌套:
struct movies_t {
char title [50];
int year;
}

struct friends_t {
char name [50];
char email [50];
movies_t favourite_movie;
} charlie, maria;

friends_t * pfriends = &charlie;
charlie.name
maria.favourite_movie.title
charlie.favourite_movie.year
pfriends->favourite_movie.year
---------------------------------------------------------------------------------------
解题思路:
题目的要求是让我们实现一个图的深拷贝。深拷贝指的是复制另外一个对象到自己的对象中，且两者不共享一个内存区，浅拷贝指的是两者共享一个内存区。
所以我们需要new 来开辟新的内存区执行拷贝。还要注意一个问题。我们这个图实际上是个有向图，如果A有一个相邻顶点B，则A->B, 但是B能否到A取决于B是否有相邻顶点A. 也就是说如果B能达到A，说明图中存在环，如果不考虑环的存在，我们在拷贝中可能形成死循环。
例如:A<-->B
假设我们从图的A点出发，进行拷贝得到A(A2), 发现A有一个相邻顶点B，然后进行拷贝得到B(B2),然后链接A2->B2，使得B2成为A2的相邻顶点。
接着，我们操作B, 发现B有一个相邻顶点A, 而A我们是已经进行过拷贝的了。如果我们又对A再次进行拷贝, 将形成个死循环，我们要做的仅是将B2->A2连接起来。
如何才能避免这种再次拷贝呢？我们只需要一个map即可，每次我们做一份拷贝，就放入map中，下次查询，如果是已经有的copy就不再继续拷贝，只是连接。
如果没有，就做拷贝，然后连接，然后放入map. map的key是原来的顶点，value是原来定点的copy版。

queue中维护的是未处理neighbor的顶点，也是未拷贝过的结点。
map中的key,value分别保存copy过的原节点和copy节点。

我们先copy根结点，然后放入队列，接下来进行广度优先搜索办法，不断处理队列中的节点，先得到当前节点和其copy版本，然后判断当前节点的所有neighbors, 
如果已经拷贝过，只做连接操作，如果没有拷贝过，先进行拷贝，然后连接，然后放入map和queue.当队列中的元素都处理完，BFS结束，返回copy根结点。





























