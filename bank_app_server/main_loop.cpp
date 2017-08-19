#include "main_loop.h"

void ProccessRequest(Csocket* user_sock)
{
    int user_type = 0;
    char str[16]={0};
    int size=user_sock->Receive(str,USER_TYPE_SIZE);
    user_type=atoi(str);
    if(user_type==REQ_EXIT)
    {
        std::cout<<"[USER_MSG] EXIT"<<std::endl;
        return;
    }
    std::cout<<"[USER_TYPE]"<<str<<std::endl;
    char send_str[]="TYPE";
    if (user_type == CLIENT)
    {
        ClientRequest event_loop(user_sock,str);
        OnMessage(&event_loop);
    }
    if (user_type == ADMAIN)
    {
        size=user_sock->Send(send_str,USER_TYPE_SIZE);
        std::cout<<"[SEND_SIZE]"<<size<<std::endl;
        AdminRequest event_loop(user_sock,str);
        OnMessage(&event_loop);
    }
}



void MainLoop::ThreadMake(int i)
{
    thread_pool[i].thread_count=0;
    pthread_create(&thread_pool[i].thread_tid,NULL,proccess_fun,&i);
    return;
}

bool MainLoop::SetThreadPool()
{
    for(unsigned long i=0;i<thread_pool.size();++i)
    {
        ThreadMake(i);
    }
    return true;
}

bool MainLoop::OnStart()
{
    SetThreadPool();
    return true;
}


MainLoop::~MainLoop()
{
}

