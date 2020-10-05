#!/bin/bash

# Html Script
# brief  Our First Script of creating an html page to be viewed on a web server 
# author Luke E. Tatro
# Html script
# date 10/5/2020

# sysinfo_page - A scipt to produce HTML file 

######VARIABLES 
title="My System Information" 
RIGHT_NOW="$(date +"%x %r %Z")"
TIME_STAMP="Updated on $RIGHT_NOW by $USER"

######FUNCTIONS 

#brief:   Display the systems distribution info

distribution_info()
{
	echo "<h2>Distribution  info</h2>"     
	echo "<p>"
	cat /etc/lsb-release.diverted | grep DISTRIB_DESCRIPTION | cut -d  "=" -f 2
	echo "</p>"
}

#brief   Display the systems kernel 

kernel_info()
{
	echo "<h2>Kernel  info</h2>"     
	echo "<p>"
	uname -a | cut -d "#" -f 1
	echo "<p>"
}

#brief   Display the systems memory 

memory()
{
	echo "<h2>Memory</h2>"
	echo "<p>"
	free
	echo "</p>"
}

#brief   Display the disks on the system

diskDevices()
{
        echo "<h2>Disk Devices</h2>"
        echo "<p>"
        fdisk -l
        echo "</p>"
}

#brief   Display the systems drive space (used and available)

drive_space()
{
        echo "<h2>Filesystem space</h2>"
        echo "<pre>"
        df -h #provides a summary of the space used by all of the mounted file >
        echo "</pre>"

}

#brief   Display the systems users along with IDs and group IDs

users_info()
{
	echo "<h2>Users</h2>"
	echo "<pre>"
	for user in $(cat /etc/passwd | grep bash | cut -d":" -f 1); do echo  $user;  id $user; done 
	echo "</pre>"
}

#brief   Display the devices network information to include name, status, and ip address

network_info()
{
        echo "<h2>Network Information</h2>"
        echo "<pre>"
ip addr | grep 2: | cut -d ":" -f 2
ip addr | grep fq_codel | cut -d " " -f 9
hostname -I
        echo "</pre>"
}



#brief   Display how long the system has been up for

show_uptime()
{
        echo "<h2>System uptime</h2>"
        echo "<pre>"
        uptime #dislpays length of time the system has been "up" (running) si>
        echo "</pre>"
}

#brief   Display how much space is used by each user in the home directory

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
	$(users_info)
        $(network_info)
	$(show_uptime)
        $(home_space)

        </body>
        </html>
_EOF_




