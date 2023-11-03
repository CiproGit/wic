#ifndef SERVER_H
#define SERVER_H

#include "main_window.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Main_window; }
QT_END_NAMESPACE

class Server : public QObject {
	Q_OBJECT

private:
    Main_window *window; // Server GUI

	QString ip_address;
	unsigned short port;
	QTcpServer server;
	QTcpSocket *socket;

	QString username;

public:
        Server(Main_window *window, QString ip_address, unsigned short port);
	virtual ~Server();
	void start_listening();

public slots:
	void on_newConnection();
	void on_new_message();
};

#endif // SERVER_H
