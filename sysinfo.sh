#!/bin/bash

# sysinfo_page - A scipt to produce HTML file 

######VARIABLES 
title="My System Information" 
RIGHT_NOW="$(date +"%x %r %Z")"
TIME_STAMP="Updated on $RIGHT_NOW by $USER"

######FUNCTIONS 

distribution_info()
{
	echo "<h2>Distribution  info</h2>"     
	echo "<p>"
	cat /etc/lsb-release.diverted | grep DISTRIB_DESCRIPTION
	echo "</p>"
}

kernel_info()
{
	echo "<h2>Kernel  info</h2>"     
	echo "<p>"
	uname -a | cut -d "#" -f 1
	echo "<p>"
}

memory()
{
	echo "<h2>Memory</h2>"
	echo "<p>"
	free
	echo "</p>"
}

diskDevices()
{
        echo "<h2>Disk Devices</h2>"
        echo "<p>"
        fdisk -l
        echo "</p>"
}

drive_space()
{
        echo "<h2>Filesystem space</h2>"
        echo "<pre>"
        df -h #provides a summary of the space used by all of the mounted file >
        echo "</pre>"

}

users()
{
	echo "<h2>Users</h2>"
	echo "<pre>"
#	for users in $(cat /etc/passwd | grep bash | cut -d":" -f 1); do users;  id $users; done 
	echo "</pre>"
}

show_uptime()
{
        echo "<h2>System uptime</h2>"
        echo "<pre>"
        uptime #dislpays length of time the system has been "up" (running) si>
        echo "</pre>"
}


home_space()
{
        echo "<h2>Home Directory space by user</h2>"
        echo "<pre>"
        echo "Bytes Directory" 
        # display this as a list, sorted in descending order by the amount of>
        du -s /home/* | sort -nr
        echo "<pre>"
}


######MAIN
cat <<- _EOF_
        <html>
        <head>
                <title>
                $title $HOSTNAME
                </title>
        </head>


       <body> 
        <h1> $title $HOSTNAME</h1>
        <p>$TIME_STAMP</p>
        $(distribution_info)
	$(kernel_info)
	$(memory)
	$(diskDevices)
	$(drive_space)
        $(show_uptime)
        $(home_space)
#	$(users)

        </body>
        </html>
_EOF_



