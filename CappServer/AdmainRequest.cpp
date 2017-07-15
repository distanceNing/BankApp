#include "AdmainRequest.h"



void AdmainRequest::OnReceive()
{
	int ntype;
	char str_type[4];
	while (true)
	{
		memset(str_type,'\0',4);
		sock->Receive(&str_type, 2);
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

bool AdmainRequest::OnLogin()
{
	struct LOGIN_INFO login_info;
	memset(&login_info,0,sizeof(struct LOGIN_INFO));
	int error_type=VerifyInfo(false,login_info);
	sock->Send(&error_type,sizeof(int));
	return true;
}

bool AdmainRequest::OnSearchAcc()
{
	char id[16];
	sock->Receive(id,16);
	struct CLIENT_INFO client_info;
	memset(&client_info,0,sizeof(struct CLIENT_INFO));
	if(QuerySignalInfo(id,&client_info))
		
	return false;
}

bool AdmainRequest::OnSearchCard()
{
	char id[16];
	sock->Receive(id,16);
	
}

bool AdmainRequest::OnDesAcc()
{

}

bool AdmainRequest::OnDesCard()

{}
bool AdmainRequest::ClientRequestBlockList()
{
	return false;
}

bool AdmainRequest::OnAddAccount()
{
	struct LOGIN_INFO user_info;
	memset(&user_info,0,sizeof(struct LOGIN_INFO));
	int ret=-1;
	sock->Receive(&user_info,sizeof(struct LOGIN_INFO));
	
	if(!CreateAccount(user_info))
		
	return true;
}

bool AdmainRequest::OnAddCard()
{
	struct LOGIN_INFO user_info;
	memset(&user_info,0,sizeof(struct LOGIN_INFO));
	int ret=-1;
	sock->Receive(&user_info,sizeof(struct LOGIN_INFO));
	if(!CreateCard(user_info))
		return false;
	return true;
}


bool AdmainRequest::OnAdmDelete()
{
	return false;
}

bool AdmainRequest::OnAdmRefresh()
{
	return false;
}



bool AdmainRequest::OnRefresh()
{
	return false;
}



bool AdmainRequest::OnExit()
{
	return false;
}

bool AdmainRequest::FreezeAcc(const char* id)
{
	char sql[64];
	memset(sql,'\0',64);
	sprintf(sql,"update Account set acc_status=0 where acc_no='%s'",id);
	if(SQLOperate(sql))
		return true;
	return false;
}


bool AdmainRequest::UnFreezeAcc(const char * id)
{
	char sql[64];
	memset(sql,'\0',64);
	sprintf(sql,"update Account set acc_status=1 where acc_no='%s'",id);
	if(SQLOperate(sql))
		return true;
	return false;
}






