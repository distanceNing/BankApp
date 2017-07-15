#pragma once
#ifndef _AdmainReques
#define _AdmainRequest
#include "BaseRequest.h"
#include "Csocket.h"
class AdmainRequest :
	public BaseRequest
{
public:
	AdmainRequest(Csocket* user_sock, char* id = NULL) :BaseRequest(id), sock(user_sock) {}
	~AdmainRequest() {}
	
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
	Csocket* sock;
};



#endif //!_AdmainRequest