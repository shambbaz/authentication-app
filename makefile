# C++ kääntäjä
CXX = g++
CXXFLAGS = -Wall -g

# Lähdekoodit (muutettu .cpp:ksi)
SOURCES = main.cpp test_auth.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Suoritettava tiedosto
EXEC = autentikointijärjestelmä

# Rakentaminen
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC)

# Käännä .cpp -> .o
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Puhdistaminen
clean:
	rm -f $(OBJECTS) $(EXEC)
