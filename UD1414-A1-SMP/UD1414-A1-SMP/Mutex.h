#pragma once
#include <windows.h>
#include <iosteam.h>
#include <stdio.h>
#include <stdlib.h>

namespace SMP
{
	class MutexClass
	{
	private:
		HANDLE Mutex;
		DWORD ms = 1 << 10;
	public:
		//Con
		MutexClass( std::string uniqueName, DWORD ms){
			Mutex = CreateMutex(
				NULL,
				FALSE,
				uniqueName);
			this->ms = ms;
			}
		//Decon
		~MutexClass(){
			ReleaseMutex(Mutex);
		}
		//funcs
		lock() { return 0; };
		unlock() { return 1; };

	};
}