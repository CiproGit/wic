#include "sender_thread.h"

Sender_thread::Sender_thread(MainWindow *window, const Client *client) {
	this->window = window;
	this->client = client;
}

Sender_thread::~Sender_thread() = default;

void Sender_thread::run() {
	if (this->client->get_number_of_servers() >= 1) {
		for (int server_index = 0; server_index < this->client->get_number_of_servers(); server_index++) {
			QString ip_address = this->client->get_ip_address_list().at(server_index);
			QTcpSocket *socket = this->client->get_socket_list().at(server_index);

			this->window->print_console("Trying to connect to " + ip_address + "...");

			socket->connectToHost(ip_address, this->client->get_port());

			if (socket->waitForConnected(this->client->get_timeout())) {
				this->window->print_console("Connected to " + ip_address + '\n');

				QByteArray outgoing_message;
				outgoing_message.append("Who is connected");
				socket->write(outgoing_message);
			}
			else this->window->print_console(socket->errorString() + '\n');

			emit progress(server_index);
		}
	}
	else this->window->print_console("Error: empty server list");

	exec();
}
