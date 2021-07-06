#include <iostream>
#include <WinSock2.h>
#include <thread>

//�̰ž����� wsastartup�̾ȵ�.
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
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		cout << "���� ��������" << endl;
		WSACleanup();
		return 0;
	}

	//������ ���� (���ε�������) : ���Ͽ� IP�ּҿ� Port��ȣ �Ҵ�.
	sockaddr_in hint{};
	hint.sin_family = AF_INET;
	hint.sin_addr.S_un.S_addr = inet_addr("172.30.1.30");
	hint.sin_port = htons(PORT);

	int connResult = connect(sock, reinterpret_cast<sockaddr*>(&hint), sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		cout << "Ŀ���� ����" << endl;
		closesocket(sock);
		WSACleanup();
		return 0;
	}


	thread recvThread(recvFunc,sock);
	
	//Ŭ���̾�Ʈ ��û�ް�, ������ ���� ����.
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