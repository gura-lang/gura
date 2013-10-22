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

namespace Gura {

//-----------------------------------------------------------------------------
// Main entry
//-----------------------------------------------------------------------------
bool Main(int argc, const char *argv[])
{
	const char *addr = "localhost";
	short port = 12345;
	int sockListen = static_cast<int>(::socket(AF_INET, SOCK_STREAM, 0));
	if (sockListen < 0) {
		::fprintf(stderr, "failed to create a socket\n");
		return false;
	}
	sockaddr_in saddrServer;
	::memset(&saddrServer, 0x00, sizeof(saddrServer));
	unsigned long addrNum = htonl(INADDR_ANY);
	saddrServer.sin_family = AF_INET;
	if (addr != NULL) {
		addrNum = ::inet_addr(addr);
		if (addrNum == 0xffffffff) {
			hostent *pHostEnt = ::gethostbyname(addr);
			if (pHostEnt == NULL) {
				::fprintf(stderr, "binding address not found: %s\n", addr);
				return false;
			}
			saddrServer.sin_family = pHostEnt->h_addrtype;
			addrNum = **reinterpret_cast<unsigned long **>(pHostEnt->h_addr_list);
		}
	}
	saddrServer.sin_addr.s_addr = addrNum;
	saddrServer.sin_port = htons(port);
	if (::bind(sockListen, reinterpret_cast<sockaddr *>(&saddrServer), sizeof(saddrServer)) < 0) {
		::fprintf(stderr, "failed to bind address to socket\n");
		return false;
	}
	if (::listen(sockListen, 5) < 0) {
		::fprintf(stderr, "failed to listen to port %d\n", port);
		return false;
	}
	int sockClient = -1;
	::printf("service started at port %d\n", port);
	for (;;) {
		fd_set fdsRead;
		FD_ZERO(&fdsRead);
		FD_SET(static_cast<unsigned int>(sockListen), &fdsRead);
		int sockMax = sockListen;
		if (sockClient >= 0) {
			FD_SET(static_cast<unsigned int>(sockClient), &fdsRead);
			if (sockMax < sockClient) sockMax = sockClient;
		}
		::select(sockMax + 1, &fdsRead, NULL, NULL, NULL);
		if (FD_ISSET(sockListen, &fdsRead)) {
			FD_CLR(static_cast<unsigned int>(sockListen), &fdsRead);
			sockaddr_in saddrClient;
			socklen_t bytesAddr = sizeof(saddrClient);
			sockClient = static_cast<int>(::accept(sockListen,
							reinterpret_cast<sockaddr *>(&saddrClient), &bytesAddr));
			String remoteIP = ::inet_ntoa(saddrClient.sin_addr);
			String remoteHost(remoteIP);
			const hostent *pHostEnt = ::gethostbyaddr(
					reinterpret_cast<char *>(&saddrClient.sin_addr), 4, AF_INET);
			if (pHostEnt != NULL) remoteHost = pHostEnt->h_name;
			::printf("connected with %s\n", remoteHost.c_str());
		} else if (sockClient >= 0 && FD_ISSET(sockClient, &fdsRead)) {
			char buff[512];
			int rtn = ::recv(sockClient, buff, sizeof(buff), 0);
			if (rtn == 0) {
				::printf("disconnected\n");
				sockClient = -1;
			} else {
				::printf("%d bytes received\n", rtn);
			}
		}
	}
	::closesocket(sockListen);
	return true;
}

}

int main(int argc, const char *argv[])
{
#if defined(GURA_ON_MSWIN)
	WSADATA wsaData;
	::WSAStartup(MAKEWORD(2, 0), &wsaData);
#endif
	return Gura::Main(argc, argv)? 0 : 1;
}
