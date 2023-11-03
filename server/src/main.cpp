#include "main_window.h"
#include "program_setup.h"
#include "server.h"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	Main_window w;

	Program_setup program_setup;

	Server server(&w, program_setup.get_ip_address(), program_setup.get_port());
	server.start_listening();

	return a.exec();
}
