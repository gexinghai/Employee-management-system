#include "workerManager.h"
#include "worker.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"

int main()
{
	////测试代码
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "李四", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "王五", 3);
	//worker->showInfo();
	//delete worker;
	
	//实例化管理者对象
	WorkerManager wm;

	int choice = 0;

	while (true)
	{
		//调用展示菜单成员函数
		wm.Show_Menu();
		cout << "请输入你的选择:>" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://添加职工
			wm.AddEmp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除职工
		//{
		//	//测试判断存在函数
		//	int ret = wm.IsExist(1);
		//	if (ret != -1)
		//	{
		//		cout << "职工存在" << endl;
		//	}
		//	else
		//	{
		//		cout << "职工存在" << endl;
		//	}
		//	break;
		//}
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文件
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}

	return 0;
}