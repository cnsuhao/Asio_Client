// client.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Asio_context.h"
#include "AgentMaster.h"
#include "Config.h"


int main()
{
	
	std::shared_ptr<asio::io_service> io_service(new asio::io_service());
	std::shared_ptr<Asio_context> asio_context ( new Asio_context(io_service));
	std::shared_ptr<Config> config(new Config());

	io_service->post(std::bind(&AgentMaster::ConnectAgent,io_service));
	asio_context->join();

	std::cout << "exit main \n";

    return 0;
}

