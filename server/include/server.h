#ifndef SERVER_H
#define SERVER_H

#include "mainwindow.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

const QString DEFAULT_IP_ADDRESS = "127.0.0.1";
const QString DEFAULT_PORT = "50000";

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Server : public QObject {
	Q_OBJECT

private:
	MainWindow *window; // Server GUI

	QString ip_address;
	unsigned short port;
	QTcpServer server;
	QTcpSocket *socket;

	QString username;

public:
	Server(MainWindow *window, unsigned short port);
	virtual ~Server();
	void start_listening(QString ip_address);

public slots:
	void on_newConnection();
	void on_new_message();
};

#endif // SERVER_H
