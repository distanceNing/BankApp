
#ifndef _BANKAPP_MAINLOOP_H_
#define _BANKAPP_MAINLOOP_H_
#include <iostream>
#include <memory>
#include <vector>

#include <pthread.h>

#include "tcp_socket.h"
#include "define.h"
#include "base_request.h"
#include "client_request.h"
#include "admin_request.h"

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

#endif //!_BANKAPP_MAINLOOP_H_
