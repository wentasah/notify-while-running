#include <libnotify/notify.h>
#include <signal.h>

void sighandler()
{ }

int main(int argc, char *argv[])
{
	notify_init (argv[0]);

	char *summary = (argc >= 2) ? argv[1] : argv[0];
	char *body = (argc >= 3) ? argv[2] : NULL;

	NotifyNotification * notification = notify_notification_new (summary, body, "dialog-information");
	notify_notification_set_timeout (notification, NOTIFY_EXPIRES_NEVER);
	notify_notification_show (notification, NULL);

	signal(SIGTERM, sighandler);
	signal(SIGHUP,  sighandler);
	signal(SIGINT,  sighandler);
	pause();

	notify_notification_close(notification, NULL);
	g_object_unref(G_OBJECT(notification));
	notify_uninit();

	return 0;
}
