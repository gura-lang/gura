//-----------------------------------------------------------------------------
// Gura guri module
//-----------------------------------------------------------------------------
#ifndef __MODULE_GURI_H__
#define __MODULE_GURI_H__
#include <gura.h>
#if defined(GURA_ON_MSWIN)
typedef int socklen_t;
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

inline void closesocket(int sock) { close(sock); }
#endif

Gura_BeginModuleHeader(guri, guri)
Gura_EndModuleHeader(guri, guri)

#endif
