#include"iostream"
#include <fstream>
#include"stdlib.h"
#define MAX 100
using namespace std;
class person  //����һ����ʵ�ֹ��еĻ�����Ϣ
{
public:
	int num;
	char name[20];
	string sex;
	int age;
};

//Teacher class ��ʦ
class Teacher :virtual public person
{

public:
	char dept[20];
	char special[20];
	char title[20];
	void Input(int nu)  //¼����Ϣ
	{
		num = nu;
		cout << "Input name:"; cin >> name;
		do {
			cout << "Input sex:"; cin >> sex;
			if (sex != "��" && sex != "Ů")
				cout << "�Ա�ֻ�����л�Ů�����������룺" << endl;;
		} while (sex != "��" && sex != "Ů");
		cout << "Input age:"; cin >> age;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ��������Ϊ��������������" << endl;; cin >> nu;
		}
		cout << "Input dept:"; cin >> dept;
		cout << "Input special:"; cin >> special;
		cout << "Input title:"; cin >> title;
	}
	void Output()  //�����Ϣ
	{
		cout << "���: " << num << "  " << "����: " << name << "  " << "�Ա�: " << sex << "  " << "����: " << age <<
			"  " << "����ϵ: " << dept << "  " << "רҵ: " << special << "  " << "ְ��: " << title << endl;
	}
};
Teacher Tea[MAX]; 
static int Teatop;  

class TeaManager  //��ʦ�Ĺ�����
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
int TeaManager::Add()  //��ӹ���
{
	
	Teacher t;
	int i, nu, n = 1;
	
	if (Teatop == MAX)
	{
		cout << "��������" << endl;
		return 0;
	}
	do {
		int flag = 0; //�Ƿ��Ѵ���
		cout << "��������:"; cin >> nu;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> nu;
		}
		for (i = 0; i < Teatop; i++)
		{
			if (nu == Tea[i].num)
			{
				cout << "���иñ��" << endl;
				flag = 1;
			}
		}
		if (flag != 1)
		{
			t.Input(nu); Tea[Teatop] = t; Teatop++;
			cout << "��ӳɹ���" << endl;
		}
		cout << "�Ƿ������ӣ�������1�����������������" << endl;
		cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			return 1;
		}
	} while (n == 1);
	cout << "�Ƿ�������ݱ��浽�ĵ�������(1),�����棨������" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	return 1;
}
int TeaManager::Search()  //��ѯ����
{
	
	int j, n;
	int flag=0;
	
	do {
		cout << "�������ţ�"; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> n;
		}
		for (j = 0; j < Teatop; j++)
		{
			if (n == Tea[j].num) break;
		}
		if (j == Teatop)
		{
			cout << "û�д��ˣ�" << endl;
			cout << "�Ƿ�������ң����ң�1���������ң�0��"<<endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�"; cin >> flag;
			}
		}
		else
		{
			Tea[j].Output();
			cout << "�Ƿ�������ң����ң�1���������ң�0����" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�"; cin >> flag;
			}
		}
		
	} while (flag==1);

	return 1;
}
void TeaManager::Show()  //��ʾ����
{
	int i;
	if (Teatop == 0)
	{
		cout << "��¼Ϊ�գ�" << endl; return;
	}
	for (i = 0; i < Teatop; i++)
		Tea[i].Output();
}
void TeaManager::Edit()  //�༭����
{
	
	int j, n;
	int flag = 0;
	Teacher t1;
	do {
		cout << "�������ţ�"; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> n;
		}
		for (j = 0; j < Teatop; j++)
		{
			if (n == Tea[j].num) break;
		}
		if (j == Teatop)
		{
			cout << "û�д��ˣ�" << endl;
			cout << "�Ƿ�����༭����(1),��(0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
				cin >> flag;
			}
		}
		else
		{
			cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
			t1.Input(n);
			Tea[j] = t1;
			cout << "�Ƿ�����༭����(1),��(0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "�Ƿ񽫱༭���ݱ��浽�ĵ�������(1),�����棨������" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	
}
int TeaManager::Delete()  //ɾ������
{
	int j, n;
	int flag = 0;

	do {
		cout << "�������ţ�"; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> n;
		}
		for (j = 0; j < Teatop; j++)
		{
			if (n == Tea[j].num) break;
		}
		if (j == Teatop)
		{
			cout << "û�д��ˣ�" << endl;
			cout << "�Ƿ����ɾ����ɾ����1������ɾ����0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�"; 
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
			cout << "�Ƿ����ɾ����ɾ����1������ɾ����0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�"; 
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "�Ƿ�ɾ�����ݱ��浽�ĵ�������(1),�����棨������" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	return 1;
}
void TeaManager::Save()  //���湦��
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
	cout << "����ɹ���" << endl;
}
void TeaManager::Read()  //��ȡ����
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
	cout << "��ȡ�ɹ���" << endl;
}
void Tea_mune(TeaManager TM)  //��һ�������ʦ������ʵ�ֽ������ʾ
{
	
	int b;
	char c;
	do {

		cout << endl; cout << endl;
		cout << "��ʦ����" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.���    ";
		cout << "2.��ѯ    ";
		cout << "3.��ʾ    ";
		cout << "4.�༭    ";
		cout << "5.ɾ��    ";
		cout << "6.ͳ��    ";
		cout << "7.����    ";
		cout << "8.��ȡ    ";
		cout << "0.�˳� |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "��ѡ��"; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); break;
		case 2:TM.Search(); break;
		case 3:TM.Show(); break;
		case 4:TM.Edit(); break;
		case 5:TM.Delete(); break;
		case 6:cout << "���н�ʦ������" << Teatop << endl; break;  //ͳ�ƹ���
		case 7:TM.Save(); break;
		case 8:TM.Read(); break;
		default:cout << "\n error" << endl; break;
		case 0:break;
		}


	} while (b != 0);
}

