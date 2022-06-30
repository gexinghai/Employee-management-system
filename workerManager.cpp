#pragma once
#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ���������
	int num = this->getEmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	//��������
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ浽������
	this->init_Emp();

	////���Դ���
	//for (int i = 0; i < this->m_EmpNum; ++i)
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
	//		<< "������" << this->m_EmpArray[i]->m_Name
	//		<< "���ű�ţ�" << this->m_EmpArray[i]->m_DeptId
	//		<< endl;
	//}

}

void WorkerManager::AddEmp()
{
	cout << "���������ְ����������" << endl;

	int addNum = 0;//�����û�����������
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ��С
		
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; ++i)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; ++i)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "��ְ���ı�ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "��ְ����������" << endl;
			cin >> name;

			cout << "��ѡ���" << i + 1 << "��ְ���ĸ�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//������ְ��ְ�� ���浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//���¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;
		//����ְ����Ϊ��
		this->m_FileIsEmpty = false;

		//�ɹ���Ӻ� ���浽�ļ���
		this->save();

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
	}
	else
	{
		cout << "������������" << endl;
	}

	//������������ص��ϼ�
	system("pause");
	system("cls");
}

void WorkerManager::Show_Menu()
{
	cout << "**********************************" << endl;
	cout << "****** ��ӭʹ��ְ������ϵͳ! *****" << endl;
	cout << "********* 0.�˳�������� *********" << endl;
	cout << "********* 1.����ְ����Ϣ *********" << endl;
	cout << "********* 2.��ʾְ����Ϣ *********" << endl;
	cout << "********* 3.ɾ����ְְ�� *********" << endl;
	cout << "********* 4.�޸�ְ����Ϣ**********" << endl;
	cout << "********* 5.����ְ����Ϣ *********" << endl;
	cout << "********* 6.���ձ������ *********" << endl;
	cout << "********* 7.��������ĵ� *********" << endl;
	cout << "**********************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//д�ļ�

	//��ÿ���˵�����д���ļ���
	for (int i = 0; i < this->m_EmpNum; ++i)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	//ͳ������
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}

	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)//��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else//�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();

}

void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; ++i)
		{
			//���ö�̬���ó���
			this->m_EmpArray[i]->showInfo();
		}
		//�����������
		system("pause");
		system("cls");
	}
}

void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//����ְ���ı��ɾ��
		cout << "��������Ҫɾ����ְ���ı��" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			//����ǰ��
			for (int i = 0; i < this->m_EmpNum - 1; ++i)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//���������м�¼��Ա�ĸ���
			//����ͬ�����µ��ļ�
			this->save();

			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; ++i)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//�ҵ�ְ��
			index = i;

			break;
		}
	}

	return index;

}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		int id;

		int newId;
		string newName;
		int newdSelect;

		cout << "�������޸�ְ���ı�ţ�" << endl;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��
			delete this->m_EmpArray[ret];
			cout << "���ҳɹ�" << endl;
			cout << "������Ա������ID��" << endl;
			cin >> newId;
			
			cout << "������ְ������������" << endl;
			cin >> newName;

			cout << "��ѡ��ְ�����¸�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> newdSelect;

			Worker* worker = NULL;

			switch (newdSelect)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			//�������ݱ��浽������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}

		system("pause");
		system("cls");
	}
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�����" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//����Ų�
			int id;
			cout << "��������ҵ�ְ���ı�ţ�" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				//�ҵ�ְ��
				cout << "���ҳɹ�����Ա����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ��" << endl;
			}
		}
		else if(select == 2)
		{
			//��������
			string name;
			cout << "��������ҵ�ְ����������" << endl;
			cin >> name;
			
			//�����Ƿ���ҵ��ı�־
			bool flag = false;

			for (int i = 0; i < m_EmpNum; ++i)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						<< this->m_EmpArray[i]->m_Id
						<< "��ְ����Ϣ���£�"
						<< endl;
					flag = true;

					//������ʾ��Ϣ�ӿ�
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}

	system("pause");
	system("cls");
}

//ѡ������
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.����ְ���Ž�������" << endl;
		cout << "2.����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; ++i)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; ++j)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			//�жϿ�ʼ�϶�����Сֵ�����ֵ �ǲ��� �������Сֵ�����ֵ��������� ��������
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();
		this->Show_Emp();
	}
}

void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; ++i)
			{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}

		cout << "��ճɹ�" << endl;
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	for (int i = 0; i < this->m_EmpNum; ++i)
	{
		if (this->m_EmpArray[i] != NULL)
		{
			delete this->m_EmpArray;
		}
	}

	delete[] this->m_EmpArray;
	this->m_EmpArray = NULL;
}