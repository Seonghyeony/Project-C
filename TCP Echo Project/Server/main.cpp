#include <iostream>
#include <string>
#include <WinSock2.h>

using namespace std;

void ShowErrorMessage(string message) {
	cout << "[오류 발생]: " << message << endl;
	system("pause");
	exit(1);
}

int main() {
	WSADATA wsaData;
	SOCKET serverSocket, clientSocket;
	SOCKADDR_IN serverAddress, clientAddress;

	int serverPort = 9876;
	char received[256];

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {	// winsock을 초기화.
		ShowErrorMessage("WSAStartup()");
	}

	serverSocket = socket(PF_INET, SOCK_STREAM, 0);		// TCP 소켓을 생성

	if (serverSocket == INVALID_SOCKET)
		ShowErrorMessage("socket()");

	memset(&serverAddress, 0, sizeof(serverAddress));	// serverAddress 값 0으로 초기화.
	serverAddress.sin_family = AF_INET;	// 체계
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);	// 4바이트 정수를 네트워크 바이트 형식으로
	serverAddress.sin_port = htons(serverPort);			// 2바이트 정수를 네트워크 바이트 형식으로
	if (bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		ShowErrorMessage("bind()");
	cout << "[현재 상태]: bind()" << endl;

	if (listen(serverSocket, 5) == SOCKET_ERROR)	// 동시연결 5개.
		ShowErrorMessage("listen()");
	cout << "[현재 상태]: listen()" << endl;

	int sizeClientAddress = sizeof(clientAddress);
	clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddress, &sizeClientAddress);
	cout << "[현재 상태]: accept()" << endl;

	if (clientSocket == INVALID_SOCKET)
		ShowErrorMessage("accept()");

	// 무한 반복
	while (1) {	// 클라이언트의 메시지를 받아서 그대로 다시 전달.
		int length = recv(clientSocket, received, sizeof(received), 0);
		received[length] = NULL;	// 마지막 문자는 NULL
		cout << "[클라이언트 메시지]: " << received << endl;
		cout << "[메시지 전송]: " << received << endl;
		if (strcmp(received, "[exit]") == 0) {
			send(clientSocket, received, sizeof(received) - 1, 0);
			cout << "[서버 종료]" << endl;
			break;
		}
		// 클라이언트가 엔터를 쳐서 문자를 보내므로 마지막 공백 문자는 제거.
		send(clientSocket, received, sizeof(received) - 1, 0);
	}

	closesocket(clientSocket);
	closesocket(serverSocket);
	WSACleanup();
	system("pause");
	return 0;
}