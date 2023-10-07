#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "about.h"
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
	Q_OBJECT

private:
	Ui::MainWindow *ui;
	QSystemTrayIcon tray_icon;
	About about;

	const QString ICON_FILE = ":/wic_server_icon.png";

private slots:
	void iconActivated(QSystemTrayIcon::ActivationReason reason);

protected:
	void closeEvent(QCloseEvent *event);

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	void print_ip_addresses(QString string) const; // It appends the given string in the IP addresses panel
	void print_username(QString string) const; // It prints the given string in the username panel
	void print_settings(QString string) const; // It appends the given string in the settings panel
	void print_console(QString string) const; // It appends the given string in the console panel

public slots:
	void show_about();
	void quit();
};
#endif // MAINWINDOW_H
