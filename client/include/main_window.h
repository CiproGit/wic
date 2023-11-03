#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "about.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Main_window; }
QT_END_NAMESPACE

class Main_window : public QMainWindow {
	Q_OBJECT

private:
	Ui::Main_window *ui;
	About about;

	const QString ICON_FILE = ":/wic_client_icon.png";

public:
	Main_window(QWidget *parent = nullptr);
	~Main_window();
	void set_progressbar(int max) const; // It sets the maximum value of the progressbar with the given max
	void update_progressbar(int progress) const;
	void print_settings(QString string) const; // It appends the given string in the settings panel
	void print_console(QString string) const; // It appends the given string in the console panel

public slots:
	void show_about();
};
#endif // MAIN_WINDOW_H
