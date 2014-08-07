Steps,


 [x] convert fl_flews over to cmake;
 
 [x] convert viewpoints over to cmake;
 
 [x] run cppcheck on viewpoint and flews; (still have some errors to fix)
 
 [x] run llvm static analyzer on the code;
 
 [x] bring over changes including ROOT reading;
 
 [ ] attempt to build a simple JSON reader;
 
 [ ] run cppcheck on the entire source code; (still have soem errors to fix
 
 [x] correct warnings from gcc and g++; (mostly); 
 
 [ ] correct warnings from clang and clang++ -Weverything 
 
 [ ] fix rotation bugs (selection on rotating display does not work properly)
 
 [ ] fix interface bugs
 
 [ ] improve selection handling
 
 [ ] start re-writing the code(?)

 [ ] Move sprite brushes to image files (TGA?)
Code removed from initialize_sprites() [plot_window.cpp]

    //GLfloat rgb2rgba[16] = {
    //  1, 0, 0, 1/3.0,
    //  0, 1, 0, 1/3.0,
    //  0, 0, 1, 1/3.0,
    //  0, 0, 0, 0
    //};
    //CHECK_GL_ERROR( "BEFORE glMatrixMode(GL_COLOR)");
    //glMatrixMode(GL_COLOR);//bug here
    //CHECK_GL_ERROR( "AFTER glMatrixMode(GL_COLOR)");
    //glLoadMatrixf(rgb2rgba);
    //CHECK_GL_ERROR( "glLoadMatrixf(rgb2rgba)");

What this code does:
  takes a RGB texture (and then gives it an alpha channel equal to 1/3(r+b+g))
  now, in the case of the sprites defined (which are graph scale) -> this
  sets up an alpha channel relative to the actually graph lvl being drawn;
  closer to white (means alpha -> closer to "1.0");

  The texture_alpha blending was done through GL_INTENSITY



//https://www.opengl.org/sdk/docs/man2/xhtml/glTexImage2D.xml
//GL_INTENSITY
//Each element is a single intensity value. The GL converts it to floating point, then assembles it into an RGBA element by replicating the intensity value three times for red, green, blue, and alpha. Each component is then multiplied by the signed scale factor GL_c_SCALE, added to the signed bias GL_c_BIAS, and clamped to the range [0,1] (see glPixelTransfer).
//GL_LUMINANCE
//Each element is a single luminance value. The GL converts it to floating point, then assembles it into an RGBA element by replicating the luminance value three times for red, green, and blue and attaching 1 for alpha. Each component is then multiplied by the signed scale factor GL_c_SCALE, added to the signed bias GL_c_BIAS, and clamped to the range [0,1] (see glPixelTransfer).
//GL_LUMINANCE_ALPHA
//Each element is a luminance/alpha pair. The GL converts it to floating point, then assembles it into an RGBA element by replicating the luminance value three times for red, green, and blue. Each component is then multiplied by the signed scale factor GL_c_SCALE, added to the signed bias GL_c_BIAS, and clamped to the range [0,1] (see glPixelTransfer).
//THESE are deprecated in OpenGL v3
//http://www.opengl.org/wiki/Texture#Swizzle_mask
//Texture Swizzle Mask requires 3.3 (at least)

idata_## is of size 12288 (note some are character string created :/)
Meaning that there is \0 at the end; (size is thus 12289 :/)
spriteWidth  = 64
spriteHeight = 64 
//  size_t out_count = 0;
//  size_t alpha_out = 0;
//  for (size_t iter = 0; iter < 12288; ++iter)
//  {
//    std::cout << size_t(Sprite_Textures::idata_osaka_63[iter]) << ", ";
//    alpha_out+= size_t(Sprite_Textures::idata_osaka_63[iter]);
//    if (++out_count == 3)
//    {
//      if (iter < 12287 )
//      {
//        std::cout << alpha_out/3 << "," << std::endl;
//      }
//      else
//      {
//        std::cout << alpha_out/3 << std::endl;
//      }
//      out_count = 0;
//      alpha_out = 0;
//    }
//  }
//  std::cout << std::endl;

