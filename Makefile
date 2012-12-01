CFLAGS=-O0 -g -Wall -I libgraphoscope
CXXFLAGS=$(CFLAGS)
LDFLAGS=-lSDL -lSDL_mixer
SOURCES=`ls *.cpp`
BUILDS=ninja_gl ninja_scope
MAKE=make
all: .depend $(BUILDS)

.depend:
	fastdep $(SOURCES) > .depend

-include .depend

libgraphoscope_soundcard.o:\
	audio_buffer.o\
	graphoscope_soundcard.o
	ld -r $^ -o $@

libgraphoscope_sdl_gl.o:\
	graphoscope_sdl_gl.o
	ld -r $^ -o $@

ninja_gl: main.o libgraphoscope/libgraphoscope_sdl_gl.o
	$(CXX) -o $@ $(LDFLAGS) $^ -lGL -lGLU

ninja_scope: main.o libgraphoscope/libgraphoscope_soundcard.o
	$(CXX) -o $@ $(LDFLAGS) $^ -lGL -lGLU

libgraphoscope/libgraphoscope_sdl_gl.o:
	$(MAKE) -C libgraphoscope

libgraphoscope/libgraphoscope_soundcard.o:
	$(MAKE) -C libgraphoscope
	
clean:
	rm -f *.o .depend $(BUILDS)
	$(MAKE) -C libgraphoscope clean
