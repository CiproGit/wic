#include "server.h"
#include <QHostAddress>
#include <QNetworkInterface>

using namespace std;

Server::Server(Main_window *window, QString ip_address, unsigned short port) {
	this->window = window;

	this->ip_address = ip_address;
	this->port = port;

	connect(&this->server, SIGNAL(newConnection()), this, SLOT(on_newConnection()));

	// List all server IP addresses (loopback and IPv6 excluded)
	QList<QHostAddress> ip_address_list = QNetworkInterface::allAddresses();
	for (const auto &ip_address : ip_address_list) {
		if (!ip_address.isLoopback() && ip_address.protocol() == QAbstractSocket::IPv4Protocol) this->window->print_ip_addresses(ip_address.toString());
	}

	// Read the username of the user logged in
	this->username = qgetenv("USER");
	if (this->username.isEmpty()) this->username = qgetenv("USERNAME");
	this->window->print_username(this->username);
}

Server::~Server() {
	this->server.close();
}

void Server::start_listening() {
	this->window->print_settings("IP address: " + this->ip_address);
	this->window->print_settings("Port: " + QString::number(this->port));

	if (this->server.listen(QHostAddress(this->ip_address), this->port)) this->window->print_console("Server listening...");
	else this->window->print_console("Error: server not listening");
}

void Server::on_newConnection() {
	this->socket = this->server.nextPendingConnection();
	connect(this->socket, SIGNAL(readyRead()), this, SLOT(on_new_message()));
}

void Server::on_new_message() {
	QByteArray ingoing_message = this->socket->readAll();

	QString message_string = QString(ingoing_message);
	this->window->print_console("Ingoing message: " + message_string);

	if (QString::compare(message_string, "Who is connected", Qt::CaseInsensitive) == 0) {
		QByteArray outgoing_message;
		outgoing_message.append(this->ip_address.toUtf8());
		outgoing_message.append(" ---> ");
		outgoing_message.append(this->username.toUtf8());

		this->window->print_console("Outgoing message: " + QString(outgoing_message) + '\n');
		this->socket->write(outgoing_message);
	}
}
