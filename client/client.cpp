// client.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ClientWindow.h"

int main()
{
	std::shared_ptr<ClientWindow> ClientWindow_(new ClientWindow());
	ClientWindow_->Run();

	std::cout << "exit main \n";

    return 0;
}

