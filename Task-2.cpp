#include <iostream>
#include <thread>
#include <chrono>
#include <list>
#include <iterator>

using namespace std;

#define INTERVAL 10000
#define WRITE_TEMP 5
#define READ_TEMP 95
list <int> myList;

void Write()
{
	while (true)
	{
		this_thread::sleep_for(chrono::milliseconds(INTERVAL / WRITE_TEMP));
		int value = rand() % (10);
		myList.emplace_back(value);
		cout << "WRITE " << value << endl;
	}
}
void Read()
{
	while (true)
	{
		this_thread::sleep_for(chrono::milliseconds(INTERVAL / READ_TEMP));
		cout << "READ ";
		for (auto i = myList.begin(); i != myList.end(); i++)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
}

int main()
{
	thread thread_1(Write);
	thread thread_2(Read);
	thread_1.join();
	thread_2.join();
	return 0;
}