//ʵ��Ա
class Tester :virtual public person  //ʵ��Ա
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
			if (sex != "��" && sex != "Ů")
				cout << "�Ա�ֻ�����л�Ů�����������룺" << endl;;
		} while (sex != "��" && sex != "Ů");
		cout << "Input age:"; cin >> age;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ��������Ϊ��������������" << endl;; cin >> nu;
		}
		cout << "Input testroom:"; cin >> testroom;
		cout << "Input post:"; cin >> post;
		
	}
	void Output()
	{
		cout << "���: " << num << "  " << "����: " << name << "  " << "�Ա�: " << sex << "  " << "����: " << age <<
			"  " << "����ʵ����: " << testroom << "  " << "ְ��: " << post << endl;
	}

};
Tester Test[MAX];
static int Testop;
class TestManager  //����ʵ��Ա����
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
		cout << "��������" << endl;
		return 0;
	}
	do {
		int flag = 0; //�Ƿ��Ѵ���
		cout << "��������:"; cin >> nu;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> nu;
		}
		for (i = 0; i < Testop; i++)
		{
			if (nu == Test[i].num)
			{
				cout << "���иñ��" << endl;
				flag = 1;
			}
		}
		if (flag != 1)
		{
			t.Input(nu); Test[Testop] = t; Testop++;
			cout << "��ӳɹ���" << endl;
		}
		cout << "�Ƿ������ӣ�������1�����������������" << endl;
		cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			return 1;
		}
	} while (n == 1);
	cout << "�Ƿ�������ݱ��浽�ĵ�������(1),�����棨������" << endl;
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
		cout << "�������ţ�"; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> n;
		}
		for (j = 0; j < Testop; j++)
		{
			if (n == Test[j].num) break;
		}
		if (j == Testop)
		{
			cout << "û�д��ˣ�" << endl;
			cout << "�Ƿ�������ң����ң�1���������ң�0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�"; cin >> flag;
			}
		}
		else
		{
			Test[j].Output();
			cout << "�Ƿ�������ң����ң�1���������ң�0����" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�"; cin >> flag;
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
		cout << "��¼Ϊ�գ�" << endl; return;
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
		cout << "�������ţ�"; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> n;
		}
		for (j = 0; j < Testop; j++)
		{
			if (n == Test[j].num) break;
		}
		if (j == Testop)
		{
			cout << "û�д��ˣ�" << endl;
			cout << "�Ƿ�����༭����(1),��(0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
				cin >> flag;
			}
		}
		else
		{
			cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
			t1.Input(n);
			Test[j] = t1;
			cout << "�Ƿ�����༭����(1),��(0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "�Ƿ񽫱༭���ݱ��浽�ĵ�������(1),�����棨������" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
}
int TestManager::Delete()
{
	
	int j, n;
	int flag = 0;

	do {
		cout << "�������ţ�"; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> n;
		}
		for (j = 0; j < Testop; j++)
		{
			if (n == Test[j].num) break;
		}
		if (j == Testop)
		{
			cout << "û�д��ˣ�" << endl;
			cout << "�Ƿ����ɾ����ɾ����1������ɾ����0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
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
			cout << "�Ƿ����ɾ����ɾ����1������ɾ����0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "�Ƿ�ɾ�����ݱ��浽�ĵ�������(1),�����棨������" << endl;
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
	cout << "����ɹ���" << endl;
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
	cout << "��ȡ�ɹ���" << endl;
}
void Test_mune(TestManager TM)
{
	
	int b;
	char c;
	do {
		cout << endl; cout << endl;
		cout << "ʵ����Ա����" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.���    ";
		cout << "2.��ѯ    ";
		cout << "3.��ʾ    ";
		cout << "4.�༭    ";
		cout << "5.ɾ��    ";
		cout << "6.ͳ��    ";
		cout << "7.����    ";
		cout << "8.��ȡ    ";
		cout << "0.�˳� |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "��ѡ��"; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); break;
		case 2:TM.Search(); break;
		case 3:TM.Show(); break;
		case 4:TM.Edit(); break;
		case 5:TM.Delete(); break;
		case 6:cout << "����ʵ��Ա������" << Testop << endl; break;
		case 7:TM.Save(); break;
		case 8:TM.Read(); break;
		default:cout << "\n error" << endl; break;
		case 0:break;
		}

	} while (b != 0);
}


