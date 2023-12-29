bin/testTableEntry: testTableEntry.cpp tableentry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp

bin/testBSTree: testBSTree.cpp BSTree.h
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp

bin/testBSTreeDict: testBSTreeDict.cpp BSDict.h
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp

clean:
	rm -rf *.o *.gch bin
