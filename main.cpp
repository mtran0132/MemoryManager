/*	This is the driver for your memory manager. Do not make any changes to this file
Compile it with your MemeryManager.h and MemoryManager.cpp files.
The output that I got is at the bottom. Your ourput should be similar.
Notice that Total Memory = Free Memory + InUse Memory + Used Memory

Include this file when you submit your program
*/


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS // allow Microsoft Visual C++ to user strcpy insted of strcpy_s
#endif

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <iomanip>

#include "MemoryManager.h"
using namespace std;
using namespace MemoryManager;  // allow functions in Memory Manager to be used without prefix

void memStats();

int main(void)
{
	initializeMemoryManager();

	int alloc = 0;
	int dealloc = 0;
	int start = freeMemory();

	cout << "Program Starting...";
	memStats();

	cout << "\nAllocate some memory";


	short* shortPtr = (short*)allocate(sizeof(short));
	alloc++;
	char* charPtr = (char*)allocate(sizeof(char));
	alloc++;
	int* intPtr = (int*)allocate(sizeof(int));
	alloc++;
    char* name = (char*)allocate(11);
	alloc++;

	memStats();

	*charPtr = 'A';
	*shortPtr = 30000;
	*intPtr = 2000000000;
	strcpy(name, "Steve Gold");

	cout << endl;
	print();
	cout << "charPtr Value :" << setw(11) << *charPtr << " address:" << (long*)charPtr << endl;
	cout << "shortPtr Value:" << setw(11) << *shortPtr << " address:" << (long*)shortPtr << endl;
	cout << "intPtr Value  :" << setw(11) << *intPtr << " address:" << (long*)intPtr << endl;
	cout << "name Value    :" << setw(11) << name << " address:" << (long*)name << endl;

	//cout << "\nDeallocating intPtr:";
	//deallocate(intPtr);
	//dealloc++;
	//memStats();

	//cout << "\nDeallocating charPtr:";
	//deallocate(charPtr);
	//dealloc++;
	//memStats();

	////	std::cout << "Deallacting shortPtr:";
	////	deallocate(shortPtr);

	//std::cout << "\nDeallocating name:";
	//deallocate(name);
	//dealloc++;
	//memStats();

	//cout << "\n\nFree memory at start = " << start << endl;

	//cout << "\n\nFree memory now = " << freeMemory() << endl;

	//cout << "\n\nTotal Memory used = " << start - freeMemory() << endl;

	//memStats();

	//cout << endl;

	//// this next section will print a '+' when it allocates and '-' when it deallocates
	//// It will test how much memory s left and stop before it runs out.
	//int i = 0;
	//while (freeMemory() > 100) // this loop has a very bad memory leak...
	//{
	//	int *ptr = (int*)allocate(4);
	//	alloc++;
	//	cout << '+';
	//	i++;
	//	if (!(i % 75)) cout << endl;
	//	if ((i % 37) == 0) // randomly deallocate
	//	{
	//		deallocate(ptr);
	//		dealloc++;
	//		cout << '-';
	//		i++;
	//		if (!(i % 75)) cout << endl;
	//	}
	//}

	//cout << "\n\nFree memory at start = " << start << endl;

	//cout << "\n\nFree memory now = " << freeMemory() << endl;

	//cout << "\nTotal Allocations made: " << alloc;
	//cout << "\nTotal deallocations made: " << dealloc << endl;
	//memStats();

}


void memStats()
{
	int total = freeMemory() + inUseMemory() + usedMemory();
	cout << "\n#######################################";
	cout << "\n#Total:" << total << " Free:" << freeMemory() << " InUse:" << inUseMemory() << " Used:" << usedMemory();
	cout << "\n#Press any key to continue...";
	cout << "\n#######################################";
	cin.get();
}

// output from this program:
/*
Program Starting...
#######################################
#Total:65530 Free:65530 InUse:0 Used:0
#Press any key to continue...
#######################################
Allocate some memory
#######################################
#Total:65530 Free:65488 InUse:42 Used:0
#Press any key to continue...
#######################################
charPtr Value :          A address:00EC5444
shortPtr Value:      30000 address:00EC543C
intPtr Value  : 2000000000 address:00EC544B
name Value    : Steve Gold address:00EC5455

Deallocating intPtr:
#######################################
#Total:65530 Free:65488 InUse:32 Used:10
#Press any key to continue...
#######################################
Deallocating charPtr:
#######################################
#Total:65530 Free:65488 InUse:25 Used:17
#Press any key to continue...
#######################################
Deallocating name:
#######################################
#Total:65530 Free:65488 InUse:8 Used:34
#Press any key to continue...
#######################################

Free memory at start = 65530


Free memory now = 65488


Total Memory used = 42

#######################################
#Total:65530 Free:65488 InUse:8 Used:34
#Press any key to continue...
#######################################
+++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-
++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+
+++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++
++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++
+++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++
++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++
+++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++
++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++
+++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++
++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++
+++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++
++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++
+++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++
++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++
+++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++
++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++
+++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++
++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++
+++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++
++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++
+++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++
++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++
+++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++
++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++
+++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++
++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++
+++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++
++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++
+++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++
++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++++
+++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++
++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++++++
+++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++
++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++++++++
+++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++
++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++++++++++
+-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++
-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-
++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+
+++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++
++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++
+++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++
++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++
+++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++
++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++
+++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++
++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++
+++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++
++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++
+++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++
++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++
+++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++
++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++
+++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++
++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++
+++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++
++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++
+++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++
++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++
+++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++
++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++
+++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++
++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++
+++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++
++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++
+++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++
++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++++
+++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++
++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++++++
+++++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++
++++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++++++++
+++-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++
++-++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++++++++++
+-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++
-++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-
++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+
+++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++
++++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++
+++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++
++++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++
+++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++
++++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++
+++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++
++++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++
+++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++
++++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++
+++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++
++++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-+++++++++++++
+++++++++++++++++++++++-++++++++++++++++++++++++++++++++++++-++++++++++++++
++++++++++++++++++++++-++++++++++++++++++++++

Free memory at start = 65530


Free memory now = 98

Total Allocations made: 6543
Total deallocations made: 184

#######################################
#Total:65530 Free:98 InUse:63588 Used:1844
#Press any key to continue...
#######################################
*/