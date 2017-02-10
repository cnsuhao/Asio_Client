#pragma once

class ClientWindowImpl;
class ClientWindow
{
public:
	ClientWindow();
	virtual ~ClientWindow();

	void Run();

protected:
	std::unique_ptr<ClientWindowImpl> ClientWindowImpl_;
};

