#include <iostream>
#include <WinSock2.h>
#include <thread>
//이거없으면 wsastartup이안됨.
#pragma comment(lib, "ws2_32.lib")
#define SERVER_PORT 55555
using namespace std;

//스레드를 한개만 이용한 결과, 리시브 또는 센드를 담당하는동안 쓰레드가 묶여버려 메시지 송수신이 불가능하다.
//따라서 멀티스레드를이용, 메인스레드에서는 센드를 담당, 서브스레드에서는 리시브를 담당한다.
void recvFunc(SOCKET sock)
{
	string str = "";
	while (1)
	{
		int recvResult = recv(sock, const_cast<char*>(str.c_str()), sizeof(str), 0);
		if (recvResult > 0)
		{
			cout << "Client : " << str << endl;
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
	SOCKET listeningSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listeningSock == INVALID_SOCKET)
	{
		cout << "소켓 생성실패" << endl;
		WSACleanup();
		return 0;
	}

	//바인딩 : 소켓에 IP주소와 Port번호 할당.
	sockaddr_in hint{};
	hint.sin_family = AF_INET;
	hint.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	hint.sin_port = htons(SERVER_PORT);
	
	int bindResult = bind(listeningSock, reinterpret_cast<sockaddr*>(&hint), sizeof(hint));
	if (bindResult == SOCKET_ERROR)
	{
		cout << "바인드 실패" << endl;
		closesocket(listeningSock);
		WSACleanup();
		return 0;
	}
	
	//소켓을 리슨상태로만들기.
	int listenResult = listen(listeningSock, SOMAXCONN);
	if (listenResult == SOCKET_ERROR)
	{
		cout << "리슨 실패" << endl;
		closesocket(listeningSock);
		WSACleanup();
		return 0;
	}

	//클라이언트 연결 요청이 오면 연결수락.
	sockaddr_in clientSockInfo;
	int clientSockSize = sizeof(clientSockInfo);
	SOCKET clientSocket = accept(listeningSock, reinterpret_cast<sockaddr*>(&clientSocket), &clientSockSize);
	if (clientSocket == INVALID_SOCKET)
	{
		cout << "클라이언트 연결 실패" << endl;
		closesocket(listeningSock);
		WSACleanup();
		return 0;
	}
	
	//리스닝중인 소켓닫기
	int closeResult = closesocket(listeningSock);
	
	cout << "서버 열었음" << endl;
	//클라이언트 요청받고, 수행할 동작 구현.
	
	thread recvThread(recvFunc,clientSocket);
	while (1)
	{
		string sendStr = "";
		cin >> sendStr;

		if (sendStr.size() > 0)
		{
			int sendResult = send(clientSocket, sendStr.c_str(), sizeof(sendStr), 0);
			if (sendResult == SOCKET_ERROR)
			{

			}
		}
		
	}
	recvThread.join();

	WSACleanup();
}