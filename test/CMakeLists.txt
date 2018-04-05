include(CTest)
enable_testing()

add_executable(test_ops test_ops.cc)
target_link_libraries(test_ops tensor)
add_test(test_ops1 test_ops)

add_executable(test_idxr test_indexer.cc)
target_link_libraries(test_idxr tensor)
add_test(test_idxr1 test_idxr)