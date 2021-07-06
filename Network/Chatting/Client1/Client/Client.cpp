#include <iostream>
#include <WinSock2.h>

//�̰ž����� wsastartup�̾ȵ�.
#pragma comment(lib, "ws2_32.lib")
#define PORT 55555
#define IPADR "172.30.1.30"
using namespace std;

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


	//Ŭ���̾�Ʈ ��û�ް�, ������ ���� ����.
	while (1)
	{
		string sendStr = "";
		cout << "Client1 : ";
		cin >> sendStr;
		
		if (sendStr.size() > 0)
		{
			int sendResult = send(sock, sendStr.c_str(), sizeof(sendStr) + 1, 0);

			if (sendResult == SOCKET_ERROR)
			{
				
			}
		}
	}

	closesocket(sock);
	WSACleanup();
}