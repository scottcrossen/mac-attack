# Makefile for macappend

CXX = g++ $(CCFLAGS)
MACAPPEND = macappend.o
LIBS = sha1.o utils.o
OBJS = $(MACAPPEND) $(LIBS)
CCFLAGS = -g -Wall -std=c++11

all: $(MACAPPEND) $(LIBS)
	$(CXX) -o macappend $(MACAPPEND) $(LIBS)

clean:
	rm -f $(OBJS) $(OBJS:.o=.d) macappend

test: all
	./macappend -v

%.d: %.cpp
	$(SHELL) -ec '$(CC) -M $(CPPFLAGS) $< \
		| sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
		[ -s $@ ] || rm -f $@'

include $(OBJS:.o=.d)
