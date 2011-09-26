CXX		 ?= g++
RM		 ?= rm
CP		 ?= cp
MKDIR  ?= mkdir
TAR		 ?= tar
GZIP	 ?= gzip

HEADERS = eratostene.h \
					goldbach.h
SOURCES	= eratostene.cpp \
					goldbach.cpp \
					main.cpp
OBJECTS	= $(SOURCES:.cpp=.o)

TARGET	= goldbach
VERSION = 0.0.1
PROG		= $(TARGET)-$(VERSION)

all: $(OBJECTS) $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "CXX    $(TARGET)"
	@$(CXX) -o $(TARGET) $(OBJECTS)

$(OBJECTS): $(SOURCES)

$(SOURCES): $(HEADERS)

.cpp.o:
	@echo "CXX -c $@"
	@$(CXX) -c $< -o $@

dist:
	@$(MKDIR) -p $(PROG)
	@$(CP) $(SOURCES) $(HEADERS) README Makefile $(PROG)
	@$(TAR) cf $(PROG).tar $(PROG)
	@$(GZIP) $(PROG).tar
	@$(RM) -r $(PROG)

clean:
	@echo "RM $(OBJECTS) $(TARGET)"
	@$(RM) -f $(OBJECTS) $(TARGET)

.PHONY: all clean
