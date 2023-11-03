#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "about.h"
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Main_window; }
QT_END_NAMESPACE

class Main_window : public QMainWindow {
	Q_OBJECT

private:
	Ui::Main_window *ui;
	QSystemTrayIcon tray_icon;
	About about;

	const QString ICON_FILE = ":/wic_server_icon.png";

private slots:
	void iconActivated(QSystemTrayIcon::ActivationReason reason);

protected:
	void closeEvent(QCloseEvent *event);

public:
        Main_window(QWidget *parent = nullptr);
        ~Main_window();
	void print_ip_addresses(QString string) const; // It appends the given string in the IP addresses panel
	void print_username(QString string) const; // It prints the given string in the username panel
	void print_settings(QString string) const; // It appends the given string in the settings panel
	void print_console(QString string) const; // It appends the given string in the console panel

public slots:
	void show_about();
	void quit();
};
#endif // MAIN_WINDOW_H
