#ifndef _BANKAPP_BASEREQUEST_H_
#define _BANKAPP_BASEREQUEST_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "tcp_socket.h"
#include "define.h"
#include "mysql_cpp.h"

class BaseRequest
{
public:
	BaseRequest(char* id=NULL):ID(id){}
	bool LoadingDataBase();

	bool isUser(bool isClient,const char* id);
	bool QuerySignalInfo(const char* id,struct CLIENT_INFO * user_info);
	LOGIN_ERROR VerifyInfo(bool isClient,struct LOGIN_INFO &login_info);

	virtual void OnReceive() = 0;

	bool CreateAccount(struct LOGIN_INFO&);
	bool DestoryAccount(const char* id);

	bool CreateCard(struct LOGIN_INFO&);
	bool DestoryCard(const char * id);

	int GetUserCardNum(const char * id,std::vector<std::string>&card_no);
	bool SearchCardInfo(const char * id, CARD_INFO * card_info);

	int GetUserRecodeNum(const char * id,int type,std::vector<std::string>&card_no);
	bool SearchRecordInfo(const char* id,int type,struct TRCODE_INFO  * info);

	bool OnLine(const char* id);
	bool OffLine(const char* id);

	bool SQLOperate(const char* sql);


	virtual bool OnLogin()=0;
	const char * GetUserID() { return ID.c_str(); }
	void SetUserID(const char* id){
		ID=id;
	}
private:
	std::string ID;
	MySQL mysql_conn;
};


void OnMessage(BaseRequest *user_request);

#endif //!_BANKAPP_BASEREQUEST_H_


