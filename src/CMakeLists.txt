
set(viewpoint_sources
  brush.cpp
  plot_window.cpp
  vp.cpp
  column_info.cpp
  sprite_textures.cpp
  Vp_File_Chooser.cpp
  control_panel_window.cpp
  symbol_menu.cpp
  Vp_Value_Input_Spin.cpp
  data_file_manager.cpp
  unescape.cpp
  global_definitions_vp.cpp
  Vp_Color_Chooser.cpp
)

add_definitions("-DGL_GLEXT_PROTOTYPES")
add_definitions("-DSERIALIZATION")

add_executable (vp ${viewpoint_sources})
add_dependencies(vp flews-static)
target_link_libraries(vp flews-static ${FLTK_LIBRARY} ${OPENGL_LIBRARIES} ${GSL_LIBRARIES} ${CFITSIO_LIBRARIES} ${Boost_SERIALIZATION_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${ROOT_LIBRARIES})

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

set_target_properties( vp PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
