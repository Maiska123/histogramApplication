ifeq ($(BUILD),debug)   
# "Debug" build - no optimization, and debugging symbols
CFLAGS += -O0 -g
else
# "Release" build - optimization, and no debug symbols
CFLAGS += -O2 -s -DNDEBUG
endif
#
# make BUILD=debug
#

all: App

ifeq ($(BUILD),debug)   
App: main.o
	@mkdir -p build\Debug
	g++ -o  build\Debug\histogramApplicationDebug .\RandomEintegerGenerator.o .\Log.o .\Histogram.o .\main.o
else

App: main.o
	@mkdir -p build\Release
	g++ -o  build\Release\histogramApplication .\RandomEintegerGenerator.o .\Log.o .\Histogram.o .\main.o
endif

main.o: 
	g++ $(CFLAGS) -I . -c -std=c++17 -Wall -Wextra -Wpedantic -Werror .\Histogram.cpp .\Log.cpp .\RandomEintegerGenerator.cpp  .\main.cpp

.PHONY: 
	clean

clean:
	rm *.o 
