#include"iostream"
#include <fstream>
#include"stdlib.h"
#define MAX 100
using namespace std;
class person  //定义一个类实现共有的基础信息
{
public:
	int num;
	char name[20];
	string sex;
	int age;
};

//Teacher class 教师
class Teacher :virtual public person
{

public:
	char dept[20];
	char special[20];
	char title[20];
	void Input(int nu)  //录入信息
	{
		num = nu;
		cout << "Input name:"; cin >> name;
		do {
			cout << "Input sex:"; cin >> sex;
			if (sex != "男" && sex != "女")
				cout << "性别只能是男或女，请重新输入：" << endl;;
		} while (sex != "男" && sex != "女");
		cout << "Input age:"; cin >> age;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误，年龄为数，请输入数字" << endl;; cin >> nu;
		}
		cout << "Input dept:"; cin >> dept;
		cout << "Input special:"; cin >> special;
		cout << "Input title:"; cin >> title;
	}
	void Output()  //输出信息
	{
		cout << "编号: " << num << "  " << "姓名: " << name << "  " << "性别: " << sex << "  " << "年龄: " << age <<
			"  " << "所在系: " << dept << "  " << "专业: " << special << "  " << "职称: " << title << endl;
	}
};
Teacher Tea[MAX]; 
static int Teatop;  

