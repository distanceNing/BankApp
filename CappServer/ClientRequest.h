#pragma once
#ifndef _ClientRequest
#define _ClientRequest

#include "BaseRequest.h"
#include "mysql_data.h"
const int InitialCredit = 100;
#include <vector>
#include <string>

class ClientRequest
	:public BaseRequest
{
public:
	ClientRequest(Csocket* user_sock, char* id=NULL) :BaseRequest(id),sock(user_sock) {}
	~ClientRequest() {};
	
	void OnReceive();

	bool OnDesAcc();
	bool OnDesCard();

	bool OnSerAllCard();


	bool OnLogin();
	bool OnSearchAcc();
	bool OnRecord(int type);	
	
	bool OnMod();
	bool OnSave();
	bool OnWithdrow();
	bool OnRefresh();
	bool OnTrans();
	bool OnExit();
private:
	Csocket* sock;
};

#endif // !_ClientRequest
