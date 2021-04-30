#include <iostream>
#include <string>
#include <WinSock2.h>

using namespace std;

void ShowErrorMessage(string message) {
	cout << "[���� �߻�]: " << message << endl;
	system("pause");
	exit(1);
}

int main() {
	WSADATA wsaData;
	SOCKET serverSocket, clientSocket;
	SOCKADDR_IN serverAddress, clientAddress;

	int serverPort = 9876;
	char received[256];

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {	// winsock�� �ʱ�ȭ.
		ShowErrorMessage("WSAStartup()");
	}

	serverSocket = socket(PF_INET, SOCK_STREAM, 0);		// TCP ������ ����

	if (serverSocket == INVALID_SOCKET)
		ShowErrorMessage("socket()");

	memset(&serverAddress, 0, sizeof(serverAddress));	// serverAddress �� 0���� �ʱ�ȭ.
	serverAddress.sin_family = AF_INET;	// ü��
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);	// 4����Ʈ ������ ��Ʈ��ũ ����Ʈ ��������
	serverAddress.sin_port = htons(serverPort);			// 2����Ʈ ������ ��Ʈ��ũ ����Ʈ ��������
	if (bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		ShowErrorMessage("bind()");
	cout << "[���� ����]: bind()" << endl;

	if (listen(serverSocket, 5) == SOCKET_ERROR)	// ���ÿ��� 5��.
		ShowErrorMessage("listen()");
	cout << "[���� ����]: listen()" << endl;

	int sizeClientAddress = sizeof(clientAddress);
	clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddress, &sizeClientAddress);
	cout << "[���� ����]: accept()" << endl;

	if (clientSocket == INVALID_SOCKET)
		ShowErrorMessage("accept()");

	// ���� �ݺ�
	while (1) {	// Ŭ���̾�Ʈ�� �޽����� �޾Ƽ� �״�� �ٽ� ����.
		int length = recv(clientSocket, received, sizeof(received), 0);
		received[length] = NULL;	// ������ ���ڴ� NULL
		cout << "[Ŭ���̾�Ʈ �޽���]: " << received << endl;
		cout << "[�޽��� ����]: " << received << endl;
		if (strcmp(received, "[exit]") == 0) {
			send(clientSocket, received, sizeof(received) - 1, 0);
			cout << "[���� ����]" << endl;
			break;
		}
		// Ŭ���̾�Ʈ�� ���͸� �ļ� ���ڸ� �����Ƿ� ������ ���� ���ڴ� ����.
		send(clientSocket, received, sizeof(received) - 1, 0);
	}

	closesocket(clientSocket);
	closesocket(serverSocket);
	WSACleanup();
	system("pause");
	return 0;
}