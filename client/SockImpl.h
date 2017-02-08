#pragma once
class SockImpl
{
public:
	SockImpl(std::shared_ptr<asio::io_service>& io_service);
	virtual ~SockImpl();


public:
	void close(std::string reason);

	asio::ip::tcp::socket sock_;
};

