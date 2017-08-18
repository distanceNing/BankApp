#ifndef _BANKAPP_CLIENTREQUEST_H_
#define _BANKAPP_CLIENTREQUEST_H_

#include <vector>
#include <string>

#include "base_request.h"
#include "mysql_data.h"
#include "tcp_socket.h"

const int InitialCredit = 100;

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

#endif // !_BANKAPP_CLIENTREQUEST_H_