//������Ա
class Policer :virtual public person  //������Ա
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
			if (sex != "��" && sex != "Ů")
				cout << "�Ա�ֻ�����л�Ů�����������룺" << endl;;
		} while (sex != "��" && sex != "Ů");
		cout << "Input age:"; cin >> age;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ��������Ϊ��������������" << endl;; cin >> nu;
		}
		cout << "Input polices:"; cin >> polices;
		cout << "Input post1:"; cin >> post1;
	}
	void Output()
	{
		cout << "���: " << num << "  " << "����: " << name << "  " << "�Ա�: " << sex << "  " << "����: " << age <<
			"  " << "������ò: " << polices << "  " << "ְ��: " << post1 << endl;
	}

};
Policer Policers[MAX];
static int Policersop;
class PolicerManager  //����������Ա����
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
		cout << "��������" << endl;
		return 0;
	}
	do {
		int flag = 0; //�Ƿ��Ѵ���
		cout << "��������:"; cin >> nu;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> nu;
		}
		for (i = 0; i < Policersop; i++)
		{
			if (nu == Policers[i].num)
			{
				cout << "���иñ��" << endl;
				flag = 1;
			}
		}
		if (flag != 1)
		{
			t.Input(nu);  Policers[Policersop] = t; Policersop++;
			cout << "��ӳɹ���" << endl;
		}
		cout << "�Ƿ������ӣ�������1�����������������" << endl;
		cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			return 1;
		}
	} while (n == 1);
	cout << "�Ƿ�������ݱ��浽�ĵ�������(1),�����棨������" << endl;
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
		cout << "�������ţ�"; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> n;
		}
		for (j = 0; j < Policersop; j++)
		{
			if (n == Policers[j].num) break;
		}
		if (j == Policersop)
		{
			cout << "û�д��ˣ�" << endl;
			cout << "�Ƿ�������ң����ң�1���������ң�0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�"; cin >> flag;
			}
		}
		else
		{
			Policers[j].Output();
			cout << "�Ƿ�������ң����ң�1���������ң�0����" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�"; cin >> flag;
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
		cout << "��¼Ϊ�գ�" << endl; return;
	}
	for (i = 0; i < Policersop; i++)
		Policers[i].Output();

		
}
void PolicerManager::Edit()
{
	/*
	Policer t1;
	int j, n;
	cout << "������Ҫ�༭���˵ı�ţ�"; cin >> n;
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
	{
		cout << "û�д��ˣ�" << endl; return;
	};
	cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
	t1.Input(n);
	Policers[j] = t1;
	cout << "�༭�ɹ���" << endl;
	*/

	int j, n;
	int flag = 0;
	Policer t1;
	do {
		cout << "�������ţ�"; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> n;
		}
		for (j = 0; j < Policersop; j++)
		{
			if (n == Policers[j].num) break;
		}
		if (j == Policersop)
		{
			cout << "û�д��ˣ�" << endl;
			cout << "�Ƿ�����༭����(1),��(0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
				cin >> flag;
			}
		}
		else
		{
			cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
			t1.Input(n);
			Policers[j] = t1;
			cout << "�Ƿ�����༭����(1),��(0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "�Ƿ񽫱༭���ݱ��浽�ĵ�������(1),�����棨������" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
}
int PolicerManager::Delete()
{
	/*
	int j, n;
	cout << "������Ҫɾ�����˵ı�ţ�"; cin >> n;
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
	{
		cout << "û�д��ˣ�" << endl; return 0;
	};
	for (j; j < Policersop; j++)
	{
		Policers[j] = Policers[j + 1];
	}
	Policersop--;
	cout << "ɾ���ɹ���" << endl;
	return 1;
	*/
	int j, n;
	int flag = 0;

	do {
		cout << "�������ţ�"; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> n;
		}
		for (j = 0; j < Policersop; j++)
		{
			if (n == Policers[j].num) break;
		}
		if (j == Policersop)
		{
			cout << "û�д��ˣ�" << endl;
			cout << "�Ƿ����ɾ����ɾ����1������ɾ����0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
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
			cout << "�Ƿ����ɾ����ɾ����1������ɾ����0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "�Ƿ�ɾ�����ݱ��浽�ĵ�������(1),�����棨������" << endl;
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
	cout << "����ɹ���" << endl;
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
	cout << "��ȡ�ɹ���" << endl;
}
void Policers_mune(PolicerManager TM)
{

	int b;
	char c;
	do {
		cout << endl; cout << endl;
		cout << "������Ա����" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.���    ";
		cout << "2.��ѯ    ";
		cout << "3.��ʾ    ";
		cout << "4.�༭    ";
		cout << "5.ɾ��    ";
		cout << "6.ͳ��    ";
		cout << "7.����    ";
		cout << "8.��ȡ    ";
		cout << "0.�˳� |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "��ѡ��"; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); break;  //TMȥ����add��
		case 2:TM.Search(); break;
		case 3:TM.Show(); break;
		case 4:TM.Edit(); break;
		case 5:TM.Delete(); break;
		case 6:cout << "��������Ա������" << Policersop << endl; break;
		case 7:TM.Save(); break;
		case 8:TM.Read(); break;
		default:cout << "\n error" << endl; break;
		case 0:break;
		}

	} while (b != 0);
}



