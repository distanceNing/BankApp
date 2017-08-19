#include "admin_request.h"



void AdminRequest::OnReceive()
{
    int ntype;
    char str_type[16];
    int size=-1;
    while (true)
    {
        memset(str_type,'\0',16);
        size=socket_->Receive(str_type,REQ_SIZE);
        std::cout<<"[REQ_TYPE]"<<str_type<<std::endl;
        std::cout<<"[RECV_SIZE]"<<size<<std::endl;
        ntype=atoi(str_type);
        switch (ntype)
        {
            case REQ_LOGIN:
                {
                    OnLogin();
                    break;
                }
            case REQ_DESACC:
                {
                    OnDesAcc();
                    break;
                }
            case REQ_DESCARD:
                {
                    OnDesCard();
                    break;
                }
            case REQ_MOD:
                {

                    break;
                }

            case REQ_EXIT:
                {
                    OnExit();
                    return;
                }
            default:
                break;
        }
    }
}

bool AdminRequest::OnLogin()
{
    struct LOGIN_INFO login_info;
    memset(&login_info,0,sizeof(struct LOGIN_INFO));
    int size=socket_->Receive(&login_info,sizeof(struct LOGIN_INFO));

    std::cout<<"[LOGIN_INFO]"<<login_info.id<<std::endl;
    int error_type=-1;
    if(!isUser(false,login_info.id))
    {
        error_type=NO_THIS_USER;
    }
    else
    {
        error_type=VerifyInfo(false,login_info);
    }
    char send_str[16]={0};
    snprintf(send_str,16,"%d",error_type);
    socket_->Send(&error_type,sizeof(int));
    std::cout<<"[SEND_MSG]"<<send_str<<std::endl;
    return true;
}

bool AdminRequest::OnSearchAcc()
{
    char id[16];
    socket_->Receive(id,16);
    struct CLIENT_INFO client_info;
    memset(&client_info,0,sizeof(struct CLIENT_INFO));
    if(QuerySignalInfo(id,&client_info))
        return true;
    return false;
}

bool AdminRequest::OnSearchCard()
{
    char id[16];
    socket_->Receive(id,16);

    return true;
}

bool AdminRequest::OnDesAcc()
{
    return true;

}

bool AdminRequest::OnDesCard()
{
    return true;
}

bool AdminRequest::ClientRequestBlockList()
{
    return false;
}

bool AdminRequest::OnAddAccount()
{
    struct LOGIN_INFO user_info;
    memset(&user_info,0,sizeof(struct LOGIN_INFO));
    int ret=-1;
    socket_->Receive(&user_info,sizeof(struct LOGIN_INFO));

    if(!CreateAccount(user_info))
        return true;
    return false;
}

bool AdminRequest::OnAddCard()
{
    struct LOGIN_INFO user_info;
    memset(&user_info,0,sizeof(struct LOGIN_INFO));
    socket_->Receive(&user_info,sizeof(struct LOGIN_INFO));
    if(!CreateCard(user_info))
        return false;
    return true;
}


bool AdminRequest::OnAdmDelete()
{
    return false;
}

bool AdminRequest::OnAdmRefresh()
{
    return false;
}



bool AdminRequest::OnRefresh()
{
    return false;
}



bool AdminRequest::OnExit()
{
    return false;
}

bool AdminRequest::FreezeAcc(const char* id)
{
    char sql[64];
    memset(sql,'\0',64);
    sprintf(sql,"update Account set acc_status=0 where acc_no='%s'",id);
    if(SQLOperate(sql))
        return true;
    return false;
}


bool AdminRequest::UnFreezeAcc(const char * id)
{
    char sql[64];
    memset(sql,'\0',64);
    sprintf(sql,"update Account set acc_status=1 where acc_no='%s'",id);
    if(SQLOperate(sql))
        return true;
    return false;
}






