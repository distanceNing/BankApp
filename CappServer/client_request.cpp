
#include "client_request.h"
#include <iostream>

void ClientRequest::OnReceive()
{
    int ntype,size=0;
    while (true)
    {
        size=sock->Receive(&ntype, sizeof(ntype));
        std::cout<<"[RECV_SIZE] "<<size<<std::endl;
        std::cout<<"[REQ_TYPE]  "<<ntype<<std::endl;
        switch (ntype)
        {
            case REQ_LOGIN:
                {
                    OnLogin();
                    break;
                }
            case REQ_SERACC:
                {
                    OnSearchAcc();
                    break;
                }
            case REQ_SERALLCARD:
                {
                    OnSerAllCard();
                    break;
                }
            case REQ_SAVE_RECORD:
                {
                    OnRecord(REQ_SAVE_RECORD);
                    break;
                }
            case REQ_WHD_RECORD:
                {
                    OnRecord(REQ_WHD_RECORD);
                    break;
                }
            case REQ_TRANS_RECORD:
                {
                    OnRecord(REQ_TRANS_RECORD);
                    break;
                }
            case REQ_DESACC:
                {
                    OnDesAcc();
                    break;
                }
            case REQ_MOD:
                {
                    OnMod();
                    break;
                }
            case REQ_SAVE:
                {
                    OnSave();
                    break;
                }
            case REQ_WHD:
                {
                    OnWithdrow();
                    break;
                }
            case REQ_TRANS:
                {
                    OnTrans();
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

bool ClientRequest::OnLogin()
{
    struct LOGIN_INFO login_info;
    memset(&login_info,0,sizeof(struct LOGIN_INFO));
    sock->Receive(&login_info, sizeof(struct LOGIN_INFO));
    int error_type=-1;
    if(isUser(true,login_info.id))
    {
        error_type=NO_THIS_USER;
        sock->Send(&error_type,sizeof(int));
        return false;
    }

    if(!OnLine(login_info.id))
    {
        error_type=ALREADY_ONLINE;
        sock->Send(&error_type,sizeof(int));
        return false;
    }

    error_type=VerifyInfo(true,login_info);
    sock->Send(&error_type, sizeof(int));
    if(error_type==CHECK_SUCCESS)
    {
        std::cout<<"[USER_LOGIN] "<<login_info.id<<std::endl;
        SetUserID(login_info.id);
    }
    return true;
}
bool ClientRequest::OnSearchAcc()
{
    struct CLIENT_INFO client;
    memset(&client,0,sizeof(struct CLIENT_INFO));
    char id[16];
    memset(id,'\0',16);
    sock->Receive(id,16);
    QuerySignalInfo(id,&client);
    sock->Send(&client,sizeof(struct CLIENT_INFO));
    return true;
}

bool ClientRequest::OnRecord(int type)
{
    struct TRCODE_INFO info;
    std::vector<std::string>all_info;
    char id[16];
    memset(id,'\0',16);
    sock->Receive(id,16);
    int num=GetUserRecodeNum(id,type,all_info);
    sock->Send(&num,sizeof(int));

    for(int i=0;i<num;i++)
    {
        memset(&info,0,sizeof( struct TRCODE_INFO));
        SearchRecordInfo(all_info[i].c_str(),type,&info);
        sock->Send(&info,sizeof(struct TRCODE_INFO));
    }

}
bool ClientRequest::OnSerAllCard()
{
    CARD_INFO all_card;
    std::vector<std::string>card_no;
    char id[16];
    memset(id,'\0',16);
    sock->Receive(id,16);
    int num=GetUserCardNum(id,card_no);
    sock->Send(&num,sizeof(int));

    for(int i=0;i<num;i++)
    {
        memset(&all_card,0,sizeof(CARD_INFO));
        SearchCardInfo(card_no[i].c_str(),&all_card);
        sock->Send(&all_card,sizeof(CARD_INFO));
    }

    return true;
}

bool ClientRequest::OnMod()
{
    int ret=0;
    char id[16];
    memset(id,'\0',16);
    sock->Receive(id,16);
    char sql[SQL_BUF];
    memset(sql,'\0',SQL_BUF);
    struct MOD_INFO data;
    memset(&data,0,sizeof(struct MOD_INFO));
    sock->Receive(&data,sizeof(struct MOD_INFO));
    snprintf(sql,SQL_BUF,"update Account set acc_passwd='%s' where acc_no='%s'",data.pass,id);
    if(SQLOperate(sql))
        ret=1;
    sock->Send(&ret,sizeof(int));
    return false;

}

bool ClientRequest::OnSave()
{
    int ret=0;
    char sql[SQL_BUF];
    memset(sql,'\0',SQL_BUF);
    struct SAVE_INFO data;
    memset(&data,0,sizeof(struct SAVE_INFO));
    sock->Receive(&data,sizeof(struct SAVE_INFO));
    snprintf(sql,SQL_BUF,"insert into SaveMoney(save_money,card_no,save_style,save_date,save_operator) values('%s','%s',2,now(),'yn')",data.money,data.id);
    if(SQLOperate(sql))
        ret=1;
    sock->Send(&ret,sizeof(int));
    return false;
}

bool ClientRequest::OnWithdrow()
{
    int ret=-1;
    char sql[SQL_BUF];
    memset(sql,'\0',SQL_BUF);
    struct SAVE_INFO data;
    memset(&data,0,sizeof(struct SAVE_INFO));
    sock->Receive(&data,sizeof(struct SAVE_INFO));
    snprintf(sql,SQL_BUF,"insert into DrawMoney(draw_money,card_no,draw_date,draw_operator) values(%s,'%s',now(),'tom')",data.money,data.id);
    if(SQLOperate(sql))
        ret=1;
    sock->Send(&ret,sizeof(int));
    return true;
}

bool ClientRequest::OnRefresh()
{
    char id[16];
    memset(id,'\0',16);
    sock->Receive(id,16);
    struct CLIENT_INFO client_info;
    memset(&client_info,0,sizeof(struct CLIENT_INFO));
    if(!QuerySignalInfo(id,&client_info))
        return false;

    sock->Send(&client_info,sizeof(struct CLIENT_INFO));
    return false;
}

bool ClientRequest::OnDesAcc()
{
    char id[16];
    memset(id,'\0',16);
    int ret=-1;
    sock->Receive(id,16);
    if(DestoryAccount(id))
        ret=1;
    sock->Send(&ret,sizeof(int));
    return true;
}

bool ClientRequest::OnTrans()
{
    int ret=-1;
    char sql[SQL_BUF];
    memset(sql,'\0',SQL_BUF);
    struct TRANS_INFO data;
    memset(&data,0,sizeof(struct TRANS_INFO));
    sock->Receive(&data,sizeof(struct TRANS_INFO));
    snprintf(sql,SQL_BUF,"insert into TransMoney(transin_card_no,transout_card_no,trans_money,trans_date,trans_operator) values(%s,%s,%s,now(),'yn')",data.the_other_card,data.this_card,data.money);
    if(SQLOperate(sql))
        ret=1;
    sock->Send(&ret,sizeof(int));
    return false;
}

bool ClientRequest::OnExit()
{
    char id[16];
    memset(id,'\0',16);
    int ret=-1;
    sock->Receive(id,16);
    if(*id!='\0')
        OffLine(id);
    char fromIP[20];
    UINT fromPort;
    sock->GetPeerName(fromIP, fromPort);
    std::cout << "IP :" << fromIP << "---  Port : " << fromPort << "---Exit!" << std::endl;
    if(sock->CloseSocket())
        return true;
    return false;
}
