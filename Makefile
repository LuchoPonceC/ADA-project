CC = g++ 
CXXFLAAGS= -Wall -g
PROGRAMS = main 

all: $(PROGRAMS)

clean:
	rm -r $(PROGRAMS)  
	
