# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/gamos_qt_gui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/gamos_qt_gui

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target package_source
package_source:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool for source..."
	/usr/bin/cpack --config ./CPackSourceConfig.cmake /home/ubuntu/gamos_qt_gui/CPackSourceConfig.cmake
.PHONY : package_source

# Special rule for the target package_source
package_source/fast: package_source

.PHONY : package_source/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target package
package: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool..."
	/usr/bin/cpack --config ./CPackConfig.cmake
.PHONY : package

# Special rule for the target package
package/fast: package

.PHONY : package/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ubuntu/gamos_qt_gui/CMakeFiles /home/ubuntu/gamos_qt_gui/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ubuntu/gamos_qt_gui/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named gamos_gui

# Build rule for target.
gamos_gui: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gamos_gui
.PHONY : gamos_gui

# fast build rule for target.
gamos_gui/fast:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/build
.PHONY : gamos_gui/fast

#=============================================================================
# Target rules for targets named gamos_gui_autogen

# Build rule for target.
gamos_gui_autogen: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gamos_gui_autogen
.PHONY : gamos_gui_autogen

# fast build rule for target.
gamos_gui_autogen/fast:
	$(MAKE) -f CMakeFiles/gamos_gui_autogen.dir/build.make CMakeFiles/gamos_gui_autogen.dir/build
.PHONY : gamos_gui_autogen/fast

gamos_gui_autogen/mocs_compilation.o: gamos_gui_autogen/mocs_compilation.cpp.o

.PHONY : gamos_gui_autogen/mocs_compilation.o

# target to build an object file
gamos_gui_autogen/mocs_compilation.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/gamos_gui_autogen/mocs_compilation.cpp.o
.PHONY : gamos_gui_autogen/mocs_compilation.cpp.o

gamos_gui_autogen/mocs_compilation.i: gamos_gui_autogen/mocs_compilation.cpp.i

.PHONY : gamos_gui_autogen/mocs_compilation.i

# target to preprocess a source file
gamos_gui_autogen/mocs_compilation.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/gamos_gui_autogen/mocs_compilation.cpp.i
.PHONY : gamos_gui_autogen/mocs_compilation.cpp.i

gamos_gui_autogen/mocs_compilation.s: gamos_gui_autogen/mocs_compilation.cpp.s

.PHONY : gamos_gui_autogen/mocs_compilation.s

# target to generate assembly for a file
gamos_gui_autogen/mocs_compilation.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/gamos_gui_autogen/mocs_compilation.cpp.s
.PHONY : gamos_gui_autogen/mocs_compilation.cpp.s

main_app.o: main_app.cpp.o

.PHONY : main_app.o

# target to build an object file
main_app.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/main_app.cpp.o
.PHONY : main_app.cpp.o

main_app.i: main_app.cpp.i

.PHONY : main_app.i

# target to preprocess a source file
main_app.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/main_app.cpp.i
.PHONY : main_app.cpp.i

main_app.s: main_app.cpp.s

.PHONY : main_app.s

# target to generate assembly for a file
main_app.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/main_app.cpp.s
.PHONY : main_app.cpp.s

src/BExpertWindow.o: src/BExpertWindow.cpp.o

.PHONY : src/BExpertWindow.o

# target to build an object file
src/BExpertWindow.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/BExpertWindow.cpp.o
.PHONY : src/BExpertWindow.cpp.o

src/BExpertWindow.i: src/BExpertWindow.cpp.i

.PHONY : src/BExpertWindow.i

# target to preprocess a source file
src/BExpertWindow.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/BExpertWindow.cpp.i
.PHONY : src/BExpertWindow.cpp.i

src/BExpertWindow.s: src/BExpertWindow.cpp.s

.PHONY : src/BExpertWindow.s

# target to generate assembly for a file
src/BExpertWindow.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/BExpertWindow.cpp.s
.PHONY : src/BExpertWindow.cpp.s

src/BMainWindow.o: src/BMainWindow.cpp.o

.PHONY : src/BMainWindow.o

# target to build an object file
src/BMainWindow.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/BMainWindow.cpp.o
.PHONY : src/BMainWindow.cpp.o

src/BMainWindow.i: src/BMainWindow.cpp.i

.PHONY : src/BMainWindow.i

# target to preprocess a source file
src/BMainWindow.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/BMainWindow.cpp.i
.PHONY : src/BMainWindow.cpp.i

src/BMainWindow.s: src/BMainWindow.cpp.s

.PHONY : src/BMainWindow.s

