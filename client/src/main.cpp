#include "main_window.h"
#include "program_setup.h"
#include "client.h"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	Main_window w;
	w.show();

	Program_setup program_setup;

	Client client(&w, program_setup.get_port(), program_setup.get_timeout(), program_setup.get_working_dir());
	client.send_request();

	return a.exec();
}
