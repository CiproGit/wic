#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "about.h"
#include <QMainWindow>

const QString ICON_FILE = ":/wic_client_icon.png";

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
	Q_OBJECT

private:
	Ui::MainWindow *ui;
	About about;

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	void set_progressbar(int max) const; // It sets the maximum value of the progressbar with the given max
	void update_progressbar(int progress) const;
	void print_settings(QString string) const; // It appends the given string in the settings panel
	void print_console(QString string) const; // It appends the given string in the console panel

public slots:
	void show_about();
};
#endif // MAINWINDOW_H
