ifeq ($(ENABLE_COVERAGE), true)
    FLGS += -fprofile-arcs -ftest-coverage
    LDFLGS += -fprofile-arcs -ftest-coverage
    CFLAGS += -fprofile-arcs -ftest-coverage
    CXXFLAGS += -fprofile-arcs -ftest-coverage
endif

FLGS = -g -DUSE_EXTERN_C -Wl,-rpath=.
LDFLGS = -shared -fPIC

ifeq ($(ci_test),1)
FLGS += -DCI_TEST
endif

DIRS = -Isoftfloat -Ism_model_common -Ism_sfu -Ism_matrix -Ism_vae -Ism_export
HDRS = $(wildcard sm_model_common/*.h)  \
	   $(wildcard sm_sfu/*.h) \
	   $(wildcard sm_matrix/*.h) \
	   $(wildcard sm_vae/*.h) \
	   $(wildcard sm_export/*.h) \

SRCS = $(wildcard sm_model_common/*.cc)  \
	   $(wildcard sm_sfu/*.cc) \
	   $(wildcard sm_matrix/*.cc) \
	   $(wildcard sm_vae/*.cc) \
	   $(wildcard sm_export/*.cc)\
	   $(wildcard tests/*.cc)

CXX_OBJS = $(patsubst %.cc, bin/%.o, $(SRCS))
DYNAMIC_LIB_OBJS = $(filter-out %main.o, $(CXX_OBJS))
EXECUTABLE_OBJS =  $(filter %main.o, $(CXX_OBJS))

all: libsoftfp.a libcmodel.so test.elf
	@echo "-------- build all targets finish --------\n"

bin/%.o: %.cc
	@mkdir -p $(@D)
	g++ -std=c++11 $(FLGS) $(CXXFLAGS) $(LDFLGS) $(DIRS) -c $< -o $@

libcmodel.so: $(DYNAMIC_LIB_OBJS) libsoftfp.a
	g++ -std=c++11 $(FLGS) $(CXXFLAGS) $(LDFLGS) -o $@ $^ libsoftfp.a
	@echo "-------- build: $@ finish --------\n"

test.elf: $(EXECUTABLE_OBJS) libcmodel.so
	g++ -std=c++11 $(FLGS) $(CXXFLAGS) $(DIRS) -o $@ $^ -L. -lcmodel libsoftfp.a
	@echo "-------- build: $@ finish --------\n"

F_SRCS = $(wildcard softfloat/*.c)
F_OBJS = $(patsubst softfloat/%.c, build/%.o, $(F_SRCS))

build/%.o: softfloat/%.c
	gcc -fPIC $(FLGS) $(CFLAGS) -c $^ -o $@

build:
	mkdir -p build

libsoftfp.a: build $(F_OBJS)
	ar rcs $@ $(F_OBJS)
	@echo "-------- build: $@ finish --------\n"

clean:
	rm -f test.elf
	rm -f libcmodel.so
	rm -rf $(shell find . -name "*.gcda")
	rm -rf $(shell find . -name "*.gcno")
	rm -rf $(shell find . -name "*.gcov")

distclean:
	@rm -rf libcmodel.so
	@rm -f test.elf
	@rm -f libsoftfp.a
	@rm -rf build/
	@rm -rf bin/
	@rm -rf $(shell find . -name "*.gcda")
	@rm -rf $(shell find . -name "*.gcno")
	@rm -rf $(shell find . -name "*.gcov")
	@rm -rf coverage.info coverage_reports/ coverage_data/
