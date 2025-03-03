# source for our main program
SRC := csv_file.cpp main.cpp

# source for our test program
TEST_SRC := $(shell find *_test.cpp)

# gtest sources
GTEST_SRC := gtest/src/gtest-assertion-result.cc gtest/src/gtest-death-test.cc gtest/src/gtest-filepath.cc gtest/src/gtest-matchers.cc gtest/src/gtest-port.cc gtest/src/gtest-printers.cc gtest/src/gtest-test-part.cc gtest/src/gtest-typed-test.cc gtest/src/gtest.cc

.PHONY: unoptimized
unoptimized:
	g++ -std=c++20 -fprofile-arcs -ftest-coverage -fprofile-values -fPIC -g $(SRC)

.PHONY: optimized
optimized:
	g++ -std=c++20 -fprofile-arcs -ftest-coverage -fprofile-values -fPIC -g -O3 $(SRC)

.PHONY: test
test:
	g++ -std=c++20 -O3 -I gtest/include -I gtest $(GTEST_SRC) $(TEST_SRC) -o input_tester \
		-lgtest -lgtest_main -lpthread
