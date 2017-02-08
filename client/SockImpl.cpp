#include "stdafx.h"
#include "SockImpl.h"


SockImpl::SockImpl(std::shared_ptr<asio::io_service>& io_service)
	:sock_(*io_service)
{
}


SockImpl::~SockImpl()
{
}

void SockImpl::close(std::string reason)
{

}
