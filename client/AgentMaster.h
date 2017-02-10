#pragma once

class Config;
class IClientNetWork;
class SockImpl;
class AgentMaster  
{
public:
	AgentMaster(std::shared_ptr<Config>);
	virtual ~AgentMaster();

public:
	void ConnectAgent(std::shared_ptr<asio::io_service>& io_service);

	void SetClientNetWork(std::shared_ptr<IClientNetWork> ClientNetWork);
protected:
	std::shared_ptr<Config> config_;
	std::shared_ptr<IClientNetWork> ClientNetWork_;
	std::shared_ptr<SockImpl> SockImpl_;
};