class TeaManager  //教师的管理类
{
public:
	int Add();
	int Search();
	void Show();
	void Edit();
	int Delete();
	void Save();
	void Read();
};
int TeaManager::Add()  //添加功能
{
	
	Teacher t;
	int i, nu, n = 1;
	
	if (Teatop == MAX)
	{
		cout << "人数已满" << endl;
		return 0;
	}
	do {
		int flag = 0; //是否已存在
		cout << "请输入编号:"; cin >> nu;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> nu;
		}
		for (i = 0; i < Teatop; i++)
		{
			if (nu == Tea[i].num)
			{
				cout << "已有该编号" << endl;
				flag = 1;
			}
		}
		if (flag != 1)
		{
			t.Input(nu); Tea[Teatop] = t; Teatop++;
			cout << "添加成功！" << endl;
		}
		cout << "是否继续添加，是输入1，不添加输入其他：" << endl;
		cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			return 1;
		}
	} while (n == 1);
	cout << "是否将添加内容保存到文档：保存(1),不保存（其他）" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	return 1;
}
int TeaManager::Search()  //查询功能
{
	
	int j, n;
	int flag=0;
	
	do {
		cout << "请输入编号："; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> n;
		}
		for (j = 0; j < Teatop; j++)
		{
			if (n == Tea[j].num) break;
		}
		if (j == Teatop)
		{
			cout << "没有此人！" << endl;
			cout << "是否继续查找：查找（1），不查找（0）"<<endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字："; cin >> flag;
			}
		}
		else
		{
			Tea[j].Output();
			cout << "是否继续查找：查找（1），不查找（0）：" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字："; cin >> flag;
			}
		}
		
	} while (flag==1);

	return 1;
}
void TeaManager::Show()  //显示功能
{
	int i;
	if (Teatop == 0)
	{
		cout << "记录为空！" << endl; return;
	}
	for (i = 0; i < Teatop; i++)
		Tea[i].Output();
}
void TeaManager::Edit()  //编辑功能
{
	
	int j, n;
	int flag = 0;
	Teacher t1;
	do {
		cout << "请输入编号："; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> n;
		}
		for (j = 0; j < Teatop; j++)
		{
			if (n == Tea[j].num) break;
		}
		if (j == Teatop)
		{
			cout << "没有此人！" << endl;
			cout << "是否继续编辑：是(1),否(0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}
		else
		{
			cout << "输入修改后的信息，编号不能改:" << endl;
			t1.Input(n);
			Tea[j] = t1;
			cout << "是否继续编辑：是(1),否(0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "是否将编辑内容保存到文档：保存(1),不保存（其他）" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	
}
int TeaManager::Delete()  //删除功能
{
	int j, n;
	int flag = 0;

	do {
		cout << "请输入编号："; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> n;
		}
		for (j = 0; j < Teatop; j++)
		{
			if (n == Tea[j].num) break;
		}
		if (j == Teatop)
		{
			cout << "没有此人！" << endl;
			cout << "是否继续删除：删除（1），不删除（0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字："; 
				cin >> flag;
			}
		}
		else
		{
			for (j; j < Teatop; j++)
			{
				Tea[j] = Tea[j + 1];
			}
			Teatop--;
			cout << "是否继续删除：删除（1），不删除（0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字："; 
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "是否将删除内容保存到文档：保存(1),不保存（其他）" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	return 1;
}
void TeaManager::Save()  //保存功能
{
	
	int i;
	ofstream outfile, outfile1;
	outfile1.open("E:\\Teatop.txt", ios::out);
	outfile1 << Teatop;
	outfile.open("E:\\Tea_data.txt", ios::binary);
	if (!outfile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Teatop; i++)
		
		outfile << Tea[i].num<<" "<< Tea[i].name <<" "<< Tea[i].sex<<" " << Tea[i].age <<" " << Tea[i].dept<<" " << Tea[i].special <<" "<< Tea[i].title << endl;
	outfile.close();
	cout << "保存成功！" << endl;
}
void TeaManager::Read()  //读取功能
{
	
	int i;
	ifstream infile, infile1;
	infile1.open("E:\\Teatop.txt", ios::in);
	infile1 >> Teatop;
	infile.open("E:\\Tea_data.txt", ios::binary);
	if (!infile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Teatop; i++)
		
	{
		infile >> Tea[i].num >> Tea[i].name >> Tea[i].sex >> Tea[i].age >> Tea[i].dept >> Tea[i].special >> Tea[i].title;
		cout << Tea[i].num << " " << Tea[i].name << " " << Tea[i].sex << " " << Tea[i].age << " " << Tea[i].dept << " " << Tea[i].special << " " << Tea[i].title << endl;
	}
	infile.close();
	cout << "读取成功！" << endl;
}
void Tea_mune(TeaManager TM)  //用一个管理教师的类来实现结果的显示
{
	
	int b;
	char c;
	do {

		cout << endl; cout << endl;
		cout << "教师管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.添加    ";
		cout << "2.查询    ";
		cout << "3.显示    ";
		cout << "4.编辑    ";
		cout << "5.删除    ";
		cout << "6.统计    ";
		cout << "7.保存    ";
		cout << "8.读取    ";
		cout << "0.退出 |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "请选择："; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); break;
		case 2:TM.Search(); break;
		case 3:TM.Show(); break;
		case 4:TM.Edit(); break;
		case 5:TM.Delete(); break;
		case 6:cout << "共有教师人数：" << Teatop << endl; break;  //统计功能
		case 7:TM.Save(); break;
		case 8:TM.Read(); break;
		default:cout << "\n error" << endl; break;
		case 0:break;
		}


	} while (b != 0);
}

//实验员
class Tester :virtual public person  //实验员
{
public:
	char testroom[10];
	char post[10];
	void Input(int nu)
	{
		
		num = nu;
		cout << "Input name:"; cin >> name;
		do {
			cout << "Input sex:"; cin >> sex;
			if (sex != "男" && sex != "女")
				cout << "性别只能是男或女，请重新输入：" << endl;;
		} while (sex != "男" && sex != "女");
		cout << "Input age:"; cin >> age;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误，年龄为数，请输入数字" << endl;; cin >> nu;
		}
		cout << "Input testroom:"; cin >> testroom;
		cout << "Input post:"; cin >> post;
		
	}
	void Output()
	{
		cout << "编号: " << num << "  " << "姓名: " << name << "  " << "性别: " << sex << "  " << "年龄: " << age <<
			"  " << "所在实验室: " << testroom << "  " << "职务: " << post << endl;
	}

};
Tester Test[MAX];
static int Testop;
class TestManager  //管理实验员的类
{
public:
	int Add();
	int Search();
	void Show();
	void Edit();
	int Delete();
	void Save();
	void Read();
};
int TestManager::Add()
{
	Tester t;
	int i, nu, n = 1;
	
	if (Testop == MAX)
	{
		cout << "人数已满" << endl;
		return 0;
	}
	do {
		int flag = 0; //是否已存在
		cout << "请输入编号:"; cin >> nu;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> nu;
		}
		for (i = 0; i < Testop; i++)
		{
			if (nu == Test[i].num)
			{
				cout << "已有该编号" << endl;
				flag = 1;
			}
		}
		if (flag != 1)
		{
			t.Input(nu); Test[Testop] = t; Testop++;
			cout << "添加成功！" << endl;
		}
		cout << "是否继续添加，是输入1，不添加输入其他：" << endl;
		cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			return 1;
		}
	} while (n == 1);
	cout << "是否将添加内容保存到文档：保存(1),不保存（其他）" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	return 1;
}
int TestManager::Search()
{
	
	

	int j, n;
	int flag = 0;

	do {
		cout << "请输入编号："; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> n;
		}
		for (j = 0; j < Testop; j++)
		{
			if (n == Test[j].num) break;
		}
		if (j == Testop)
		{
			cout << "没有此人！" << endl;
			cout << "是否继续查找：查找（1），不查找（0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字："; cin >> flag;
			}
		}
		else
		{
			Test[j].Output();
			cout << "是否继续查找：查找（1），不查找（0）：" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字："; cin >> flag;
			}
		}

	} while (flag == 1);

	return 1;
}
void TestManager::Show()
{
	
	int i;
	if (Testop == 0)
	{
		cout << "记录为空！" << endl; return;
	}
	for (i = 0; i < Testop; i++)
		Test[i].Output();
}
void TestManager::Edit()
{
	int j, n;
	int flag = 0;
	Tester t1;
	do {
		cout << "请输入编号："; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> n;
		}
		for (j = 0; j < Testop; j++)
		{
			if (n == Test[j].num) break;
		}
		if (j == Testop)
		{
			cout << "没有此人！" << endl;
			cout << "是否继续编辑：是(1),否(0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}
		else
		{
			cout << "输入修改后的信息，编号不能改:" << endl;
			t1.Input(n);
			Test[j] = t1;
			cout << "是否继续编辑：是(1),否(0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "是否将编辑内容保存到文档：保存(1),不保存（其他）" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
}
int TestManager::Delete()
{
	
	int j, n;
	int flag = 0;

	do {
		cout << "请输入编号："; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> n;
		}
		for (j = 0; j < Testop; j++)
		{
			if (n == Test[j].num) break;
		}
		if (j == Testop)
		{
			cout << "没有此人！" << endl;
			cout << "是否继续删除：删除（1），不删除（0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}
		else
		{
			for (j; j < Testop; j++)
			{
				Test[j] = Test[j + 1];
			}
			Testop--;
			cout << "是否继续删除：删除（1），不删除（0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "是否将删除内容保存到文档：保存(1),不保存（其他）" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	return 1;
}
void TestManager::Save()
{
	
	int i;
	ofstream outfile, outfile1;
	outfile1.open("E:\\Testop.txt", ios::out);
	outfile1 << Testop;
	outfile.open("E:\\Test_data.txt", ios::binary);
	if (!outfile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Testop; i++)
		//outfile.write((char*)&Test[i], sizeof(Test[i]));
		outfile << Test[i].num << " " << Test[i].name << " " << Test[i].sex << " " << Test[i].age << " " << Test[i].testroom << " " << Test[i].post << " " << endl;
	outfile.close();
	cout << "保存成功！" << endl;
}
void TestManager::Read()
{
	
	int i;
	ifstream infile, infile1;
	infile1.open("E:\\Testop.txt", ios::in);
	infile1 >> Testop;
	infile.open("E:\\Test_data.txt", ios::binary);
	if (!infile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Testop; i++)
	{
		infile >> Test[i].num >> Test[i].name >> Test[i].sex >> Test[i].age >> Test[i].testroom >> Test[i].post;
		cout << Test[i].num << " " << Test[i].name << " " << Test[i].sex << " " << Test[i].age << " " << Test[i].testroom << " " << Test[i].post << endl;
	}
	infile.close();
	cout << "读取成功！" << endl;
}
void Test_mune(TestManager TM)
{
	
	int b;
	char c;
	do {
		cout << endl; cout << endl;
		cout << "实验人员管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.添加    ";
		cout << "2.查询    ";
		cout << "3.显示    ";
		cout << "4.编辑    ";
		cout << "5.删除    ";
		cout << "6.统计    ";
		cout << "7.保存    ";
		cout << "8.读取    ";
		cout << "0.退出 |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "请选择："; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); break;
		case 2:TM.Search(); break;
		case 3:TM.Show(); break;
		case 4:TM.Edit(); break;
		case 5:TM.Delete(); break;
		case 6:cout << "共有实验员人数：" << Testop << endl; break;
		case 7:TM.Save(); break;
		case 8:TM.Read(); break;
		default:cout << "\n error" << endl; break;
		case 0:break;
		}

	} while (b != 0);
}


//行政人员
class Policer :virtual public person  //行政人员
{
public:
	char polices[10];
	char post1[10];
	void Input(int nu)
	{
		num = nu;
		cout << "Input name:"; cin >> name;
		do {
			cout << "Input sex:"; cin >> sex;
			if (sex != "男" && sex != "女")
				cout << "性别只能是男或女，请重新输入：" << endl;;
		} while (sex != "男" && sex != "女");
		cout << "Input age:"; cin >> age;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误，年龄为数，请输入数字" << endl;; cin >> nu;
		}
		cout << "Input polices:"; cin >> polices;
		cout << "Input post1:"; cin >> post1;
	}
	void Output()
	{
		cout << "编号: " << num << "  " << "姓名: " << name << "  " << "性别: " << sex << "  " << "年龄: " << age <<
			"  " << "政治面貌: " << polices << "  " << "职称: " << post1 << endl;
	}

};
Policer Policers[MAX];
static int Policersop;
class PolicerManager  //管理行政人员的类
{
public:
	int Add();
	int Search();
	void Show();
	void Edit();
	int Delete();
	void Save();
	void Read();
};
int PolicerManager::Add()
{
	
	Policer t;
	int i, nu, n = 1;
	
	if (Policersop == MAX)
	{
		cout << "人数已满" << endl;
		return 0;
	}
	do {
		int flag = 0; //是否已存在
		cout << "请输入编号:"; cin >> nu;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> nu;
		}
		for (i = 0; i < Policersop; i++)
		{
			if (nu == Policers[i].num)
			{
				cout << "已有该编号" << endl;
				flag = 1;
			}
		}
		if (flag != 1)
		{
			t.Input(nu);  Policers[Policersop] = t; Policersop++;
			cout << "添加成功！" << endl;
		}
		cout << "是否继续添加，是输入1，不添加输入其他：" << endl;
		cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			return 1;
		}
	} while (n == 1);
	cout << "是否将添加内容保存到文档：保存(1),不保存（其他）" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	return 1;
	

}
int PolicerManager::Search()
{

	int j, n;
	int flag = 0;

	do {
		cout << "请输入编号："; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> n;
		}
		for (j = 0; j < Policersop; j++)
		{
			if (n == Policers[j].num) break;
		}
		if (j == Policersop)
		{
			cout << "没有此人！" << endl;
			cout << "是否继续查找：查找（1），不查找（0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字："; cin >> flag;
			}
		}
		else
		{
			Policers[j].Output();
			cout << "是否继续查找：查找（1），不查找（0）：" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字："; cin >> flag;
			}
		}

	} while (flag == 1);

	return 1;
}
void PolicerManager::Show()
{
	
	int i;
	if (Policersop == 0)
	{
		cout << "记录为空！" << endl; return;
	}
	for (i = 0; i < Policersop; i++)
		Policers[i].Output();

		
}
void PolicerManager::Edit()
{
	/*
	Policer t1;
	int j, n;
	cout << "请输入要编辑的人的编号："; cin >> n;
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
	{
		cout << "没有此人！" << endl; return;
	};
	cout << "输入修改后的信息，编号不能改:" << endl;
	t1.Input(n);
	Policers[j] = t1;
	cout << "编辑成功！" << endl;
	*/

	int j, n;
	int flag = 0;
	Policer t1;
	do {
		cout << "请输入编号："; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> n;
		}
		for (j = 0; j < Policersop; j++)
		{
			if (n == Policers[j].num) break;
		}
		if (j == Policersop)
		{
			cout << "没有此人！" << endl;
			cout << "是否继续编辑：是(1),否(0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}
		else
		{
			cout << "输入修改后的信息，编号不能改:" << endl;
			t1.Input(n);
			Policers[j] = t1;
			cout << "是否继续编辑：是(1),否(0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "是否将编辑内容保存到文档：保存(1),不保存（其他）" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
}
int PolicerManager::Delete()
{
	/*
	int j, n;
	cout << "请输入要删除的人的编号："; cin >> n;
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
	{
		cout << "没有此人！" << endl; return 0;
	};
	for (j; j < Policersop; j++)
	{
		Policers[j] = Policers[j + 1];
	}
	Policersop--;
	cout << "删除成功！" << endl;
	return 1;
	*/
	int j, n;
	int flag = 0;

	do {
		cout << "请输入编号："; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> n;
		}
		for (j = 0; j < Policersop; j++)
		{
			if (n == Policers[j].num) break;
		}
		if (j == Policersop)
		{
			cout << "没有此人！" << endl;
			cout << "是否继续删除：删除（1），不删除（0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}
		else
		{
			for (j; j < Policersop; j++)
			{
				Policers[j] = Policers[j + 1];
			}
			Policersop--;
			cout << "是否继续删除：删除（1），不删除（0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "是否将删除内容保存到文档：保存(1),不保存（其他）" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	return 1;

}
void PolicerManager::Save()
{

	int i;
	ofstream outfile, outfile1;
	outfile1.open("E:\\Policersop.txt", ios::out);
	outfile1 << Policersop;
	outfile.open("E:\\Policers_data.txt", ios::binary);
	if (!outfile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Policersop; i++)
		//outfile.write((char*)&Policers[i], sizeof(Policers[i]));
		outfile << Policers[i].num << " " << Policers[i].name << " " << Policers[i].sex << " " << Policers[i].age << " " << Policers[i].polices << " " << Policers[i].post1 << " " << endl;
	outfile.close();
	cout << "保存成功！" << endl;
}
void PolicerManager::Read()
{
	
	int i;
	ifstream infile, infile1;
	infile1.open("E:\\Policersop.txt", ios::in);
	infile1 >> Policersop;
	infile.open("E:\\Policers_data.txt", ios::binary);
	if (!infile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Policersop; i++)
	{
		infile >> Policers[i].num >> Policers[i].name >> Policers[i].sex >> Policers[i].age >> Policers[i].polices >> Policers[i].post1;
		cout << Policers[i].num << " " << Policers[i].name << " " << Policers[i].sex << " " << Policers[i].age << " " << Policers[i].polices << endl;
	}
	infile.close();
	cout << "读取成功！" << endl;
}
void Policers_mune(PolicerManager TM)
{

	int b;
	char c;
	do {
		cout << endl; cout << endl;
		cout << "行政人员管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.添加    ";
		cout << "2.查询    ";
		cout << "3.显示    ";
		cout << "4.编辑    ";
		cout << "5.删除    ";
		cout << "6.统计    ";
		cout << "7.保存    ";
		cout << "8.读取    ";
		cout << "0.退出 |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "请选择："; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); break;  //TM去调用add类
		case 2:TM.Search(); break;
		case 3:TM.Show(); break;
		case 4:TM.Edit(); break;
		case 5:TM.Delete(); break;
		case 6:cout << "共有行政员人数：" << Policersop << endl; break;
		case 7:TM.Save(); break;
		case 8:TM.Read(); break;
		default:cout << "\n error" << endl; break;
		case 0:break;
		}

	} while (b != 0);
}



class Teapoli :virtual public person  //教师兼行政
{

public:
	char dept1[20];
	char special1[20];
	char title1[20];
	char polices1[10];
	char post11[10];
	void Input(int nu)  //录入信息
	{
		num=nu;
		cout << "Input name:"; cin >> name;
		do {
			cout << "Input sex:"; cin >> sex;
			if (sex != "男" && sex != "女")
				cout << "性别只能是男或女，请重新输入：" << endl;;
		} while (sex != "男" && sex != "女");
		cout << "Input age:"; cin >> age;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误，年龄为数，请输入数字" << endl;; cin >> nu;
		}
		cout << "Input dept:"; cin >> dept1;
		cout << "Input special:"; cin >> special1;
		cout << "Input title:"; cin >> title1;
		cout << "Input polices:"; cin >> polices1;
		cout << "Input post1:"; cin >> post11;


	}
	void Output()  //输出信息
	{
		cout << "编号: " << num << "  " << "姓名: " << name << "  " << "性别: " << sex << "  " << "年龄: " << age << endl;
	}
};
Teapoli Teap[MAX];
static int Teapolitop;


//教师兼行政
class TeapoliManager  //教师兼行政管理类
{
public:
	int Add();
	int Search();
	void Show();
	void Edit();
	int Delete();
	void Save();
	void Read();
};
int TeapoliManager::Add()  //添加功能
{
	/*
	Teapoli t;
	int i, nu;
	if (Teapolitop == MAX)
	{
		cout << "人数已满" << endl;
		return 0;
	}
	cout << "请输入编号："; cin >> nu;
	for (i = 0; i < Teapolitop; i++)
	{
		if (nu == Teap[i].num)
		{
			cout << "已有该编号" << endl;
			return 0;
		}
	}
	t.Input(nu); Teap[Teapolitop] = t; Teapolitop++;
	cout << "添加成功！" << endl;
	return 1;
	*/
	Teapoli t;
	int i, nu, n = 1;
	
	if (Teapolitop == MAX)
	{
		cout << "人数已满" << endl;
		return 0;
	}
	do {
		int flag = 0; //是否已存在
		cout << "请输入编号:"; cin >> nu;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> nu;
		}
		for (i = 0; i < Teapolitop; i++)
		{
			if (nu == Teap[i].num)
			{
				cout << "已有该编号" << endl;
				flag = 1;
			}
		}
		if (flag != 1)
		{
			t.Input(nu); Teap[Teapolitop] = t; Teapolitop++;
			cout << "添加成功！" << endl;
		}
		cout << "是否继续添加，是输入1，不添加输入其他：" << endl;
		cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			return 1;
		}
	} while (n == 1);
	cout << "是否将添加内容保存到文档：保存(1),不保存（其他）" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	return 1;

}

