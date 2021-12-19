CXX=g++
CXXFLAGS = -std=c++11 -g
ROOT_DIR := $(shell git rev-parse --show-toplevel)
-include $(ROOT_DIR)/config/settings
-include $(DEP_DIR)/env

WEB_DIR = /project/grades/Fall-2021/csci3081/dependencies/include/
ACTUAL_LIB= /project/grades/Fall-2021/csci3081/dependencies/lib/
BUILD_DIR = build
INCLUDES = -I.. -I$(DEP_DIR)/include -Isrc -I. -I$(DEP_DIR)/include -Iinclude -I. -I$(WEB_DIR) -Isrc/simulation_facade -Isrc/img_proc_src
LIBDIRS = -L$(DEP_DIR)/lib -L$(ACTUAL_LIB)
LIBS = -lCppWebServer -lwebsockets -lssl -lcrypto -lz -lpthread

SOURCES = $(shell find src -name '*.cc')
OBJFILES = $(addprefix $(BUILD_DIR)/, $(SOURCES:.cc=.o))

EXEFILE = $(BUILD_DIR)/web-app

TESTFILES = $(shell find tests -name '*.cc')
TESTOBJFILES = $(filter-out $(BUILD_DIR)/src/main.o $(BUILD_DIR)/src/web_app.o,$(OBJFILES)) $(addprefix $(BUILD_DIR)/, $(TESTFILES:.cc=.o))
TESTEXEFILE = $(BUILD_DIR)/test-app

all: $(BUILD_DIR) $(EXEFILE) tests

tests: $(BUILD_DIR) $(TESTEXEFILE)

# Applicaiton Targets:
$(EXEFILE): $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(LIBDIRS) $(OBJFILES) $(LIBS) -o $@

# Object File Targets:
$(BUILD_DIR)/%.o: %.cc
	mkdir -p $(dir $@)
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Generate dependencies
make-depend-cxx=$(CXX) -MM -MF $3 -MP -MT $2 $(CXXFLAGS) $(INCLUDES) $1
-include $(OBJFILES:.o=.d)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TESTEXEFILE): $(TESTOBJFILES)
	$(CXX) $(CXXFLAGS) $(LIBDIRS) $(TESTOBJFILES) -lgtest_main -lgtest -lgmock $(LIBS) -o $@

clean:
	rm -rf build
	rm *.csv
