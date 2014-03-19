// viewpoints - interactive linked scatterplots and more.
// copyright 2005 Creon Levit and Paul Gazis, all rights reserved.
//***************************************************************************
// File name: symbol_menu.h
//
// Class definitions:
//   Symbol_Menu -- Symbol menu
//
// Classes referenced:
//   Various FLTK classes
//
// Required packages: none
//
// Compiler directives:
//   Requires WIN32 to be defined
//
// Purpose: Structure to hold statics for symbol menu used by class Brush
//
// Author: Creon Levit    2007
// Modified: P. R. Gazis  07-JUL-2008
//***************************************************************************

// Based on code were generated by Fast Light User Interface Designer (fluid)
// version 1.0108.  Modified 07-Jul-2008 to move static variables and member 
// functons to the appropriate classes (class Brush).

// Protection to make sure this header is not included twice
#ifndef SYMBOL_MENU_H
#define SYMBOL_MENU_H  1

// Include the necessary include libraries
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Choice.H>

// This isn't needed because the relevant objects were mved to class Brush
// #include <FL/Fl_Pixmap.H>

// This doesn't seem to be used so it was commented out 07-JUL-2008
// Fl_Double_Window* make_window();

//***************************************************************************
// Class: Symbol_Menu
//
// Class definitions:
//   Symbol_Menu
//
// Classes referenced: none, this is just a structure
//
// Purpose: Structure to hold statics used to generate symbol menu used by 
//   class Brush
//
// Functions: none
//
// Author: Creon Levit    2005-2006
// Modified: P. R. Gazis  07-JUL-2008
//***************************************************************************
class Symbol_Menu
{
  protected:
            
  public:
    // Define static arrays to hold symbols
    static const char *idata_0[];
    static const char *idata_1[];
    static const char *idata_2[];
    static const char *idata_3[];
    static const char *idata_4[];
    static const char *idata_5[];
    static const char *idata_6[];
    static const char *idata_7[];
    static const char *idata_8[];
    static const char *idata_9[];
    static const char *idata_10[];
    static const char *idata_11[];
    static const char *idata_12[];
    static const char *idata_13[];
    static const char *idata_14[];
    static const char *idata_18[];
    static const char *idata_19[];

    // Define static array to hold symbol for line plot
    static const char *idata_line[];

    // Define static arrays to hold numbers and letters
    static const char *idata_osaka_21[];
    static const char *idata_osaka_22[];
    static const char *idata_osaka_23[];
    static const char *idata_osaka_24[];
    static const char *idata_osaka_25[];
    static const char *idata_osaka_26[];
    static const char *idata_osaka_27[];
    static const char *idata_osaka_28[];
    static const char *idata_osaka_29[];
    static const char *idata_osaka_30[];
    static const char *idata_osaka_38[];
    static const char *idata_osaka_39[];
    static const char *idata_osaka_40[];
    static const char *idata_osaka_41[];
    static const char *idata_osaka_42[];
    static const char *idata_osaka_43[];
    static const char *idata_osaka_44[];
    static const char *idata_osaka_45[];
    static const char *idata_osaka_46[];
    static const char *idata_osaka_47[];
    static const char *idata_osaka_48[];
    static const char *idata_osaka_49[];
    static const char *idata_osaka_50[];
    static const char *idata_osaka_51[];
    static const char *idata_osaka_52[];
    static const char *idata_osaka_53[];
    static const char *idata_osaka_54[];
    static const char *idata_osaka_55[];
    static const char *idata_osaka_56[];
    static const char *idata_osaka_57[];
    static const char *idata_osaka_58[];
    static const char *idata_osaka_59[];
    static const char *idata_osaka_60[];
    static const char *idata_osaka_61[];
    static const char *idata_osaka_62[];
    static const char *idata_osaka_63[];
};

#endif   // SYMBOL_MENU_H