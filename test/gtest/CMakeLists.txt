INCLUDE(CTest)
INCLUDE(GoogleTest)

ADD_LIBRARY(gtest_main STATIC gtest_main.cpp)
TARGET_LINK_LIBRARIES(gtest_main PUBLIC CONAN_PKG::gtest)
TARGET_LINK_LIBRARIES(gtest_main PRIVATE project_options)

ADD_EXECUTABLE(gtest_tests tests.cpp)
TARGET_LINK_LIBRARIES(gtest_tests PRIVATE project_warnings project_options gtest_main CONAN_PKG::gtest)

# automatically discover tests that are defined in gtest based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
GTEST_DISCOVER_TESTS(
        gtest_tests
        TEST_PREFIX
        "gtest_unittests."
        XML_OUTPUT_DIR
        .)

# Add a file containing a set of constexpr tests
ADD_EXECUTABLE(gtest_constexpr_tests constexpr_tests.cpp)
TARGET_LINK_LIBRARIES(gtest_constexpr_tests PRIVATE project_options project_warnings gtest_main CONAN_PKG::gtest)

GTEST_DISCOVER_TESTS(
        gtest_constexpr_tests
        TEST_PREFIX
        "gtest_constexpr."
        XML_OUTPUT_DIR
        .)
