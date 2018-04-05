set(tensor_install tensor.h)
set(tensor_headers ${tensor_install} densor.h)
set(tensor_sources tensor.cc densor.cc)

add_library(tensor ${tensor_sources} ${tensor_headers})
target_include_directories(tensor PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include/tensor>)
#target_link_libraries(tensor PUBLIC ${LIBS})

install(TARGETS tensor DESTINATION lib)
install(FILES ${tensor_headers} DESTINATION include/tensor)
