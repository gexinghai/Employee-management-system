#include "workerManager.h"
#include "worker.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"

int main()
{
	////���Դ���
	//Worker* worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "����", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "����", 3);
	//worker->showInfo();
	//delete worker;
	
	//ʵ���������߶���
	WorkerManager wm;

	int choice = 0;

	while (true)
	{
		//����չʾ�˵���Ա����
		wm.Show_Menu();
		cout << "���������ѡ��:>" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://���ְ��
			wm.AddEmp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
		//{
		//	//�����жϴ��ں���
		//	int ret = wm.IsExist(1);
		//	if (ret != -1)
		//	{
		//		cout << "ְ������" << endl;
		//	}
		//	else
		//	{
		//		cout << "ְ������" << endl;
		//	}
		//	break;
		//}
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ļ�
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}

	return 0;
}