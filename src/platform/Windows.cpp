#include "../getTime.h"
#include <cstdint>

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#include <windows.h>
#include <time.h>

uint64_t getTime()
{
	FILETIME ft;
	uint64_t time = 0;
	static int tzflag;

	// system time�� ���ϱ�
	GetSystemTimeAsFileTime(&ft);

	// unsigned 64 bit�� �����
	time |= ft.dwHighDateTime;
	time <<= 32;
	time |= ft.dwLowDateTime;

	// 100nano�� 1micro�� ��ȯ�ϱ�
	time /= 10;

	// epoch time���� ��ȯ�ϱ�
	time -= 11644473600000000Ui64;    

	return time / 1000;
}

#endif