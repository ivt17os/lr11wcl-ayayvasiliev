#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip> 
#include <windows.h>

using namespace std;

int main(int argc, char** argv ) {
    long long t1, t2, freq;
	char str[4096];
	
	//if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}

	cout << "Opening file b.txt\n"; // << argv[1] << "\n";
	
	FILE* f = fopen("b.txt", "rb");
	
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// запрашиваем число тиков в 1 сек


	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// смотрим время после окончания цикла
	
	long long nread, numOfLines = 0;
    while (!feof(f)){
		nread = fread(str, 1, 4096, f);
		for (long long i = 0; i < nread;i++) {
			if (str[i] == '\n') numOfLines++;
		}
	};
    
    QueryPerformanceCounter((LARGE_INTEGER *)&t2);// смотрим время после окончания цикла

	fclose(f);

    cout.precision(3);
    cout << "Time: " << fixed << (t2-t1)/(1.*freq) << "sec" << endl;
    cout << "File b.txt has " << numOfLines << " lines." << endl;
	return 0;
}