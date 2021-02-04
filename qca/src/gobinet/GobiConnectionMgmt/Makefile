INCLUDES=-I ../Core -I ../Shared -lrt -L. -lCore
CXXFLAGS=-Wunused-variable -fPIC --std=c++11
LDFLAGS=-melf_i386
DEBUGFLAGS=-g3 -D DEBUG
INCLUDEFILES=../Core/Comm.h \
	../Core/Connection.h \
	../Core/Event.h \
	../Core/ProtocolBuffer.h \
	../Core/ProtocolEnum.h \
	../Core/ProtocolLog.h \
	../Core/ProtocolNotification.h \
	../Core/ProtocolRequest.h \
	../Core/ProtocolServer.h \
	../Core/QMIBuffers.h \
	../Core/QMIEnum.h \
	../Core/QMIProtocolServer.h \
	../Core/SharedBuffer.h \
	../Core/Socket.h \
	../Core/StdAfx.h \
	../Core/SyncQueue.h \
	GobiConnectionMgmt.h \
	../Shared/GobiError.h \
	../Shared/GobiQMICore.h
SOURCES=GobiConnectionMgmtExports.cpp \
        GobiConnectionMgmt.cpp \
        ../Shared/GobiQMICore.cpp
OUTPUT=GobiConnectionMgmt.so
INSTALLDIR=/opt/Qualcomm/GobiExtensibleAPI/


all: clean $(OUTPUT)

$(OUTPUT): $(SOURCES) $(INCLUDEFILES) libCore.a
	$(CXX) $(CXXFLAGS) -shared $(SOURCES) $(INCLUDES) -o $(OUTPUT) 


# Must set ANDROID_PATH variable
Android: 
	$(MAKE) $(MFLAGS) \
      PATH=$(PATH):$(ANDROID_PATH) \
      CXX="arm-linux-androideabi-g++ --verbose" \
      LD=arm-linux-androideabi-ld \
      AR=arm-linux-androideabi-ar \
      CXXFLAGS=-Wunused-variable \
      LDFLAGS=-marmelf_linux_eabi \
      INCLUDES="-I ../Core -I ../Shared -L. -lCore" \
      all

# Must set OE_PATH variable
OpenEmbedded: 
	$(MAKE) $(MFLAGS) \
      PATH=$(PATH):$(OE_PATH) \
      CXX="arm-oe-linux-gnueabi-g++" \
      LD=arm-oe-linux-gnueabi-ld \
      AR=arm-oe-linux-gnueabi-ar \
      CXXFLAGS=-Wunused-variable \
      LDFLAGS=-marmelf \
      INCLUDES="-I ../Core -I ../Shared -L. -lCore" \
      all

install: $(OUTPUT)
	mkdir -p $(INSTALLDIR)
	cp -f $(OUTPUT) $(INSTALLDIR)
	cp GobiConnectionMgmtAPI.h $(INSTALLDIR)
	cp GobiConnectionMgmtAPIEnums.h $(INSTALLDIR)
	cp GobiConnectionMgmtAPIStructs.h $(INSTALLDIR)

clean:
	rm -f $(OUTPUT) \
         libCore.a \
         Comm.o \
         Event.o \
         ProtocolBuffer.o \
         ProtocolLog.o \
         ProtocolNotification.o \
         ProtocolRequest.o \
         ProtocolServer.o \
         QMIBuffers.o \
         QMIProtocolServer.o \
         SharedBuffer.o \
         Socket.o

debug: 
	$(MAKE) $(MFLAGS) CXXFLAGS="$(CXXFLAGS) $(DEBUGFLAGS)" all

libCore.a: Comm.o \
           Event.o \
           ProtocolBuffer.o \
           ProtocolLog.o \
           ProtocolNotification.o \
           ProtocolRequest.o \
           ProtocolServer.o \
           QMIBuffers.o \
           QMIProtocolServer.o \
           SharedBuffer.o \
           Socket.o
	$(AR) rcs libCore.a \
          Comm.o \
          Event.o \
          ProtocolBuffer.o \
          ProtocolLog.o \
          ProtocolNotification.o \
          ProtocolRequest.o \
          ProtocolServer.o \
          QMIBuffers.o \
          QMIProtocolServer.o \
          SharedBuffer.o \
          Socket.o

Comm.o: ../Core/Comm.cpp
	$(CXX) $(CXXFLAGS) -c ../Core/Comm.cpp

Event.o: ../Core/Event.cpp
	$(CXX) $(CXXFLAGS) -c ../Core/Event.cpp

ProtocolBuffer.o: ../Core/ProtocolBuffer.cpp
	$(CXX) $(CXXFLAGS) -c ../Core/ProtocolBuffer.cpp

ProtocolLog.o: ../Core/ProtocolLog.cpp
	$(CXX) $(CXXFLAGS) -c ../Core/ProtocolLog.cpp

ProtocolNotification.o: ../Core/ProtocolNotification.cpp
	$(CXX) $(CXXFLAGS) -c ../Core/ProtocolNotification.cpp

ProtocolRequest.o: ../Core/ProtocolRequest.cpp
	$(CXX) $(CXXFLAGS) -c ../Core/ProtocolRequest.cpp

ProtocolServer.o: ../Core/ProtocolServer.cpp
	$(CXX) $(CXXFLAGS) -c ../Core/ProtocolServer.cpp

QMIBuffers.o: ../Core/QMIBuffers.cpp
	$(CXX) $(CXXFLAGS) -c ../Core/QMIBuffers.cpp

QMIProtocolServer.o: ../Core/QMIProtocolServer.cpp
	$(CXX) $(CXXFLAGS) -c ../Core/QMIProtocolServer.cpp

SharedBuffer.o: ../Core/SharedBuffer.cpp
	$(CXX) $(CXXFLAGS) -c ../Core/SharedBuffer.cpp

Socket.o: ../Core/Socket.cpp
	$(CXX) $(CXXFLAGS) -c ../Core/Socket.cpp
	
