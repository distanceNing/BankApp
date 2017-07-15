#pragma once

#define SQL_BUF 512

#define PORT 9000

enum ACCOUNT_STATE
{
	ACCOUNT_STATE_AVAILABLE = 1,
	ACCOUNT_STATE_UNAVAILABLE = 0
};



struct LOGIN_INFO
{
	char id[16];
	char pass[16];
};

enum LOGIN_ERROR
{
	CHECK_SUCCESS = 1001,
	NO_THIS_USER,
	PASSWD_ERROR,
	ALREADY_ONLINE
};

enum USER_TYPE
{
	ADMAIN = 1,
	CLIENT
};

struct ADMIN_INFO
{
	char name[32];
	char date[32];
};

struct CLIENT_INFO
{
	char id[16];
	char name[32];
	char credit[4];
	char money[20];
	char date[32];
	char status[4];
};

typedef CLIENT_INFO CARD_INFO;


struct TRCODE_INFO
{
	char id[16];
	char name[32];
	char money[20];
	char date[32];
};


/*
struct CARD_INFO
{
	char id[16];
	char name[32];
	char credit[4];
	char money[20];
	char date[32];
	char status[4];
};*/


struct SER_INFO
{
	char name[16];
	char id[16];
};

//operate info

struct SAVE_INFO
{
	char id[16];
	char money[20];
};


struct MOD_INFO
{
	char pass[16];
	char name[32];
};

struct TRANS_INFO
{
	char this_card[16];
	char the_other_card[16];
	char money[20];
};


//2bytes request

enum REQ
{
	REQ_LOGIN=20,


   	REQ_SAVE,
	REQ_WHD,
	REQ_TRANS,

	REQ_MOD,



	REQ_SERACC,
	REQ_SERCARD,
	REQ_SERALLCARD,


	REQ_ADDACC,
	REQ_ADDCARD,

	REQ_ADMINFO,
	REQ_ALLADMINFO,

	REQ_SAVE_RECORD,
	REQ_WHD_RECORD,
	REQ_TRANS_RECORD,

	REQ_DESACC,
	REQ_DESCARD,

	REQ_FREEZE,
	REQ_UNFREEZE,

	REQ_OFF,
	REQ_EXIT

};








