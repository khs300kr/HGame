#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ConcurrentQueue.h"
#include "ConcurrentStack.h"

LockQueue<int32> q;
LockStack<int32> s;

void Push()
{
	while (true)
	{
		int32 value = rand() % 100;
		q.Push(value);

		this_thread::sleep_for(100ms);
	}
}

void Pop()
{
	while (true)
	{
		/// 1. queue
		//if (q.empty() == true)
		//{
		//	return;
		//}

		//int32 data = q.front();
		//q.pop();
		//cout << data << endl;

		
		int32 data = 0;
		q.WaitPop(OUT data);
		cout << data << endl;
		
		//if(data!= 0)
		//if (q.TryPop(OUT data) == true)
		//{
		//}
	}
}

int main()
{
	thread t1(Push);
	thread t2(Pop);

	t1.join();
	t2.join();

}
