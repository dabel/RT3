/*
	Copyright (C) 2012  rt3cpp Development Team

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/* 
 * File: Server.cpp
 * Description: Listens for and handles clients
 * Author: t4
 * 
 */
 
#include <iostream>

#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include "ByteStream.h"
#include "PacketFactory.h"
#include "ISAACCipher.h"

using boost::asio::ip::tcp;

using namespace std;

typedef boost::shared_ptr<tcp::socket> socket_ptr;

static const short PORT = 43594;
static const int BUFFER_SIZE = 4096;
static bool active = true;

void session(socket_ptr sock) {
	//TODO: login block and do gay ass flying shit
}

void init_listener(boost::asio::io_service& ios) {
	tcp::acceptor a(ios, tcp::endpoint(tcp::v4(), PORT));
	while(active) {
		socket_ptr sock(new tcp::socket(ios));
		a.accept(*sock);
		boost::thread t(boost::bind(session, sock));
	}
}

int main(int argc, char** argv) {
	boost::asio::io_service ios;
	init_listener(ios);
	return 0;
}
