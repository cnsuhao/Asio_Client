#include "stdafx.h"
#include "Asio_context.h"


Asio_context::Asio_context(std::shared_ptr<asio::io_service>& io_service)
	: io_service_(io_service)
	, work_ ( new asio::io_service::work(*io_service))
{
	thread_ = std::thread([this]() {
		std::cout << "io_service run begin \n";
		io_service_->run();
		std::cout << "io_service run end \n";
	});
}


Asio_context::~Asio_context()
{
	Stop();
}
