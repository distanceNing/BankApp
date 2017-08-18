#include <iostream>
#include "main_loop.h"
#include "Csocket.h"
#include "define.h"

pthread_mutex_t mlock;

void*  _StartUserRequestServer(void* arg);

Csocket  listen_sock;

int main()
{
    const int thread_num=5;
    if(!listen_sock.CreatSocket(AF_INET,SOCK_STREAM,PORT))
    {
        std::cout<<"Create Sokcet Error"<<std::endl;
        return -1;
    }
    listen_sock.Listen();
    std::cout<<"Listening----"<<std::endl;
    MainLoop main_loop(thread_num,_StartUserRequestServer);
    main_loop.OnStart();

    while(true)
        pause();

    return 0;
}


void*  _StartUserRequestServer(void* arg)
{
    Csocket* client_sock;
    char fromIP[32];
    UINT fromPort;
    int thread_id=*static_cast<int*>(arg);
    std::cout<<"Thread "<<thread_id<<"is strating --- "<<std::endl;
    while(true)
    {
        client_sock=new Csocket;
        pthread_mutex_lock(&mlock);
        listen_sock.Accept(*client_sock, fromIP, fromPort);
        pthread_mutex_unlock(&mlock);
        std::cout << "From IP: " << fromIP << "-- From Port: " << fromPort << "---Login" << std::endl;
        ProccessRequest(client_sock);
        client_sock->CloseSocket();
    }
}
