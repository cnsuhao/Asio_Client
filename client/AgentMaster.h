#pragma once

class Config;

class AgentMaster  
{
public:
	AgentMaster();
	virtual ~AgentMaster();

public:
	static void ConnectAgent(std::shared_ptr<asio::io_service>& io_service);
};