class Teapoli :virtual public person  //��ʦ������
{

public:
	char dept1[20];
	char special1[20];
	char title1[20];
	char polices1[10];
	char post11[10];
	void Input(int nu)  //¼����Ϣ
	{
		num=nu;
		cout << "Input name:"; cin >> name;
		do {
			cout << "Input sex:"; cin >> sex;
			if (sex != "��" && sex != "Ů")
				cout << "�Ա�ֻ�����л�Ů�����������룺" << endl;;
		} while (sex != "��" && sex != "Ů");
		cout << "Input age:"; cin >> age;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ��������Ϊ��������������" << endl;; cin >> nu;
		}
		cout << "Input dept:"; cin >> dept1;
		cout << "Input special:"; cin >> special1;
		cout << "Input title:"; cin >> title1;
		cout << "Input polices:"; cin >> polices1;
		cout << "Input post1:"; cin >> post11;


	}
	void Output()  //�����Ϣ
	{
		cout << "���: " << num << "  " << "����: " << name << "  " << "�Ա�: " << sex << "  " << "����: " << age << endl;
	}
};
Teapoli Teap[MAX];
static int Teapolitop;


//��ʦ������
class TeapoliManager  //��ʦ������������
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
int TeapoliManager::Add()  //��ӹ���
{
	/*
	Teapoli t;
	int i, nu;
	if (Teapolitop == MAX)
	{
		cout << "��������" << endl;
		return 0;
	}
	cout << "�������ţ�"; cin >> nu;
	for (i = 0; i < Teapolitop; i++)
	{
		if (nu == Teap[i].num)
		{
			cout << "���иñ��" << endl;
			return 0;
		}
	}
	t.Input(nu); Teap[Teapolitop] = t; Teapolitop++;
	cout << "��ӳɹ���" << endl;
	return 1;
	*/
	Teapoli t;
	int i, nu, n = 1;
	
	if (Teapolitop == MAX)
	{
		cout << "��������" << endl;
		return 0;
	}
	do {
		int flag = 0; //�Ƿ��Ѵ���
		cout << "��������:"; cin >> nu;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> nu;
		}
		for (i = 0; i < Teapolitop; i++)
		{
			if (nu == Teap[i].num)
			{
				cout << "���иñ��" << endl;
				flag = 1;
			}
		}
		if (flag != 1)
		{
			t.Input(nu); Teap[Teapolitop] = t; Teapolitop++;
			cout << "��ӳɹ���" << endl;
		}
		cout << "�Ƿ������ӣ�������1�����������������" << endl;
		cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			return 1;
		}
	} while (n == 1);
	cout << "�Ƿ�������ݱ��浽�ĵ�������(1),�����棨������" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	return 1;

}

