#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <string>
#include <WinSock2.h>

using namespace std;

void ShowErrorMessage(string message) {
	cout << "[���� �߻�]: " << message << endl;
	system("pause");
	exit(-1);
}

int main() {
	WSADATA wsaData;
	SOCKET clientSocket;
	SOCKADDR_IN serverAddress;

	int serverPort = 9876;	// ������ ������ ��Ʈ�� ����ؾ� ��. 
	char received[256];
	string sent;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)	// Winsock �ʱ�ȭ
		ShowErrorMessage("WSAStartup()");

	clientSocket = socket(PF_INET, SOCK_STREAM, 0);

	if (clientSocket == INVALID_SOCKET) 
		ShowErrorMessage("clientSocket()");

	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");	// ���ڿ� IP�� ��Ʈ��ũ ����Ʈ ��������
	serverAddress.sin_port = htons(serverPort);	// 2 ����Ʈ ���� ��Ʈ��ũ ����Ʈ ��������
	if (connect(clientSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		ShowErrorMessage("connect()");
	cout << "[���� ����]: connect()" << endl;

	while (1) {	// �ݺ������� ������ �޽����� �����ϰ� ���� �޽����� ���� �޴´�.
		cout << "[�޽��� ����]: ";
		getline(cin, sent);
		if (sent == "") continue;
		send(clientSocket, sent.c_str(), sent.length(), 0);
		int length = recv(clientSocket, received, sizeof(received), 0);
		received[length] = NULL;
		if (strcmp(received, "[exit]") == 0) {
			cout << "[���� ����]" << endl;
			break;
		}
		cout << "[���� �޽���]: " << received << endl;
	}

	closesocket(clientSocket);
	WSACleanup();
	system("pause");
	return 0;
}