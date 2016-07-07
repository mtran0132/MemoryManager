#pragma once

#ifndef __MEMORY_MANAGER_H__

#define __MEMORY_MANAGER_H__

// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT

//

// DO NOT CHANGE THIS HEADER FILE

//

// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT

namespace MemoryManager

{
	void memView(int start, int end);

	//---

	//--- CORE Functions, these will need to be completed by the applicant

	//---

	// Initialize any data needed to manage the memory pool

	void initializeMemoryManager(void);

	// return a pointer inside the memory pool

	// If no chunk can accommodate aSize call onOutOfMemory

	void* allocate(int aSize);

	// Free up a chunk previously allocated

	void deallocate(void* aPointer);

	//---

	//--- support routines

	//---

	// Will scan the memory pool and return the total free space remaining

	int freeMemory(void);

	// Will scan the memory pool and return the total used memory - memory that has been deallocated

	int usedMemory(void);

	// Will scan the memory pool and return the total in use memory - memory being curretnly used

	int inUseMemory(void);

	// Call if no space is left for the allocation request

	void onOutOfMemory(void);

};

#endif // __MEMORY_MANAGER_H__