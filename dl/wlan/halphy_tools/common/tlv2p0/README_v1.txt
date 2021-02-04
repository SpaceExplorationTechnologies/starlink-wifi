/*

  Welcome, this is TLV 2.0 for UTF/FTM.

  A little bit history ...
  The TLV 1.0 was created to provide a Test Sequence (TS) based solution to address the challenge 
  Atheros AEs (now CEs) faced while supporting a wide range of HLOS on customer platforms.
  For example, to support ART/NART on Venus, a daemon, often more, needs to run on a customer platform.
  The link between testing PC and embedded host can be slow and unreliable, e.g. serial.
  
  The secondary problem is the testing speed, not satisfactory to customers.

  Thus, born the test sequence based solution ...
  A test sequence is known to both testing PC and target. There is no communication between them through
  any cable connection.
  The test proceeding is coordinated via a simple handshake protocol over RF.

  TLV 1.0 was implemented for this purpose. 
  It has the following requirements/constraints:
    1. a small set of commands/responses suffice;
    2. it should be brief, for memory consideration;

  But, later it was expanded for all communication between host and DUT.
  Thus exposed the following shortcomings:
    1. Adding a new command can be a bit work;
    2. It could enlarge the state machine (for handshaking protocol), though pipes are created to channel
       simple commands/responses;
    3. It would consume more memory if more commands/responses are added;
    4. Some optimization could be done;

  After realizing the TLV for UTF/FTM has become a liability, and my dear colleagues are hesitant to 
  touch it, I intended to restructure it in the following way:
    1. Added version 2 for TLV 2.0, which supports simple ONE command/response;
    2. Kept version 1 for TS solution which is requested by Corp Testing Solution;
    3. Simplified the implementation and usage, which became a main driving force;
    
  The code is structured (at least trying) in self contained, modular fashion, e.g. an encoder and a parser
  which can be used in the host or DUT. They are symmetric.

  The file directory is organized accordingly, with "common" containing shared files.
    common
      include
      src
    cmdEncoder
      include
      src
    cmdParser
      include
      src

  Please refer to cmdRspParmsDict.[ch] for some helpful notes.
   
  The example below of adding RX cmd illustrates the steps and files involved.

  You should have the RX command behavior (cmd handling and response processing)
  and parameter structure defined already.

  1. Add command code to, identify parameter codes, if available, in the cmdRspParmsDict.src
     1.1 If a parameter is not in the dictionary, add it to the dictionary
         cmdRspParmsDict.src

     1.2 The build script generates cmdRspParmsDict.[ch]

     (This step should take care of the encoder and lay foundation for the parser ...)

  2. Add command handler
     2.1 cmdRxHandler.h
         typedef struct rx_parms_struct {
             A_UINT8   freq;
             ...
         } RX_PARMS;

     2.2 cmdRxHandler.c
         void* initRxOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
         {
         }
         void rxOp(A_UINT32 phyId, void *pParms)
         {
         }

     2.3 Add the command handler to cmdHandlerTbl.c

     (Done with the parser ...)

*/
