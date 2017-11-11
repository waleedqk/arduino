# arduino

**Install the Arduino Software (IDE) on on Linux**

	https://www.arduino.cc/en/Guide/Linux
    
Extract the folder and place it at the dierised location

**Install the IDE**

    bash install.sh

or 

    ./install.sh

**Need Serial Port Permissions**

Open Terminal and type:

    ls -l /dev/ttyACM*

Change permission

	sudo chmod a+rw /dev/ttyACM0

add our user to the group

    sudo usermod -a -G dialout $USER
