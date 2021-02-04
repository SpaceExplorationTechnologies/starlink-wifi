# Compile, link and install the QTI Gobinet Connection Manager
# on OpenWrt;

# ====================================================================
# symbols;
# --------------------------------------------------------------------

VPATH=../Core:../Gobi3000Translation:../GobiConnectionMgmt:../GobiSampleCM:../Shared
CXXFLAGS += -fPIC -DDEBUG -std=c++0x -Wunused-variable -I../Core -I../Gobi3000Translation -I../GobiConnectionMgmt -I../GobiNet -I../Shared
LDFLAGS += -L. -L../Core -L../GobiConnectionMgmt -lCore -lgobicm
DBGFLAGS=-g3

# ====================================================================
# rules;
# --------------------------------------------------------------------

.PHONY: all clean compile install

%:%.o
	${CXX} -o ${@} ${^} ${LDFLAGS}

%.o:%.cpp
	${CXX} -c ${<} ${CXXFLAGS} ${DBGFLAGS}

%.o:%.c
	${CXX} -c ${<} ${CXXFLAGS} ${DBGFLAGS}

# ====================================================================
# targets;
# --------------------------------------------------------------------

all: clean compile
compile: libCore.a libgobicm charlietalk
install: compile
	echo ${STAGING_DIR}

clean:
	rm -f charlietalk libgobicm.* *.o *.so *.a

# ====================================================================
# programs;
# --------------------------------------------------------------------

charlietalk: charlietalk.o Gobi3000Translation.o Gobi3000TranslationDMS.o Gobi3000TranslationWDS.o Gobi3000TranslationNAS.o charlietalkError.o charlietalkCallback.o charlietalkChannelAvoidance.o
	${CXX} -o charlietalkd ${^} ${DBGFLAGS} ${CXXFLAGS} ${LDFLAGS}

# ====================================================================
# components;
# --------------------------------------------------------------------

libgobicm: GobiConnectionMgmtExports.o GobiConnectionMgmt.o GobiQMICore.o Comm.o Event.o ProtocolBuffer.o ProtocolLog.o ProtocolNotification.o ProtocolRequest.o ProtocolServer.o QMIBuffers.o QMIProtocolServer.o SharedBuffer.o Socket.o
	$(CXX) -o ${@} ${^} ${DBGFLAGS} ${CXXFLAGS} --shared
	ln -fs ${@} libgobicm.so
libCore.a: Comm.o Event.o ProtocolBuffer.o ProtocolLog.o ProtocolNotification.o ProtocolRequest.o ProtocolServer.o QMIBuffers.o QMIProtocolServer.o SharedBuffer.o Socket.o
	$(AR) rcs ${@} ${^}