int TeapoliManager::Search()  //��ѯ����
{
	/*
	int j, n;
	cout << "�������ţ�"; cin >> n;
	for (j = 0; j < Teapolitop; j++)
	{
		if (n == Teap[j].num) break;
	}
	if (j == Teapolitop)
		cout << "û�д��ˣ�" << endl;
	else
		Teap[j].Output();
	return 1;
	*/

	int j, n;
	int flag = 0;

	do {
		cout << "�������ţ�"; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> n;
		}
		for (j = 0; j < Teapolitop; j++)
		{
			if (n == Teap[j].num) break;
		}
		if (j == Teapolitop)
		{
			cout << "û�д��ˣ�" << endl;
			cout << "�Ƿ�������ң����ң�1���������ң�0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�"; cin >> flag;
			}
		}
		else
		{
			Teap[j].Output();
			cout << "�Ƿ�������ң����ң�1���������ң�0����" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�"; cin >> flag;
			}
		}

	} while (flag == 1);

	return 1;
}
void TeapoliManager::Show()  //��ʾ����
{
	
	int i;
	if (Teapolitop == 0)
	{
		cout << "��¼Ϊ�գ�" << endl; return;
	}
	for (i = 0; i < Teapolitop; i++)
		Teap[i].Output();
}
void TeapoliManager::Edit()  //�༭����
{
/*
	Teapoli t1;
	int j, n;
	cout << "������Ҫ�༭���˵ı�ţ�"; cin >> n;
	for (j = 0; j < Teapolitop; j++)
	{
		if (n == Teap[j].num) break;
	}
	if (j == Teapolitop)
	{
		cout << "û�д��ˣ�" << endl; return;
	};
	cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
	t1.Input(n);
	Teap[j] = t1;
	cout << "�༭�ɹ���" << endl;
	*/

	int j, n;
	int flag = 0;
	Teapoli t1;
	do {
		cout << "�������ţ�"; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> n;
		}
		for (j = 0; j < Teapolitop; j++)
		{
			if (n == Teap[j].num) break;
		}
		if (j == Teapolitop)
		{
			cout << "û�д��ˣ�" << endl;
			cout << "�Ƿ�����༭����(1),��(0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
				cin >> flag;
			}
		}
		else
		{
			cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
			t1.Input(n);
			Teap[j] = t1;
			cout << "�Ƿ�����༭����(1),��(0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "�Ƿ񽫱༭���ݱ��浽�ĵ�������(1),�����棨������" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
}
int TeapoliManager::Delete()  //ɾ������
{
	/*
	int j, n;
	cout << "������Ҫɾ�����˵ı�ţ�"; cin >> n;
	for (j = 0; j < Teapolitop; j++)
	{
		if (n == Teap[j].num) break;
	}
	if (j == Teapolitop)
	{
		cout << "û�д��ˣ�" << endl; return 0;
	};
	for (j; j < Teapolitop; j++)
	{
		Teap[j] = Teap[j + 1];
	}
	Teapolitop--;
	cout << "ɾ���ɹ���" << endl;
	return 1;
	*/
	int j, n;
	int flag = 0;

	do {
		cout << "�������ţ�"; cin >> n;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����ʽ����������һ�����֣�"; cin >> n;
		}
		for (j = 0; j < Teapolitop; j++)
		{
			if (n == Teap[j].num) break;
		}
		if (j == Teapolitop)
		{
			cout << "û�д��ˣ�" << endl;
			cout << "�Ƿ����ɾ����ɾ����1������ɾ����0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
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
			cout << "�Ƿ����ɾ����ɾ����1������ɾ����0��" << endl;
			cin >> flag;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����ʽ����������һ�����֣�";
				cin >> flag;
			}
		}

	} while (flag == 1);
	cout << "�Ƿ�ɾ�����ݱ��浽�ĵ�������(1),�����棨������" << endl;
	int m;
	cin >> m;
	if (m == 1)Save();
	return 1;
}
void TeapoliManager::Save()  //���湦��
{
	system("cls");  //����
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
	cout << "����ɹ���" << endl;
}
void TeapoliManager::Read()  //��ȡ����
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
	cout << "��ȡ�ɹ���" << endl;
}
void Teapoli_mune(TeapoliManager TM)
{
	system("cls");
	int b;
	char c;
	do {

		cout << endl; cout << endl;
		cout << "��ʦ����������" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.���    ";
		cout << "2.��ѯ    ";
		cout << "3.��ʾ    ";
		cout << "4.�༭    ";
		cout << "5.ɾ��    ";
		cout << "6.ͳ��    ";
		cout << "7.����    ";
		cout << "8.��ȡ    ";
		cout << "0.�˳� |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "��ѡ��"; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); break;
		case 2:TM.Search(); break;
		case 3:TM.Show(); break;
		case 4:TM.Edit(); break;
		case 5:TM.Delete(); break;
		case 6:cout << "���н�ʦ������������" << Teapolitop << endl; break;  //ͳ�ƹ���
		case 7:TM.Save(); break;
		case 8:TM.Read(); break;
		default:cout << "\n error" << endl; break;
		case 0:break;
		}


	} while (b != 0);
}

