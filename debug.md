# Debug Tips

**Cannot upload code to device - Port Busy**

https://askubuntu.com/questions/767505/cannot-access-adafruit-feather-32u4

    sudo systemctl stop ModemManager.service
    `upload_code`
    sudo systemctl start ModemManager.service

### Permanent Ficx

https://learn.adafruit.com/adafruit-arduino-ide-setup/linux-setup#udev-rules

    wget https://github.com/adafruit/Trinket_Arduino_Linux/raw/master/99-adafruit-boards.rules
    sudo mv 99-adafruit-boards.rules /etc/udev/rules.d/

Reload udev's rules

    sudo reload udev

If the command above fails, try instead running:

    sudo udevadm control --reload-rules
    sudo udevadm trigger

Add current user to the dialout group with

    sudo usermod -a -G dialout <user>
