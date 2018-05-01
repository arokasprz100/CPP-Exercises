ALLSRC=cotest.cpp Containers.cpp
EXEC=test
CXXFLAGS=-Wall -g 


$(EXEC): $(ALLSRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(EXEC)
	./$(EXEC)  | tee results

fail: $(ALLSRC)
	$(CXX) $(CXXFLAGS) -DCOMPILE_ERROR $^ -o $@

clean:
	rm -f $(EXEC) *.o