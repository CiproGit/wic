#include "mainwindow.h"
#include "client.h"
#include <QApplication>
#include <QSettings>

using namespace std;

const QString CONFIG_FILE = "./client_config.ini";

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	// Read port and timeout from settings file
	QSettings settings(CONFIG_FILE, QSettings::IniFormat);
	unsigned short port = static_cast<unsigned short>(settings.value("CLIENT/PORT", DEFAULT_PORT).toUInt());
	unsigned short timeout = static_cast<unsigned short>(settings.value("CLIENT/TIMEOUT", DEFAULT_TIMEOUT).toUInt());

	Client client(&w, port, timeout);
	client.send_request();

	return a.exec();
}