# target to generate assembly for a file
src/BMainWindow.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/BMainWindow.cpp.s
.PHONY : src/BMainWindow.cpp.s

src/moc_BExpertWindow.o: src/moc_BExpertWindow.cpp.o

.PHONY : src/moc_BExpertWindow.o

# target to build an object file
src/moc_BExpertWindow.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/moc_BExpertWindow.cpp.o
.PHONY : src/moc_BExpertWindow.cpp.o

src/moc_BExpertWindow.i: src/moc_BExpertWindow.cpp.i

.PHONY : src/moc_BExpertWindow.i

# target to preprocess a source file
src/moc_BExpertWindow.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/moc_BExpertWindow.cpp.i
.PHONY : src/moc_BExpertWindow.cpp.i

src/moc_BExpertWindow.s: src/moc_BExpertWindow.cpp.s

.PHONY : src/moc_BExpertWindow.s

# target to generate assembly for a file
src/moc_BExpertWindow.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/moc_BExpertWindow.cpp.s
.PHONY : src/moc_BExpertWindow.cpp.s

src/moc_BMainWindow.o: src/moc_BMainWindow.cpp.o

.PHONY : src/moc_BMainWindow.o

# target to build an object file
src/moc_BMainWindow.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/moc_BMainWindow.cpp.o
.PHONY : src/moc_BMainWindow.cpp.o

src/moc_BMainWindow.i: src/moc_BMainWindow.cpp.i

.PHONY : src/moc_BMainWindow.i

# target to preprocess a source file
src/moc_BMainWindow.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/moc_BMainWindow.cpp.i
.PHONY : src/moc_BMainWindow.cpp.i

src/moc_BMainWindow.s: src/moc_BMainWindow.cpp.s

.PHONY : src/moc_BMainWindow.s

# target to generate assembly for a file
src/moc_BMainWindow.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/moc_BMainWindow.cpp.s
.PHONY : src/moc_BMainWindow.cpp.s

src/moc_BMainWindows.o: src/moc_BMainWindows.cpp.o

.PHONY : src/moc_BMainWindows.o

# target to build an object file
src/moc_BMainWindows.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/moc_BMainWindows.cpp.o
.PHONY : src/moc_BMainWindows.cpp.o

src/moc_BMainWindows.i: src/moc_BMainWindows.cpp.i

.PHONY : src/moc_BMainWindows.i

# target to preprocess a source file
src/moc_BMainWindows.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/moc_BMainWindows.cpp.i
.PHONY : src/moc_BMainWindows.cpp.i

src/moc_BMainWindows.s: src/moc_BMainWindows.cpp.s

.PHONY : src/moc_BMainWindows.s

# target to generate assembly for a file
src/moc_BMainWindows.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/moc_BMainWindows.cpp.s
.PHONY : src/moc_BMainWindows.cpp.s

src/utils/Helper.o: src/utils/Helper.cpp.o

.PHONY : src/utils/Helper.o

# target to build an object file
src/utils/Helper.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/utils/Helper.cpp.o
.PHONY : src/utils/Helper.cpp.o

src/utils/Helper.i: src/utils/Helper.cpp.i

.PHONY : src/utils/Helper.i

# target to preprocess a source file
src/utils/Helper.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/utils/Helper.cpp.i
.PHONY : src/utils/Helper.cpp.i

src/utils/Helper.s: src/utils/Helper.cpp.s

.PHONY : src/utils/Helper.s

# target to generate assembly for a file
src/utils/Helper.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/utils/Helper.cpp.s
.PHONY : src/utils/Helper.cpp.s

src/widget/BHStackWidget.o: src/widget/BHStackWidget.cpp.o

.PHONY : src/widget/BHStackWidget.o

# target to build an object file
src/widget/BHStackWidget.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BHStackWidget.cpp.o
.PHONY : src/widget/BHStackWidget.cpp.o

src/widget/BHStackWidget.i: src/widget/BHStackWidget.cpp.i

.PHONY : src/widget/BHStackWidget.i

# target to preprocess a source file
src/widget/BHStackWidget.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BHStackWidget.cpp.i
.PHONY : src/widget/BHStackWidget.cpp.i

src/widget/BHStackWidget.s: src/widget/BHStackWidget.cpp.s

.PHONY : src/widget/BHStackWidget.s

# target to generate assembly for a file
src/widget/BHStackWidget.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BHStackWidget.cpp.s
.PHONY : src/widget/BHStackWidget.cpp.s

src/widget/BNumberInput.o: src/widget/BNumberInput.cpp.o

