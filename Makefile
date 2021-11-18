CXX=g++
CXXFLAGS = -std=c++11 -g
ROOT_DIR := $(shell git rev-parse --show-toplevel)
-include $(ROOT_DIR)/config/settings
-include $(DEP_DIR)/env

SOURCES = $(wildcard */*.cc)
SOURCEDIRS = $(wildcard *_src/)
OBJFILES = $(notdir $(SOURCES:.cc=.o))

#all: image_processor

# Applicaiton Targets:
image_processor: $(OBJFILES) main.o
	$(CXX) $(CXXFLAGS) $(addprefix img_proc_src/,$(OBJFILES)) -o $@
	
# Main obj files
main.o: img_proc_src/main.cc
	$(CXX) $(CXXFLAGS) -c $< -o img_proc_src/$@

# Object file targets	
%.o: $(SOURCEDIRS)/%.cc $(SOURCEDIRS)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $(SOURCEDIRS)/$@

clean:
	rm -f $(SOURCEDIRS)/*.o image_processor