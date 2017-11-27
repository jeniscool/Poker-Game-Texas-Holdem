OBJECTS = card.o deck.o rank.o SortedLinkedList.o pokerhand.o
	#(listing all object files)
HEADERS = card.h deck.h rank.h SortedLinkedList.h pokerhand.h
	#(listing all header files)
PROGRAM = CS216PA2
$(PROGRAM): $(OBJECTS) PA2.o
	g++ $^ -o $@
testPA2 : $(OBJECTS) testPA2.o
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
Clean:
	rm -i *.o $(PROGRAM)

