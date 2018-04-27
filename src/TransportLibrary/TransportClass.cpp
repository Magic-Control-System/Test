#include <iostream>
#include <TransportLibrary\TransportCLass.h>

int TransportClass::main(const std::vector<std::string>& args)
{
	Poco::Net::ServerSocket socket(8000);
	TCPServer srv(new TCPServerConnectionFactoryImpl<EchoConnection>(), socket);
	srv.start();
	waitForTerminationRequest();
	srv.stop();
	return 0;
}