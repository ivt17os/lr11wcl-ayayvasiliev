#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip> 
#include <windows.h>

using namespace std;

int main(int argc, char** argv ) {
    long long t1, t2, freq;
	char str[4096];
	DWORD nread = 1;
	
	//if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}

	cout << "Opening file a.txt\n"; // << argv[1] << "\n";
	
	//FILE* f = fopen("a.txt", "rb");
	
	HANDLE f = CreateFile(L"a.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, 0);
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// ����������� ����� ����� � 1 ���
	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// ������� ����� ����� ��������� �����
	
	BOOL bResult = TRUE;
	int numOfLines = 0;
	while (!(bResult && nread == 0)) {
		bResult = ReadFile(f, str, 4096, &nread, 0);
		for (DWORD i = 0; i < nread;i++)
			if (str[i] == '\n') numOfLines++;
	}

    QueryPerformanceCounter((LARGE_INTEGER *)&t2);// ������� ����� ����� ��������� �����


	CloseHandle(f);

    cout.precision(3);
    cout << "Time: " << fixed << (t2-t1)/(1.*freq) << "sec" << endl;
    cout << "File a.txt has " << numOfLines << " lines." << endl;
	return 0;
}