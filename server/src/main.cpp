#include "mainwindow.h"
#include "server.h"
#include <QApplication>
#include <QSettings>

using namespace std;

const QString CONFIG_FILE = "./server_config.ini";

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;

	// Read IP address and port from settings file
	QSettings settings(CONFIG_FILE, QSettings::IniFormat);
	QString ip_address = settings.value("SERVER/IP_ADDRESS", DEFAULT_IP_ADDRESS).toString();
	unsigned short port = static_cast<unsigned short>(settings.value("SERVER/PORT", DEFAULT_PORT).toUInt());

	Server server(&w, port);
	server.start_listening(ip_address);

	return a.exec();
}
