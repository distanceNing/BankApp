
#ifndef _MainLoop
#define _MainLoop
#include <iostream>
#include <memory>
#include "Csocket.h"
#include "define.h"
#include "BaseRequest.h"
#include "AdmainRequest.h"
#include "ClientRequest.h"
#include <pthread.h>
#include <vector>
typedef struct {
	pthread_t thread_tid;
	long thread_count;
}Thread;

class MainLoop
{
public:

	MainLoop(int thread_num,ProccessFun proccess):thread_pool(thread_num,Thread()),proccess_fun(proccess){}

	void ThreadMake(int count);
	bool SetThreadPool();


	bool OnStart();

	~MainLoop();
private:
	std::vector<Thread>thread_pool;
	ProccessFun proccess_fun;
};

void ProccessRequest(Csocket * listen_sock);;

#endif //!_MainLoop
