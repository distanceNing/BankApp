#include "base_request.h"




void OnMessage(BaseRequest * user_request)
{
    if(!user_request->LoadingDataBase())
    {
        std::cout<<"Loading Database Error"<<std::endl;
        return;
    }
    user_request->OnReceive();
}


bool BaseRequest::LoadingDataBase()
{
    if(!mysql_conn.InitMySQL())
    {
        perror("Init Mysql error");
        return false;
    }
    if(!mysql_conn.ConnectMySQL("47.93.255.194","root","","bank",0,NULL,0))
    {
        perror("Connect Mysql error");
        return false;
    }
    return true;
}

bool BaseRequest::isUser(bool isClient,const char* id)
{
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    if(isClient)
        snprintf(sql,SQL_BUF,"select acc_no from Account where acc_no='%s'",id);
    else
        snprintf(sql,SQL_BUF," select a_no from Admin where a_no=%s",id);
    int row,fetch;
    std::auto_ptr<mysql_data> result(mysql_conn.QueryResultSet(sql,row,fetch));
    if(!result->isEmpty())
        return false;
    return true;

}

bool BaseRequest::QuerySignalInfo(const char* id,struct CLIENT_INFO *user_info)
{
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    memset(user_info,'\0',sizeof(struct CLIENT_INFO));
    snprintf(sql,SQL_BUF,"select c_name,Client.acc_no,acc_balance,acc_open_date,acc_credit,acc_status from Client,Account where Client.acc_no=Account.acc_no and Account.acc_no='%s'",id);
    int row,fetch;
    std::auto_ptr<mysql_data> result(mysql_conn.QueryResultSet(sql,row,fetch));
    if(result->isEmpty())
        return false;
    strncpy(user_info->name,(*result)[0],32);
    strncpy(user_info->id,(*result)[1],16);
    strncpy(user_info->money,(*result)[2],20);
    strncpy(user_info->date,(*result)[3],32);
    strncpy(user_info->credit,(*result)[4],4);
    strncpy(user_info->status,(*result)[5],4);
    return true;
}

bool BaseRequest::SearchCardInfo(const char* id, CARD_INFO *user_info)
{
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    memset(user_info,'\0',sizeof(CARD_INFO));
    snprintf(sql,SQL_BUF,"select card_name,card_no,card_balance,card_open_date,card_credit,card_status from Card where  card_no='%s'",id);
    int row,fetch;
    std::auto_ptr<mysql_data> result(mysql_conn.QueryResultSet(sql,row,fetch));
    if(result->isEmpty())
        return false;
    strncpy(user_info->name,(*result)[0],32);
    strncpy(user_info->id,(*result)[1],16);
    strncpy(user_info->money,(*result)[2],20);
    strncpy(user_info->date,(*result)[3],32);
    strncpy(user_info->credit,(*result)[4],4);
    strncpy(user_info->status,(*result)[5],4);
    return true;
}


LOGIN_ERROR BaseRequest::VerifyInfo(bool isClient,LOGIN_INFO & login_info)
{
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    if(isClient)
        snprintf(sql,SQL_BUF,"select acc_passwd from Account where acc_no='%s'",login_info.id);
    else
        snprintf(sql,SQL_BUF," select a_passwd from Admin where a_no=%s",login_info.id);
    int row,fetch;
    std::auto_ptr<mysql_data> result(mysql_conn.QueryResultSet(sql,row,fetch));
    if(!strcmp(login_info.pass,(*result)[0]))
        return CHECK_SUCCESS;
    return PASSWD_ERROR;

}

int BaseRequest::GetUserCardNum(const char* id,std::vector<std::string>&card_no)
{
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    snprintf(sql,SQL_BUF,"select card_no from Card where acc_no='%s'",id);
    int row,fetch;
    std::auto_ptr<mysql_data> result(mysql_conn.QueryResultSet(sql,row,fetch));
    for(int i=0;i<row;i++)
    {
        card_no.push_back(std::string((*result)[i]));
    }
    return card_no.size();
}

