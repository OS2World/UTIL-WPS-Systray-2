____________________________________________________________

 Systray/2 1.0 alpha 4                          (15/08/2000)
____________________________________________________________
                                   Team OS/2 Russian project


 1. What is it?
 2. Description
 3. Tray API
 4. Known problems
 5. Sources
 6. Author, thanks and contacts





 1. What is it?

 Systray is what we deal with when we work with operating 
 systems Windows '95/98/NT. Actually besides task switcher 
 it is a convenient utility called system tray. 
 Tray is  a section of the screen assigned for the programs 
 not seen in the screen at the moment but active and performing 
 an operation which the user can control through the tray.
 It differs from task switcher in several aspects:

 The program that has its icon on the tray manages this icon 
 by itself. The user s manipulations over the program are sent 
 as a message to it and operate it through the pop-up menu.    

 The program gets the mechanism allowing to inform the user about 
 the process of performing an operation.  E.g. ReGet, ICQ, The Bat.



 2. Description of the program.


 2.1. Installation

 To install the program start script  install.cmd that 
 will create folder Systray/2, objects of the program 
 and documentation as well as Systray/2 shadow in 
 Startup folder.
 After that you can start object Systray with settings 
 by default (INI-file "systray2.ini").

 Attention: If you do not start Systray as an object 
 but EXE file you should indicate as a parameter either 
 INI-file of configuration (systray2.ini, as example) 
 or any other, if it does not exist it will be created).
 If the parameter is not indicated OS2.INI will be used 
 by default.


 2.2. Settings and options

 Main points of settings are unlikely to give rise to any 
 questions or problems and will be described in the 
 final documentation which will also contain a brief 
 description of base plug-in content Systray.dll. Plug-in 
 consist of units that are separate completed programs 
 able to function under Systray/2 management.

 A standard plug-in includes:

 SystrayClockClass  	shows the current time, one can 
                        indicate in settings:
			- displaying seconds;
			- displaying date;
			- 12-hours mode.

			Background of the clock window
 			and font used for displaying the time 
			can be changed by drag-and-drop from 
			the corresponding OS/2 palettes.
			
 
 SystrayToolbarClass	Toolbar, analogue of Launchpad or 
			Tray from WarpCenter Is used for 
      			customizable quick access bar to the 
			programs. This module settings allow to 
			- indicate which programs will be in the Toolbar';
			- their order;
			- start parameters and working directory					
			
 SystrayDiskMonitor	Free space on the disk monitor

SystraySwapMonitorClass Monitor of system swap-file

 SystrayClass		System tray for displaying and managing 
			working processes.

 SystrayTaskbarClass	Task switcher. Its settings:
			- not to show the icons of the 
			  processes (only names);
			- select the type of buttons of tasks 
			  (Warp4 or Warp3);
			- the size of buttons of tasks ("stretching"
			  to the width).

			Besides task switcher has filters and
			Can hide certain processes from the list 
			of tasks. The filters are set up both 
			from the settings window of the module 
			and by the right click on the processes.			 

			The right click on the task button can 
			also cancel its work (point "Close"). 
			

 It is not recommended to create more than one SystrayClass or 
 SystrayTaskbarClass object. 

 You can start several copies of systray simultaneously.



 3. Tray API.

 The  use of Tray API is shown in the example trayex.exe with 
 switched on tray. The example is rather simple. With the help 
 of Tray API a lot can be done, API documentation is finishing. 
 Meanwhile you can get the sources of the example. 



 4. Known problems.

 If you started version Systray alpha 1 before 
 delete keys HINI_USER_PROFILE\NewSystray from system registry (OS2.INI).
 You can do it with the help of REGEDIT2.



 5. Sources

 You can find the sources of System Tray exaple in Systray/2
 distribution ("Development" folder).

 In future (first beta), Systray/2 sources will be opened 
 under GPL license.



 6. Author, thanks and contacts.

 The main developer is me, Dmitry Zakharov,  MadInt13h at #OS2Russian.
 Special thanks to Konstantin Okounkov for the idea and kicks that 
 made me fulfill it. :).

 Contacts:

 Dmitry Zakharov (madint@os2.ru)	programming, design		      	
 Konstantin Okounkov (admin@os2.ru)	web-hosting, russian docs
 Irina Koudina (irink@os2.ru)		translation (readme, www)
 Vit Timchishin (tvv@os2.ru)		translation (dev.docs)

 Systray Homepage			http://os2.ru/projects/systray


____________________________________________________________
Systray/2 	Copyright (á) 1999-2000,   Team OS/2 Russian
Translated from Russian by Irina Koudina (irink@os2.ru)
