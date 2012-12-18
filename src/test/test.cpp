#include <windows.h>
#include <stdio.h>

#include <mysql.h>

int main()
{
	MYSQL mysql;
	::mysql_init(&mysql);
	::mysql_real_connect(&mysql, NULL, "user", "password", "dbname", 0, NULL, 0);
	if (::mysql_error(&mysql) != 0) {
		::printf("%s\n", ::mysql_error(&mysql));
		return 1;
	}
	::mysql_query(&mysql, "select * from people");
	if (::mysql_error(&mysql) != 0) {
		::printf("%s\n", ::mysql_error(&mysql));
		return 1;
	}
	MYSQL_RES *results = ::mysql_store_result(&mysql);
	MYSQL_ROW row;
	while ((row = ::mysql_fetch_row(results)) != NULL) {
		::printf("%s\n", row[0]);
	}
	::mysql_free_result(results);
	::mysql_close(&mysql);
	::mysql_server_end();
	return 0;
}

#if 0
#include <winsock2.h>

int main()
{
	WSADATA wsaData;
	::WSAStartup(MAKEWORD(2, 0), &wsaData);
	fd_set fds;
	SOCKET sock = ::socket(AF_INET, SOCK_STREAM, 0);
	//do {
	//	unsigned long ulFlag = 1;	// enable non-blocking mode
	//	::ioctlsocket(sock, FIONBIO, &ulFlag);
	//} while (0);
	const char *strAddr = "10.29.15.24";
	short iPort = 80;
	do {
		sockaddr_in addr;
		::memset(&addr, 0x00, sizeof(addr));
		int bytesAddr = sizeof(addr);
		::WSAStringToAddress(const_cast<char *>(strAddr), AF_INET, NULL,
						reinterpret_cast<LPSOCKADDR>(&addr), &bytesAddr);
		addr.sin_port = ::htons(iPort);
		//addr.sin_family = AF_INET;
		//addr.sin_addr.S_un.S_addr = ::htonl(dwIPAddr);
		::connect(sock, reinterpret_cast<sockaddr *>(&addr), sizeof(addr));
	} while (0);
	::send(sock, "GET / \n\n", 8, 0);
	char buff[2048];
	int nBytes = ::recv(sock, buff, 2048, 0);
	::printf("%d bytes\n", nBytes);
	const char *buffp = buff;
	for (int i = 0; i < nBytes; i++, buffp++) {
		printf("%c", *buffp);
	}
	::closesocket(sock);
	return 0;
}
#endif
