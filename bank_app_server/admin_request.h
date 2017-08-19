#ifndef _BANKAPP_ADMINREQUEST_H_
#define _BANKAPP_ADMINREQUEST_H_
#include "base_request.h"
#include "tcp_socket.h"
class AdminRequest :
	public BaseRequest
{
public:
	AdminRequest(Csocket* socket, char* id = NULL) :BaseRequest(id), socket_(socket) {}
	~AdminRequest() {}
	
	void OnReceive();

	bool OnLogin();

	bool OnSearchAcc();
	bool OnSearchCard();

	bool ClientRequestBlockList();

	bool FreezeAcc(const char * id);
	bool UnFreezeAcc(const char* id);

	bool OnDesCard();
	bool OnDesAcc();

	bool OnAddAccount();
	bool OnAddCard();
	
	bool OnAdmDelete();
	
	bool OnAdmRefresh();
	bool OnModState();
	bool OnRefresh();
	bool OnExit();
private:
	Csocket* socket_;
};
#endif //!_BANKAPP_ADMINREQUEST_H_

