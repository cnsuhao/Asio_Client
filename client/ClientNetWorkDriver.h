#pragma once

class Config;
class ClientNetWorkDriverImpl;

class ClientNetWorkDriver
{
public:
	ClientNetWorkDriver();
	virtual ~ClientNetWorkDriver();

	void DoConnect();
	void Run();
protected:
	std::shared_ptr<ClientNetWorkDriverImpl > ClientNetWorkDriverImpl_;
};

