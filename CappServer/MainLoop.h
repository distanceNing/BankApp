
#ifndef _MainLoop
#define _MainLoop
#include <iostream>
#include <memory>
#include "Csocket.h"
#include "define.h"
#include "AdmainRequest.h"
#include "ClientRequest.h"
class MainLoop
{
private:
	Csocket *sock;
public:
	MainLoop();
	bool OnStart();
	~MainLoop();
};




#endif //!_MainLoop