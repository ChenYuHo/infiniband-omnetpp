//
// Generated file, do not edit! Created by opp_msgtool 6.0 from ib.msg.
//

#ifndef __IB_M_H
#define __IB_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class IBWireMsg;
class IBDataMsg;
class IBFlowControl;
class IBTQLoadUpdateMsg;
class IBSinkTimerMsg;
class IBTxCredMsg;
class IBRxCredMsg;
class IBSentMsg;
class IBFreeMsg;
class IBDoneMsg;
class IBAppMsg;
class IBPushFECNMsg;
class IBPushBECNMsg;
/**
 * Enum generated from <tt>ib.msg:23</tt> by opp_msgtool.
 * <pre>
 * // Enumarate all IB massages
 * enum IB_MSGS
 * {
 *     IB_DATA_MSG = 1;
 *     IB_FLOWCTRL_MSG = 2;
 *     IB_SENT_MSG = 3;
 *     IB_TXCRED_MSG = 4;
 *     IB_RXCRED_MSG = 5;
 *     IB_MINTIME_MSG = 6;
 *     IB_POP_MSG = 7;
 *     IB_HICCUP_MSG = 8;
 *     IB_FREE_MSG = 9;
 *     IB_DONE_MSG = 10;
 *     IB_APP_MSG = 11;
 *     IB_PUSH_MSG = 12;
 *     IB_TQ_LOAD_MSG = 13;
 *     IB_TIMER_MSG = 14;     // general timer, used for throughput calculation etc
 *     IB_PUSHFECN_MSG = 15;
 *     IB_PUSHBECN_MSG = 16;
 *     IB_CCTIMER_MSG = 17;   // IB CC timer for rate increase
 *     IB_SENDTIMER_MSG = 18;
 *     IB_SINKTIMER_MSG = 19;  // timer at sink module for new cc control
 * }
 * 
 * ///////////////////////////////////////////////////////////////////////////
 * //
 * // MESSAGES THAT ARE AVAILABLE ON IB WIRE
 * //
 * 
 * //
 * // Base class for all type of IB wire messages
 * //
 * </pre>
 */
enum IB_MSGS {
    IB_DATA_MSG = 1,
    IB_FLOWCTRL_MSG = 2,
    IB_SENT_MSG = 3,
    IB_TXCRED_MSG = 4,
    IB_RXCRED_MSG = 5,
    IB_MINTIME_MSG = 6,
    IB_POP_MSG = 7,
    IB_HICCUP_MSG = 8,
    IB_FREE_MSG = 9,
    IB_DONE_MSG = 10,
    IB_APP_MSG = 11,
    IB_PUSH_MSG = 12,
    IB_TQ_LOAD_MSG = 13,
    IB_TIMER_MSG = 14,
    IB_PUSHFECN_MSG = 15,
    IB_PUSHBECN_MSG = 16,
    IB_CCTIMER_MSG = 17,
    IB_SENDTIMER_MSG = 18,
    IB_SINKTIMER_MSG = 19
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IB_MSGS& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IB_MSGS& e) { int n; b->unpack(n); e = static_cast<IB_MSGS>(n); }

/**
 * Class generated from <tt>ib.msg:55</tt> by opp_msgtool.
 * <pre>
 * message IBWireMsg extends cPacket
 * {
 *     short VL; // the VL for the packet
 * }
 * 
 * //
 * // NOTE the generic message already have length in bits !!!
 * //
 * </pre>
 */
class IBWireMsg : public ::omnetpp::cPacket
{
  protected:
    short VL = 0;

  private:
    void copy(const IBWireMsg& other);

  protected:
    bool operator==(const IBWireMsg&) = delete;

