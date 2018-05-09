# ZNIX
ZNIX is an operating system that I am working on to further develop my low-level programming skills using C and Assembly to manipulate hardware very close to the metal. It currently only has a basic shell but I am hoping to add many advanced features in the future as I learn more about how an OS works.

*Note: Tutorials on building and working with ZNIX are currently only for people running Linux, I'll release instructions on how to build on other OSes in the future.*

#### Getting the files
Just incase you don't know how to get files from a Git repository, simply run this command in your terminal to download the ZNIX source:
`git clone https://github.com/ZakFarmer/ZNIX.git`
The source files will then be cloned into a directory called 'ZNIX'.
Simply do `cd ZNIX` and you can start working with the source.

#### Running ZNIX
To run ZNIX, you can either choose to emulate the OS without having to boot it directly or you can build an ISO image and then boot this on whatever (i386/x86) machine you'd like.

##### The emulation method
For ease of development, I use **QEMU** for emulating the kernel. This is what these instructions will tell you how to use as well.

Use your preferred package manager to install these dependencies:
`qemu`, `make`, `nasm`, `gcc`, `ld`


Then you'll need to get the source files so follow the instructions above to do that if you haven't done so already.

Now, run the following command:
`make`
If you don't know what Make is, it's basically a build system that makes working with lots of source files easy to deal with. I have set up the Makefile to launch the emulator after the kernel has been built. If you get any errors, make sure you have all the dependencies listed above. If not, you should now see a QEMU window with ZNIX booted up inside it. That's it, you're done.

##### The image method
This method is just as easy as the emulation method as I have included a rule in the Makefile for building an ISO image.

For this method, you'll need these dependencies:
`gcc`, `ld`, `nasm`, `grub`

Once you have those dependencies and you've got the ZNIX source files, simply run the following command in your terminal:
`make build`

If everything works successfully, you should now have a file called `znix.iso` in your ZNIX directory. You can burn this to a disc or create other bootable media with a tool such as UNetBootin and then boot the image on whichever compatible machine you'd like.

#### Developing ZNIX
If you would like to assist in the development of ZNIX, I'd be grateful for your help.

Simply follow one of the steps above to get a working development directory, then make your changes to the source files.

Any extra source files you make, remember to add rules for them to the Makefile if they need to be compiled/assembled/etc.

Thanks for taking an interest in this project
**___Zak___**

