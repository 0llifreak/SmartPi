#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{


	/*
	//Dieses C-Programm startet bei jedem Neustart des Raspberry s�mtliche Anwendungen
	//f�r den SmartPi, u.a. die Datenbankaufzeichnung (rrdtool) und die REST-API!!!
	//Wichtig:
	//Das C-Programm wird in der "crontab -e" gespeichert, wie folgt: @reboot sudo /home/pi/./smartpi_autostart &
	//Wichtig dabei ist, das man bei der Konfiguration unbedingt als pi@ angemeldet ist und nicht als root
	//Es wird n�mlich zwischen crontab als root und pi unterschieden!!!!
	*/

	mkdir("/run/SmartPi");//Erstelle Ordner f�r die rrd-datenbank

	system("sudo touch /run/SmartPi/Smartpi_Value.txt");//Erstelle Textdatei f�r die rrd-datenbank! //Da ich das Programm mit "sudo", also als "root" starte, kann ich die Textdatei auch nur �ffnen, wenn ich als "root" angemeldet bin!!!


	system("sudo nohup python /home/pi/webserver.py &");//Zuerst die REST-API
	
	

	system("sudo nohup python /home/pi/smartpi_web.py &");//Starte Datenbankaufzeichnung und Web-Frontend!!!

	//Info:
	//nohup: Das Programm l�uft im Hintergrund
	//&: Das C-Programm wird weiter abgearbeitet und wartet nicht bis der aktuelle Befehl abgearbeitet wird!


	
return 0;
}
