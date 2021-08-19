#if 0
#include<iostream>
#include<mutex>
#include<condition_variable>
#include<queue>
using namespace std;

class Queue{
    public:
    void put(int val)
    {
        unique_lock<mutex> lck(mex);
        while(!que.empty())
        {
            cv.wait(lck)
        }
        que.push(val);
        cv.notify_all();
    }
    int get()
    {
        int val = 0;
        {
        unique_lock<mutex> lck(mex);
        while(que.empty())
        {
            cv.wait(lck);
        }
        val = que.front();
        que.pop();
        cv.notify_all();
        }
        return val;
    }

    const int MAX_ = 10;

    private:
    mutex mex;
    queue<int> que;
    condition_variable cv;
}

#endif
#include <bits/stdc++.h>
using namespace std;


class Queue
{
public:
	void put(int val)
	{
		// lock_guard<mutex> lock(mtx);
		std::unique_lock<mutex> lck(mtx);
		while(!que.empty())
		{
			// que不为空，生产者应该通知消费之去消费，
			// 使用条件变量，当不为空，就将锁释放掉，
			
			cv.wait(lck);
		}
		que.push(val);
		cv.notify_all(); // 通知所有的消费线程去消费
		// cv.notify_one(); // 通知一个线程
		// 其他线程得到该通知，就从等待状态，编程
		// 阻塞状态，然后在获取互斥锁继续执行。
	}

	int get()
	{
		int val = 0;
		{
			unique_lock<mutex> lck(mtx);
			while (que.empty())
			{
				// 通知生产者生产，
				// 进入等待状态，释放互斥锁

				cv.wait(lck);
			}
			val = que.front();
			que.pop();
			cv.notify_all(); // 通知消费线程，我消费完了，赶紧生产吧
		}
		return val;
	}

	const int MAX_PRODUCER = 10;
private:
	queue<int> que;
	mutex mtx; // 全局的锁,互斥线程访问队列
	condition_variable cv; // 定义全局的条件变量，同步线程
};

void producer(Queue *que)
{
	for (int i = 1; i <= que->MAX_PRODUCER; ++i)
	{
		que->put(i);
		cout << this_thread::get_id() << "生产 : " << i << "商品" << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

void consumer(Queue *que)
{
	for (int i = 0; i < que->MAX_PRODUCER; ++i)
	{
		int data = que->get();
		cout << this_thread::get_id() << "消费 : " << data << "商品" << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

int main()
{
	Queue que;
	thread t1(producer,&que);
	thread t2(consumer,&que);

	t1.join();
	t2.join();
	
	return 0;
}