.PHONY : src/widget/BNumberInput.o

# target to build an object file
src/widget/BNumberInput.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BNumberInput.cpp.o
.PHONY : src/widget/BNumberInput.cpp.o

src/widget/BNumberInput.i: src/widget/BNumberInput.cpp.i

.PHONY : src/widget/BNumberInput.i

# target to preprocess a source file
src/widget/BNumberInput.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BNumberInput.cpp.i
.PHONY : src/widget/BNumberInput.cpp.i

src/widget/BNumberInput.s: src/widget/BNumberInput.cpp.s

.PHONY : src/widget/BNumberInput.s

# target to generate assembly for a file
src/widget/BNumberInput.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BNumberInput.cpp.s
.PHONY : src/widget/BNumberInput.cpp.s

src/widget/BPathInput.o: src/widget/BPathInput.cpp.o

.PHONY : src/widget/BPathInput.o

# target to build an object file
src/widget/BPathInput.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BPathInput.cpp.o
.PHONY : src/widget/BPathInput.cpp.o

src/widget/BPathInput.i: src/widget/BPathInput.cpp.i

.PHONY : src/widget/BPathInput.i

# target to preprocess a source file
src/widget/BPathInput.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BPathInput.cpp.i
.PHONY : src/widget/BPathInput.cpp.i

src/widget/BPathInput.s: src/widget/BPathInput.cpp.s

.PHONY : src/widget/BPathInput.s

# target to generate assembly for a file
src/widget/BPathInput.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BPathInput.cpp.s
.PHONY : src/widget/BPathInput.cpp.s

src/widget/BPhantomTab.o: src/widget/BPhantomTab.cpp.o

.PHONY : src/widget/BPhantomTab.o

# target to build an object file
src/widget/BPhantomTab.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BPhantomTab.cpp.o
.PHONY : src/widget/BPhantomTab.cpp.o

src/widget/BPhantomTab.i: src/widget/BPhantomTab.cpp.i

.PHONY : src/widget/BPhantomTab.i

# target to preprocess a source file
src/widget/BPhantomTab.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BPhantomTab.cpp.i
.PHONY : src/widget/BPhantomTab.cpp.i

src/widget/BPhantomTab.s: src/widget/BPhantomTab.cpp.s

.PHONY : src/widget/BPhantomTab.s

# target to generate assembly for a file
src/widget/BPhantomTab.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BPhantomTab.cpp.s
.PHONY : src/widget/BPhantomTab.cpp.s

src/widget/BStyleLabel.o: src/widget/BStyleLabel.cpp.o

.PHONY : src/widget/BStyleLabel.o

# target to build an object file
src/widget/BStyleLabel.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BStyleLabel.cpp.o
.PHONY : src/widget/BStyleLabel.cpp.o

src/widget/BStyleLabel.i: src/widget/BStyleLabel.cpp.i

.PHONY : src/widget/BStyleLabel.i

# target to preprocess a source file
src/widget/BStyleLabel.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BStyleLabel.cpp.i
.PHONY : src/widget/BStyleLabel.cpp.i

src/widget/BStyleLabel.s: src/widget/BStyleLabel.cpp.s

.PHONY : src/widget/BStyleLabel.s

# target to generate assembly for a file
src/widget/BStyleLabel.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BStyleLabel.cpp.s
.PHONY : src/widget/BStyleLabel.cpp.s

src/widget/BVStackWidget.o: src/widget/BVStackWidget.cpp.o

.PHONY : src/widget/BVStackWidget.o

# target to build an object file
src/widget/BVStackWidget.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BVStackWidget.cpp.o
.PHONY : src/widget/BVStackWidget.cpp.o

src/widget/BVStackWidget.i: src/widget/BVStackWidget.cpp.i

.PHONY : src/widget/BVStackWidget.i

# target to preprocess a source file
src/widget/BVStackWidget.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BVStackWidget.cpp.i
.PHONY : src/widget/BVStackWidget.cpp.i

src/widget/BVStackWidget.s: src/widget/BVStackWidget.cpp.s

.PHONY : src/widget/BVStackWidget.s

# target to generate assembly for a file
src/widget/BVStackWidget.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BVStackWidget.cpp.s
.PHONY : src/widget/BVStackWidget.cpp.s

src/widget/moc_BHStackWidget.o: src/widget/moc_BHStackWidget.cpp.o

.PHONY : src/widget/moc_BHStackWidget.o

# target to build an object file
src/widget/moc_BHStackWidget.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BHStackWidget.cpp.o
.PHONY : src/widget/moc_BHStackWidget.cpp.o

