VIEWPOINTS
==========

viewpoints is a fast interactive linked plotting of large multivariante data sets. Currently my build requires the use of `cmake` to build the code. The current build is working on Ubuntu 14.04.  **UNTESTED** on OS X or Windows.


>Viewpoints (vp) is a high-performance visualization and analysis tool for large, complex, multidimensional data sets. It allows interactive exploration of data in 100 or more dimensions with sample counts, or the number of points, exceeding 10^6 (up to 10^8 depending on available RAM). Viewpoints was originaly created for use with the extremely large data sets produced by current and future NASA space science missions, but it has been used for a wide variety of diverse applications ranging from aeronautical engineering, quantum chemistry, and computational fluid dynamics to virology, computational finance, and aviation safety.

[Paper](http://pubs.giss.nasa.gov/docs/2010/2010_Gazis_etal_1.pdf)

[Another Paper](http://www.academia.edu/2717234/Viewpoints_high_performance_visualization_for_large_high-dimensional_space_science_earth_science_and_engineering_data)

[Website](https://www.assembla.com/spaces/viewpoints/wiki/Home/)

[Original FAQ](https://www.assembla.com/spaces/viewpoints/wiki/FAQs)

Screenshots
-----------

The main window acts a simple mediator (it handles queuing or draw updates to the display windows, handles changing scales for drawing windows, handles generating histograms and then drawing).

![main window](https://raw.githubusercontent.com/kingtaurus/viewpoints/master/images/viewpoints-main-window.png)

Data Display Windows
--------------------

![viewpoints display window #2](https://raw.githubusercontent.com/kingtaurus/viewpoints/master/images/viewpoints-display-2.png)
![viewpoints display window #3](https://raw.githubusercontent.com/kingtaurus/viewpoints/master/images/viewpoints-display-3.png)

Data Distplay Window (with selection)
-------------------------------------

![viewpoints display window #2](https://raw.githubusercontent.com/kingtaurus/viewpoints/master/images/viewpoints-display-2-selection.png)
![viewpoints display window #3 selection](https://raw.githubusercontent.com/kingtaurus/viewpoints/master/images/viewpoints-display-3-selection.png)

Movies
------
**NONE YET**

Getting the code
----------------
So, to get the code you have to do the following:

```
git clone https://github.com/kingtaurus/viewpoints
cd viewpoints
git submodule init
git submodule update
```

To do an update (assuming you are on the master branch):
```
git pull
git submodule update
```
then re-run `make` within a build directory;

Dependency
==========

 * blitz++
 * OpenGL and GLUT
 * root-system (root.cern.ch)
 * boost       (specifically boost serialize)
 * C++11       (nullptr, std::shared_ptr)
 * FLTK 1.3    (www.fltk.org)
 * CFITSIO     (Flexible Image Transport System)
 * GSL         (GNU Scientific Library)
 * cmake       (current build system)

Ubuntu (and other Debian Derivatives)
-------------------------------------

```
sudo apt-get --install-suggests install libblitz0-dev libboost1.55-all-dev \
libfltk1.3-dev root-system-bin libroot-tree-dev libcfitsio3-dev \
libgsl0-dev g++-4.8 gfortran libxcb-xinerama0-dev libxinerama-dev \
libgl-dev libgl1-mesa-dev libgl1-mesa-glx-dev libglu-dev libglu1-mesa-dev \
libxft2-dev libgl1-mesa-dri-experimental freeglut3-dev cmake \
libroot-graf3d-g3d-dev libroot-math-physics-dev \
libroot-graf2d-postscript-dev libroot-core-dev
```

Mac OS X (10.9)
---------------
Ports:
```
sudo port install blitz freeglut cmake root5 fltk cfitsio boost gsl
```

Brew:
```
sudo brew install blitz freeglut cmake homebrew/science/root fltk cfitsio boost gsl
```


Build
=====

This is a fork of https://www.assembla.com/wiki/show/viewpoints (original github repository jblomo/viewpoints). The build proceedure has been updated. Original used a makefile to build. This revision now use cmake to correctly find dependencies and link against them. Further Fl_flews (a custom FLTK widget librarty is included as a submodule). From the project root directory (pick a release type):

```
mkdir -p build/gcc/
cd build/gcc/
cmake ../.. -DCMAKE_BUILD_TYPE=(DEBUG|RELEASE)
make all
```

This will end up building all the necessary libraries and exectubles.

```
CC=clang CXX=clang++ cmake ../.. -DCMAKE_BUILD_TYPE=RELEASE
CC=gcc   CXX=g++     cmake ../.. -DCMAKE_BUILD_TYPE=RELEASE
```

If it builds,

```
./vp ../../sample_data/sampledata.txt 
```

This is some biometric data that was originally provided for testing viewpoint; The data is originally, according the header: *Mörchen, F., Ultsch, A., Hoos, O.*; Extracting interpretable muscle activation patterns with Time Series Knowledge Mining; **International Journal of Knowledge-Based & Intelligent Engineering Systems** (2005). All the data views are selection connected 2d scatter plots.
* Click on any of the 4 plots to select it (or clink on the desired tab at the top of the control panel)
* Using the plot buttons (and its associated drop down menu) select which variable to plot.
* At the lower section of the control panel are multi-coloured tabs. Default colour for data points is red. However if you select a portion of the graph you can colour them in some other hue. Viewpoints defaults to blue for selection.
* Once you've selected a region (hold the shift key and click-hold on the region and drag it to some other location); the other plot windows will show which points are now with in the selection region.


Other Work
==========

BaBar
=====
The following work (and sample files are due to M. Bellis) [M. Bellis Viewpoints Website](http://web.stanford.edu/group/burchat/cgi-bin/bellis_mediawiki/index.php/Viewpoints_NASA)

Converted Photons
-----------------

```./vp --np=500000 ../../sample_data/converted_photons.txt```

* Converted Photons [original file](http://www.slac.stanford.edu/~bellis/viewpoints/converted_photons.txt)
* Suggested by Steve Sekula
* Added file to the repository in [updated file](sample_data/converted_photons.txt)
* Photons can convert to an electron-positron pair via interaction with the material.
* Tracking these electron and positrons back to the creation center, we can then produce an image of the SVT (silicon vertex tracker) which surrounds the interaction region.
  1. Using the first plot. Try plotting x-position vs. y-position vs. z-position. Using the **rotate** slider you can see the structure of the material around the interaction point.
  2. In the upper part of the main control panel, attempt to adjust the **lumin**.
  3. Select the *red* tab on the lower part of the control panel. Adjust **lum1** and **lum2** to highlight different features of the SVT (look for the beam pipe, 5 different layers of the SVT).


Some Notes (DEPENDENCY INFO, ....)
==========

fl_flews
--------
Dynamic Link Dependency (removing debugging libraries):
```
ldd testflews  | cut -f2 -d'>'  | cut -f1 -d'(' | sort | xargs -n1 apt-file search | cut -f1 -d: | sort | uniq 
libc6
libexpat1
libfontconfig1
libfreetype6
libgcc1
libstdc++6
libx11-6
libxau6
libxcb1
libxdmcp6
libxext6
libxft2
libxinerama1
libxrender1
zlib1g
```

So, using `apt-rdepends` or `apt-cache depends` on the following :

```
for x in libc6 libexpat1 libfontconfig1 libfreetype6 libgcc1 libstdc++6 \
libx11-6 libxau6 libxcb1 libxdmcp6 libxext6 libxft2 libxinerama1 \
libxrender1 zlib1g; 
do 
  echo "${x}"; echo "`apt-cache depends ${x} | grep Depend | cut -f 2 -d: | grep -v multiarch-support `"; 
done
libc6
 libgcc1
libexpat1
 libc6
libfontconfig1
 libc6
 libexpat1
 libfreetype6
 fontconfig-config
libfreetype6
 libc6
 zlib1g
libgcc1
 gcc-4.8-base
 libc6
libstdc++6
 gcc-4.8-base
 libc6
 libgcc1
libx11-6
 libc6
 libxcb1
 libx11-data
libxau6
 libc6
libxcb1
 libc6
 libxau6
 libxdmcp6
libxdmcp6
 libc6
libxext6
 libc6
 libx11-6
libxft2
 libc6
 libfontconfig1
 libfreetype6
 libx11-6
 libxrender1
libxinerama1
 libc6
 libx11-6
 libxext6
libxrender1
 libc6
 libx11-6
zlib1g
 libc6
```

 **1** So (notice `libc6` is a dependency on all, it can be removed - along with `libgcc1`);
```
libexpat1
libfontconfig1
 libexpat1
 libfreetype6
 fontconfig-config
libfreetype6
 zlib1g
libstdc++6
 gcc-4.8-base
libx11-6
 libxcb1
 libx11-data
libxau6
libxcb1
 libxau6
 libxdmcp6
libxdmcp6
libxext6
 libx11-6
libxft2
 libfontconfig1
 libfreetype6
 libx11-6
 libxrender1
libxinerama1
 libx11-6
 libxext6
libxrender1
 libx11-6
zlib1g
```
 **2** Substitute each dependency list inplace;
```
libstdc++6
libxft2
 libfontconfig1
 libexpat1
 libfreetype6
 zlib1g
 fontconfig-config
 libfreetype6
 libx11-6
 libxrender1
 libx11-6
 libxcb1
 libxau6
 libxdmcp6
 libx11-data
libxinerama1
 libx11-6
 libxcb1
 libx11-data
 libxext6
 libx11-6
 libxcb1
 libxau6
 libxdmcp6
 libx11-data
```
 **3** Grab top level packages.
```
libstdc++6
libxft2
libxinerama1
``` 

To get the static link Dependency (from the cmake fl\_flews build directory BUILD\_DIR/fl_flews/src and ignoring fltk1.1):
```
make clean && make all VERBOSE=1 | tr ' ' '\n' | grep -v home | grep -v ^-D | grep -v ^-W | grep -v ^-I | grep -v ^-L | grep lib
/usr/lib/x86_64-linux-gnu/libfltk.a
/usr/lib/x86_64-linux-gnu/libfltk_gl.a
/usr/lib/x86_64-linux-gnu/libfltk_forms.a
/usr/lib/x86_64-linux-gnu/libfltk_images.a
```
**OR**
```
libfltk1.3-dev
```

So the full list for fl_flews dependencies becomes,
```
libstdc++6 libxft2 libxinerama1 libfltk1.3-dev
```
**NOTE** `libfltk1.3-dev` suggests/depends on `libstdc++6`, `libxft2`, `libxinerama1`

Library Dependency
------------------
To get the static link Dependency (from cmake viewpoints build director BULD\_DIR/src and ignoring fltk1.1):
```
make clean && make -j2 all VERBOSE=1 2>&1 | tr ' ' '\n'  | grep -v home | grep -v ^-D | grep -v ^-W | grep -v ^-I | grep -v ^-L | grep lib
../fl_flews/src/libflews.a
/usr/lib/x86_64-linux-gnu/libfltk_images.a
/usr/lib/x86_64-linux-gnu/libfltk_forms.a
/usr/lib/x86_64-linux-gnu/libfltk_gl.a
/usr/lib/x86_64-linux-gnu/libfltk.a
```
**OR**
```
libfltk1.3-dev
```

To get the list of libraries that are dynamically loaded when calling viewpoints:
```
ldd vp | cut -f1 -d= | grep -v ld-linux
	linux-vdso.so.1 
	libGL.so.1 
	libX11.so.6 
	libXext.so.6 
	libGLU.so.1 
	libgsl.so.0 
	libgslcblas.so.0 
	libm.so.6 
	libcfitsio.so.3 
	libboost_serialization.so.1.55.0 
	libCore.so.5.34 
	libRIO.so.5.34 
	libTree.so.5.34 
	libdl.so.2 
	libXft.so.2 
	libfontconfig.so.1 
	libXinerama.so.1 
	libstdc++.so.6 
	libgcc_s.so.1 
	libpthread.so.0 
	libc.so.6 
	libglapi.so.0 
	libXdamage.so.1 
	libXfixes.so.3 
	libX11-xcb.so.1 
	libxcb-glx.so.0 
	libxcb-dri2.so.0 
	libxcb.so.1 
	libXxf86vm.so.1 
	libdrm.so.2 
	libz.so.1 
	liblzma.so.5 
	libpcre.so.3 
	libCint.so.5.34 
	libThread.so.5.34 
	libNet.so.5.34 
	libfreetype.so.6 
	libXrender.so.1 
	libexpat.so.1 
	libXau.so.6 
	libXdmcp.so.6 
	libMathCore.so.5.34 
	libcrypto.so.1.0.0 
	libssl.so.1.0.0
```

To get the list of packages that vp depends on:
```
ldd vp | cut -f2 -d'>' | cut -f1 -d'(' | sort | sed 's/[ \t]//g' | xargs -n1 apt-file search 
libc6: /lib64/ld-linux-x86-64.so.2
libssl1.0.0: /lib/x86_64-linux-gnu/libcrypto.so.1.0.0
libssl1.0.0-dbg: /usr/lib/debug/lib/x86_64-linux-gnu/libcrypto.so.1.0.0
libc6: /lib/x86_64-linux-gnu/libc.so.6
libc6: /lib/x86_64-linux-gnu/libdl.so.2
libexpat1: /lib/x86_64-linux-gnu/libexpat.so.1
libexpat1: /lib/x86_64-linux-gnu/libexpat.so.1.6.0
libgcc1: /lib/x86_64-linux-gnu/libgcc_s.so.1
libgcc1-dbg: /usr/lib/debug/lib/x86_64-linux-gnu/libgcc_s.so.1
liblzma5: /lib/x86_64-linux-gnu/liblzma.so.5
liblzma5: /lib/x86_64-linux-gnu/liblzma.so.5.0.0
libc6: /lib/x86_64-linux-gnu/libm.so.6
libpcre3: /lib/x86_64-linux-gnu/libpcre.so.3
libpcre3: /lib/x86_64-linux-gnu/libpcre.so.3.13.1
libpcre3-dbg: /usr/lib/debug/lib/x86_64-linux-gnu/libpcre.so.3.13.1
libc6: /lib/x86_64-linux-gnu/libpthread.so.0
libssl1.0.0: /lib/x86_64-linux-gnu/libssl.so.1.0.0
libssl1.0.0-dbg: /usr/lib/debug/lib/x86_64-linux-gnu/libssl.so.1.0.0
zlib1g: /lib/x86_64-linux-gnu/libz.so.1
zlib1g: /lib/x86_64-linux-gnu/libz.so.1.2.8
libboost-serialization1.55.0: /usr/lib/libboost_serialization.so.1.55.0
libgsl0-dbg: /usr/lib/debug/usr/lib/libgslcblas.so.0.0.0
libgsl0ldbl: /usr/lib/libgslcblas.so.0
libgsl0ldbl: /usr/lib/libgslcblas.so.0.0.0
libgsl0-dbg: /usr/lib/debug/usr/lib/libgsl.so.0.17.0
libgsl0ldbl: /usr/lib/libgsl.so.0
libgsl0ldbl: /usr/lib/libgsl.so.0.17.0
libcfitsio3: /usr/lib/x86_64-linux-gnu/libcfitsio.so.3
libcfitsio3: /usr/lib/x86_64-linux-gnu/libcfitsio.so.3.310
libcfitsio3-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libcfitsio.so.3.310
libroot-core5.34: /usr/lib/x86_64-linux-gnu/libCint.so.5.34
libroot-core5.34: /usr/lib/x86_64-linux-gnu/libCore.so.5.34
libdrm2: /usr/lib/x86_64-linux-gnu/libdrm.so.2
libdrm2: /usr/lib/x86_64-linux-gnu/libdrm.so.2.4.0
libfontconfig1: /usr/lib/x86_64-linux-gnu/libfontconfig.so.1
libfontconfig1: /usr/lib/x86_64-linux-gnu/libfontconfig.so.1.7.0
libfreetype6: /usr/lib/x86_64-linux-gnu/libfreetype.so.6
libfreetype6: /usr/lib/x86_64-linux-gnu/libfreetype.so.6.10.1
libglapi-mesa: /usr/lib/x86_64-linux-gnu/libglapi.so.0
libglapi-mesa: /usr/lib/x86_64-linux-gnu/libglapi.so.0.0.0
libglapi-mesa-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libglapi.so.0.0.0
libglu1-mesa: /usr/lib/x86_64-linux-gnu/libGLU.so.1
libglu1-mesa: /usr/lib/x86_64-linux-gnu/libGLU.so.1.3.1
libroot-math-mathcore5.34: /usr/lib/x86_64-linux-gnu/libMathCore.so.5.34
libroot-net5.34: /usr/lib/x86_64-linux-gnu/libNet.so.5.34
libroot-io5.34: /usr/lib/x86_64-linux-gnu/libRIO.so.5.34
libstdc++6: /usr/lib/x86_64-linux-gnu/libstdc++.so.6
libstdc++6: /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.18
libstdc++6-4.8-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.18
libstdc++6-4.8-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.18-gdb.py
libroot-core5.34: /usr/lib/x86_64-linux-gnu/libThread.so.5.34
libroot-tree5.34: /usr/lib/x86_64-linux-gnu/libTree.so.5.34
libx11-6: /usr/lib/x86_64-linux-gnu/libX11.so.6
libx11-6: /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0
libx11-6-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libX11.so.6.3.0
libx11-xcb1: /usr/lib/x86_64-linux-gnu/libX11-xcb.so.1
libx11-xcb1: /usr/lib/x86_64-linux-gnu/libX11-xcb.so.1.0.0
libx11-xcb1-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libX11-xcb.so.1.0.0
libxau6: /usr/lib/x86_64-linux-gnu/libXau.so.6
libxau6: /usr/lib/x86_64-linux-gnu/libXau.so.6.0.0
libxau6-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libXau.so.6.0.0
libxcb-dri2-0: /usr/lib/x86_64-linux-gnu/libxcb-dri2.so.0
libxcb-dri2-0: /usr/lib/x86_64-linux-gnu/libxcb-dri2.so.0.0.0
libxcb-glx0: /usr/lib/x86_64-linux-gnu/libxcb-glx.so.0
libxcb-glx0: /usr/lib/x86_64-linux-gnu/libxcb-glx.so.0.0.0
libxcb1: /usr/lib/x86_64-linux-gnu/libxcb.so.1
libxcb1: /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0
libxdamage1: /usr/lib/x86_64-linux-gnu/libXdamage.so.1
libxdamage1: /usr/lib/x86_64-linux-gnu/libXdamage.so.1.1.0
libxdamage1-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libXdamage.so.1.1.0
libxdmcp6: /usr/lib/x86_64-linux-gnu/libXdmcp.so.6
libxdmcp6: /usr/lib/x86_64-linux-gnu/libXdmcp.so.6.0.0
libxdmcp6-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libXdmcp.so.6.0.0
libxext6: /usr/lib/x86_64-linux-gnu/libXext.so.6
libxext6: /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0
libxext6-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libXext.so.6.4.0
libxfixes3: /usr/lib/x86_64-linux-gnu/libXfixes.so.3
libxfixes3: /usr/lib/x86_64-linux-gnu/libXfixes.so.3.1.0
libxft2: /usr/lib/x86_64-linux-gnu/libXft.so.2
libxft2: /usr/lib/x86_64-linux-gnu/libXft.so.2.3.1
libxft2-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libXft.so.2.3.1
libxinerama1: /usr/lib/x86_64-linux-gnu/libXinerama.so.1
libxinerama1: /usr/lib/x86_64-linux-gnu/libXinerama.so.1.0.0
libxinerama1-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libXinerama.so.1.0.0
libxrender1: /usr/lib/x86_64-linux-gnu/libXrender.so.1
libxrender1: /usr/lib/x86_64-linux-gnu/libXrender.so.1.3.0
libxrender1-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/libXrender.so.1.3.0
libxxf86vm1: /usr/lib/x86_64-linux-gnu/libXxf86vm.so.1
libxxf86vm1: /usr/lib/x86_64-linux-gnu/libXxf86vm.so.1.0.0
libgl1-mesa-glx: /usr/lib/x86_64-linux-gnu/mesa/libGL.so.1
libgl1-mesa-glx: /usr/lib/x86_64-linux-gnu/mesa/libGL.so.1.2.0
libgl1-mesa-glx-dbg: /usr/lib/debug/usr/lib/x86_64-linux-gnu/mesa/libGL.so.1.2.0

```

List of all possible packages sorted (and uniq):
```
ldd vp | cut -f2 -d'>' | cut -f1 -d'(' | sort | sed 's/[ \t]//g' | xargs -n1 apt-file search | cut -f1 -d: | sort | uniq
libboost-serialization1.55.0
libc6
libcfitsio3
libcfitsio3-dbg
libdrm2
libexpat1
libfontconfig1
libfreetype6
libgcc1
libgcc1-dbg
libgl1-mesa-glx
libgl1-mesa-glx-dbg
libglapi-mesa
libglapi-mesa-dbg
libglu1-mesa
libgsl0-dbg
libgsl0ldbl
liblzma5
libpcre3
libpcre3-dbg
libroot-core5.34
libroot-io5.34
libroot-math-mathcore5.34
libroot-net5.34
libroot-tree5.34
libssl1.0.0
libssl1.0.0-dbg
libstdc++6
libstdc++6-4.8-dbg
libx11-6
libx11-6-dbg
libx11-xcb1
libx11-xcb1-dbg
libxau6
libxau6-dbg
libxcb1
libxcb-dri2-0
libxcb-glx0
libxdamage1
libxdamage1-dbg
libxdmcp6
libxdmcp6-dbg
libxext6
libxext6-dbg
libxfixes3
libxft2
libxft2-dbg
libxinerama1
libxinerama1-dbg
libxrender1
libxrender1-dbg
libxxf86vm1
zlib1g

```

So, now taking the above list (and remove debugging versions - at least for now),
```
libboost-serialization1.55.0
libc6
libcfitsio3
libdrm2
libexpat1
libfontconfig1
libfreetype6
libgcc1
libgl1-mesa-glx
libglapi-mesa
libglu1-mesa
libgsl0ldbl
liblzma5
libpcre3
libroot-core5.34
libroot-io5.34
libroot-math-mathcore5.34
libroot-net5.34
libroot-tree5.34
libssl1.0.0
libstdc++6
libx11-6
libx11-xcb1
libxau6
libxcb1
libxcb-dri2-0
libxcb-glx0
libxdamage1
libxdmcp6
libxext6
libxfixes3
libxft2
libxinerama1
libxrender1
libxxf86vm1
zlib1g
```

So the list is,

```
libboost-serialization1.55.0 libc6 libcfitsio3 libdrm2 libexpat1 libfontconfig1 libfreetype6 libgcc1 libgl1-mesa-glx libglapi-mesa libglu1-mesa libgsl0ldbl liblzma5 libpcre3 libroot-core5.34 libroot-io5.34 libroot-math-mathcore5.34 libroot-net5.34 libroot-tree5.34 libssl1.0.0 libstdc++6 libx11-6 libx11-xcb1 libxau6 libxcb1 libxcb-dri2-0 libxcb-glx0 libxdamage1 libxdmcp6 libxext6 libxfixes3 libxft2 libxinerama1 libxrender1 libxxf86vm1 zlib1g
```


```
for x in libboost-serialization1.55.0 libc6 libcfitsio3 \
libdrm2 libexpat1 libfontconfig1 libfreetype6 libgcc1 \
libgl1-mesa-glx libglapi-mesa libglu1-mesa libgsl0-dbg \
libgsl0ldbl liblzma5 libpcre3 libroot-core5.34 libroot-io5.34 \
libroot-math-mathcore5.34 libroot-net5.34 libroot-tree5.34 \
libssl1.0.0 libstdc++6 libx11-6 libx11-6-dbg libx11-xcb1 \
libxau6 libxcb1 libxcb-dri2-0 libxcb-glx0 libxdamage1 libxdmcp6 \
libxext6 libxfixes3 libxft2 libxinerama1 libxrender1 \
libxxf86vm1 zlib1g; 
do 
	echo ${x}; 
	apt-cache depends ${x} | grep Depends: | grep -v Pre | grep -v multiarch-support
done
```

Returns:
```
libboost-serialization1.55.0
  Depends: libstdc++6
libcfitsio3
  Depends: libc6
libexpat1
libfontconfig1
  Depends: libexpat1
  Depends: libfreetype6
  Depends: fontconfig-config
libfreetype6
libgl1-mesa-glx
  Depends: libdrm2
  Depends: libglapi-mesa
  Depends: libx11-6
  Depends: libx11-xcb1
  Depends: libxcb-dri2-0
  Depends: libxcb-glx0
  Depends: libxcb1
  Depends: libxdamage1
  Depends: libxext6
  Depends: libxfixes3
  Depends: libxxf86vm1
libglapi-mesa
libglu1-mesa
  Depends: libgl1-mesa-glx
  Depends: <libgl1>
  Depends: libstdc++6
libgsl0ldbl
liblzma5
libpcre3
libroot-core5.34
  Depends: root-system-common
  Depends: libgcc1
  Depends: liblzma5
  Depends: libpcre3
  Depends: libstdc++6
libroot-io5.34
  Depends: libroot-core5.34
  Depends: libstdc++6
libroot-math-mathcore5.34
  Depends: libroot-core5.34
  Depends: libstdc++6
libroot-net5.34
  Depends: libroot-core5.34
  Depends: libroot-io5.34
  Depends: libroot-math-mathcore5.34
  Depends: libssl1.0.0
  Depends: libstdc++6
libroot-tree5.34
  Depends: libroot-core5.34
  Depends: libroot-io5.34
  Depends: libroot-net5.34
  Depends: libstdc++6
libssl1.0.0
 |Depends: debconf
  Depends: <debconf-2.0>
libstdc++6
  Depends: libgcc1
libx11-6
  Depends: libxcb1
  Depends: libx11-data
libx11-6-dbg
  Depends: libx11-6
libx11-xcb1
libxau6
libxcb1
  Depends: libxau6
  Depends: libxdmcp6
libxcb-dri2-0
  Depends: libxcb1
libxcb-glx0
  Depends: libxcb1
libxdamage1
  Depends: libx11-6
libxdmcp6
libxext6
  Depends: libx11-6
libxfixes3
  Depends: libx11-6
libxft2
  Depends: libfontconfig1
  Depends: libfreetype6
  Depends: libx11-6
  Depends: libxrender1
libxinerama1
  Depends: libx11-6
  Depends: libxext6
libxrender1
  Depends: libx11-6
libxxf86vm1
  Depends: libx11-6
  Depends: libxext6
```

Reduces to:

```
libboost-serialization1.55.0
libcfitsio3
libgl1-mesa-glx
libglu1-mesa
libgsl0ldbl
libroot-tree5.34
libxft2
libxinerama1
```

Noting that `libfltk1.3-dev` depends on `libgl1-mesa-glx`,`libxft2`, and `libxinerama1`. We get the minimal library dependency as,

```
libboost-serialization1.55.0 libcfitsio3 libglu1-mesa libgsl0ldbl libroot-tree5.34-dev libfltk1.3-dev
```


Original README follows:
------------------------

Creon Levit <Creon.Levit@nasa.gov>   and    Paul Gazis <Paul.R.Gazis@nasa.gov>

Preface:

Please let us know how viewpoints helps you. Did it enable you to solve a
problem?  To make a discovery?  To find an error?  To generate a figure for 
a paper?  The more we know that viewpoints is useful, the more time we'll 
spend working on it.  


Overview:

Each archive on this site contains the  viewpoints (vp) executable, 
documentation, a sample data file with examples, and for MS Windows, any 
dynamic link libraries (dlls) that may be required by the package.  The 
contents of these archives are listed below:

File                Comments
-----------------------------------------------------------------
README              This documentation file
vp.exe              viewpoints executable (MS windows only)
vp.ico              viewpoints icon (MS windows only)
vp                  viewpoints executable (linux only)
viewpoints.app      application bundle (Mac OS X only, see below)
vp_help_manual.htm  HTML help manual
sampledata.txt      sample data
libgsl.dll          DLL library for GSL (Windows only)
libgslcblas.dll     DLL for GSL CBLAS (Windows only)
OglExt.dll          DLL for OGL Extension Library (Windows only)


Installation:

Unpack these files into a target directory, then either click on the 'vp' 
icon or run the code from the command line as described below.

Data Organization and Format:

Viewpoints can read and write data from ASCII or binary files.  ASCII files 
consist of zero of more header lines, indicated by comment characters '!#&%', 
followed by a data block.  The data block is assumed to consist of a line of 
column labels followed by successive lines of data.  Words in the data block 
can be delimited by whitespace or some user-defined character.  Binary files
conists of a line of column label information followed by a block of binary
data in row- or column-major format.  Note that the line of column labels 
must NOT be preceded by a comment character unless they are specified by the
user to be part of the header.

Data can also be read directly from the input line using the --stdin command
line option described below.  This allows piping on systems that support it,
which allows the user to use a wide variety of third-party applications to
read or process different data formats such as FITS, CDF, etc.

FITS files: Viewpoints now has limited ability to read and write FITS files.  
When asked to read a FITS file, viewpoints will search for the first ASCII 
table extension, attempt to read it, and restore the existing data if 
unsuccessful.  When asked to write to a FITS file, it will create a new file, 
overwriting and destroying any original of the same name, and write the data 
to a single ASCII table extension in that file.  This FITS i/o capability is 
still under development and will be expanded in future revisions.

Configuration Files:

Viewpoints can save configuration information, such as axis and brush 
settings, window positions, and the name of the last input or output data 
file, to a configuration file for later reuse.  This is equivalent to saving
a snapshot of the work session.  Note that this process does not save the 
actual data or selection information itself!  If it did, this could lead to 
unnecessary duplication of the data files.  For this reason, the user must 
save any new or modified data they wish to associate with a configuration 
before they save that configuration.

Saved configurations can be loaded with or without reading their associated 
input file.  When this happens, viewpoints will attempt to use the axis
indices described in the configuration file (e.g., if the configuration
used axes 1, 2, 6, 7, and 10, viewpoints will attempt to display the
corresponding columns in the current data file).

Configuration files are saved in XML format for ease of display, but these
are not treated as conventional XML files.  In particular, due to limitations
of the BOOST serialization library, the contents of these files are order
dependant.  For this reason, any attempts to edit them should be performed
with extreme caution.

Usage:

In its current form (Version 2.2.4, build 258) 'viewpoints' is run either by 
clicking on the 'vp' icon or from the command line in the directory in which 
it has been installed or to which a path is available.  When viewpoints is 
run from the icon, it will come up with an array of default data.  When it is
run from the command line, the user must specify the input data file 
explicitly.

Apple OS X: to run viewpoints from the command line, you will probably want 
to create a shell alias to the actual executable, which is located inside the 
application bundle.  For example, if you dragged the viewpoints application 
"viewpoints.app" to your /Applications folder, then you will probably want to 
add the following to your .cshrc file (assuming you are using csh or tcsh as 
your shell):

 alias vp  /Applications/viewpoints.app/Contents/MacOS/viewpoints

A symbolic link will not work.  Use a shell alias.

If you don't care about running it from the command line, ignore the above.  
You can just double-click on the viewpoints.app icon to start it up.


The invocation for the command line version is:

 vp [optional arguments] [optional inputfile]

 the optional arguments are:
    
  --format=ascii (default) [shortcut: -f a] 
    Read an ASCII input file that consists of a header block followed by a
    data block.  Lines in the header block are indicated by one the comment 
    characters '!', '#', or '%'.  In the absence of comment characters, the 
    header block is assumed to consist of a number of lines specified by the 
    '--skip_header' command below, with a default value of 0 lines.  The 
    first line of the data block contains the attribute names.  By default,
    this is not preceeded by a comment character and is delimited by
    whitespace, but this can be controlled from the main menu or by command
    line arguments (see --delimiter, below).  Successive lines in the data
    block contain the numeric attribute values for successive samples, 
    delimited by the delimiter character.  See the file "sampledata.txt" for 
    an example.

  --format=binary [shortcut: -f b]
    Read a binary input file.  For files that don't contain ASCII values, 
    the first record be a header that consists of a tab-delimited line of 
    ASCII attribute names ending with a newline (\n).  This will be followed 
    by a contiguous block that contains a table of binary floating point 
    values.  For files that contain ASCII values, the header will consist a
    succession of lines of ASCII text that describe the contents and provide
    ASCII lookup tables, if any, for each column of data.
    
  --format=fits [shortcut: -f f]
    Read the first ASCII table from a FITS file.  If no ASCII table is found,
    routine will assume file was empty.

  --skip_lines=<integer> [shortcut: -s <int>] (default 1)
    Specifies the number of lines that will be assigned to the header block 
    in the absence of comment characters.

  --npoints=<integer> [shortcut: -n <int>] (default min(all,3000000))
    Specifies the number of samples (records or rows in the data block of an 
    ASCII file) to read. End of file will terminate read.  Note the default:
    if you want to read more than 3 million samples, you must say so using 
    this argument.

  --rows=<integer> [shortcut: -r <int>] (default 2)
    Specifies the number of rows of scatterplots

  --cols=<integer> [shortcut: -c <int>] (default 2)
    Specifies the number of columns of scatterplots

  --input_file=<filespec> [shortcut: -i <filespec>]
    Filespec of the input file.  NOTE: if this parameter is not specified, 
    the code will assume that the final token in the command line is the 
    input filespec.

  --laptop_mode [shortcut -l]
    Shrink control panel to fit in a laptop screen
    
  --commented_labels [shortcut -L]
    Assume that column labels are contained in the last commented line 
    before the data block -- i.e., the last line of the header block.
    Default behavior is to read column labels from the first (uncommented) 
    line of the data block.

  --config_file=<filespec> [shortcut: -C <filespec>]
    Filespec of a saved configuration file.  NOTE: If this parameter is 
    specified, it will override any input filespec.

  --borderless [shortcut: -b]
    Attempt to maximize plot windows' usable area by removing window manager 
    decorations.  Note: this seems to cause problems with keyboard shortcuts 
    in plot windows under Mac OSX.

  --help [shortcut: -h]
    Print a short help message.

  --ordering={rowmajor,columnmajor}
    ordering for binary data, default=columnmajor

  --nvars [shortcut -v <int>]
    The number of variables (attributes) per sample is automatically 
    determined from the last header line in an ascii input file, or from the 
    first line of a column-major binary file.  This option is only for row 
    major binary data, in which case one must also specfiy --npoints above.

  --delimiter [shortcut -d=<char>]
    interpret char as field separator, default is whitespace.  Delimiter 
    characters can be escaped using the standard c-language convetions. This 
    delimiter is also used in the header to delimit variable (attribute) 
    names.
    e.g.  --delimiter=,  for comma delimited
    or    --delimter=\t  for tab delimited
    
  --missing_values [shortcut -M <number>]
    set the value of any unreadable, nonnumeric, empty, or missing values to 
    NUMBER, default=0.0.  NOTE: if you use the default delimiter (whitespace) 
    then lines with one or more missing values are skipped and so this 
    option has no effect. 

  --no_vbo [shortcut -B]
    don't use openGL vertex buffer objects.  Useful if you have an older 
    graphics card or if the graphics are inconsistent or very slow.  May be
    useful if you are attempting to look at huge datasets.

  --preserve_data=(T,F) [shortcut: -P <string>] (default TRUE)
    Preserve existing data for restoration if a read operation fails.  Turn
    this off to reduce memory usage for extremely karge data sets.

  --stdin [shortcut -I]
    read input data from stdin.  This allows piping on systems that support 
    it.
    e.g.   tail -n 100 bigfile | awk '{print $0 " " $3/$2}' | vp --stdin
  
  --trivial_columns=(T,F) [shortcut: -t <string>] (default TRUE)
    Removes columns with a single value

  --verbose [shortcut -O]
    print verbose output with additional diagnostics
    
  --version [shortcut -V]
    print version information and then exit.
    
  --expert [shortcut -x]
    enable expert mode, that bypasses confirmations and allows reads from
    stdin, etc.

  --help [shortcut -h]
    print out brief usage message and then exit.


When 'viewpoints' is invoked, it will read the input file, then display a 
control panel along with an 'r' x 'c' array of linked scatter plots.  These 
windows can be moved and resized in the conventional fashion.  If you delete 
some window by accident, you can restore every window using the 'reload 
plots' command. (If you delete every plot window, the program may crash).

You can also select a particular plot by giving it the mouse focus directly, 
or by clicking on its associated tab in the control panel window.  Within 
different windows, you can use the mouse to select portions of the data set.  
It is in this feature that the power of 'viewpoints' resides.  Rather than 
attempt to describe it in detail, we encourage you to experiment!


Main menu bar

 command                     action
 --------------------        ----------
 File|Open data file         Read data from an input file
 File|Append more data       Append additional samples to the existing data
 File|Merge another file     Merge additional attributes for these samples
 File|Write ASCII file       Write all the current data as an ASCII file
 File|Save all data          Write all data
 File|Save selected data     Write only the currently selected data
 File|Load Configuration     Load configuration information
 File|Save Configuration     Save configuration information
 File|Current File Name      Show name of current data file
 File|Clear all data         Replace data with a small default array
 File|Quit                   Quit
 View|Add Row                Add a row of plot windows
 View|Add Column             Add a column of plot windows
 View|Remove Row             Remove a row of plot windows
 View|Remove Column          Remove a column of plot windows
 View|Reload File            Reload the existing data file
 View|Restore Panels         Restore deleted plot windows
 View|Default Panels         Restore the default polt window configuration
 Tools|Edit Column Labels    Prototype of a column label editor
 Tools|Statistics            Show selection statistics
 Tools|Options               Set viewpoints options
 Help|Viewpoints Help        Opens a simple HELP window
 Help|About Viewpoints       Information about this version


Buttons and (keyboard shortcuts when a plot window has mouse focus):

 action                 key
 --------------------   ----------
 new selection          left-mouse
 move selection         left-mouse + shift
 invert selection       i
 display deselected     d
 clear selection        c
 search x-axis strings  F
 search y-axis strings  f
 kill selected points   x
 reset view             r
 quit                   q


Mouse Gestures (with the cursor in one of plot windows):

 action                 gesture
 --------------------   ----------
 select points          left-mouse
 translate              right-mouse  (opt-mouse in OSX)
 scale                  middle-mouse (ctl-mouse in OSX)
 scale both x and y     mouse-wheel
 scale histogram        middle-mouse + h (ctl-mouse + h in OSX)

    
Controls in the control panels:

 The control panel consists of a set of tabbed control panels for individual 
 windows, tabbed control panels for individual brushes, and a main control 
 panel for the entire array of panels.  For the most part, these controls 
 should be intuitive.  Some of these controls are described below:

 Tabbed control panels for individual windows:
 control                action
 --------------------   ----------
 lock X, Y, or Z        Lock axis so it won't change
 plot                   Attribute to be displayed in that axis
 scale                  Normalization scheme for that axis
 offset                 Offset data by +/-i points along this axis.  Note 
                        that this is a spinner rather than a slider.
 histog                 Show histograms along that axis.  
                        'Marginal/Selection/Conditional' corresponds to 
                        'All points/Selected points/Fraction selected'
 N bins                 number (log) of histogram bins for that axis
 bin ht                 height of histogram bins for that axis
 bkgrnd                 background color (try bkg=0.5, lum2=0.2)
 lumin                  luminosity for all points
 pntsize                default size of unselected points
 scale                  Scale point sizes along with axes
 rotate                 rotation angle in 3D about the y-axis.  NOTE: to take
                        advantage of this feature one must first select 
                        something for the Z-axis to display.
 spin                   continuous rotation about the y-axis.  NOTE: to start
                        this, you may have to give the rot slider a twitch.
 reset view             Reset rotation and other display params
 z-buffering            Use z-buffering (only for 3D plots)
 blending               Blending scheme for brushes
 don't clear            Don't clear selected points in this panel
 points                 Show data points
 unselected             Show unselected data points
 axes                   Show axes
 ticks                  Show tic marks
 grid                   Show grid
 identity               plot y vs x
 sum vs. diff plot      plot (x+y) vs. (x-y)
 rank(y|x)              Plot x vs the rank of y for a range about that x  (e.g., 
                        rank points within a sliding bin of x-values by their 
                        value in y.  The width of this bin is controlled the 
                        number of histogram bins, N bins.)
 fluc(y|x)              Plot x vs the deviation in y for a range about that x
                        (e.g., rank points within a sliding bin of x-values by 
                        their variation in y.)

 Tabbed control panels for individual brushes
 control                action
 --------------------   ----------
 size                   size of this brush, in pixels
 reset brush            reset this brush
 Alpha                  point opacity
 symbol                 symbol used by this brush
 lum1                   successive brightness increase for overplotting
 lum2                   successive brightness increase for overplotting
 Color chart            Color controls for this brush
 extend selection       combine successive selections with this brush
 clear selection        clear successive selection for this brush
 paint                  'dribble paint' while dragging the selection box
  
 Main control panel
 control                 action
 --------------------   ----------
 show nonselected       Show unselected points
 invert selection       Invert selected and nonselected points
 clear selcetion        Clear selection
 kill selection         Delete all selected points
 unselected color       Chose color of unselected points
 change axes            Change all (unlocked) axes
 link axes              Link similar axes
 defer redraw           Update selections on mouse-up only (for large data)


Normalization schemes (per axis)

 Data can be normalized in several different ways.  The normalization scheme 
 for any axis can be selected from the appropriate menu.

 type                   description
 --------------------   -----------
 none                   show all data, center of window at median
 minmax                 window spans maimimum to maximum.
 zeromax                show all positive data
 maxabs                 show all data, center the window at zero
 trim 10^-2             window spans the 1st-99th percentile
 trim 10^-3             window spans the 0.1th-99.9th percentile
 threesigma             center window at sample mean so that window spans 
                        +/- three sigma.
 log_10                 Logarithmic axis
 atan                   Simple sigmoid
 rank                   plot rank (order) of x instead of x -- i.e. 
                        nonuniform rescaling to force a uniform marginal
 partial rank           as 'rank' above, but overplot identical values
 gaussianize            plot inverse of the Gaussian cummulative 
                        distribution function of x -- i.e. nonuniform 
                        rescaling to force a uniform marginal
randomize               Randomize


Notes and warnings:

The current release of the 'viewpoints' package (version 2.2.4, build 258) is 
still a development version.  While every effort has been make to ensure that 
it will work -- or fail gracefully if it doesn't -- it still has many rough 
edges.  Some of these are described below.  These issues will all be 
addressed in future releases.

1) If you drag a window over the main control panel, the main control panel
may need to be refreshed.  This can be accomplished by resizing it.

2) The Load and Save Configuration commands are a comparatively new feature.
For this reason, they are still evolving.  While every effort has been made 
to ensure that old configuration files are upward-compatible with new 
versions of viewpoints, it is advisable to resave a new version of these 
files if the package warns you to do so.

3) The FITS file i/o capability is new, and is not yet guaranteed to work on 
every system.  It will undergo substantial improvement in future releases.

4) The Edit Column Labels tool is still under development, and can produce
unexpected behavior.  It is not guaranteed to preserve axis or scaling 
information, and in the current release can only delete labels.  For ASCII
files, column labels can be renamed via by using an editor in a conventional 
fashion.  Small binary files can be saved to ASCII and edited.  For large 
binary files, it is possible, with difficulty, to rename labels by saving a 
small portion of the file as ASCII, editing this, reloading it, and appending 
the remaining portion of the original binary file.

5) For a variety of reasons related to platform-independance and formatting
of multiple windows, there is, as yet, no 'print' command.  Images can be 
saved for use as screenshots in a conventional fashion using the relevant OS 
commands.

Please send any questions, bug reports, feature requests, and/or praise to: 

Creon Levit at   creon.levit@nasa.gov
or
Paul Gazis at    Paul.R.Gazis@nasa.gov

