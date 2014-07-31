FAQ
===
This FAQ is copied from the [original](https://www.assembla.com/wiki/show/viewpoints/FAQs)


Viewpoints crashes on startup. Why?
-----------------------------------
Viewpoints may crash (or fail to display your data) if it tries to read a corrupt data file.  

If viewpoints starts up when given no input data, and if it can read and display the "sampledata.txt" file included in the distribution, then a mal-formed input data file is probably your problem.
If viewpoints crashes right away on startup given no input data, the most likely reason is your combination of machine + graphics hardware + graphics driver + openGL library does not support "openGL Vertex Buffer Objects" (VBOs).   Download and install the latest drivers and libraries for your graphics hardware and operating system from the graphics hardware vendor's website.  (Users running Apple OS X don't need to worry about this).
If your graphics drivers and openGL libraries are up to date and viewpoints still crashes on startup then tell viewpoints not to use VBOs.  Presently, the only way to do this is to run viewpoints ("vp") from the command line with the --no_vbo command line flag.  It would be good to enhance viewpoints to autodetect (lack of) VBO support.

Why does viewpoints only read 2 million lines from my input file?
-----------------------------------------------------------------
You must explicity tell viewpoints to read more than 2 million lines.  To do this, run viewpoints from the command line and specify the --npoints command line argument.  For example, if you want to read the first five million lines (sample points) from mybigfile.txt, use:
```vp --npoints=5000000 --input=mybigfile.txt```

Viewpoints renders large datasets very slowly.  Why?
----------------------------------------------------
Viewpoints is supposed to render large data sets quickly.  It does so using hardware acceleratated openGL graphics.  You must have graphics hardware drivers and openGL (and, on linux, X11) libraries for your machine which are mutually compatible and correctlty installed.  If you don't, then openGL will fall back to software rendering which is orders of magnitude slower for large data.  Download and install the latest drivers and libraries for your graphics hardware from the graphics hardware vendor's website.  Users running Apple OS X don't need to worry about this.
None of the menus seem to work when I run viewpoints on my mac.  Why?
---------------------------------------------------------------------
You may be running a very old release of viewpoints. Download a new one [here](https://www.assembla.com/wiki/show/viewpoints/downloads).  Or, you may be running an old version of Apple OS X.   Upgrade to OS X 10.5 or above.  Or try running viewpoints on a another mac with a more recent operating system. Viewpoints is no longer supported on Mac OS X versions older than 10.5

Can I get the source code for viewpoints?
-----------------------------------------
Yes you can.  Viewpoints has been released under the NASA Open Source Agreement.  You can browse the source code here.   The repository url is http://svn2.assembla.com/svn/viewpoints if you want to check out the code using subversion.

If you want to join the development team, great!  Please send a request to creon.levit@nasa.gov

How do I report a bug or request a feature?
-------------------------------------------
If you're on the viewpoints development team and/or you have a (free) assembla.com account, then create a ticket in the viewpoints space on assembla.com. Unfortunately you have to log into the viewpoints trac interface separately, but with your same assembla.com credentials.  (Assembla knows about this "usability issue").
If you're not on the development team, send bug reports and feature requests to creon.levit@nasa.gov.
If you want to join the development team, great!  Please send a request to creon.levit@nasa.gov.
