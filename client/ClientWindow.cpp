#include "stdafx.h"
#include "ClientWindow.h"
#include "ClientNetWorkDriver.h"

class ClientWindowImpl
{
public:
	ClientWindowImpl() {
		ClientNetWorkDrive_ = std::make_shared<ClientNetWorkDriver>();
		thread_ = std::thread(&ClientWindowImpl::TryConnect, this);
	}

	void Run()
	{
		ClientNetWorkDrive_->Run();
	}

	void TryConnect()
	{
		ClientNetWorkDrive_->DoConnect();
	}

protected:
	std::thread  thread_;

	std::shared_ptr<ClientNetWorkDriver> ClientNetWorkDrive_;
};

ClientWindow::ClientWindow()
{
	ClientWindowImpl_ = std::make_unique<ClientWindowImpl>();
}


ClientWindow::~ClientWindow()
{

}


void ClientWindow::Run()
{
	ClientWindowImpl_->Run();
}