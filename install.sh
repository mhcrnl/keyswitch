cc src/main.c -o keyswitch.out `pkg-config --cflags --libs gtk+-3.0`
cp keyswitch.out /usr/local/bin/.
