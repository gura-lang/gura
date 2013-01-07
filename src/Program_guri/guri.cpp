#include <gura.h>
#if defined(HAVE_WINDOWS_H)
typedef int socklen_t;
#else
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
		::fprintf(stderr, "failed to create a socket");
		return false;
	}
	sockaddr_in saddrServer;
	::memset(&saddrServer, 0x00, sizeof(saddrServer));
	unsigned long addrNum = ::htonl(INADDR_ANY);
	saddrServer.sin_family = AF_INET;
	if (addr != NULL) {
		addrNum = ::inet_addr(addr);
		if (addrNum == 0xffffffff) {
			hostent *pHostEnt = ::gethostbyname(addr);
			if (pHostEnt == NULL) {
				::fprintf(stderr, "binding address not found: %s", addr);
				return false;
			}
			saddrServer.sin_family = pHostEnt->h_addrtype;
			addrNum = **reinterpret_cast<unsigned long **>(pHostEnt->h_addr_list);
		}
	}
	saddrServer.sin_addr.s_addr = addrNum;
	saddrServer.sin_port = ::htons(port);
	if (::bind(sockListen, reinterpret_cast<sockaddr *>(&saddrServer), sizeof(saddrServer)) < 0) {
		::fprintf(stderr, "failed to bind address to socket");
		return false;
	}
	if (::listen(sockListen, 5) < 0) {
		::fprintf(stderr, "failed to listen to port %d", port);
		return false;
	}
	fd_set fdsRead;
	FD_ZERO(&fdsRead);
	FD_SET(static_cast<unsigned int>(sockListen), &fdsRead);
	int sockMax = sockListen;
	for (;;) {
		::select(sockMax + 1, &fdsRead, NULL, NULL, NULL);
		if (FD_ISSET(sockListen, &fdsRead)) {
			FD_CLR(static_cast<unsigned int>(sockListen), &fdsRead);
			sockaddr_in saddrClient;
			socklen_t bytesAddr = sizeof(saddrClient);
			int sockClient = static_cast<int>(::accept(sockListen,
							reinterpret_cast<sockaddr *>(&saddrClient), &bytesAddr));
			
		}
	}
	::closesocket(sockListen);
	return true;
}

}

int main(int argc, const char *argv[])
{
#if defined(HAVE_WINDOWS_H)
	WSADATA wsaData;
	::WSAStartup(MAKEWORD(2, 0), &wsaData);
#endif
	return Gura::Main(argc, argv)? 0 : 1;
}
