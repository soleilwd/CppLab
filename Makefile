
# environment
BUILD_CONFIG := debug
BASE_DIR := $(shell pwd)
EXT_DIR := ${BASE_DIR}/../ext
BUILD_DIR := ${BASE_DIR}/${BUILD_CONFIG}
DIRS := $(shell find '${BASE_DIR}' -maxdepth 1 -mindepth 1 -type d)
PROJ_DIRS := $(filter-out ${BUILD_DIR},${DIRS})
PROJS := $(notdir ${PROJ_DIRS})

# enable build platform for (only) cygwin and linux 
OS := $(shell uname -o)
PLATFORM :=
ifeq ($(findstring Cygwin,${OS}),Cygwin)
	PLATFORM := cygwin
endif
ifeq ($(findstring Linux,${OS}),Linux)
	PLATFORM := linux
endif

export BUILD_CONFIG PLATFORM BASE_DIR BUILD_DIR EXT_DIR

# targets
TARGETS := ${PROJS}
ifeq (${PLATFORM},cygwin)
	TARGETS := $(patsubst %,%.dll,${PROJS})
endif
ifeq (${PLATFORM},linux)
	TARGETS := $(patsubst %,lib%.so,${PROJS})
endif

.PHONY : all
all : ${TARGETS}
	@for proj in ${PROJS}; \
	do \
		echo "making target $${proj}.."; \
		cd $${proj} && $(MAKE); \
		echo "$${proj} has been made"; \
	done
	@echo Build has completed successfully.

${TARGETS} : ${BUILD_DIR}

${BUILD_DIR} :
	@mkdir -p ${BUILD_DIR}
	for proj in ${PROJS}; do mkdir -p ${BUILD_DIR}/$${proj}; done;

	
.PHONY : test
test :
	@echo ${PROJS}

.PHONY : clean
clean :
	@echo cleaning intermediate and temporary files...
	-rm -rf ${BUILD_DIR}
	-for proj in ${PROJS}; do cd $${proj} && rm -f *.dll *.so *.u *.o; done
	
