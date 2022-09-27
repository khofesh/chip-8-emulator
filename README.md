# CHIP-8 Emulator in C

## dependencies

```shell
sudo dnf install SDL2-devel SDL2_sound-devel SDL2_net-devel
```

## beep

we're using `toot` here. if you want to use `beep`, uncomment the `system("bee");` line, then install beep and configure `pcspkr` udev rule.

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

## checking in `main.c`

````clang
// chip8_screen_set(&chip8.screen, 10, 1);

/* check the memory */
// chip8_memory_set(&chip8.memory, 0x400, 'Z');
// printf("%c\n", chip8_memory_get(&chip8.memory, 0x400));

/* check the register */
// chip8.registers.V[0x0f] = 50;

/* check the stack */
// chip8.registers.SP = 0;
// chip8_stack_push(&chip8, 0xff);
// chip8_stack_push(&chip8, 0xaa);
// printf("%x\n", chip8_stack_pop(&chip8));
// printf("%x\n", chip8_stack_pop(&chip8));

/* check keyboard */
// chip8_keyboard_down(&chip8.keyboard, 0x0f);
// printf("%x\n", chip8_keyboard_map(keyboard_map, 0xff));
// bool is_down = chip8_keyboard_is_down(&chip8.keyboard, 0x0f);
// printf("%i\n", (int)is_down);

/* check delay timer and sound timer */
// chip8.registers.delay_timer = 255;
// chip8.registers.sound_timer = 255;

// chip8_load(&chip8, "hola mundo", sizeof("hola mundo"));

// chip8_screen_draw_sprite(&chip8.screen, 32, 30, &chip8.memory.memory[0x00], 5);
// chip8_exec(&chip8, 0x00E0);

// chip8_exec(&chip8, 0x1ff2);
// printf("%x\n", chip8.registers.PC);

/* check 3xkk - SE Vx, byte */
chip8.registers.PC = 0x00;
chip8.registers.V[0x00] = 0x22;
chip8_exec(&chip8, 0x3022);
printf("%x\n", chip8.registers.PC);

/* check 0x5000 */
    chip8.registers.PC = 0;
    chip8.registers.V[2] = 0x10;
    chip8.registers.V[3] = 0x10;
    chip8_exec(&chip8, 0x5230);
    printf("%x\n", chip8.registers.PC);

 // check 8xy0
    chip8.registers.V[0] = 0x20;
    chip8.registers.V[1] = 0x30;
    chip8_exec(&chip8, 0x8010);
    printf("%x\n", chip8.registers.V[0]);
 // check 8xy4 - ADD Vx, Vy
    chip8.registers.V[0] = 200;
    chip8.registers.V[1] = 50;
    chip8_exec(&chip8, 0x8014);
    printf("%i\n", chip8.registers.V[0]);
    printf("%i\n", chip8.registers.V[0x0f]);
// check Dxyn - DRW Vx, Vy, nibble
    chip8.registers.I = 0x00;
    chip8.registers.V[0] = 10;
    chip8.registers.V[1] = 10;
    chip8_exec(&chip8, 0xD005);
```

# References

- https://github.com/JamesGriffin/CHIP-8-Emulator (this one is written in C++)
- https://libsdl.org/
- http://devernay.free.fr/hacks/chip8/C8TECH10.HTM (**Important**)
- https://www.udemy.com/course/creating-a-chip-8-emulator-in-c/ (I have to convert it into linux)
- toot - https://github.com/vareille/toot
- users and groups management https://wiki.archlinux.org/title/users_and_groups
- https://stackoverflow.com/questions/10072909/beep-on-linux-in-c
````