int main()   //������
{
	TeaManager Tmer1;
	TestManager Tetmer;
	PolicerManager Polimer;
	TeapoliManager Tp;
	int a = 1, m = 0;
	char c;
	cout << "    *************************************";
	cout << endl << "    $         ��У��Ա����ϵͳ         $" << endl;
	cout << "    *************************************";
	cout << endl << "���������룺"; cin >> m;

	if (m != 123)
	{
		cout << "�������" << endl;
		
		return 0;
	}

	while (a)
	{
		system("cls");

		cout << endl;
		cout << "              ****��ӭʹ�ø�У��Ա��Ϣ����ϵͳ****" << endl;
		cout << "               =================================" << endl;
		cout << "               | 1.��ʦ����                    |" << endl;
		cout << "               | 2.ʵ��Ա����                  |" << endl;
		cout << "               | 3.����Ա����                  |" << endl;
		cout << "               | 4.��ʦ����������              |" << endl;
		cout << "               | 0.�˳�                        |" << endl;
		cout << "               =================================" << endl;
		cout << "��ѡ��:"; cin >> a;

		switch (a)  //��switch������ж����������
		{
		case 1:Tea_mune(Tmer1); break;
		case 2:Test_mune(Tetmer); break;
		case 3:Policers_mune(Polimer); break;
		case 4:Teapoli_mune(Tp); break;
		case 0:break;
		default:cout << "\n error" << endl;
			cout << "���س�������" << endl;
			c = getchar();
			break;
		}
	}
	system("cls");
	cout << endl << "ллʹ��" << endl;
	
	return 0;
}
