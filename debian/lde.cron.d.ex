#
# Regular cron jobs for the lde package
#
0 4	* * *	root	[ -x /usr/bin/lde_maintenance ] && /usr/bin/lde_maintenance
