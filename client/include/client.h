#ifndef CLIENT_H
#define CLIENT_H

#include "mainwindow.h"
#include <QObject>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Client : public QObject {
	Q_OBJECT

private:
	MainWindow *window; // Client GUI

	unsigned short port;
	int timeout;

	int number_of_servers; // Total number of servers in SERVER_LIST_FILE
	QList<QString> ip_address_list; // IP address of each server
	QList<QTcpSocket *> socket_list; // One socket for each server

	const QString SERVER_LIST_FILE = "server_list.txt";

	void read_from_file(QString working_dir);

public:
	Client(MainWindow *window, unsigned short port, int timeout, QString working_dir);
	virtual ~Client();
	unsigned short get_port() const;
	int get_timeout() const;
	int get_number_of_servers() const;
	QList<QString> get_ip_address_list() const;
	QList<QTcpSocket *> get_socket_list() const;
	void send_request() const;

public slots:
	void on_readyRead();
	void on_progress(int progress);
};

#endif // CLIENT_H
