#include "stdafx.h"
#include "ClientNetWorkDriver.h"
#include "IClientNetWork.h"
#include "Asio_context.h"
#include "AgentMaster.h"
#include "Config.h"
class ClientNetWorkDriverImpl : public std::enable_shared_from_this<ClientNetWorkDriverImpl>, public IClientNetWork
{
public:
	ClientNetWorkDriverImpl()
		: io_service_(new asio::io_service())
	{
		Config_ = std::make_shared<Config>();
		Asio_context_ = std::make_shared<Asio_context>(io_service_);
		AgentMaster_ = std::make_shared<AgentMaster>(Config_);
	}

	void DoConnect()
	{
		AgentMaster_->SetClientNetWork(shared_from_this());
		AgentMaster_->ConnectAgent(io_service_);
	}

	void Run()
	{
		Asio_context_->join();
	}

protected:
	std::shared_ptr<Asio_context> Asio_context_;
	std::shared_ptr<AgentMaster>  AgentMaster_;
	std::shared_ptr<asio::io_service> io_service_;
	std::shared_ptr<Config> Config_;
};

ClientNetWorkDriver::ClientNetWorkDriver()
	: ClientNetWorkDriverImpl_(new ClientNetWorkDriverImpl())
{
}


ClientNetWorkDriver::~ClientNetWorkDriver()
{

}

void ClientNetWorkDriver::DoConnect()
{
	ClientNetWorkDriverImpl_->DoConnect();
}

void ClientNetWorkDriver::Run()
{
	ClientNetWorkDriverImpl_->Run();
}