int BaseRequest::GetUserRecodeNum(const char* id,int type,std::vector<std::string>&card_no)
{
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    switch (type)
    {
        case REQ_SAVE_RECORD:
            snprintf(sql,SQL_BUF,"select save_no from SaveMoney where card_no='%s'",id);
            break;
        case REQ_WHD_RECORD:
            snprintf(sql,SQL_BUF,"select draw_no from DrawMoney where card_no='%s'",id);
            break;
        case REQ_TRANS_RECORD:
            snprintf(sql,SQL_BUF,"select trans_no from TransMoney where transout_card_no='%s'",id);
            break;
    }
    int row,fetch;
    std::auto_ptr<mysql_data> result(mysql_conn.QueryResultSet(sql,row,fetch));
    if(result->isEmpty())
    {
        return 0;
    }
    for(int i=0;i<row;i++)
    {
        card_no.push_back(std::string((*result)[i]));
    }
    return card_no.size();
}

bool BaseRequest::SearchRecordInfo(const char* id,int type,struct TRCODE_INFO * user_info)
{
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    memset(user_info,'\0',sizeof(struct TRCODE_INFO));
    switch (type)
    {
        case REQ_SAVE_RECORD:
            snprintf(sql,SQL_BUF,"select card_no,save_operator,save_money,save_date from SaveMoney where save_no='%s'",id);
            break;
        case REQ_WHD_RECORD:
            snprintf(sql,SQL_BUF,"select card_no,draw_operator,draw_money,draw_date from DrawMoney where draw_no='%s'",id);
            break;
        case REQ_TRANS_RECORD:
            snprintf(sql,SQL_BUF,"select transout_card_no,trans_operator,trans_money,trans_date from TransMoney where trans_no='%s'",id);
            break;
    }
    int row,fetch;
    std::auto_ptr<mysql_data> result(mysql_conn.QueryResultSet(sql,row,fetch));
    if(result->isEmpty())
        return false;
    strncpy(user_info->id,(*result)[0],16);
    strncpy(user_info->name,(*result)[1],32);
    strncpy(user_info->money,(*result)[2],20);
    strncpy(user_info->date,(*result)[3],32);
    return true;
}

bool BaseRequest::OnLine(const char* id)
{
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    snprintf(sql,SQL_BUF,"select *from LoginStatus where acc_no=%s",id);
    int row,fetch;
    std::auto_ptr<mysql_data> result(mysql_conn.QueryResultSet(sql,row,fetch));
    if(!result->isEmpty())
        return false;
    memset(sql,0,SQL_BUF*sizeof(char));
    snprintf(sql,SQL_BUF,"insert into LoginStatus values(%s)",id);
    if(SQLOperate(sql))
        return true;
}
bool BaseRequest::OffLine(const char* id)
{
    if(*id=='\0')
        return false;
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    snprintf(sql,SQL_BUF,"delete from LoginStatus where acc_no=%s",id);
    if(SQLOperate(sql))
        return true;
    return false;
}

bool BaseRequest::SQLOperate(const char* sql)
{
    if(mysql_conn.QueryNoResultSet(sql))
        return true;
    return false;
}

bool BaseRequest::CreateAccount(struct LOGIN_INFO& user_info)
{
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    snprintf(sql,SQL_BUF,"insert into Account values('%s','%s',0,now(),1,1,'1'",user_info.id,user_info.pass);
    if(SQLOperate(sql))
        return true;
    return false;
}

bool BaseRequest::DestoryAccount(const char* id)
{
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    snprintf(sql,SQL_BUF,"insert into DestoryAcc(acc_no,des_balance,des_date,des_operator) values('%s',0,now(),'tom')",id);
    if(SQLOperate(sql))
        return true;
    return false;
}

bool BaseRequest::CreateCard(struct LOGIN_INFO & card_info)
{
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    snprintf(sql,SQL_BUF,"insert into Card values('%s','%s','114001',0,now(),1,1,'yn','23'",card_info.id,card_info.pass);
    if(SQLOperate(sql))
        return true;

}

bool BaseRequest::DestoryCard(const char* id)
{
    char sql[SQL_BUF];
    memset(sql,0,SQL_BUF*sizeof(char));
    snprintf(sql,SQL_BUF,"insert into DestoryCard(card_no,des_balance,des_date,des_operator) values('%s',0,now(),'tom');",id);
    if(SQLOperate(sql))
        return true;
}
