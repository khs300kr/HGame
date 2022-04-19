#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>

queue<int32> q;
stack<int32> s;

void Push()
{
	while (true)
	{
		int32 value = rand() % 100;
		q.push(value);

		this_thread::sleep_for(10ms);
	}
}

void Pop()
{
	while (true)
	{
		if (q.empty() == true)
		{
			continue;
		}

		int32 data = q.front();
		q.pop();
		cout << data << endl;
	}
}

int main()
{
	thread t1(Push);
	thread t2(Pop);

	t1.join();
	t2.join();

}
