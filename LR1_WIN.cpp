#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
#include <time.h>
#include <Windows.h>

using namespace std;

void getDate() {
	time_t timer;
	while (true) {
		timer = time(NULL);
		std::cout << ctime(&timer);
		Sleep(1000);
		system("cls");
	}

}


int main() {
	STARTUPINFO start;
	PROCESS_INFORMATION info;
	ZeroMemory(&start, sizeof(start));
	start.cb = sizeof(start);
	ZeroMemory(&info, sizeof(info));
	const char* name = "C:\\Users\\Serega-senpai\\source\\repos\\new_process\\Debug\\new_process.exe";
	if (!CreateProcessA(name, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &start, &info)) {
		cout << GetLastError() << endl;
		system("pause");
	}
	else {
		WaitForSingleObject(info.hProcess, INFINITE);
		getDate();
	}
	return 0;
}
