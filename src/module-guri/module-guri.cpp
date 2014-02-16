//-----------------------------------------------------------------------------
// Gura module: guri
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(guri)

//-----------------------------------------------------------------------------
// Gura module functions: guri
//-----------------------------------------------------------------------------
// guri.test()
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(test)
{
	const char *addrToConnect = "127.0.0.1";
	short portToConnect = 12345;
	int sock = static_cast<int>(::socket(AF_INET, SOCK_STREAM, 0)); //IPPROTO_TCP);
	if (sock < 0) {
		sig.SetError(ERR_IOError, "failed to create a socket");
		return Value::Null;
	}
	sockaddr_in saddrServer;
	::memset(&saddrServer, 0x00, sizeof(saddrServer));
	ULong addrNum = ::inet_addr(addrToConnect);
	if (addrNum == 0xffffffff) {
		hostent *pHostEnt = ::gethostbyname(addrToConnect);
		if (pHostEnt == NULL) {
			sig.SetError(ERR_IOError, "host not found: %s", addrToConnect);
			return Value::Null;
		}
		saddrServer.sin_family = pHostEnt->h_addrtype;
		addrNum = **reinterpret_cast<ULong **>(pHostEnt->h_addr_list);
	} else {
		saddrServer.sin_family = AF_INET;
	}
	saddrServer.sin_addr.s_addr = addrNum;
	saddrServer.sin_port = ::htons(portToConnect);
	if (::connect(sock, reinterpret_cast<sockaddr *>(&saddrServer), sizeof(saddrServer)) < 0) {
		sig.SetError(ERR_IOError, "failed to connect to host %s:%d",
											addrToConnect, portToConnect);
		return Value::Null;
	}
	::send(sock, "Hello world", 11, 0);
	::closesocket(sock);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
#if defined(GURA_ON_MSWIN)
	WSADATA wsaData;
	::WSAStartup(MAKEWORD(2, 0), &wsaData);
#endif
	// function assignment
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(guri, guri)

Gura_RegisterModule(guri)
