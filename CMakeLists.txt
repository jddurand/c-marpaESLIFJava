#
# Multi-config generator, e.g. Visual Studio on Windows:
#
# cmake -S c-marpaESLIFJava -B c-marpaESLIFJava-build
# cmake --build c-marpaESLIFJava-build --config RelWithDebInfo
# ctest --test-dir c-marpaESLIFJava-build -C RelWithDebInfo
# Windows:
#   cmake --install c-marpaESLIFJava-build --config RelWithDebInfo --prefix %cd%/c-marpaESLIFJava-install
# Others:
#   cmake --install c-marpaESLIFJava-build --config RelWithDebInfo --prefix `pwd`/c-marpaESLIFJava-install
# cmake --build c-marpaESLIFJava-build --config RelWithDebInfo --target package
#
# Single-config generator, e.g. NMake Makefiles on Windows, Unix Makefiles on Linxu:
#
# cmake -S c-marpaESLIFJava -B c-marpaESLIFJava-build -DCMAKE_BUILD_TYPE=RelWithDebInfo
# cmake --build c-marpaESLIFJava-build
# ctest --test-dir c-marpaESLIFJava-build
# Windows:
#   cmake --install c-marpaESLIFJava-build --prefix %cd%/c-marpaESLIFJava-install
# Others:
#   cmake --install c-marpaESLIFJava-build --prefix `pwd`/c-marpaESLIFJava-install
# cmake --build c-marpaESLIFJava-build --target package
#
# Local tests done with: cmake -S c-marpaESLIFJava -B c-marpaESLIFJava-build -DCMAKE_HELPERS_DEBUG=OFF -DICU_ROOT=C:\icu4c-74_2-Win64-MSVC2019
#
cmake_minimum_required(VERSION 3.26.0 FATAL_ERROR)
project(marpaESLIFJava LANGUAGES C) # We will set version later
#
# PROJECT_VERSION: see below. we will inherit marpaESLIF's PROJECT_VESION, and increment
# only PROJECT_VERSION_TWEAK
#
set(PROJECT_VERSION_TWEAK 1)
#
# Java dependency
#
find_package(Java REQUIRED) # For Java_JAVA_EXECUTABLE
find_package(JNI REQUIRED) # For include paths
include(UseJava)   # To create jars, doc
message(STATUS "")
message(STATUS "JAVA Setup:")
message(STATUS "----------")
message(STATUS "Path to javac    : " ${Java_JAVAC_EXECUTABLE})
message(STATUS "Path to javadoc  : " ${Java_JAVADOC_EXECUTABLE})
message(STATUS "Path to jar      : " ${Java_JAR_EXECUTABLE})
message(STATUS "")
message(STATUS "JNI Setup:")
message(STATUS "----------")
message(STATUS "Path to jni.h    : " ${JAVA_INCLUDE_PATH})
message(STATUS "Path to jni_md.h : " ${JAVA_INCLUDE_PATH2})
message(STATUS "")
#
# Get library helper
#
include(FetchContent)
FetchContent_Declare(cmake-helpers GIT_REPOSITORY https://github.com/jddurand/cmake-helpers.git GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(cmake-helpers)
#
# Dependencies
#
set(marpaESLIFJava_depends)
set(marpaESLIFJava_depends_ext)
set(marpaESLIFJava_find_dependencies)
#
# genericLogger dependency
#
set(genericLogger_git https://github.com/jddurand/c-genericLogger.git)
cmake_helpers_depend(genericLogger
  EXTERNALPROJECT_ADD_ARGS GIT_REPOSITORY ${genericLogger_git} GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS REQUIRED CONFIG
)
list(APPEND marpaESLIFJava_find_dependencies "genericLogger REQUIRED CONFIG")
list(APPEND marpaESLIFJava_depends PUBLIC genericLogger::genericLogger)
#
# genericStack dependency
#
set(genericStack_git https://github.com/jddurand/c-genericStack.git)
cmake_helpers_depend(genericStack
  EXTERNALPROJECT_ADD_ARGS GIT_REPOSITORY ${genericStack_git} GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS REQUIRED CONFIG
)
list(APPEND marpaESLIFJava_find_dependencies "genericStack REQUIRED CONFIG")
list(APPEND marpaESLIFJava_depends PUBLIC genericStack::genericStack)
#
# marpaESLIF dependency (DEV: How to get it to work with a branch ? Does not for me if I use origin/<branch name>
#
set(marpaESLIF_git https://github.com/jddurand/c-marpaESLIF.git)
cmake_helpers_depend(marpaESLIF
  EXTERNALPROJECT_ADD_ARGS DOWNLOAD_COMMAND ${GIT_EXECUTABLE} clone --single-branch --branch cmake_helpers ${marpaESLIF_git} ${CMAKE_CURRENT_BINARY_DIR}/_deps/marpaeslif-src
  FIND_PACKAGE_ARGS REQUIRED CONFIG
)
list(APPEND marpaESLIFJava_find_dependencies "marpaESLIF REQUIRED CONFIG")
list(APPEND marpaESLIFJava_depends PUBLIC marpaESLIF::marpaESLIF)
#
# We inherit marpaESLIF's version
#
find_package(marpaESLIF REQUIRED CONFIG)
message(STATUS "Using marpaESLIF's version: ${marpaESLIF_VERSION}")
set(PROJECT_VERSION ${marpaESLIF_VERSION})
set(PROJECT_VERSION_MAJOR ${marpaESLIF_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${marpaESLIF_VERSION_MINOR})
set(PROJECT_VERSION_PATCH ${marpaESLIF_VERSION_PATCH})
#
# Create library
#
cmake_helpers_library(marpaESLIFJava
  CONFIG_ARGS        include/marpaESLIFJava/internal/config.h.in include/marpaESLIFJava/internal/config.h
  FIND_DEPENDENCIES  ${marpaESLIFJava_find_dependencies}
  DEPENDS            ${marpaESLIFJava_depends}
  DEPENDS_EXT        ${marpaESLIFJava_depends_ext}
  TARGETS_OUTVAR     targets
)
#
# Add internal definitions
#
foreach(_target IN LISTS targets)
  target_compile_definitions(${_target} PRIVATE
    -DMARPAESLIFJAVA_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
    -DMARPAESLIFJAVA_VERSION_MINOR=${PROJECT_VERSION_MINOR}
    -DMARPAESLIFJAVA_VERSION_PATCH=${PROJECT_VERSION_PATCH}
    -DMARPAESLIFJAVA_VERSION="${PROJECT_VERSION}"
  )
  target_include_directories(${_target} PRIVATE
    ${JAVA_INCLUDE_PATH} ${JAVA_INCLUDE_PATH2}
  )
endforeach()
#
# Create jars
#
set(_java_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIF.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFEvent.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFEventType.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFException.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFGrammar.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFGrammarProperties.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFGrammarRuleProperties.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFGrammarSymbolProperties.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFJSON.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFJSONDecoder.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFJSONDecoderOption.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFJSONEncoder.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFLoggerInterface.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFLoggerLevel.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFMultitonNullLogger.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFProgress.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFRecognizer.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFRecognizerInterface.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFRegexCallout.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFRulePropertyBitSet.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFSymbol.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFSymbolEventBitSet.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFSymbolPropertyBitSet.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFSymbolType.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFValue.java
  ${CMAKE_CURRENT_SOURCE_DIR}/src/org/parser/marpa/ESLIFValueInterface.java
)
add_jar(marpaESLIFJavaJar
  SOURCES ${_java_sources}
  OUTPUT_NAME marpaESLIF
)
add_dependencies(marpaESLIFJavaJar marpaESLIFJava)
install_jar(marpaESLIFJavaJar
  DESTINATION ${CMAKE_HELPERS_INSTALL_JAVADIR}
  COMPONENT ${PROJECT_NAME}RuntimeComponent
)
export_jars(
  TARGETS marpaESLIFJavaJar
  NAMESPACE marpaESLIFJava::
  FILE marpaESLIFJavaTargets.cmake
)
install_jar_exports(
  TARGETS marpaESLIFJavaJar
  NAMESPACE marpaESLIFJava::
  FILE marpaESLIFJavaTargets.cmake
  DESTINATION ${CMAKE_HELPERS_INSTALL_CMAKEDIR}
  COMPONENT ${PROJECT_NAME}ConfigComponent
)
#
# Create documentation: UseJava does not allow to specify a COMPONENT, so we do it ourself
#
if(Java_JAVADOC_EXECUTABLE)
  set(_javadoc_builddir )
  cmake_helpers_call(add_custom_target marpaESLIFJava_javadoc ALL
    COMMAND ${Java_JAVADOC_EXECUTABLE}
      -d ${CMAKE_CURRENT_BINARY_DIR}/javadoc/marpaESLIFJava
      -sourcepath src
      -doctitle "\"marpaESLIF Java Bindings\""
      -windowtitle marpaESLIFJava
      -author
      -use
      -version
      org.parser.marpa
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
  install(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/javadoc/marpaESLIFJava
    DESTINATION ${CMAKE_HELPERS_INSTALL_JAVADOCDIR}
    COMPONENT marpaESLIFJavaHtmlComponent
  )
  set_property(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} PROPERTY cmake_helpers_property_marpaESLIFJava_HaveHtmlComponent TRUE)
  add_dependencies(marpaESLIFJavaJar marpaESLIFJava_javadoc)
endif()
#
# Tests
#
include(CTest)
#
# We run no test if the JVM platform does not match our architecture
#
math(EXPR _current_platform "${CMAKE_SIZEOF_VOID_P} * 8")
message(STATUS "Checking JVM platform architecture")
set(_can_test FALSE)
if(Java_JAVAC_EXECUTABLE)
  execute_process(
    COMMAND ${Java_JAVAC_EXECUTABLE} -d ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/test/Is64.java
    COMMAND_ECHO STDOUT
    RESULT_VARIABLE javac_result
    OUTPUT_VARIABLE javac_output
    ERROR_VARIABLE javac_error
  )
  if((NOT RESULT_VARIABLE) OR (RESULT_VARIABLE EQUAL 0))
    execute_process(
      COMMAND ${Java_JAVA_EXECUTABLE} -cp ${CMAKE_CURRENT_BINARY_DIR} Is64
      COMMAND_ECHO STDOUT
      RESULT_VARIABLE java_result
      OUTPUT_VARIABLE java_output
      ERROR_VARIABLE java_error
    )
    if((NOT RESULT_VARIABLE) OR (RESULT_VARIABLE EQUAL 0))
      message(STATUS "Checking JVM platform architecture - ${java_output} bits")
      if(${java_output} EQUAL ${_current_platform})
	set(_can_test TRUE)
      else()
	message(STATUS "JVM platform does not match current platform (Java: ${java_output} bits, Current: ${_current_platform} bits)")
      endif()
    else()
      message(STATUS "Failed to execute Is64 java program")
      if(java_output)
	message(STATUS "${java_output}")
      endif()
      if(java_error)
	message(STATUS "${java_error}")
      endif()
    endif()
  else()
    message(STATUS "Failed to compile Is64.java")
    if(javac_output)
      message(STATUS "${javac_output}")
    endif()
    if(javac_error)
      message(STATUS "${javac_error}")
    endif()
  endif()
else()
  message(STATUS "Disabling test: No javac executable")
endif()
if(NOT _can_test)
  message(STATUS "Disabling tests")
else()
  set(_test_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppEmptyRecognizer.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppImportExport.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppJSON.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppJSONDecoder.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppJSONEncoder.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppJSONLua.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppLexeme.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppLogger.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppParameterizedRules.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppParse.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppRecognizerInterface.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppThread.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/AppValueInterface.java
    ${CMAKE_CURRENT_SOURCE_DIR}/test/org/parser/marpa/Describe.java
  )
  set(CMAKE_JNI_TARGET FALSE)
  set(CMAKE_JAVA_TARGET_VERSION FALSE)
  add_jar(marpaESLIFJavaTestJar
    SOURCES ${_test_sources}
    INCLUDE_JARS marpaESLIFJavaJar
    ENTRY_POINT org/parser/marpa/AppParse
    OUTPUT_NAME marpaESLIFJavaTest
  )
  add_dependencies(marpaESLIFJavaTestJar marpaESLIFJavaJar)
  #
  # Recuperate our two jar files locations. It is hard to get rid of ";" interpretation if we play
  # with the -cp option, fortunately CLASSPATH environment variable exists.
  #
  get_target_property(marpaESLIFJavaJarFile marpaESLIFJavaJar JAR_FILE)
  get_target_property(marpaESLIFJavaTestJarFile marpaESLIFJavaTestJar JAR_FILE)
  #
  # Recuperate path separator: if separator is ";" then we have to escape otherwise CTest will not understand
  #
  cmake_path(CONVERT "x;y" TO_NATIVE_PATH_LIST _xy)
  string(SUBSTRING "${_xy}" 1 1 _sep)
  if(_sep STREQUAL ";")
    set(_sep "\\$<SEMICOLON>")
  endif()
  #
  # Declare the test. cmake_helpers_exe() has the logic to do path modifications. So we build
  # a fake binary and run test with a custom COMMAND
  #
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/marpaESLIFJavaTesterDummy.c [[
#include <stdlib.h>

int main(int argc, char **argv) {
  exit(0);
}
]])
  cmake_helpers_exe(marpaESLIFJavaTester
    INSTALL FALSE
    TEST TRUE
    SOURCES marpaESLIFJavaTesterDummy.c
    #
    # Note how we play with ${_sep}
    #
    ENVIRONMENTS "CLASSPATH=set:${marpaESLIFJavaJarFile}${_sep}${marpaESLIFJavaTestJarFile}"
    COMMAND ${CMAKE_COMMAND} -E env ${Java_JAVA_EXECUTABLE} org.parser.marpa.AppParse
  )
endif()
#
# Package
#
cmake_helpers_package()
