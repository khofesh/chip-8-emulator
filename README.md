# CHIP-8 Emulator in C

## dependencies

```shell
sudo dnf install SDL2-devel SDL2_sound-devel SDL2_net-devel
```

## beep

```shell
sudo dnf install beep

sudo vim /etc/udev/rules.d/70-pcspkr-beep.rules
sudo udevadm control --reload
sudo rmmod pcspkr
sudo modprobe pcspkr
```

https://wiki.archlinux.org/title/PC_speaker#Beep

a restart would help

**this doesn't work**

```shell
# chmod 4755 /usr/bin/beep
# chgrp beep /usr/bin/beep
# chmod 4750 /usr/bin/beep
# usermod -a -G beep fahmad
```

## hex editor

```shell
sudo dnf ghex
```

# References

- https://github.com/JamesGriffin/CHIP-8-Emulator (this one is written in C++)
- https://libsdl.org/
- http://devernay.free.fr/hacks/chip8/C8TECH10.HTM (**Important**)
- https://www.udemy.com/course/creating-a-chip-8-emulator-in-c/ (I have to convert it into linux)
- toot - https://github.com/vareille/toot
- users and groups management https://wiki.archlinux.org/title/users_and_groups
- https://stackoverflow.com/questions/10072909/beep-on-linux-in-c
