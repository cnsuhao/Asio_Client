#include "stdafx.h"
#include "AgentMaster.h"
#include "Config.h"
#include "SockImpl.h"

AgentMaster::AgentMaster(std::shared_ptr<Config> config)
	: config_(config)
{

}


AgentMaster::~AgentMaster()
{
}

void AgentMaster::SetClientNetWork(std::shared_ptr<IClientNetWork> ClientNetWork)
{
	ClientNetWork_ = ClientNetWork;
}

void AgentMaster::ConnectAgent(std::shared_ptr<asio::io_service>& io_service)
{
	auto port = std::to_string(config_->port_);
	std::string host = config_->ip_;

	asio::ip::tcp::resolver reslove(*io_service);
	asio::ip::tcp::resolver::query query(host, port);

	SockImpl_ = std::make_shared<SockImpl>(io_service);

	asio::error_code ec;
	auto endpoint = reslove.resolve(query,ec);
	if (ec)
	{
		SockImpl_->close(std::string("resolve failed") + ec.message());
	}
	else
	{
		asio::async_connect(SockImpl_->sock_, endpoint, [](const asio::error_code& ec, auto next) {
			if (ec)
			{
				std::cout << "async_connect failed error msg is " << ec.message().c_str() << std::endl;
			}
			else
			{
				std::cout << "async_connect success\n";
			}
		});
	}

}
