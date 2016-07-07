#include "stdafx.h"
#include "MemoryManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace MemoryManager

{

	// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT

	//

	// This is the only static memory that you may use, no other global variables

	// may be created, if you need to save data make it fit in MM_pool

	//

	// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT

	const int MM_POOL_SIZE = 65536;

	char MM_pool[MM_POOL_SIZE];

	// I have provided this tool for your use

	void memView(int start, int end)

	{

		const unsigned int SHIFT = 8;

		const unsigned int MASK = 1 << SHIFT - 1;

		unsigned int value; // used to facilitate bit shifting and masking

		cout << " Pool Unsignd Unsigned " << endl;

		cout << "Mem Add indx bits chr ASCII# short int " << endl;

		cout << "-------- ---- -------- --- ------ ------- ------------" << endl;

		for (int i = start; i <= end; i++)

		{

			cout << (long*)(MM_pool + i) << ':'; // the actual address in hexadecimal

			cout << '[' << setw(2) << i << ']'; // the index into MM_pool

			value = MM_pool[i];

			cout << " ";

			for (int j = 1; j <= SHIFT; j++) // the bit sequence for this byte (8 bits)

			{

				cout << ((value & MASK) ? '1' : '0');

				value <<= 1;

			}

			cout << " ";

			cout << '|' << *(char*)(MM_pool + i) << "| ("; // the ASCII character of the 8 bits (1 byte)

			cout << setw(4) << ((int)(*((unsigned char*)(MM_pool + i)))) << ")"; // the ASCII number of the character

			cout << " (" << setw(5) << (*(unsigned short*)(MM_pool + i)) << ")"; // the unsigned short value of 16 bits (2 bytes)

			cout << " (" << setw(10) << (*(unsigned int*)(MM_pool + i)) << ")"; // the unsigned int value of 32 bits (4 bytes)

			cout << endl;

		}

	}

	// Initialize set up any data needed to manage the memory pool

	void initializeMemoryManager(void)

	{
		int freeMemLoc = 0;
		MM_pool[freeMemLoc] = 6;
	}



	// return a pointer inside the memory pool

	// If no chunk can accommodate aSize call onOutOfMemory() - still

	void* allocate(int aSize)
	{
		unsigned short *thisNode, *head;
		unsigned short freeMemLoc = *((unsigned short*)MM_pool);
		*((unsigned short*)(MM_pool + freeMemLoc)) = aSize;
		*((unsigned short*)MM_pool) = aSize + 6 + *((unsigned short*)MM_pool);				//Updates MM_pool[0] to a higher value
		thisNode = (unsigned short*)(MM_pool + freeMemLoc);									//sets 'thisNode' to the node being allocated at the moment.
		head = (unsigned short*)(MM_pool + (*(unsigned short*)(MM_pool + 2)));				//sets 'head' to point to the start of the list
		if (*((unsigned short*)(MM_pool + 2)) == 0)
		{
			*(thisNode + 1) = 0;
			*(thisNode + 2) = 0;
		}
		else
		{
			*(thisNode + 1) = *((unsigned short*)(MM_pool + 2));
			*(thisNode + 2) = 0;
			*(head + 2) = freeMemLoc;			
		}
		*((unsigned short*)(MM_pool + 2)) = freeMemLoc;										//Updates the memory location to the new head.
		return (void*)(MM_pool + freeMemLoc + 6);											//Returns address for user.
	}

	// Free up a chunk previously allocated

	void deallocate(void* aPointer)

	{	
		unsigned short *head = (unsigned short*)(MM_pool + (*(unsigned short*)(MM_pool + 4)));  //sets 'head' to point to the start of the used list
		int lastUsedLoc = (*(unsigned short*)(MM_pool + 4));
		unsigned short *thisNode = ((unsigned short*) aPointer) - 3;	
		unsigned short *prevNode = (unsigned short*)(MM_pool + *(thisNode + 2));				//sets prevNode to thisNode's prevnode
		unsigned short *nextNode = (unsigned short*)(MM_pool + *(thisNode + 1));				//sets nextNode to thisNode's nextNode		

		if (*((unsigned short*)(MM_pool + 4)) == 0)
		{
			*(unsigned short*)(MM_pool + 4) = *(prevNode + 1);
			*(prevNode + 1) = *(thisNode + 1);													//Updates the prev node to point to next node
			*(nextNode + 2) = *(thisNode + 2);													//Updates the next node to point to prev node
			*(thisNode + 2) = 0;																//removes the node from the list
			*(thisNode + 1) = 0;																//removes the node from the list
		}
		else
		{
			if (*(thisNode + 1) == 0 && *(thisNode + 2) == 0)
			{
				*(unsigned short*)(MM_pool+4) = *(unsigned short*)(MM_pool + 2);
				*(unsigned short*)(MM_pool + 2) = 0;
				*(thisNode + 1) = lastUsedLoc;
				*(thisNode + 2) = 0;
			}
			else
			{
				if (*(thisNode + 2) != 0)
				{
					*(unsigned short*)(MM_pool + 4) = *(prevNode + 1);
					*(prevNode + 1) = *(thisNode + 1);													//Updates the prev node to point to next node
				}
				else
				{
					*(unsigned short*)(MM_pool + 2) = *(thisNode + 1);
					*(unsigned short*)(MM_pool + 4) = *(nextNode + 2);

				}
				*(head + 2) = *(unsigned short*)(MM_pool + 4);
				if (*(thisNode + 1) != 0)
				{
					*(nextNode + 2) = *(thisNode + 2);													//Updates the next node to point to prev node
				}
				else
				{
					*(prevNode + 1) = *(thisNode + 1);
				}
				*(thisNode + 1) = lastUsedLoc;
				*(thisNode + 2) = 0;
			}
		}
	}

	//---

	//--- support routines

	//---

	// Will scan the memory pool and return the total free space remaining

	int freeMemory(void)

	{

		return MM_POOL_SIZE - inUseMemory() - 6 - usedMemory() ;

	}

	// Will scan the memory pool and return the total deallocated memory

	int usedMemory(void)

	{
		int overhead = 6;
		int count = 0;
		int size = 0;
		unsigned short *thisNode = (unsigned short*)(MM_pool + *(unsigned short*)(MM_pool + 4));
		if (*(MM_pool + 4) == 0)
		{
			return size;
		}
		else
		{
			while (true)
			{
				size += *(thisNode);                                                    //Updates size
				count++;
				if (*(thisNode + 1) == 0)
				{
					break;
				}
				thisNode = (unsigned short*)(MM_pool + *(thisNode + 1));				//Moves thisNode down the link list
			}
		}
		return size + count*overhead;
	}

	// Will scan the memory pool and return the total in use memory

	int inUseMemory(void)

	{
		int overhead = 6;
		int count = 0;
		int size = 0;
		unsigned short *thisNode = (unsigned short*)(MM_pool + *(unsigned short*)(MM_pool + 2));

		if (*(unsigned short*)(MM_pool + 2) == 0)
		{
			return size;
		}
		else
		{
			while (true)
			{
				size += *(thisNode);                                                    //Updates size
				count++;
				if (*(thisNode + 1) == 0)
				{
					break;
				}
				thisNode = (unsigned short*)(MM_pool + *(thisNode + 1));				//Moves thisNode down the link list
			}
		}
		return size + count*overhead;
	}

}