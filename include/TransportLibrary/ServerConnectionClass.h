#pragma once
#include <iostream>

#ifndef SERVER_COMMONREQUESTHANDLER_H_
#define SERVER_COMMONREQUESTHANDLER_H_

#include "Poco/Net/TCPServerConnectionFactory.h"
#include "Poco/DateTimeFormatter.h"
#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/TCPServer.h>
#include <Poco/DateTimeFormat.h>
#include <iostream>
#include "./ServerConnectionClass.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"

using Poco::DateTimeFormat;
using Poco::Net::StreamSocket;
using Poco::Net::SocketAddress;
using Poco::Net::TCPServer;
using Poco::Net::TCPServerConnectionFactoryImpl;
using Poco::DateTimeFormatter;
using Poco::Net::TCPServerConnection;
using namespace std;


class TRANSPORT_LIBRARY_API EchoConnection : public TCPServerConnection {
public:
	EchoConnection(const StreamSocket& s) : TCPServerConnection(s) { }
	void run() {
		StreamSocket& ss = socket();
		Poco::Util::Application& app = Poco::Util::Application::instance();
		app.logger().information("Request from " + this->socket().peerAddress().toString());
		try {
			char buffer[256];
			int n = ss.receiveBytes(buffer, sizeof(buffer));
			std::cout << std::string(buffer, n) << std::endl;// ВЫВОД в консоль всего что приходит 
			while (n > 0) {
				ss.sendBytes(buffer, n);
				n = ss.receiveBytes(buffer, sizeof(buffer));
			}
		}
		catch (Poco::Exception& exc)
		{
			std::cerr << "EchoConnection: " << exc.displayText() << std::endl;
		}
	}
};

#endif // SERVER_COMMONREQUESTHANDLER_H_

