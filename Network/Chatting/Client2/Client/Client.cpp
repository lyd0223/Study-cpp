#include <iostream>
#include <WinSock2.h>
#include <thread>

//이거없으면 wsastartup이안됨.
#pragma comment(lib, "ws2_32.lib")
#define PORT 55555
#define IPADR "172.30.1.30"
using namespace std;

void recvFunc(SOCKET sock)
{
	string str = "";
	while (1)
	{
		int recvResult = recv(sock, const_cast<char*>(str.c_str()), sizeof(str), 0);
		if (recvResult > 0)
		{
			cout << "Server : " << str << endl;
		}
	}
}
int main()
{
	WSADATA wsaData;
	//첫번째 인자는 버전, 두번째 인자는 담을 구조체
	//성공여부를 확인하기위해 체크함.
	int wsaResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (wsaResult != 0)
	{
		cout << "WSAStartup 실패" << endl;
		return 0;
	}

	//소켓생성 : 리스닝 소켓생성.
	//실패시 INVALID_SOCKET반환.
	//첫번째 인자는 IPv4인지, IPv6인지 , 여기서는 IPv4사용.
	//두번째 인자는 TCP인지 UDP인지. 여기서는 TCP사용.
	//세번째 인자는 프로토콜설정. 0으로하면 자동으로 설정됨.
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		cout << "소켓 생성실패" << endl;
		WSACleanup();
		return 0;
	}

	//서버에 연결 (바인딩과유사) : 소켓에 IP주소와 Port번호 할당.
	sockaddr_in hint{};
	hint.sin_family = AF_INET;
	hint.sin_addr.S_un.S_addr = inet_addr("172.30.1.30");
	hint.sin_port = htons(PORT);

	int connResult = connect(sock, reinterpret_cast<sockaddr*>(&hint), sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		cout << "커넥팅 실패" << endl;
		closesocket(sock);
		WSACleanup();
		return 0;
	}


	thread recvThread(recvFunc,sock);
	
	//클라이언트 요청받고, 수행할 동작 구현.
	while (1)
	{
		
		string sendStr = "";
		cin >> sendStr;
		if (sendStr.size() > 0)
		{
			int sendResult = send(sock, sendStr.c_str(), sizeof(sendStr), 0);
			if (sendResult == SOCKET_ERROR)
			{

			}
		}
	}
	recvThread.join();
	closesocket(sock);
	WSACleanup();
}