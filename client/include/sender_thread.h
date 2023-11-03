#ifndef SENDER_THREAD_H
#define SENDER_THREAD_H

#include "client.h"
#include "main_window.h"
#include <QThread>

class Sender_thread : public QThread {
	Q_OBJECT

private:
    Main_window *window; // Client GUI
	const Client *client;

public:
        Sender_thread(Main_window *window, const Client *client);
	virtual ~Sender_thread() override;
	void run() override;

signals:
	void progress(const int);
};

#endif // SENDER_THREAD_H
