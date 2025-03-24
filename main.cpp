#include <iostream>
#include <string>
#include <vector>

int test1(int para);

int a = 1;


using T1 = decltype(a);
using T = decltype(test1);



int test(int para) {
  return para;
}

int* test(int* para) {
  return para;
}

class MyClass
{
public:
  MyClass()
  {
		std::cout << "MyClass()" << std::endl;
  }
  ~MyClass()
  {
    std::cout << "~MyClass()" << std::endl;
  }

  MyClass(const MyClass& other)
  :_ix(other._ix)
  , _iy(other._iy)
  {
    std::cout << "MyClass(const MyClass & other)" << std::endl;
  }

  

private:
  int _ix;
	int _iy;

protected:
	int _iz;
};


class File
{
public:
	File();
	~File();

private:

public:
	std::string content;
};

class Employee
{
public:
	Employee();
	~Employee();

public:
	char* id;
	int age;
	std::vector<File> files;
};

Employee::Employee()
	: id(nullptr) // 初始化 id 为 nullptr
{
}

Employee::~Employee()
{
	if (id != nullptr) {
		delete[] id; // 释放 id 指向的内存
	}
}





//void readFile(const std::string& filename)
//{
//	//读文件的大小
//  int size = getSizeofFile();
//
//  //分配堆内存
//	char* buf = new char[size];
//
//	//把文件内容读到buf中
//	readFileToBuf(buf, size);
//	//处理buf中的内容
//	process(buf, size);
//	//释放堆内存
//	delete[] buf;
//}


//C++内置类型
//int char float double
void builtin_type()
{
	bool a = true;//1个字节 布尔型

	char b; sizeof(b);//1个字节 字符型
	unsigned char c; sizeof(c);//1个字节

	short d = 0; sizeof(c);//2个字节 短整型
	unsigned short d1; sizeof(d);//2个字节	

	int e; sizeof(e);//4个字节 整型
	unsigned int f; sizeof(f);//4个字节

	long g; sizeof(g);	//4个字节 长整型
	unsigned long h; sizeof(h);//4个字节	

	long long i; sizeof(i);//8个字节 长长整型
	unsigned long long j; sizeof(j);//8个字节

	const char* str = "hello";//str指向的内容不能改变
	sizeof(str);//4个字节 指针的大小 32位系统4个字节 64位系统8个字节 C语言字符串以'\0'结尾 1个字节
	std::cout << strlen(str) << std::endl;//5个字节
	std::cout << sizeof(str) << std::endl;

	const char* str1 = "xxx";
	std::cout << sizeof(str1) << std::endl;
	std::cout << sizeof("xxx") << std::endl;//"xxx"是一个字符串常量，占用4个字节 因为C语言字符串以'\0'结尾 1个字节


  //数组
	//定义：类型 数组名[元素个数] = {元素1, 元素2, ...};
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//40个字节
	std::cout << sizeof(arr) << std::endl;//40个字节
	//不用new[]分配的数组是栈上的数组，编译时就确定了数组的大小，也就是要求个数必须是常量（已知的）
	const int aa = 10;
	int a_stack_arr[aa] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//40个字节
	//访问数组元素（第一个值）
	std::cout << arr[0] << std::endl; //1
	std::cout << *arr << std::endl; //1
	//访问第二个值
	std::cout << a_stack_arr[1] << std::endl;		//2
	std::cout << *(a_stack_arr + 1) << std::endl; //2
}



int main() {
    //C++风格
	  int* pInt = new int[100];//100×4个字节
		//C风格
		int* pInt2 = (int*)malloc(100 * sizeof(int));//100×4个字节


    int a = 1;
    int b = test(a);

    MyClass m1;
    MyClass m2 = m1;

    builtin_type();

		File f1;
		f1.content = "hello";

		/*Employee e1;
		e1.age = 22;
		e1.files.push_back(f1);*/

		Employee e1;
		e1.age = 22;
		e1.files.push_back(f1);
		e1.id = new char[10]; // 为 id 分配内存
		//strcpy(e1.id, "123456"); // 复制字符串到 id

		// 使用 strcpy_s 代替 strcpy
		strcpy_s(e1.id, 10, "123456"); // 复制字符串到 id


    return 0;

		

		
}