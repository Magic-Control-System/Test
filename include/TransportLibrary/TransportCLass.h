#pragma once

#ifndef SERVER_LISTENER_H_
#define SERVER_LISTENER_H_

#include <TransportLibrary\TransportLibrary.h>
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

class TRANSPORT_LIBRARY_API TransportClass : public Poco::Util::ServerApplication
{
	virtual int main(const std::vector<std::string>& args);
};
#endif // SERVER_LISTENER_H_
