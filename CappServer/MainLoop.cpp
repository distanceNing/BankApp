#include "MainLoop.h"

void OnMessage(BaseRequest* user_request)
{
	if(!user_request->LoadingDataBase())
	{
		return;
	}
	user_request->OnReceive();
}




void  _StartUserRequestServe(void* psock)
{
	Csocket* user_sock = static_cast<Csocket*>(psock);
	int user_type = 0;
	char str[]="\0";
	user_sock->Receive(&user_type,sizeof(int));
	if (user_type == CLIENT)
	{
		ClientRequest event_loop(user_sock,str);
		OnMessage(&event_loop);
	}
	if (user_type == ADMAIN)
	{
		AdmainRequest event_loop(user_sock,str);
		OnMessage(&event_loop);
	}
	
}



MainLoop::MainLoop()
{
	sock = new Csocket;
	int flag = sock->CreatSocket(AF_INET, SOCK_STREAM, PORT);
	if (flag == 0)
		std::cerr<<"Creat socket error : "<<GetLastError()<<std::endl;
}

bool MainLoop::OnStart()
{
	sock->Listen();
	char fromIP[20];
	UINT fromPort;
	Csocket* user_sock;
	while (true)
	{
		user_sock = new Csocket;
		sock->Accept(*user_sock, fromIP, fromPort);
		std::cout << "From IP: " << fromIP << "-- From Port: " << fromPort << "---Login" << std::endl;

#ifdef _WIN32
		_beginthread(_StartUserRequestServe, 0, user_sock);
#else
		_StartUserRequestServe(user_sock);
		//pServe->OnLogin();
#endif // _WIN32

	}
	return false;
}


MainLoop::~MainLoop()
{
	delete sock;
	sock = NULL;
}

