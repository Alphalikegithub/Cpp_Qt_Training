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
	: id(nullptr) // ��ʼ�� id Ϊ nullptr
{
}

Employee::~Employee()
{
	if (id != nullptr) {
		delete[] id; // �ͷ� id ָ����ڴ�
	}
}





//void readFile(const std::string& filename)
//{
//	//���ļ��Ĵ�С
//  int size = getSizeofFile();
//
//  //������ڴ�
//	char* buf = new char[size];
//
//	//���ļ����ݶ���buf��
//	readFileToBuf(buf, size);
//	//����buf�е�����
//	process(buf, size);
//	//�ͷŶ��ڴ�
//	delete[] buf;
//}


//C++��������
//int char float double
void builtin_type()
{
	bool a = true;//1���ֽ� ������

	char b; sizeof(b);//1���ֽ� �ַ���
	unsigned char c; sizeof(c);//1���ֽ�

	short d = 0; sizeof(c);//2���ֽ� ������
	unsigned short d1; sizeof(d);//2���ֽ�	

	int e; sizeof(e);//4���ֽ� ����
	unsigned int f; sizeof(f);//4���ֽ�

	long g; sizeof(g);	//4���ֽ� ������
	unsigned long h; sizeof(h);//4���ֽ�	

	long long i; sizeof(i);//8���ֽ� ��������
	unsigned long long j; sizeof(j);//8���ֽ�

	const char* str = "hello";//strָ������ݲ��ܸı�
	sizeof(str);//4���ֽ� ָ��Ĵ�С 32λϵͳ4���ֽ� 64λϵͳ8���ֽ� C�����ַ�����'\0'��β 1���ֽ�
	std::cout << strlen(str) << std::endl;//5���ֽ�
	std::cout << sizeof(str) << std::endl;

	const char* str1 = "xxx";
	std::cout << sizeof(str1) << std::endl;
	std::cout << sizeof("xxx") << std::endl;//"xxx"��һ���ַ���������ռ��4���ֽ� ��ΪC�����ַ�����'\0'��β 1���ֽ�


  //����
	//���壺���� ������[Ԫ�ظ���] = {Ԫ��1, Ԫ��2, ...};
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//40���ֽ�
	std::cout << sizeof(arr) << std::endl;//40���ֽ�
	//����new[]�����������ջ�ϵ����飬����ʱ��ȷ��������Ĵ�С��Ҳ����Ҫ����������ǳ�������֪�ģ�
	const int aa = 10;
	int a_stack_arr[aa] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//40���ֽ�
	//��������Ԫ�أ���һ��ֵ��
	std::cout << arr[0] << std::endl; //1
	std::cout << *arr << std::endl; //1
	//���ʵڶ���ֵ
	std::cout << a_stack_arr[1] << std::endl;		//2
	std::cout << *(a_stack_arr + 1) << std::endl; //2
}



int main() {
    //C++���
	  int* pInt = new int[100];//100��4���ֽ�
		//C���
		int* pInt2 = (int*)malloc(100 * sizeof(int));//100��4���ֽ�


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
		e1.id = new char[10]; // Ϊ id �����ڴ�
		//strcpy(e1.id, "123456"); // �����ַ����� id

		// ʹ�� strcpy_s ���� strcpy
		strcpy_s(e1.id, 10, "123456"); // �����ַ����� id


    return 0;

		

		
}