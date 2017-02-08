#include "stdafx.h"
#include "AgentMaster.h"
#include "Config.h"
#include "SockImpl.h"

AgentMaster::AgentMaster()
{

}


AgentMaster::~AgentMaster()
{
}

void AgentMaster::ConnectAgent(std::shared_ptr<asio::io_service>& io_service)
{
	std::unique_ptr<Config> config =  std::make_unique<Config>();

	auto port = std::to_string(config->port_);
	std::string host = config->ip_;

	asio::ip::tcp::resolver reslove(*io_service);
	asio::ip::tcp::resolver::query query(host, port);

	auto sock = std::make_shared<SockImpl>(io_service);

	asio::error_code ec;
	auto endpoint = reslove.resolve(query,ec);
	if (ec)
	{
		sock->close(std::string("async_connect") + ec.message());
	}
	else
	{
		asio::async_connect(sock->sock_, endpoint, [](const asio::error_code& ec, auto next) {
		
			std::cout << "async connect success \n";

		});
	}

}