src/widget/moc_BHStackWidget.i: src/widget/moc_BHStackWidget.cpp.i

.PHONY : src/widget/moc_BHStackWidget.i

# target to preprocess a source file
src/widget/moc_BHStackWidget.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BHStackWidget.cpp.i
.PHONY : src/widget/moc_BHStackWidget.cpp.i

src/widget/moc_BHStackWidget.s: src/widget/moc_BHStackWidget.cpp.s

.PHONY : src/widget/moc_BHStackWidget.s

# target to generate assembly for a file
src/widget/moc_BHStackWidget.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BHStackWidget.cpp.s
.PHONY : src/widget/moc_BHStackWidget.cpp.s

src/widget/moc_BNumberInput.o: src/widget/moc_BNumberInput.cpp.o

.PHONY : src/widget/moc_BNumberInput.o

# target to build an object file
src/widget/moc_BNumberInput.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BNumberInput.cpp.o
.PHONY : src/widget/moc_BNumberInput.cpp.o

src/widget/moc_BNumberInput.i: src/widget/moc_BNumberInput.cpp.i

.PHONY : src/widget/moc_BNumberInput.i

# target to preprocess a source file
src/widget/moc_BNumberInput.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BNumberInput.cpp.i
.PHONY : src/widget/moc_BNumberInput.cpp.i

src/widget/moc_BNumberInput.s: src/widget/moc_BNumberInput.cpp.s

.PHONY : src/widget/moc_BNumberInput.s

# target to generate assembly for a file
src/widget/moc_BNumberInput.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BNumberInput.cpp.s
.PHONY : src/widget/moc_BNumberInput.cpp.s

src/widget/moc_BPathInput.o: src/widget/moc_BPathInput.cpp.o

.PHONY : src/widget/moc_BPathInput.o

# target to build an object file
src/widget/moc_BPathInput.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BPathInput.cpp.o
.PHONY : src/widget/moc_BPathInput.cpp.o

src/widget/moc_BPathInput.i: src/widget/moc_BPathInput.cpp.i

.PHONY : src/widget/moc_BPathInput.i

# target to preprocess a source file
src/widget/moc_BPathInput.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BPathInput.cpp.i
.PHONY : src/widget/moc_BPathInput.cpp.i

src/widget/moc_BPathInput.s: src/widget/moc_BPathInput.cpp.s

.PHONY : src/widget/moc_BPathInput.s

# target to generate assembly for a file
src/widget/moc_BPathInput.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BPathInput.cpp.s
.PHONY : src/widget/moc_BPathInput.cpp.s

src/widget/moc_BPhantomTab.o: src/widget/moc_BPhantomTab.cpp.o

.PHONY : src/widget/moc_BPhantomTab.o

# target to build an object file
src/widget/moc_BPhantomTab.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BPhantomTab.cpp.o
.PHONY : src/widget/moc_BPhantomTab.cpp.o

src/widget/moc_BPhantomTab.i: src/widget/moc_BPhantomTab.cpp.i

.PHONY : src/widget/moc_BPhantomTab.i

# target to preprocess a source file
src/widget/moc_BPhantomTab.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BPhantomTab.cpp.i
.PHONY : src/widget/moc_BPhantomTab.cpp.i

src/widget/moc_BPhantomTab.s: src/widget/moc_BPhantomTab.cpp.s

.PHONY : src/widget/moc_BPhantomTab.s

# target to generate assembly for a file
src/widget/moc_BPhantomTab.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BPhantomTab.cpp.s
.PHONY : src/widget/moc_BPhantomTab.cpp.s

src/widget/moc_BStyleLabel.o: src/widget/moc_BStyleLabel.cpp.o

.PHONY : src/widget/moc_BStyleLabel.o

# target to build an object file
src/widget/moc_BStyleLabel.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BStyleLabel.cpp.o
.PHONY : src/widget/moc_BStyleLabel.cpp.o

src/widget/moc_BStyleLabel.i: src/widget/moc_BStyleLabel.cpp.i

.PHONY : src/widget/moc_BStyleLabel.i

# target to preprocess a source file
src/widget/moc_BStyleLabel.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BStyleLabel.cpp.i
.PHONY : src/widget/moc_BStyleLabel.cpp.i

src/widget/moc_BStyleLabel.s: src/widget/moc_BStyleLabel.cpp.s

.PHONY : src/widget/moc_BStyleLabel.s

# target to generate assembly for a file
src/widget/moc_BStyleLabel.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BStyleLabel.cpp.s
.PHONY : src/widget/moc_BStyleLabel.cpp.s