int TeapoliManager::Search()  //查询功能
{
	/*
	int j, n;
	cout << "请输入编号："; cin >> n;
	for (j = 0; j < Teapolitop; j++)
	{
		if (n == Teap[j].num) break;
	}
	if (j == Teapolitop)
		cout << "没有此人！" << endl;
	else
		Teap[j].Output();
	return 1;
	*/

	int j, n;
	int flag = 0;

	do {
		cout << "请输入编号："; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> n;
		}
		for (j = 0; j < Teapolitop; j++)
		{
			if (n == Teap[j].num) break;
		}
		if (j == Teapolitop)
		{
			cout << "没有此人！" << endl;
			cout << "是否继续查找：查找（1），不查找（0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字："; cin >> flag;
			}
		}
		else
		{
			Teap[j].Output();
			cout << "是否继续查找：查找（1），不查找（0）：" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字："; cin >> flag;
			}
		}

	} while (flag == 1);

	return 1;
}
void TeapoliManager::Show()  //显示功能
{
	
	int i;
	if (Teapolitop == 0)
	{
		cout << "记录为空！" << endl; return;
	}
	for (i = 0; i < Teapolitop; i++)
		Teap[i].Output();
}
void TeapoliManager::Edit()  //编辑功能
{
/*
	Teapoli t1;
	int j, n;
	cout << "请输入要编辑的人的编号："; cin >> n;
	for (j = 0; j < Teapolitop; j++)
	{
		if (n == Teap[j].num) break;
	}
	if (j == Teapolitop)
	{
		cout << "没有此人！" << endl; return;
	};
	cout << "输入修改后的信息，编号不能改:" << endl;
	t1.Input(n);
	Teap[j] = t1;
	cout << "编辑成功！" << endl;
	*/

	int j, n;
	int flag = 0;
	Teapoli t1;
	do {
		cout << "请输入编号："; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> n;
		}
		for (j = 0; j < Teapolitop; j++)
		{
			if (n == Teap[j].num) break;
		}
		if (j == Teapolitop)
		{
			cout << "没有此人！" << endl;
			cout << "是否继续编辑：是(1),否(0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}
		else
		{
			cout << "输入修改后的信息，编号不能改:" << endl;
			t1.Input(n);
			Teap[j] = t1;
			cout << "是否继续编辑：是(1),否(0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "是否将编辑内容保存到文档：保存(1),不保存（其他）" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
}
int TeapoliManager::Delete()  //删除功能
{
	/*
	int j, n;
	cout << "请输入要删除的人的编号："; cin >> n;
	for (j = 0; j < Teapolitop; j++)
	{
		if (n == Teap[j].num) break;
	}
	if (j == Teapolitop)
	{
		cout << "没有此人！" << endl; return 0;
	};
	for (j; j < Teapolitop; j++)
	{
		Teap[j] = Teap[j + 1];
	}
	Teapolitop--;
	cout << "删除成功！" << endl;
	return 1;
	*/
	int j, n;
	int flag = 0;

	do {
		cout << "请输入编号："; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误请输入一个数字："; cin >> n;
		}
		for (j = 0; j < Teapolitop; j++)
		{
			if (n == Teap[j].num) break;
		}
		if (j == Teapolitop)
		{
			cout << "没有此人！" << endl;
			cout << "是否继续删除：删除（1），不删除（0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}
		else
		{
			for (j; j < Teapolitop; j++)
			{
				Teap[j] = Teap[j + 1];
			}
			Teapolitop--;
			cout << "是否继续删除：删除（1），不删除（0）" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入格式错误请输入一个数字：";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "是否将删除内容保存到文档：保存(1),不保存（其他）" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	return 1;
}
void TeapoliManager::Save()  //保存功能
{
	system("cls");  //清屏
	int i;
	ofstream outfile, outfile1;
	outfile1.open("E:\\TeaPoltop.txt", ios::out);
	outfile1 << Teapolitop;
	outfile.open("E:\\TeaPol_data.txt", ios::binary);
	if (!outfile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Teapolitop; i++)
		//outfile.write((char*)&Teap[i], sizeof(Teap[i]));
		outfile << Teap[i].num << " " << Teap[i].name << " " << Teap[i].sex << " " << Teap[i].age << " " << Teap[i].dept1 << " " << Teap[i].special1 << " " << Teap[i].title1  << " " << Teap[i].polices1 << " " << Teap[i].post11 <<endl;
	outfile.close();
	cout << "保存成功！" << endl;
}
void TeapoliManager::Read()  //读取功能
{
	int i;
	ifstream infile, infile1;
	infile1.open("E:\\Teatop.txt", ios::in);
	infile1 >> Teapolitop;
	infile.open("E:\\TeaPol_data.txt", ios::binary);
	if (!infile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Teapolitop; i++)
	{
		infile >> Teap[i].num >> Teap[i].name >> Teap[i].sex >> Teap[i].age >> Teap[i].dept1 >> Teap[i].special1 >> Teap[i].title1 >> Teap[i].polices1 >> Teap[i].post11;
		cout << Teap[i].num << " " << Teap[i].name << " " << Teap[i].sex << " " << Teap[i].age << " " << Teap[i].dept1 << " " << Teap[i].special1 << " " << Teap[i].title1 << " " << Teap[i].polices1 << " " << Teap[i].post11 << endl;;
	}
	infile.close();
	cout << "读取成功！" << endl;
}
void Teapoli_mune(TeapoliManager TM)
{
	system("cls");
	int b;
	char c;
	do {

		cout << endl; cout << endl;
		cout << "教师兼行政管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.添加    ";
		cout << "2.查询    ";
		cout << "3.显示    ";
		cout << "4.编辑    ";
		cout << "5.删除    ";
		cout << "6.统计    ";
		cout << "7.保存    ";
		cout << "8.读取    ";
		cout << "0.退出 |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "请选择："; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); break;
		case 2:TM.Search(); break;
		case 3:TM.Show(); break;
		case 4:TM.Edit(); break;
		case 5:TM.Delete(); break;
		case 6:cout << "共有教师兼行政人数：" << Teapolitop << endl; break;  //统计功能
		case 7:TM.Save(); break;
		case 8:TM.Read(); break;
		default:cout << "\n error" << endl; break;
		case 0:break;
		}


	} while (b != 0);
}

int main()   //主函数
{
	TeaManager Tmer1;
	TestManager Tetmer;
	PolicerManager Polimer;
	TeapoliManager Tp;
	int a = 1, m = 0;
	char c;
	cout << "    *************************************";
	cout << endl << "    $         高校人员管理系统         $" << endl;
	cout << "    *************************************";
	cout << endl << "请输入密码："; cin >> m;

	if (m != 123)
	{
		cout << "密码错误！" << endl;
		
		return 0;
	}

	while (a)
	{
		system("cls");

		cout << endl;
		cout << "              ****欢迎使用高校人员信息管理系统****" << endl;
		cout << "               =================================" << endl;
		cout << "               | 1.教师管理                    |" << endl;
		cout << "               | 2.实验员管理                  |" << endl;
		cout << "               | 3.行政员管理                  |" << endl;
		cout << "               | 4.教师兼行政管理              |" << endl;
		cout << "               | 0.退出                        |" << endl;
		cout << "               =================================" << endl;
		cout << "请选择:"; cin >> a;

		switch (a)  //用switch语句来判断输入的数字
		{
		case 1:Tea_mune(Tmer1); break;
		case 2:Test_mune(Tetmer); break;
		case 3:Policers_mune(Polimer); break;
		case 4:Teapoli_mune(Tp); break;
		case 0:break;
		default:cout << "\n error" << endl;
			cout << "按回车键继续" << endl;
			c = getchar();
			break;
		}
	}
	system("cls");
	cout << endl << "谢谢使用" << endl;
	
	return 0;
}
