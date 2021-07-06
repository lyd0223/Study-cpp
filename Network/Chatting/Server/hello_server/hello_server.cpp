#include <iostream>
#include <WinSock2.h>
#include <thread>
//�̰ž����� wsastartup�̾ȵ�.
#pragma comment(lib, "ws2_32.lib")
#define SERVER_PORT 55555
using namespace std;

//�����带 �Ѱ��� �̿��� ���, ���ú� �Ǵ� ���带 ����ϴµ��� �����尡 �������� �޽��� �ۼ����� �Ұ����ϴ�.
//���� ��Ƽ�����带�̿�, ���ν����忡���� ���带 ���, ���꽺���忡���� ���ú긦 ����Ѵ�.
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
	//ù��° ���ڴ� ����, �ι�° ���ڴ� ���� ����ü
	//�������θ� Ȯ���ϱ����� üũ��.
	int wsaResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (wsaResult != 0)
	{
		cout << "WSAStartup ����" << endl;
		return 0;
	}

	//���ϻ��� : ������ ���ϻ���.
	//���н� INVALID_SOCKET��ȯ.
	//ù��° ���ڴ� IPv4����, IPv6���� , ���⼭�� IPv4���.
	//�ι�° ���ڴ� TCP���� UDP����. ���⼭�� TCP���.
	//����° ���ڴ� �������ݼ���. 0�����ϸ� �ڵ����� ������.
	SOCKET listeningSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listeningSock == INVALID_SOCKET)
	{
		cout << "���� ��������" << endl;
		WSACleanup();
		return 0;
	}

	//���ε� : ���Ͽ� IP�ּҿ� Port��ȣ �Ҵ�.
	sockaddr_in hint{};
	hint.sin_family = AF_INET;
	hint.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	hint.sin_port = htons(SERVER_PORT);
	
	int bindResult = bind(listeningSock, reinterpret_cast<sockaddr*>(&hint), sizeof(hint));
	if (bindResult == SOCKET_ERROR)
	{
		cout << "���ε� ����" << endl;
		closesocket(listeningSock);
		WSACleanup();
		return 0;
	}
	
	//������ �������·θ����.
	int listenResult = listen(listeningSock, SOMAXCONN);
	if (listenResult == SOCKET_ERROR)
	{
		cout << "���� ����" << endl;
		closesocket(listeningSock);
		WSACleanup();
		return 0;
	}

	//Ŭ���̾�Ʈ ���� ��û�� ���� �������.
	sockaddr_in clientSockInfo;
	int clientSockSize = sizeof(clientSockInfo);
	SOCKET clientSocket = accept(listeningSock, reinterpret_cast<sockaddr*>(&clientSocket), &clientSockSize);
	if (clientSocket == INVALID_SOCKET)
	{
		cout << "Ŭ���̾�Ʈ ���� ����" << endl;
		closesocket(listeningSock);
		WSACleanup();
		return 0;
	}
	
	//���������� ���ϴݱ�
	int closeResult = closesocket(listeningSock);
	
	cout << "���� ������" << endl;
	//Ŭ���̾�Ʈ ��û�ް�, ������ ���� ����.
	
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