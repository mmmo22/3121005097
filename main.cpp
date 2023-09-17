#include"main.h"

using namespace std; 

string UTF8ToGB(const char* str) //����ת��utf-8 --> gbk,������벻�����ֵ������������⡣
{
	string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}

bool check(int argc, char* argv[]) {  //����������
	if (argc != 4) {
		cout << "ERROR:��������\n";
		return false;
	}
	if (_access(argv[1], 00) == -1 || _access(argv[2], 00) == -1) {
		if (_access(argv[1], 00) == -1) cout << "Refer Adress Error\n";
		if (_access(argv[2], 00) == -1) cout << "Test Adress Error\n";
		return false;
	}
	return true;
}

int main(int argc,char* argv[]) {

	if (check(argc, argv)) {
		Leven leven;
		leven.init(argc,argv);
		leven.Run();
	}
	system("pause");
	return 0;
}