src/widget/moc_BVStackWidget.o: src/widget/moc_BVStackWidget.cpp.o

.PHONY : src/widget/moc_BVStackWidget.o

# target to build an object file
src/widget/moc_BVStackWidget.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BVStackWidget.cpp.o
.PHONY : src/widget/moc_BVStackWidget.cpp.o

src/widget/moc_BVStackWidget.i: src/widget/moc_BVStackWidget.cpp.i

.PHONY : src/widget/moc_BVStackWidget.i

# target to preprocess a source file
src/widget/moc_BVStackWidget.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BVStackWidget.cpp.i
.PHONY : src/widget/moc_BVStackWidget.cpp.i

src/widget/moc_BVStackWidget.s: src/widget/moc_BVStackWidget.cpp.s

.PHONY : src/widget/moc_BVStackWidget.s

# target to generate assembly for a file
src/widget/moc_BVStackWidget.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/moc_BVStackWidget.cpp.s
.PHONY : src/widget/moc_BVStackWidget.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install/local"
	@echo "... edit_cache"
	@echo "... package_source"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... package"
	@echo "... gamos_gui"
	@echo "... gamos_gui_autogen"
	@echo "... gamos_gui_autogen/mocs_compilation.o"
	@echo "... gamos_gui_autogen/mocs_compilation.i"
	@echo "... gamos_gui_autogen/mocs_compilation.s"
	@echo "... main_app.o"
	@echo "... main_app.i"
	@echo "... main_app.s"
	@echo "... src/BExpertWindow.o"
	@echo "... src/BExpertWindow.i"
	@echo "... src/BExpertWindow.s"
	@echo "... src/BMainWindow.o"
	@echo "... src/BMainWindow.i"
	@echo "... src/BMainWindow.s"
	@echo "... src/moc_BExpertWindow.o"
	@echo "... src/moc_BExpertWindow.i"
	@echo "... src/moc_BExpertWindow.s"
	@echo "... src/moc_BMainWindow.o"
	@echo "... src/moc_BMainWindow.i"
	@echo "... src/moc_BMainWindow.s"
	@echo "... src/moc_BMainWindows.o"
	@echo "... src/moc_BMainWindows.i"
	@echo "... src/moc_BMainWindows.s"
	@echo "... src/utils/Helper.o"
	@echo "... src/utils/Helper.i"
	@echo "... src/utils/Helper.s"
	@echo "... src/widget/BHStackWidget.o"
	@echo "... src/widget/BHStackWidget.i"
	@echo "... src/widget/BHStackWidget.s"
	@echo "... src/widget/BNumberInput.o"
	@echo "... src/widget/BNumberInput.i"
	@echo "... src/widget/BNumberInput.s"
	@echo "... src/widget/BPathInput.o"
	@echo "... src/widget/BPathInput.i"
	@echo "... src/widget/BPathInput.s"
	@echo "... src/widget/BPhantomTab.o"
	@echo "... src/widget/BPhantomTab.i"
	@echo "... src/widget/BPhantomTab.s"
	@echo "... src/widget/BStyleLabel.o"
	@echo "... src/widget/BStyleLabel.i"
	@echo "... src/widget/BStyleLabel.s"
	@echo "... src/widget/BVStackWidget.o"
	@echo "... src/widget/BVStackWidget.i"
	@echo "... src/widget/BVStackWidget.s"
	@echo "... src/widget/moc_BHStackWidget.o"
	@echo "... src/widget/moc_BHStackWidget.i"
	@echo "... src/widget/moc_BHStackWidget.s"
	@echo "... src/widget/moc_BNumberInput.o"
	@echo "... src/widget/moc_BNumberInput.i"
	@echo "... src/widget/moc_BNumberInput.s"
	@echo "... src/widget/moc_BPathInput.o"
	@echo "... src/widget/moc_BPathInput.i"
	@echo "... src/widget/moc_BPathInput.s"
	@echo "... src/widget/moc_BPhantomTab.o"
	@echo "... src/widget/moc_BPhantomTab.i"
	@echo "... src/widget/moc_BPhantomTab.s"
	@echo "... src/widget/moc_BStyleLabel.o"
	@echo "... src/widget/moc_BStyleLabel.i"
	@echo "... src/widget/moc_BStyleLabel.s"
	@echo "... src/widget/moc_BVStackWidget.o"
	@echo "... src/widget/moc_BVStackWidget.i"
	@echo "... src/widget/moc_BVStackWidget.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

