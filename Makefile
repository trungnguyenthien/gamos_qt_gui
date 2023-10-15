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

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

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

src/widget/BStackWidget.o: src/widget/BStackWidget.cpp.o

.PHONY : src/widget/BStackWidget.o

# target to build an object file
src/widget/BStackWidget.cpp.o:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BStackWidget.cpp.o
.PHONY : src/widget/BStackWidget.cpp.o

src/widget/BStackWidget.i: src/widget/BStackWidget.cpp.i

.PHONY : src/widget/BStackWidget.i

# target to preprocess a source file
src/widget/BStackWidget.cpp.i:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BStackWidget.cpp.i
.PHONY : src/widget/BStackWidget.cpp.i

src/widget/BStackWidget.s: src/widget/BStackWidget.cpp.s

.PHONY : src/widget/BStackWidget.s

# target to generate assembly for a file
src/widget/BStackWidget.cpp.s:
	$(MAKE) -f CMakeFiles/gamos_gui.dir/build.make CMakeFiles/gamos_gui.dir/src/widget/BStackWidget.cpp.s
.PHONY : src/widget/BStackWidget.cpp.s

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

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... gamos_gui"
	@echo "... gamos_gui_autogen"
	@echo "... gamos_gui_autogen/mocs_compilation.o"
	@echo "... gamos_gui_autogen/mocs_compilation.i"
	@echo "... gamos_gui_autogen/mocs_compilation.s"
	@echo "... main_app.o"
	@echo "... main_app.i"
	@echo "... main_app.s"
	@echo "... src/BMainWindow.o"
	@echo "... src/BMainWindow.i"
	@echo "... src/BMainWindow.s"
	@echo "... src/moc_BMainWindow.o"
	@echo "... src/moc_BMainWindow.i"
	@echo "... src/moc_BMainWindow.s"
	@echo "... src/widget/BPhantomTab.o"
	@echo "... src/widget/BPhantomTab.i"
	@echo "... src/widget/BPhantomTab.s"
	@echo "... src/widget/BStackWidget.o"
	@echo "... src/widget/BStackWidget.i"
	@echo "... src/widget/BStackWidget.s"
	@echo "... src/widget/moc_BPhantomTab.o"
	@echo "... src/widget/moc_BPhantomTab.i"
	@echo "... src/widget/moc_BPhantomTab.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

