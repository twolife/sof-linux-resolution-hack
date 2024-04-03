# SoF Resolution Hack

This is a small hack that allows you to play the original native Linux version of Soldier of Fortune (SoF), released in July 2000, in any resolution you want.

This code was originally found on https://dusted.dk/pages/sof-resolution/

## Requirements
Make sure you have a 32-bit capable C compiler.

You are most likely running a Linux distribution on a shiny 64 bits CPU, but the binaries you are trying to run are build for the classic 32 bits PC architecture. In the Debian/Ubuntu world, you will need to install the *gcc-multilib* package.

## Usage

Build the code:

    $ make

Go to your SoF directory and run the game:

    $ LD_PRELOAD=/path/to/ResHook.so SOF_WIDTH=1920 SOF_HEIGHT=1080 ./sof +set gl_mode 9

If you want another resolution, simply replace 1920 and 1080 with the width and height you want.

## Notes

- SoF has a fixed number of video mode available.
  The first (and default) mode is 3 (640x480), the last one is 9 (1600x1200).

- This hook enables the custom resolution on mode 9.

- Please bear in mind that while the game engine can cope with any resolution (it works great at 1440p),
  the menu is designed to be used with a 4:3 format.

