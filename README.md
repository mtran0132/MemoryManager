# MemoryManager
Written in C++, the MemoryManager was means to better understand pointers. The program runs by the user pressing "Enter" a couple of times. This was assignment 6 from CECS 282

>Computer languages often require a way to dynamically allocate memory. This means that memory is acquired while the program is running.
>This is in contrast to static memory allocation such as declaring a variable, an instance of an object or an array of some data type.

#Features 

* 65536 bytes of memory avaiable to the user
* Keeps track of how much memory is available
* Keeps track of how muhc memory has been used

#Key Concepts to Understand
* Pointers
 * char
 * short
 * int
 * void
* Arrays
* Type Casting
* Byte Size  
I'm not sure if byte size stays constant but for MemoryManager these are the sizes I used
 * char = 1 byte
 * short = 2 bytes
 * int = 4 bytes

#How to Use
1. Make a new project in Visual Studio 
2. Name it MemoryManager
3. Import the files from above
4. Run
5. ???
6. Profit
7. Edit the main.cpp if you so desire


###MemoryManager.h
* void* allocate(int)  

    >short* shortPtr = (short*)allocate(sizeof(short));  
    >char* charPtr = (char*)allocate(sizeof(char));

* void deallocate(void*) 

    >deallocate(charPtr);  
    >deallocate(shortPtr);

* int freeMemory(void)  

    >cout << "\n\nFree memory now = " << freeMemory() << endl; 

* int usedMemory(void)  

    > int used = usedMemory();

* int inUseMemory(void)
 
    > int inUse = inUseMemory();

