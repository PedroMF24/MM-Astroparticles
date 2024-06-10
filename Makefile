CXX := g++
CXXFLAGS := -std=c++17 -fPIC
LDFLAGS := -L lib -l FC -lpthread

UNAME := $(shell uname)

SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst %.cpp, bin/%.o, $(notdir $(SRCS)) )
EXES := $(patsubst %.cpp, bin/%.exe, $(notdir $(wildcard main/*.cpp)) )

# ifeq ($(UNAME),Linux)
# 	EIGEN_INC := $(shell pkg-config --cflags eigen3 )
# 	else
# 	EIGEN_INC := -I /usr/local/Cellar/eigen/3.4.0_1/include/eigen3
# endif	

# ROOT_INC := -I $(shell root-config --incdir)
# ROOT_LIB := $(shell root-config --libs)
# LDFLAGS+=-L$(LIBDIR) -l2HDMC -lgsl -lgslcblas -lm

VPATH = main:src

# # Specify phony targets
.PHONY: main run clean

# # $(EXES)
# main:
# 	@echo Compiling ...
# 	$(MAKE) $(EXES)
# 	@echo Done

# # Target to run the main executable
# run: bin/main.exe
# 	@echo Running bin/main.exe ...
# 	./bin/main.exe

main: $(EXES)

run: bin/main.exe
	@echo Running bin/main.exe ...
	./bin/main.exe

lib: lib/libFC.a

lib/%.a: $(OBJS)
	@echo making lib...[$^]
	ar ruv $@ $^
	ranlib $@

bin/%.exe: bin/%.o lib/libFC.a 
	@echo executable... $< [$@]
	$(CXX) $(CXXFLAGS) -o $@ $< -I src $(LDFLAGS)

bin/%.o: %.cpp
	@echo compiling... $< [$@]
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I src

clean:
	@echo cleaning...
	rm -f $(wildcard bin/*) $(wildcard lib/*) $(wildcard data/*)

dump:
	@echo SRCS...[$(SRCS)] [$(OBJS)] [$(EXES)]
	@echo $(UNAME)
	@echo src: $(SRCS)
	@echo obj: $(OBJS)
	@echo exe: $(EXES)