  public:
    IBWireMsg(const char *name=nullptr, short kind=0);
    IBWireMsg(const IBWireMsg& other);
    virtual ~IBWireMsg();
    IBWireMsg& operator=(const IBWireMsg& other);
    virtual IBWireMsg *dup() const override {return new IBWireMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual short getVL() const;
    virtual void setVL(short VL);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBWireMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBWireMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ib.msg:64</tt> by opp_msgtool.
 * <pre>
 * message IBDataMsg extends IBWireMsg
 * {
 *     int appIdx;           // the application index within the SRC
 *     int msgIdx;           // a message ID unique to the SRC
 *     int msgLen;           // number of packets in the msg
 *     int pktIdx;           // packet index within the message
 *     int packetId;       	// globally unique packet ID 
 *     int packetSn;         // serial number of packet by the source to this dst 
 *     int flitSn;       	// serial number with the flit: 0..N 
 *     int PacketLength;     // Total number of credits in this packet. 
 *     int PacketLengthBytes;// Total packet Length in Bytes
 *     int dstLid;         	// target LID 
 *     int srcLid;         	// source LID 
 *     int SL;             	// the SL 
 *     int useStatic;       	// Used in ib_credits
 *     simtime_t SwTimeStamp;// Time stamp set when credit gets in IBRX    
 *     simtime_t injectionTime; // the time the credit hit the wire 
 *     bool beforeAnySwitch; // set to true by HCA and then to false by the first switch - to identify loops
 *     int isFECN;           //mark congested root
 *     int isBECN;           //carried in CNP
 *     int isAppMsg;
 *     double RecvRate;
 * }
 * </pre>
 */
class IBDataMsg : public ::IBWireMsg
{
  protected:
    int appIdx = 0;
    int msgIdx = 0;
    int msgLen = 0;
    int pktIdx = 0;
    int packetId = 0;
    int packetSn = 0;
    int flitSn = 0;
    int PacketLength = 0;
    int PacketLengthBytes = 0;
    int dstLid = 0;
    int srcLid = 0;
    int SL = 0;
    int useStatic = 0;
    omnetpp::simtime_t SwTimeStamp = SIMTIME_ZERO;
    omnetpp::simtime_t injectionTime = SIMTIME_ZERO;
    bool beforeAnySwitch = false;
    int isFECN = 0;
    int isBECN = 0;
    int isAppMsg = 0;
    double RecvRate = 0;

  private:
    void copy(const IBDataMsg& other);

  protected:
    bool operator==(const IBDataMsg&) = delete;

  public:
    IBDataMsg(const char *name=nullptr, short kind=0);
    IBDataMsg(const IBDataMsg& other);
    virtual ~IBDataMsg();
    IBDataMsg& operator=(const IBDataMsg& other);
    virtual IBDataMsg *dup() const override {return new IBDataMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getAppIdx() const;
    virtual void setAppIdx(int appIdx);

    virtual int getMsgIdx() const;
    virtual void setMsgIdx(int msgIdx);

    virtual int getMsgLen() const;
    virtual void setMsgLen(int msgLen);

    virtual int getPktIdx() const;
    virtual void setPktIdx(int pktIdx);

    virtual int getPacketId() const;
    virtual void setPacketId(int packetId);

    virtual int getPacketSn() const;
    virtual void setPacketSn(int packetSn);

    virtual int getFlitSn() const;
    virtual void setFlitSn(int flitSn);

    virtual int getPacketLength() const;
    virtual void setPacketLength(int PacketLength);

    virtual int getPacketLengthBytes() const;
    virtual void setPacketLengthBytes(int PacketLengthBytes);

    virtual int getDstLid() const;
    virtual void setDstLid(int dstLid);

    virtual int getSrcLid() const;
    virtual void setSrcLid(int srcLid);

    virtual int getSL() const;
    virtual void setSL(int SL);

    virtual int getUseStatic() const;
    virtual void setUseStatic(int useStatic);

    virtual omnetpp::simtime_t getSwTimeStamp() const;
    virtual void setSwTimeStamp(omnetpp::simtime_t SwTimeStamp);

    virtual omnetpp::simtime_t getInjectionTime() const;
    virtual void setInjectionTime(omnetpp::simtime_t injectionTime);

    virtual bool getBeforeAnySwitch() const;
    virtual void setBeforeAnySwitch(bool beforeAnySwitch);

    virtual int getIsFECN() const;
    virtual void setIsFECN(int isFECN);

    virtual int getIsBECN() const;
    virtual void setIsBECN(int isBECN);

    virtual int getIsAppMsg() const;
    virtual void setIsAppMsg(int isAppMsg);

    virtual double getRecvRate() const;
    virtual void setRecvRate(double RecvRate);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBDataMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBDataMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ib.msg:88</tt> by opp_msgtool.
 * <pre>
 * message IBFlowControl extends IBWireMsg
 * {
 *     long FCTBS;
 *     long FCCL;
 * }
 * </pre>
 */
class IBFlowControl : public ::IBWireMsg
{
  protected:
    long FCTBS = 0;
    long FCCL = 0;

  private:
    void copy(const IBFlowControl& other);

  protected:
    bool operator==(const IBFlowControl&) = delete;

  public:
    IBFlowControl(const char *name=nullptr, short kind=0);
    IBFlowControl(const IBFlowControl& other);
    virtual ~IBFlowControl();
    IBFlowControl& operator=(const IBFlowControl& other);
    virtual IBFlowControl *dup() const override {return new IBFlowControl(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual long getFCTBS() const;
    virtual void setFCTBS(long FCTBS);

    virtual long getFCCL() const;
    virtual void setFCCL(long FCCL);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBFlowControl& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBFlowControl& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ib.msg:95</tt> by opp_msgtool.
 * <pre>
 * // this message used to signal a down port for upper level switch is loaded/unloaded
 * message IBTQLoadUpdateMsg extends IBWireMsg
 * {
 *     int load; // 0 - unloaded, 1 - loaded, 2 - overload
 *     int srcRank;
 *     int firstLid; // the LID range
 *     int lastLid;
 * }
 * 
 * ///////////////////////////////////////////////////////////////////////////
 * //
 * // MESSAGES THAT ARE AVAILABLE INSIDE THE DEVICES
 * //
 * </pre>
 */
class IBTQLoadUpdateMsg : public ::IBWireMsg
{
  protected:
    int load = 0;
    int srcRank = 0;
    int firstLid = 0;
    int lastLid = 0;

  private:
    void copy(const IBTQLoadUpdateMsg& other);

  protected:
    bool operator==(const IBTQLoadUpdateMsg&) = delete;

  public:
    IBTQLoadUpdateMsg(const char *name=nullptr, short kind=0);
    IBTQLoadUpdateMsg(const IBTQLoadUpdateMsg& other);
    virtual ~IBTQLoadUpdateMsg();
    IBTQLoadUpdateMsg& operator=(const IBTQLoadUpdateMsg& other);
    virtual IBTQLoadUpdateMsg *dup() const override {return new IBTQLoadUpdateMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getLoad() const;
    virtual void setLoad(int load);

    virtual int getSrcRank() const;
    virtual void setSrcRank(int srcRank);

    virtual int getFirstLid() const;
    virtual void setFirstLid(int firstLid);

    virtual int getLastLid() const;
    virtual void setLastLid(int lastLid);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBTQLoadUpdateMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBTQLoadUpdateMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ib.msg:109</tt> by opp_msgtool.
 * <pre>
 * message IBSinkTimerMsg extends cMessage
 * {
 *     int srcLid;
 * }
 * </pre>
 */
class IBSinkTimerMsg : public ::omnetpp::cMessage
{
  protected:
    int srcLid = 0;

  private:
    void copy(const IBSinkTimerMsg& other);

  protected:
    bool operator==(const IBSinkTimerMsg&) = delete;

  public:
    IBSinkTimerMsg(const char *name=nullptr, short kind=0);
    IBSinkTimerMsg(const IBSinkTimerMsg& other);
    virtual ~IBSinkTimerMsg();
    IBSinkTimerMsg& operator=(const IBSinkTimerMsg& other);
    virtual IBSinkTimerMsg *dup() const override {return new IBSinkTimerMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getSrcLid() const;
    virtual void setSrcLid(int srcLid);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBSinkTimerMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBSinkTimerMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ib.msg:116</tt> by opp_msgtool.
 * <pre>
 * // This message carry the "just" received flow control packet FCCL&FCTBS
 * message IBTxCredMsg extends cMessage
 * {
 *     int VL;
 *     long FCCL;
 *     long FCTBS;
 * }
 * </pre>
 */
class IBTxCredMsg : public ::omnetpp::cMessage
{
  protected:
    int VL = 0;
    long FCCL = 0;
    long FCTBS = 0;

  private:
    void copy(const IBTxCredMsg& other);

  protected:
    bool operator==(const IBTxCredMsg&) = delete;

  public:
    IBTxCredMsg(const char *name=nullptr, short kind=0);
    IBTxCredMsg(const IBTxCredMsg& other);
    virtual ~IBTxCredMsg();
    IBTxCredMsg& operator=(const IBTxCredMsg& other);
    virtual IBTxCredMsg *dup() const override {return new IBTxCredMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getVL() const;
    virtual void setVL(int VL);

    virtual long getFCCL() const;
    virtual void setFCCL(long FCCL);

    virtual long getFCTBS() const;
    virtual void setFCTBS(long FCTBS);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBTxCredMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBTxCredMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ib.msg:124</tt> by opp_msgtool.
 * <pre>
 * // This message carry the FCCL from the the IBUF to the OBUF
 * message IBRxCredMsg extends cMessage
 * {
 *     int VL;
 *     long FCCL;
 * }
 * 
 * // FOR IB_CREDITS ONLY
 * </pre>
 */
class IBRxCredMsg : public ::omnetpp::cMessage
{
  protected:
    int VL = 0;
    long FCCL = 0;

  private:
    void copy(const IBRxCredMsg& other);

  protected:
    bool operator==(const IBRxCredMsg&) = delete;

  public:
    IBRxCredMsg(const char *name=nullptr, short kind=0);
    IBRxCredMsg(const IBRxCredMsg& other);
    virtual ~IBRxCredMsg();
    IBRxCredMsg& operator=(const IBRxCredMsg& other);
    virtual IBRxCredMsg *dup() const override {return new IBRxCredMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getVL() const;
    virtual void setVL(int VL);

    virtual long getFCCL() const;
    virtual void setFCCL(long FCCL);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBRxCredMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBRxCredMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ib.msg:134</tt> by opp_msgtool.
 * <pre>
 * // When a credit is sent by the arbiter it needs to notify the IBUF
 * // which packet was sent
 * message IBSentMsg extends cMessage
 * {
 *     short VL;
 *     short usedStatic;
 *     short wasLast;
 * }
 * </pre>
 */
class IBSentMsg : public ::omnetpp::cMessage
{
  protected:
    short VL = 0;
    short usedStatic = 0;
    short wasLast = 0;

  private:
    void copy(const IBSentMsg& other);

  protected:
    bool operator==(const IBSentMsg&) = delete;

  public:
    IBSentMsg(const char *name=nullptr, short kind=0);
    IBSentMsg(const IBSentMsg& other);
    virtual ~IBSentMsg();
    IBSentMsg& operator=(const IBSentMsg& other);
    virtual IBSentMsg *dup() const override {return new IBSentMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual short getVL() const;
    virtual void setVL(short VL);

    virtual short getUsedStatic() const;
    virtual void setUsedStatic(short usedStatic);

    virtual short getWasLast() const;
    virtual void setWasLast(short wasLast);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBSentMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBSentMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ib.msg:146</tt> by opp_msgtool.
 * <pre>
 * // OBUF Informs the driver VLA about the number of credits it can hold
 * // this in turn can trigger a new arbitration.
 * // NOTE: to avoid races the arbiter only uses this info as a trigger for
 * // arbitration, it actually access the Q when it needs to know the Q free
 * // credits
 * message IBFreeMsg extends cMessage
 * {
 *     short VL;
 * }
 * </pre>
 */
class IBFreeMsg : public ::omnetpp::cMessage
{
  protected:
    short VL = 0;

  private:
    void copy(const IBFreeMsg& other);

  protected:
    bool operator==(const IBFreeMsg&) = delete;

  public:
    IBFreeMsg(const char *name=nullptr, short kind=0);
    IBFreeMsg(const IBFreeMsg& other);
    virtual ~IBFreeMsg();
    IBFreeMsg& operator=(const IBFreeMsg& other);
    virtual IBFreeMsg *dup() const override {return new IBFreeMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual short getVL() const;
    virtual void setVL(short VL);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBFreeMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBFreeMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ib.msg:156</tt> by opp_msgtool.
 * <pre>
 * // IBUF informs the VLAs it is driving about its ability to take a new
 * // arbitration
 * // NOTE: to avoid races the arbiter only uses this info as a trigger for
 * // arbitration, it actually access the IBUF BusyPorts structure to know if the
 * // arbitration succeeded message
 * message IBDoneMsg extends cMessage
 * {
 *     int appIdx;
 *     short VL;
 * }
 * </pre>
 */
class IBDoneMsg : public ::omnetpp::cMessage
{
  protected:
    int appIdx = 0;
    short VL = 0;

  private:
    void copy(const IBDoneMsg& other);

  protected:
    bool operator==(const IBDoneMsg&) = delete;

  public:
    IBDoneMsg(const char *name=nullptr, short kind=0);
    IBDoneMsg(const IBDoneMsg& other);
    virtual ~IBDoneMsg();
    IBDoneMsg& operator=(const IBDoneMsg& other);
    virtual IBDoneMsg *dup() const override {return new IBDoneMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getAppIdx() const;
    virtual void setAppIdx(int appIdx);

    virtual short getVL() const;
    virtual void setVL(short VL);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBDoneMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBDoneMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ib.msg:164</tt> by opp_msgtool.
 * <pre>
 * // Applications sends this message that represent a transmission request to 
 * // one destination on some schedule queue
 * message IBAppMsg extends cMessage
 * {
 *     unsigned int appIdx;   // the application Idx in the SRC 
 *     unsigned int msgIdx;   // the application message index (uniq per APP)
 *     unsigned int SQ;       // the scheduler Q for this message
 *     unsigned int lenBytes; // the message length in bytes
 *     unsigned int lenPkts;  // the message length in packets
 *     unsigned int dstLid;   // destination lid
 *     unsigned int mtuBytes; // the MTU to be used in bytes
 *     // to be updated by the gen
 *     unsigned int pktLenFlits; // Current packet length in FLITs
 *     unsigned int pktLenBytes; // Current packet length in bytes
 *     unsigned int pktIdx;   // the next pkt index within the message
 *     unsigned int flitIdx;  // the next flit index in the packet
 *     unsigned int VL;       // the out VL to be used
 * }
 * </pre>
 */
class IBAppMsg : public ::omnetpp::cMessage
{
  protected:
    unsigned int appIdx = 0;
    unsigned int msgIdx = 0;
    unsigned int SQ = 0;
    unsigned int lenBytes = 0;
    unsigned int lenPkts = 0;
    unsigned int dstLid = 0;
    unsigned int mtuBytes = 0;
    unsigned int pktLenFlits = 0;
    unsigned int pktLenBytes = 0;
    unsigned int pktIdx = 0;
    unsigned int flitIdx = 0;
    unsigned int VL = 0;

  private:
    void copy(const IBAppMsg& other);

  protected:
    bool operator==(const IBAppMsg&) = delete;

  public:
    IBAppMsg(const char *name=nullptr, short kind=0);
    IBAppMsg(const IBAppMsg& other);
    virtual ~IBAppMsg();
    IBAppMsg& operator=(const IBAppMsg& other);
    virtual IBAppMsg *dup() const override {return new IBAppMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual unsigned int getAppIdx() const;
    virtual void setAppIdx(unsigned int appIdx);

    virtual unsigned int getMsgIdx() const;
    virtual void setMsgIdx(unsigned int msgIdx);

    virtual unsigned int getSQ() const;
    virtual void setSQ(unsigned int SQ);

    virtual unsigned int getLenBytes() const;
    virtual void setLenBytes(unsigned int lenBytes);

    virtual unsigned int getLenPkts() const;
    virtual void setLenPkts(unsigned int lenPkts);

    virtual unsigned int getDstLid() const;
    virtual void setDstLid(unsigned int dstLid);

    virtual unsigned int getMtuBytes() const;
    virtual void setMtuBytes(unsigned int mtuBytes);

    virtual unsigned int getPktLenFlits() const;
    virtual void setPktLenFlits(unsigned int pktLenFlits);

    virtual unsigned int getPktLenBytes() const;
    virtual void setPktLenBytes(unsigned int pktLenBytes);

    virtual unsigned int getPktIdx() const;
    virtual void setPktIdx(unsigned int pktIdx);

    virtual unsigned int getFlitIdx() const;
    virtual void setFlitIdx(unsigned int flitIdx);

    virtual unsigned int getVL() const;
    virtual void setVL(unsigned int VL);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBAppMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBAppMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ib.msg:182</tt> by opp_msgtool.
 * <pre>
 * message IBPushFECNMsg extends cMessage
 * {
 *     int srcLid;
 *     int dstLid;
 *     int SL;               // the SL
 *     int msgIdx;           // a message ID unique to the SRC
 *     int appIdx;           // the application index within the SRC
 *     double RecvRate;
 *     int BECNValue;
 * }
 * </pre>
 */
class IBPushFECNMsg : public ::omnetpp::cMessage
{
  protected:
    int srcLid = 0;
    int dstLid = 0;
    int SL = 0;
    int msgIdx = 0;
    int appIdx = 0;
    double RecvRate = 0;
    int BECNValue = 0;

  private:
    void copy(const IBPushFECNMsg& other);

  protected:
    bool operator==(const IBPushFECNMsg&) = delete;

  public:
    IBPushFECNMsg(const char *name=nullptr, short kind=0);
    IBPushFECNMsg(const IBPushFECNMsg& other);
    virtual ~IBPushFECNMsg();
    IBPushFECNMsg& operator=(const IBPushFECNMsg& other);
    virtual IBPushFECNMsg *dup() const override {return new IBPushFECNMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getSrcLid() const;
    virtual void setSrcLid(int srcLid);

    virtual int getDstLid() const;
    virtual void setDstLid(int dstLid);

    virtual int getSL() const;
    virtual void setSL(int SL);

    virtual int getMsgIdx() const;
    virtual void setMsgIdx(int msgIdx);

    virtual int getAppIdx() const;
    virtual void setAppIdx(int appIdx);

    virtual double getRecvRate() const;
    virtual void setRecvRate(double RecvRate);

    virtual int getBECNValue() const;
    virtual void setBECNValue(int BECNValue);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBPushFECNMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBPushFECNMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ib.msg:194</tt> by opp_msgtool.
 * <pre>
 * message IBPushBECNMsg extends IBWireMsg
 * {
 *     int BECNValue;        //value of BECN. 1: congestion root, 2: congestion victim 3: non-congestion
 *     int srcLid;
 *     int dstLid;
 *     int SL;               // the SL
 *     int msgIdx;           // a message ID unique to the SRC
 *     int appIdx;           // the application index within the SRC
 *     double RecvRate;
 *   //int pktIdx;           // packet index within the message
 * }
 * </pre>
 */
class IBPushBECNMsg : public ::IBWireMsg
{
  protected:
    int BECNValue = 0;
    int srcLid = 0;
    int dstLid = 0;
    int SL = 0;
    int msgIdx = 0;
    int appIdx = 0;
    double RecvRate = 0;

  private:
    void copy(const IBPushBECNMsg& other);

  protected:
    bool operator==(const IBPushBECNMsg&) = delete;

  public:
    IBPushBECNMsg(const char *name=nullptr, short kind=0);
    IBPushBECNMsg(const IBPushBECNMsg& other);
    virtual ~IBPushBECNMsg();
    IBPushBECNMsg& operator=(const IBPushBECNMsg& other);
    virtual IBPushBECNMsg *dup() const override {return new IBPushBECNMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getBECNValue() const;
    virtual void setBECNValue(int BECNValue);

    virtual int getSrcLid() const;
    virtual void setSrcLid(int srcLid);

    virtual int getDstLid() const;
    virtual void setDstLid(int dstLid);

    virtual int getSL() const;
    virtual void setSL(int SL);

    virtual int getMsgIdx() const;
    virtual void setMsgIdx(int msgIdx);

    virtual int getAppIdx() const;
    virtual void setAppIdx(int appIdx);

    virtual double getRecvRate() const;
    virtual void setRecvRate(double RecvRate);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IBPushBECNMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IBPushBECNMsg& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline IBWireMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBWireMsg*>(ptr.get<cObject>()); }
template<> inline IBDataMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBDataMsg*>(ptr.get<cObject>()); }
template<> inline IBFlowControl *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBFlowControl*>(ptr.get<cObject>()); }
template<> inline IBTQLoadUpdateMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBTQLoadUpdateMsg*>(ptr.get<cObject>()); }
template<> inline IBSinkTimerMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBSinkTimerMsg*>(ptr.get<cObject>()); }
template<> inline IBTxCredMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBTxCredMsg*>(ptr.get<cObject>()); }
template<> inline IBRxCredMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBRxCredMsg*>(ptr.get<cObject>()); }
template<> inline IBSentMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBSentMsg*>(ptr.get<cObject>()); }
template<> inline IBFreeMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBFreeMsg*>(ptr.get<cObject>()); }
template<> inline IBDoneMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBDoneMsg*>(ptr.get<cObject>()); }
template<> inline IBAppMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBAppMsg*>(ptr.get<cObject>()); }
template<> inline IBPushFECNMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBPushFECNMsg*>(ptr.get<cObject>()); }
template<> inline IBPushBECNMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<IBPushBECNMsg*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __IB_M_H

