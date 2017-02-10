#pragma once

class Asio_context
{
public:
	Asio_context(std::shared_ptr<asio::io_service>& io_service);
	~Asio_context();

	void join() {
		if(thread_.joinable()) thread_.join();
	}

	void Stop() {
		io_service_->stop();
		thread_.join();
	}

	std::shared_ptr<asio::io_service> io_service_;
protected:
	std::shared_ptr<asio::io_service::work> work_;
	std::thread   thread_;
};

