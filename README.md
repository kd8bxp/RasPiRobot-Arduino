# RasPiRobot V3f Board using Arduino

For this project I am using a Raspberry PI Zero W, the RasPiRobot v3f Board by MonkMakes.com (Simon Monk)  
https://github.com/simonmonk/raspirobotboard3  
This is still a work in progress, and I don't have everything working. But plan on adding at least the SWITCHES.  
This is not a library, it just some working examples.  IF your robot moves in the wrong direction you probably need to switch the motor wires.  
See Simon Monks github for troubleshooting right motor issues.  

## Installation

To use the Arduino IDE you need to install the Raspberry PI board Core from this project: https://github.com/me-no-dev/RasPiArduino  
This is an older project, I am not sure if it is still be supported or not. It does work, and it does work with the current Oct 2018 release of Raspbain Stretch.  
Follow the setup closely, when it you get the step.  
```  
sed -i "s/PermitRootLogin without-password/PermitRootLogin yes/" /etc/ssh/sshd_config  
```  

If you are using Stretch you need to edit the sshd_config manually,
Look for 
```
PermitRootLogin _something_  
```
you'll want to make sure that is commented out, and below it add  
```
PermitRootLogin yes  
```
  
IF you run into problems, I suggest looking at the issues on the repository, while this is an older project, I found the information to be very good.  

There are some limitations, the creator of RasPiArduino doesn't have any type of analogWrite,  I am using a bit-bang method, that seems to work, at times the robot does seem to studder a bit.  
Most of the libraries don't work, so you need to come up with your own methods, luckly most of this is easy to do.  

The Arduino project uses the same pin numbers that Simon Monk uses (GPIO numbers), I have included a couple of just pure tests C++ code samples (examples), using WiringPI with is using it's own pin numbers. And I've included a list of the pin numbers.  

## Things To Do

Make some more pure C++ examples (forward, backward, stop, ect).  
Finish out the rest of the motor code (Right Turn, Backward, ect)  

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## Support Me

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  
https://www.paypal.me/KD8BXP  

## Other Projects

https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  


## Credits

Copyright (c) 2018 LeRoy Miller

## License

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>
