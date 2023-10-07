#include "client.h"
#include "common.h"
#include "sender_thread.h"
#include <QHostAddress>
#include <QNetworkInterface>
#include <QFile>

using namespace std;

Client::Client(MainWindow *window, unsigned short port,  int timeout, QString working_dir) {
	this->window = window;

	this->port = port;
	this->timeout = timeout;

	this->window->print_settings("Port: " + QString::number(this->port));
	this->window->print_settings("Timeout: " + QString::number(this->timeout) + " ms\n");

	read_from_file(working_dir);

	this->window->set_progressbar(this->number_of_servers);

	for (int server_index = 0; server_index < this->number_of_servers; server_index++) {
		connect(this->socket_list.at(server_index), SIGNAL(readyRead()), this, SLOT(on_readyRead()));
	}
}

Client::~Client() {
	for (const auto &socket : this->socket_list) {
		socket->close();
		delete socket;
	}
}

unsigned short Client::get_port() const {
	return this->port;
}

int Client::get_timeout() const {
	return this->timeout;
}

int Client::get_number_of_servers() const {
	return this->number_of_servers;
}

QList<QString> Client::get_ip_address_list() const {
	return this->ip_address_list;
}

QList<QTcpSocket *> Client::get_socket_list() const {
	return this->socket_list;
}

void Client::read_from_file(QString working_dir) {
	this->number_of_servers = 0;

	QFile file(working_dir + FILE_PATH + SERVER_LIST_FILE);
	if (file.open(QIODevice::ReadOnly)) {
		QTextStream in(&file);

		// Read each line of SERVER_LIST_FILE
		while (!in.atEnd()) {
			QString line = in.readLine();
			this->ip_address_list.push_back(line);

			QTcpSocket *socket = new QTcpSocket();
			this->socket_list.push_back(socket);

			this->number_of_servers++;
		}

		file.close();
	}
}

void Client::send_request() const {
	Sender_thread *sender_thread = new Sender_thread(this->window, this);
	connect(sender_thread, &Sender_thread::finished, sender_thread, &QObject::deleteLater);
	connect(sender_thread, SIGNAL(progress(int)), this, SLOT(on_progress(int)));
	sender_thread->start();
}

void Client::on_readyRead() {
	for (int server_index = 0; server_index < this->number_of_servers; server_index++) {
		QByteArray ingoing_message = this->socket_list.at(server_index)->readAll();
		this->window->print_console(QString(ingoing_message));
	}
}

void Client::on_progress(int progress) {
	this->window->update_progressbar(progress);
}
