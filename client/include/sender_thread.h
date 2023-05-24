#ifndef SENDER_THREAD_H
#define SENDER_THREAD_H

#include "client.h"
#include "mainwindow.h"
#include <QThread>

class Sender_thread : public QThread {
	Q_OBJECT

private:
	MainWindow *window; // Client GUI
	const Client *client;

public:
	Sender_thread(MainWindow *window, const Client *client);
	virtual ~Sender_thread() override;
	void run() override;

signals:
	void progress(const int);
};

#endif // SENDER_THREAD_H
