include(ExternalProject)
set(EP_PREFIX "${PROJECT_SOURCE_DIR}/external")
set_directory_properties(PROPERTIES
        EP_PREFIX ${EP_PREFIX}
        )

find_package(GTest)

if (NOT GTEST_FOUND)
    ExternalProject_Add(google_test
            GIT_REPOSITORY "https://github.com/google/googletest.git"
            CMAKE_ARGS -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
            -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
            -Dgtest_force_shared_crt=ON
            -Dgtest_disable_pthreads=OFF
            -DBUILD_GTEST=ON
            -DBUILD_GMOCK=OFF
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            INSTALL_COMMAND "" # remove install step
            UPDATE_COMMAND "" # remove update step
            TEST_COMMAND "" # remove test step
            )
    ExternalProject_Get_Property(google_test source_dir binary_dir)
    set(GTEST_INCLUDE_DIRS ${source_dir}/googletest/include)
    set(GTEST_LIBRARIES ${binary_dir}/googletest/libgtest.a)
    set(GTEST_MAIN_LIBRARIES ${binary_dir}/googletest/libgtest_main.a)
    file(MAKE_DIRECTORY ${GTEST_INCLUDE_DIRS})
endif ()

add_library(gtest STATIC IMPORTED)
set_target_properties(gtest PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
        IMPORTED_LOCATION ${GTEST_LIBRARIES}
        IMPORTED_LINK_INTERFACE_LIBRARIES "pthread;${GTEST_MAIN_LIBRARIES}"
        )

if (NOT GTEST_FOUND)
    add_dependencies(gtest google_test)
endif ()