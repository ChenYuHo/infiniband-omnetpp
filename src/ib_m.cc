//
// Generated file, do not edit! Created by opp_msgtool 6.0 from ib.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "ib_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Enum(IB_MSGS, (IB_MSGS::IB_DATA_MSG, IB_MSGS::IB_FLOWCTRL_MSG, IB_MSGS::IB_SENT_MSG, IB_MSGS::IB_TXCRED_MSG, IB_MSGS::IB_RXCRED_MSG, IB_MSGS::IB_MINTIME_MSG, IB_MSGS::IB_POP_MSG, IB_MSGS::IB_HICCUP_MSG, IB_MSGS::IB_FREE_MSG, IB_MSGS::IB_DONE_MSG, IB_MSGS::IB_APP_MSG, IB_MSGS::IB_PUSH_MSG, IB_MSGS::IB_TQ_LOAD_MSG, IB_MSGS::IB_TIMER_MSG, IB_MSGS::IB_PUSHFECN_MSG, IB_MSGS::IB_PUSHBECN_MSG, IB_MSGS::IB_CCTIMER_MSG, IB_MSGS::IB_SENDTIMER_MSG, IB_MSGS::IB_SINKTIMER_MSG));

Register_Class(IBWireMsg)

IBWireMsg::IBWireMsg(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

IBWireMsg::IBWireMsg(const IBWireMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

IBWireMsg::~IBWireMsg()
{
}

IBWireMsg& IBWireMsg::operator=(const IBWireMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void IBWireMsg::copy(const IBWireMsg& other)
{
    this->VL = other.VL;
}

void IBWireMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->VL);
}

void IBWireMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->VL);
}

short IBWireMsg::getVL() const
{
    return this->VL;
}

void IBWireMsg::setVL(short VL)
{
    this->VL = VL;
}

class IBWireMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_VL,
    };
  public:
    IBWireMsgDescriptor();
    virtual ~IBWireMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBWireMsgDescriptor)

IBWireMsgDescriptor::IBWireMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBWireMsg)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

IBWireMsgDescriptor::~IBWireMsgDescriptor()
{
    delete[] propertyNames;
}

bool IBWireMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBWireMsg *>(obj)!=nullptr;
}

const char **IBWireMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBWireMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBWireMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int IBWireMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_VL
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *IBWireMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "VL",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int IBWireMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "VL") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *IBWireMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_VL
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **IBWireMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBWireMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBWireMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBWireMsg *pp = omnetpp::fromAnyPtr<IBWireMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBWireMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBWireMsg *pp = omnetpp::fromAnyPtr<IBWireMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBWireMsg'", field);
    }
}

const char *IBWireMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBWireMsg *pp = omnetpp::fromAnyPtr<IBWireMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBWireMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBWireMsg *pp = omnetpp::fromAnyPtr<IBWireMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: return long2string(pp->getVL());
        default: return "";
    }
}

void IBWireMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBWireMsg *pp = omnetpp::fromAnyPtr<IBWireMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: pp->setVL(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBWireMsg'", field);
    }
}

omnetpp::cValue IBWireMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBWireMsg *pp = omnetpp::fromAnyPtr<IBWireMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: return pp->getVL();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBWireMsg' as cValue -- field index out of range?", field);
    }
}

void IBWireMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBWireMsg *pp = omnetpp::fromAnyPtr<IBWireMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: pp->setVL(omnetpp::checked_int_cast<short>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBWireMsg'", field);
    }
}

const char *IBWireMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBWireMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBWireMsg *pp = omnetpp::fromAnyPtr<IBWireMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBWireMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBWireMsg *pp = omnetpp::fromAnyPtr<IBWireMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBWireMsg'", field);
    }
}

Register_Class(IBDataMsg)

IBDataMsg::IBDataMsg(const char *name, short kind) : ::IBWireMsg(name, kind)
{
}

IBDataMsg::IBDataMsg(const IBDataMsg& other) : ::IBWireMsg(other)
{
    copy(other);
}

IBDataMsg::~IBDataMsg()
{
}

IBDataMsg& IBDataMsg::operator=(const IBDataMsg& other)
{
    if (this == &other) return *this;
    ::IBWireMsg::operator=(other);
    copy(other);
    return *this;
}

void IBDataMsg::copy(const IBDataMsg& other)
{
    this->appIdx = other.appIdx;
    this->msgIdx = other.msgIdx;
    this->msgLen = other.msgLen;
    this->pktIdx = other.pktIdx;
    this->packetId = other.packetId;
    this->packetSn = other.packetSn;
    this->flitSn = other.flitSn;
    this->PacketLength = other.PacketLength;
    this->PacketLengthBytes = other.PacketLengthBytes;
    this->dstLid = other.dstLid;
    this->srcLid = other.srcLid;
    this->SL = other.SL;
    this->useStatic = other.useStatic;
    this->SwTimeStamp = other.SwTimeStamp;
    this->injectionTime = other.injectionTime;
    this->beforeAnySwitch = other.beforeAnySwitch;
    this->isFECN = other.isFECN;
    this->isBECN = other.isBECN;
    this->isAppMsg = other.isAppMsg;
    this->RecvRate = other.RecvRate;
}

void IBDataMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::IBWireMsg::parsimPack(b);
    doParsimPacking(b,this->appIdx);
    doParsimPacking(b,this->msgIdx);
    doParsimPacking(b,this->msgLen);
    doParsimPacking(b,this->pktIdx);
    doParsimPacking(b,this->packetId);
    doParsimPacking(b,this->packetSn);
    doParsimPacking(b,this->flitSn);
    doParsimPacking(b,this->PacketLength);
    doParsimPacking(b,this->PacketLengthBytes);
    doParsimPacking(b,this->dstLid);
    doParsimPacking(b,this->srcLid);
    doParsimPacking(b,this->SL);
    doParsimPacking(b,this->useStatic);
    doParsimPacking(b,this->SwTimeStamp);
    doParsimPacking(b,this->injectionTime);
    doParsimPacking(b,this->beforeAnySwitch);
    doParsimPacking(b,this->isFECN);
    doParsimPacking(b,this->isBECN);
    doParsimPacking(b,this->isAppMsg);
    doParsimPacking(b,this->RecvRate);
}

void IBDataMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::IBWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->appIdx);
    doParsimUnpacking(b,this->msgIdx);
    doParsimUnpacking(b,this->msgLen);
    doParsimUnpacking(b,this->pktIdx);
    doParsimUnpacking(b,this->packetId);
    doParsimUnpacking(b,this->packetSn);
    doParsimUnpacking(b,this->flitSn);
    doParsimUnpacking(b,this->PacketLength);
    doParsimUnpacking(b,this->PacketLengthBytes);
    doParsimUnpacking(b,this->dstLid);
    doParsimUnpacking(b,this->srcLid);
    doParsimUnpacking(b,this->SL);
    doParsimUnpacking(b,this->useStatic);
    doParsimUnpacking(b,this->SwTimeStamp);
    doParsimUnpacking(b,this->injectionTime);
    doParsimUnpacking(b,this->beforeAnySwitch);
    doParsimUnpacking(b,this->isFECN);
    doParsimUnpacking(b,this->isBECN);
    doParsimUnpacking(b,this->isAppMsg);
    doParsimUnpacking(b,this->RecvRate);
}

int IBDataMsg::getAppIdx() const
{
    return this->appIdx;
}

void IBDataMsg::setAppIdx(int appIdx)
{
    this->appIdx = appIdx;
}

int IBDataMsg::getMsgIdx() const
{
    return this->msgIdx;
}

void IBDataMsg::setMsgIdx(int msgIdx)
{
    this->msgIdx = msgIdx;
}

int IBDataMsg::getMsgLen() const
{
    return this->msgLen;
}

void IBDataMsg::setMsgLen(int msgLen)
{
    this->msgLen = msgLen;
}

int IBDataMsg::getPktIdx() const
{
    return this->pktIdx;
}

void IBDataMsg::setPktIdx(int pktIdx)
{
    this->pktIdx = pktIdx;
}

int IBDataMsg::getPacketId() const
{
    return this->packetId;
}

void IBDataMsg::setPacketId(int packetId)
{
    this->packetId = packetId;
}

int IBDataMsg::getPacketSn() const
{
    return this->packetSn;
}

void IBDataMsg::setPacketSn(int packetSn)
{
    this->packetSn = packetSn;
}

int IBDataMsg::getFlitSn() const
{
    return this->flitSn;
}

void IBDataMsg::setFlitSn(int flitSn)
{
    this->flitSn = flitSn;
}

int IBDataMsg::getPacketLength() const
{
    return this->PacketLength;
}

void IBDataMsg::setPacketLength(int PacketLength)
{
    this->PacketLength = PacketLength;
}

int IBDataMsg::getPacketLengthBytes() const
{
    return this->PacketLengthBytes;
}

void IBDataMsg::setPacketLengthBytes(int PacketLengthBytes)
{
    this->PacketLengthBytes = PacketLengthBytes;
}

int IBDataMsg::getDstLid() const
{
    return this->dstLid;
}

void IBDataMsg::setDstLid(int dstLid)
{
    this->dstLid = dstLid;
}

int IBDataMsg::getSrcLid() const
{
    return this->srcLid;
}

void IBDataMsg::setSrcLid(int srcLid)
{
    this->srcLid = srcLid;
}

int IBDataMsg::getSL() const
{
    return this->SL;
}

void IBDataMsg::setSL(int SL)
{
    this->SL = SL;
}

int IBDataMsg::getUseStatic() const
{
    return this->useStatic;
}

void IBDataMsg::setUseStatic(int useStatic)
{
    this->useStatic = useStatic;
}

omnetpp::simtime_t IBDataMsg::getSwTimeStamp() const
{
    return this->SwTimeStamp;
}

void IBDataMsg::setSwTimeStamp(omnetpp::simtime_t SwTimeStamp)
{
    this->SwTimeStamp = SwTimeStamp;
}

omnetpp::simtime_t IBDataMsg::getInjectionTime() const
{
    return this->injectionTime;
}

void IBDataMsg::setInjectionTime(omnetpp::simtime_t injectionTime)
{
    this->injectionTime = injectionTime;
}

bool IBDataMsg::getBeforeAnySwitch() const
{
    return this->beforeAnySwitch;
}

void IBDataMsg::setBeforeAnySwitch(bool beforeAnySwitch)
{
    this->beforeAnySwitch = beforeAnySwitch;
}

int IBDataMsg::getIsFECN() const
{
    return this->isFECN;
}

void IBDataMsg::setIsFECN(int isFECN)
{
    this->isFECN = isFECN;
}

int IBDataMsg::getIsBECN() const
{
    return this->isBECN;
}

void IBDataMsg::setIsBECN(int isBECN)
{
    this->isBECN = isBECN;
}

int IBDataMsg::getIsAppMsg() const
{
    return this->isAppMsg;
}

void IBDataMsg::setIsAppMsg(int isAppMsg)
{
    this->isAppMsg = isAppMsg;
}

double IBDataMsg::getRecvRate() const
{
    return this->RecvRate;
}

void IBDataMsg::setRecvRate(double RecvRate)
{
    this->RecvRate = RecvRate;
}

class IBDataMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_appIdx,
        FIELD_msgIdx,
        FIELD_msgLen,
        FIELD_pktIdx,
        FIELD_packetId,
        FIELD_packetSn,
        FIELD_flitSn,
        FIELD_PacketLength,
        FIELD_PacketLengthBytes,
        FIELD_dstLid,
        FIELD_srcLid,
        FIELD_SL,
        FIELD_useStatic,
        FIELD_SwTimeStamp,
        FIELD_injectionTime,
        FIELD_beforeAnySwitch,
        FIELD_isFECN,
        FIELD_isBECN,
        FIELD_isAppMsg,
        FIELD_RecvRate,
    };
  public:
    IBDataMsgDescriptor();
    virtual ~IBDataMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBDataMsgDescriptor)

IBDataMsgDescriptor::IBDataMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBDataMsg)), "IBWireMsg")
{
    propertyNames = nullptr;
}

IBDataMsgDescriptor::~IBDataMsgDescriptor()
{
    delete[] propertyNames;
}

bool IBDataMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBDataMsg *>(obj)!=nullptr;
}

const char **IBDataMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBDataMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBDataMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 20+base->getFieldCount() : 20;
}

unsigned int IBDataMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_appIdx
        FD_ISEDITABLE,    // FIELD_msgIdx
        FD_ISEDITABLE,    // FIELD_msgLen
        FD_ISEDITABLE,    // FIELD_pktIdx
        FD_ISEDITABLE,    // FIELD_packetId
        FD_ISEDITABLE,    // FIELD_packetSn
        FD_ISEDITABLE,    // FIELD_flitSn
        FD_ISEDITABLE,    // FIELD_PacketLength
        FD_ISEDITABLE,    // FIELD_PacketLengthBytes
        FD_ISEDITABLE,    // FIELD_dstLid
        FD_ISEDITABLE,    // FIELD_srcLid
        FD_ISEDITABLE,    // FIELD_SL
        FD_ISEDITABLE,    // FIELD_useStatic
        FD_ISEDITABLE,    // FIELD_SwTimeStamp
        FD_ISEDITABLE,    // FIELD_injectionTime
        FD_ISEDITABLE,    // FIELD_beforeAnySwitch
        FD_ISEDITABLE,    // FIELD_isFECN
        FD_ISEDITABLE,    // FIELD_isBECN
        FD_ISEDITABLE,    // FIELD_isAppMsg
        FD_ISEDITABLE,    // FIELD_RecvRate
    };
    return (field >= 0 && field < 20) ? fieldTypeFlags[field] : 0;
}

const char *IBDataMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "appIdx",
        "msgIdx",
        "msgLen",
        "pktIdx",
        "packetId",
        "packetSn",
        "flitSn",
        "PacketLength",
        "PacketLengthBytes",
        "dstLid",
        "srcLid",
        "SL",
        "useStatic",
        "SwTimeStamp",
        "injectionTime",
        "beforeAnySwitch",
        "isFECN",
        "isBECN",
        "isAppMsg",
        "RecvRate",
    };
    return (field >= 0 && field < 20) ? fieldNames[field] : nullptr;
}

int IBDataMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "appIdx") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "msgIdx") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "msgLen") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "pktIdx") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "packetId") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "packetSn") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "flitSn") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "PacketLength") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "PacketLengthBytes") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "dstLid") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "srcLid") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "SL") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "useStatic") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "SwTimeStamp") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "injectionTime") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "beforeAnySwitch") == 0) return baseIndex + 15;
    if (strcmp(fieldName, "isFECN") == 0) return baseIndex + 16;
    if (strcmp(fieldName, "isBECN") == 0) return baseIndex + 17;
    if (strcmp(fieldName, "isAppMsg") == 0) return baseIndex + 18;
    if (strcmp(fieldName, "RecvRate") == 0) return baseIndex + 19;
    return base ? base->findField(fieldName) : -1;
}

const char *IBDataMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_appIdx
        "int",    // FIELD_msgIdx
        "int",    // FIELD_msgLen
        "int",    // FIELD_pktIdx
        "int",    // FIELD_packetId
        "int",    // FIELD_packetSn
        "int",    // FIELD_flitSn
        "int",    // FIELD_PacketLength
        "int",    // FIELD_PacketLengthBytes
        "int",    // FIELD_dstLid
        "int",    // FIELD_srcLid
        "int",    // FIELD_SL
        "int",    // FIELD_useStatic
        "omnetpp::simtime_t",    // FIELD_SwTimeStamp
        "omnetpp::simtime_t",    // FIELD_injectionTime
        "bool",    // FIELD_beforeAnySwitch
        "int",    // FIELD_isFECN
        "int",    // FIELD_isBECN
        "int",    // FIELD_isAppMsg
        "double",    // FIELD_RecvRate
    };
    return (field >= 0 && field < 20) ? fieldTypeStrings[field] : nullptr;
}

const char **IBDataMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBDataMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBDataMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBDataMsg *pp = omnetpp::fromAnyPtr<IBDataMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBDataMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBDataMsg *pp = omnetpp::fromAnyPtr<IBDataMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBDataMsg'", field);
    }
}

const char *IBDataMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBDataMsg *pp = omnetpp::fromAnyPtr<IBDataMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBDataMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBDataMsg *pp = omnetpp::fromAnyPtr<IBDataMsg>(object); (void)pp;
    switch (field) {
        case FIELD_appIdx: return long2string(pp->getAppIdx());
        case FIELD_msgIdx: return long2string(pp->getMsgIdx());
        case FIELD_msgLen: return long2string(pp->getMsgLen());
        case FIELD_pktIdx: return long2string(pp->getPktIdx());
        case FIELD_packetId: return long2string(pp->getPacketId());
        case FIELD_packetSn: return long2string(pp->getPacketSn());
        case FIELD_flitSn: return long2string(pp->getFlitSn());
        case FIELD_PacketLength: return long2string(pp->getPacketLength());
        case FIELD_PacketLengthBytes: return long2string(pp->getPacketLengthBytes());
        case FIELD_dstLid: return long2string(pp->getDstLid());
        case FIELD_srcLid: return long2string(pp->getSrcLid());
        case FIELD_SL: return long2string(pp->getSL());
        case FIELD_useStatic: return long2string(pp->getUseStatic());
        case FIELD_SwTimeStamp: return simtime2string(pp->getSwTimeStamp());
        case FIELD_injectionTime: return simtime2string(pp->getInjectionTime());
        case FIELD_beforeAnySwitch: return bool2string(pp->getBeforeAnySwitch());
        case FIELD_isFECN: return long2string(pp->getIsFECN());
        case FIELD_isBECN: return long2string(pp->getIsBECN());
        case FIELD_isAppMsg: return long2string(pp->getIsAppMsg());
        case FIELD_RecvRate: return double2string(pp->getRecvRate());
        default: return "";
    }
}

void IBDataMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBDataMsg *pp = omnetpp::fromAnyPtr<IBDataMsg>(object); (void)pp;
    switch (field) {
        case FIELD_appIdx: pp->setAppIdx(string2long(value)); break;
        case FIELD_msgIdx: pp->setMsgIdx(string2long(value)); break;
        case FIELD_msgLen: pp->setMsgLen(string2long(value)); break;
        case FIELD_pktIdx: pp->setPktIdx(string2long(value)); break;
        case FIELD_packetId: pp->setPacketId(string2long(value)); break;
        case FIELD_packetSn: pp->setPacketSn(string2long(value)); break;
        case FIELD_flitSn: pp->setFlitSn(string2long(value)); break;
        case FIELD_PacketLength: pp->setPacketLength(string2long(value)); break;
        case FIELD_PacketLengthBytes: pp->setPacketLengthBytes(string2long(value)); break;
        case FIELD_dstLid: pp->setDstLid(string2long(value)); break;
        case FIELD_srcLid: pp->setSrcLid(string2long(value)); break;
        case FIELD_SL: pp->setSL(string2long(value)); break;
        case FIELD_useStatic: pp->setUseStatic(string2long(value)); break;
        case FIELD_SwTimeStamp: pp->setSwTimeStamp(string2simtime(value)); break;
        case FIELD_injectionTime: pp->setInjectionTime(string2simtime(value)); break;
        case FIELD_beforeAnySwitch: pp->setBeforeAnySwitch(string2bool(value)); break;
        case FIELD_isFECN: pp->setIsFECN(string2long(value)); break;
        case FIELD_isBECN: pp->setIsBECN(string2long(value)); break;
        case FIELD_isAppMsg: pp->setIsAppMsg(string2long(value)); break;
        case FIELD_RecvRate: pp->setRecvRate(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBDataMsg'", field);
    }
}

omnetpp::cValue IBDataMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBDataMsg *pp = omnetpp::fromAnyPtr<IBDataMsg>(object); (void)pp;
    switch (field) {
        case FIELD_appIdx: return pp->getAppIdx();
        case FIELD_msgIdx: return pp->getMsgIdx();
        case FIELD_msgLen: return pp->getMsgLen();
        case FIELD_pktIdx: return pp->getPktIdx();
        case FIELD_packetId: return pp->getPacketId();
        case FIELD_packetSn: return pp->getPacketSn();
        case FIELD_flitSn: return pp->getFlitSn();
        case FIELD_PacketLength: return pp->getPacketLength();
        case FIELD_PacketLengthBytes: return pp->getPacketLengthBytes();
        case FIELD_dstLid: return pp->getDstLid();
        case FIELD_srcLid: return pp->getSrcLid();
        case FIELD_SL: return pp->getSL();
        case FIELD_useStatic: return pp->getUseStatic();
        case FIELD_SwTimeStamp: return pp->getSwTimeStamp().dbl();
        case FIELD_injectionTime: return pp->getInjectionTime().dbl();
        case FIELD_beforeAnySwitch: return pp->getBeforeAnySwitch();
        case FIELD_isFECN: return pp->getIsFECN();
        case FIELD_isBECN: return pp->getIsBECN();
        case FIELD_isAppMsg: return pp->getIsAppMsg();
        case FIELD_RecvRate: return pp->getRecvRate();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBDataMsg' as cValue -- field index out of range?", field);
    }
}

void IBDataMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBDataMsg *pp = omnetpp::fromAnyPtr<IBDataMsg>(object); (void)pp;
    switch (field) {
        case FIELD_appIdx: pp->setAppIdx(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_msgIdx: pp->setMsgIdx(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_msgLen: pp->setMsgLen(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_pktIdx: pp->setPktIdx(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_packetId: pp->setPacketId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_packetSn: pp->setPacketSn(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_flitSn: pp->setFlitSn(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_PacketLength: pp->setPacketLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_PacketLengthBytes: pp->setPacketLengthBytes(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dstLid: pp->setDstLid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_srcLid: pp->setSrcLid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_SL: pp->setSL(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_useStatic: pp->setUseStatic(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_SwTimeStamp: pp->setSwTimeStamp(value.doubleValue()); break;
        case FIELD_injectionTime: pp->setInjectionTime(value.doubleValue()); break;
        case FIELD_beforeAnySwitch: pp->setBeforeAnySwitch(value.boolValue()); break;
        case FIELD_isFECN: pp->setIsFECN(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_isBECN: pp->setIsBECN(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_isAppMsg: pp->setIsAppMsg(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_RecvRate: pp->setRecvRate(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBDataMsg'", field);
    }
}

const char *IBDataMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBDataMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBDataMsg *pp = omnetpp::fromAnyPtr<IBDataMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBDataMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBDataMsg *pp = omnetpp::fromAnyPtr<IBDataMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBDataMsg'", field);
    }
}

Register_Class(IBFlowControl)

IBFlowControl::IBFlowControl(const char *name, short kind) : ::IBWireMsg(name, kind)
{
}

IBFlowControl::IBFlowControl(const IBFlowControl& other) : ::IBWireMsg(other)
{
    copy(other);
}

IBFlowControl::~IBFlowControl()
{
}

IBFlowControl& IBFlowControl::operator=(const IBFlowControl& other)
{
    if (this == &other) return *this;
    ::IBWireMsg::operator=(other);
    copy(other);
    return *this;
}

void IBFlowControl::copy(const IBFlowControl& other)
{
    this->FCTBS = other.FCTBS;
    this->FCCL = other.FCCL;
}

void IBFlowControl::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::IBWireMsg::parsimPack(b);
    doParsimPacking(b,this->FCTBS);
    doParsimPacking(b,this->FCCL);
}

void IBFlowControl::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::IBWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->FCTBS);
    doParsimUnpacking(b,this->FCCL);
}

long IBFlowControl::getFCTBS() const
{
    return this->FCTBS;
}

void IBFlowControl::setFCTBS(long FCTBS)
{
    this->FCTBS = FCTBS;
}

long IBFlowControl::getFCCL() const
{
    return this->FCCL;
}

void IBFlowControl::setFCCL(long FCCL)
{
    this->FCCL = FCCL;
}

class IBFlowControlDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_FCTBS,
        FIELD_FCCL,
    };
  public:
    IBFlowControlDescriptor();
    virtual ~IBFlowControlDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBFlowControlDescriptor)

IBFlowControlDescriptor::IBFlowControlDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBFlowControl)), "IBWireMsg")
{
    propertyNames = nullptr;
}

IBFlowControlDescriptor::~IBFlowControlDescriptor()
{
    delete[] propertyNames;
}

bool IBFlowControlDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBFlowControl *>(obj)!=nullptr;
}

const char **IBFlowControlDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBFlowControlDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBFlowControlDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int IBFlowControlDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_FCTBS
        FD_ISEDITABLE,    // FIELD_FCCL
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *IBFlowControlDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "FCTBS",
        "FCCL",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int IBFlowControlDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "FCTBS") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "FCCL") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *IBFlowControlDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "long",    // FIELD_FCTBS
        "long",    // FIELD_FCCL
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **IBFlowControlDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBFlowControlDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBFlowControlDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBFlowControl *pp = omnetpp::fromAnyPtr<IBFlowControl>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBFlowControlDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBFlowControl *pp = omnetpp::fromAnyPtr<IBFlowControl>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBFlowControl'", field);
    }
}

const char *IBFlowControlDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBFlowControl *pp = omnetpp::fromAnyPtr<IBFlowControl>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBFlowControlDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBFlowControl *pp = omnetpp::fromAnyPtr<IBFlowControl>(object); (void)pp;
    switch (field) {
        case FIELD_FCTBS: return long2string(pp->getFCTBS());
        case FIELD_FCCL: return long2string(pp->getFCCL());
        default: return "";
    }
}

void IBFlowControlDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBFlowControl *pp = omnetpp::fromAnyPtr<IBFlowControl>(object); (void)pp;
    switch (field) {
        case FIELD_FCTBS: pp->setFCTBS(string2long(value)); break;
        case FIELD_FCCL: pp->setFCCL(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBFlowControl'", field);
    }
}

omnetpp::cValue IBFlowControlDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBFlowControl *pp = omnetpp::fromAnyPtr<IBFlowControl>(object); (void)pp;
    switch (field) {
        case FIELD_FCTBS: return (omnetpp::intval_t)(pp->getFCTBS());
        case FIELD_FCCL: return (omnetpp::intval_t)(pp->getFCCL());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBFlowControl' as cValue -- field index out of range?", field);
    }
}

void IBFlowControlDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBFlowControl *pp = omnetpp::fromAnyPtr<IBFlowControl>(object); (void)pp;
    switch (field) {
        case FIELD_FCTBS: pp->setFCTBS(omnetpp::checked_int_cast<long>(value.intValue())); break;
        case FIELD_FCCL: pp->setFCCL(omnetpp::checked_int_cast<long>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBFlowControl'", field);
    }
}

const char *IBFlowControlDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBFlowControlDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBFlowControl *pp = omnetpp::fromAnyPtr<IBFlowControl>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBFlowControlDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBFlowControl *pp = omnetpp::fromAnyPtr<IBFlowControl>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBFlowControl'", field);
    }
}

Register_Class(IBTQLoadUpdateMsg)

IBTQLoadUpdateMsg::IBTQLoadUpdateMsg(const char *name, short kind) : ::IBWireMsg(name, kind)
{
}

IBTQLoadUpdateMsg::IBTQLoadUpdateMsg(const IBTQLoadUpdateMsg& other) : ::IBWireMsg(other)
{
    copy(other);
}

IBTQLoadUpdateMsg::~IBTQLoadUpdateMsg()
{
}

IBTQLoadUpdateMsg& IBTQLoadUpdateMsg::operator=(const IBTQLoadUpdateMsg& other)
{
    if (this == &other) return *this;
    ::IBWireMsg::operator=(other);
    copy(other);
    return *this;
}

void IBTQLoadUpdateMsg::copy(const IBTQLoadUpdateMsg& other)
{
    this->load = other.load;
    this->srcRank = other.srcRank;
    this->firstLid = other.firstLid;
    this->lastLid = other.lastLid;
}

void IBTQLoadUpdateMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::IBWireMsg::parsimPack(b);
    doParsimPacking(b,this->load);
    doParsimPacking(b,this->srcRank);
    doParsimPacking(b,this->firstLid);
    doParsimPacking(b,this->lastLid);
}

void IBTQLoadUpdateMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::IBWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->load);
    doParsimUnpacking(b,this->srcRank);
    doParsimUnpacking(b,this->firstLid);
    doParsimUnpacking(b,this->lastLid);
}

int IBTQLoadUpdateMsg::getLoad() const
{
    return this->load;
}

void IBTQLoadUpdateMsg::setLoad(int load)
{
    this->load = load;
}

int IBTQLoadUpdateMsg::getSrcRank() const
{
    return this->srcRank;
}

void IBTQLoadUpdateMsg::setSrcRank(int srcRank)
{
    this->srcRank = srcRank;
}

int IBTQLoadUpdateMsg::getFirstLid() const
{
    return this->firstLid;
}

void IBTQLoadUpdateMsg::setFirstLid(int firstLid)
{
    this->firstLid = firstLid;
}

int IBTQLoadUpdateMsg::getLastLid() const
{
    return this->lastLid;
}

void IBTQLoadUpdateMsg::setLastLid(int lastLid)
{
    this->lastLid = lastLid;
}

class IBTQLoadUpdateMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_load,
        FIELD_srcRank,
        FIELD_firstLid,
        FIELD_lastLid,
    };
  public:
    IBTQLoadUpdateMsgDescriptor();
    virtual ~IBTQLoadUpdateMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBTQLoadUpdateMsgDescriptor)

IBTQLoadUpdateMsgDescriptor::IBTQLoadUpdateMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBTQLoadUpdateMsg)), "IBWireMsg")
{
    propertyNames = nullptr;
}

IBTQLoadUpdateMsgDescriptor::~IBTQLoadUpdateMsgDescriptor()
{
    delete[] propertyNames;
}

bool IBTQLoadUpdateMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBTQLoadUpdateMsg *>(obj)!=nullptr;
}

const char **IBTQLoadUpdateMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBTQLoadUpdateMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBTQLoadUpdateMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int IBTQLoadUpdateMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_load
        FD_ISEDITABLE,    // FIELD_srcRank
        FD_ISEDITABLE,    // FIELD_firstLid
        FD_ISEDITABLE,    // FIELD_lastLid
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *IBTQLoadUpdateMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "load",
        "srcRank",
        "firstLid",
        "lastLid",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int IBTQLoadUpdateMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "load") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "srcRank") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "firstLid") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "lastLid") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *IBTQLoadUpdateMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_load
        "int",    // FIELD_srcRank
        "int",    // FIELD_firstLid
        "int",    // FIELD_lastLid
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **IBTQLoadUpdateMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBTQLoadUpdateMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBTQLoadUpdateMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBTQLoadUpdateMsg *pp = omnetpp::fromAnyPtr<IBTQLoadUpdateMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBTQLoadUpdateMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBTQLoadUpdateMsg *pp = omnetpp::fromAnyPtr<IBTQLoadUpdateMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBTQLoadUpdateMsg'", field);
    }
}

const char *IBTQLoadUpdateMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBTQLoadUpdateMsg *pp = omnetpp::fromAnyPtr<IBTQLoadUpdateMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBTQLoadUpdateMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBTQLoadUpdateMsg *pp = omnetpp::fromAnyPtr<IBTQLoadUpdateMsg>(object); (void)pp;
    switch (field) {
        case FIELD_load: return long2string(pp->getLoad());
        case FIELD_srcRank: return long2string(pp->getSrcRank());
        case FIELD_firstLid: return long2string(pp->getFirstLid());
        case FIELD_lastLid: return long2string(pp->getLastLid());
        default: return "";
    }
}

void IBTQLoadUpdateMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBTQLoadUpdateMsg *pp = omnetpp::fromAnyPtr<IBTQLoadUpdateMsg>(object); (void)pp;
    switch (field) {
        case FIELD_load: pp->setLoad(string2long(value)); break;
        case FIELD_srcRank: pp->setSrcRank(string2long(value)); break;
        case FIELD_firstLid: pp->setFirstLid(string2long(value)); break;
        case FIELD_lastLid: pp->setLastLid(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBTQLoadUpdateMsg'", field);
    }
}

omnetpp::cValue IBTQLoadUpdateMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBTQLoadUpdateMsg *pp = omnetpp::fromAnyPtr<IBTQLoadUpdateMsg>(object); (void)pp;
    switch (field) {
        case FIELD_load: return pp->getLoad();
        case FIELD_srcRank: return pp->getSrcRank();
        case FIELD_firstLid: return pp->getFirstLid();
        case FIELD_lastLid: return pp->getLastLid();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBTQLoadUpdateMsg' as cValue -- field index out of range?", field);
    }
}

void IBTQLoadUpdateMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBTQLoadUpdateMsg *pp = omnetpp::fromAnyPtr<IBTQLoadUpdateMsg>(object); (void)pp;
    switch (field) {
        case FIELD_load: pp->setLoad(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_srcRank: pp->setSrcRank(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_firstLid: pp->setFirstLid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_lastLid: pp->setLastLid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBTQLoadUpdateMsg'", field);
    }
}

const char *IBTQLoadUpdateMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBTQLoadUpdateMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBTQLoadUpdateMsg *pp = omnetpp::fromAnyPtr<IBTQLoadUpdateMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBTQLoadUpdateMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBTQLoadUpdateMsg *pp = omnetpp::fromAnyPtr<IBTQLoadUpdateMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBTQLoadUpdateMsg'", field);
    }
}

Register_Class(IBSinkTimerMsg)

IBSinkTimerMsg::IBSinkTimerMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

IBSinkTimerMsg::IBSinkTimerMsg(const IBSinkTimerMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

IBSinkTimerMsg::~IBSinkTimerMsg()
{
}

IBSinkTimerMsg& IBSinkTimerMsg::operator=(const IBSinkTimerMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void IBSinkTimerMsg::copy(const IBSinkTimerMsg& other)
{
    this->srcLid = other.srcLid;
}

void IBSinkTimerMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->srcLid);
}

void IBSinkTimerMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->srcLid);
}

int IBSinkTimerMsg::getSrcLid() const
{
    return this->srcLid;
}

void IBSinkTimerMsg::setSrcLid(int srcLid)
{
    this->srcLid = srcLid;
}

class IBSinkTimerMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcLid,
    };
  public:
    IBSinkTimerMsgDescriptor();
    virtual ~IBSinkTimerMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBSinkTimerMsgDescriptor)

IBSinkTimerMsgDescriptor::IBSinkTimerMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBSinkTimerMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

IBSinkTimerMsgDescriptor::~IBSinkTimerMsgDescriptor()
{
    delete[] propertyNames;
}

bool IBSinkTimerMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBSinkTimerMsg *>(obj)!=nullptr;
}

const char **IBSinkTimerMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBSinkTimerMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBSinkTimerMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int IBSinkTimerMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srcLid
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *IBSinkTimerMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcLid",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int IBSinkTimerMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcLid") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *IBSinkTimerMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_srcLid
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **IBSinkTimerMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBSinkTimerMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBSinkTimerMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBSinkTimerMsg *pp = omnetpp::fromAnyPtr<IBSinkTimerMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBSinkTimerMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBSinkTimerMsg *pp = omnetpp::fromAnyPtr<IBSinkTimerMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBSinkTimerMsg'", field);
    }
}

const char *IBSinkTimerMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBSinkTimerMsg *pp = omnetpp::fromAnyPtr<IBSinkTimerMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBSinkTimerMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBSinkTimerMsg *pp = omnetpp::fromAnyPtr<IBSinkTimerMsg>(object); (void)pp;
    switch (field) {
        case FIELD_srcLid: return long2string(pp->getSrcLid());
        default: return "";
    }
}

void IBSinkTimerMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBSinkTimerMsg *pp = omnetpp::fromAnyPtr<IBSinkTimerMsg>(object); (void)pp;
    switch (field) {
        case FIELD_srcLid: pp->setSrcLid(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBSinkTimerMsg'", field);
    }
}

omnetpp::cValue IBSinkTimerMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBSinkTimerMsg *pp = omnetpp::fromAnyPtr<IBSinkTimerMsg>(object); (void)pp;
    switch (field) {
        case FIELD_srcLid: return pp->getSrcLid();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBSinkTimerMsg' as cValue -- field index out of range?", field);
    }
}

void IBSinkTimerMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBSinkTimerMsg *pp = omnetpp::fromAnyPtr<IBSinkTimerMsg>(object); (void)pp;
    switch (field) {
        case FIELD_srcLid: pp->setSrcLid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBSinkTimerMsg'", field);
    }
}

const char *IBSinkTimerMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBSinkTimerMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBSinkTimerMsg *pp = omnetpp::fromAnyPtr<IBSinkTimerMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBSinkTimerMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBSinkTimerMsg *pp = omnetpp::fromAnyPtr<IBSinkTimerMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBSinkTimerMsg'", field);
    }
}

Register_Class(IBTxCredMsg)

IBTxCredMsg::IBTxCredMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

IBTxCredMsg::IBTxCredMsg(const IBTxCredMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

IBTxCredMsg::~IBTxCredMsg()
{
}

IBTxCredMsg& IBTxCredMsg::operator=(const IBTxCredMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void IBTxCredMsg::copy(const IBTxCredMsg& other)
{
    this->VL = other.VL;
    this->FCCL = other.FCCL;
    this->FCTBS = other.FCTBS;
}

void IBTxCredMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->VL);
    doParsimPacking(b,this->FCCL);
    doParsimPacking(b,this->FCTBS);
}

void IBTxCredMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->VL);
    doParsimUnpacking(b,this->FCCL);
    doParsimUnpacking(b,this->FCTBS);
}

int IBTxCredMsg::getVL() const
{
    return this->VL;
}

void IBTxCredMsg::setVL(int VL)
{
    this->VL = VL;
}

long IBTxCredMsg::getFCCL() const
{
    return this->FCCL;
}

void IBTxCredMsg::setFCCL(long FCCL)
{
    this->FCCL = FCCL;
}

long IBTxCredMsg::getFCTBS() const
{
    return this->FCTBS;
}

void IBTxCredMsg::setFCTBS(long FCTBS)
{
    this->FCTBS = FCTBS;
}

class IBTxCredMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_VL,
        FIELD_FCCL,
        FIELD_FCTBS,
    };
  public:
    IBTxCredMsgDescriptor();
    virtual ~IBTxCredMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBTxCredMsgDescriptor)

IBTxCredMsgDescriptor::IBTxCredMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBTxCredMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

IBTxCredMsgDescriptor::~IBTxCredMsgDescriptor()
{
    delete[] propertyNames;
}

bool IBTxCredMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBTxCredMsg *>(obj)!=nullptr;
}

const char **IBTxCredMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBTxCredMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBTxCredMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int IBTxCredMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_VL
        FD_ISEDITABLE,    // FIELD_FCCL
        FD_ISEDITABLE,    // FIELD_FCTBS
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *IBTxCredMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "VL",
        "FCCL",
        "FCTBS",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int IBTxCredMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "VL") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "FCCL") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "FCTBS") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *IBTxCredMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_VL
        "long",    // FIELD_FCCL
        "long",    // FIELD_FCTBS
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **IBTxCredMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBTxCredMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBTxCredMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBTxCredMsg *pp = omnetpp::fromAnyPtr<IBTxCredMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBTxCredMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBTxCredMsg *pp = omnetpp::fromAnyPtr<IBTxCredMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBTxCredMsg'", field);
    }
}

const char *IBTxCredMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBTxCredMsg *pp = omnetpp::fromAnyPtr<IBTxCredMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBTxCredMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBTxCredMsg *pp = omnetpp::fromAnyPtr<IBTxCredMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: return long2string(pp->getVL());
        case FIELD_FCCL: return long2string(pp->getFCCL());
        case FIELD_FCTBS: return long2string(pp->getFCTBS());
        default: return "";
    }
}

void IBTxCredMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBTxCredMsg *pp = omnetpp::fromAnyPtr<IBTxCredMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: pp->setVL(string2long(value)); break;
        case FIELD_FCCL: pp->setFCCL(string2long(value)); break;
        case FIELD_FCTBS: pp->setFCTBS(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBTxCredMsg'", field);
    }
}

omnetpp::cValue IBTxCredMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBTxCredMsg *pp = omnetpp::fromAnyPtr<IBTxCredMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: return pp->getVL();
        case FIELD_FCCL: return (omnetpp::intval_t)(pp->getFCCL());
        case FIELD_FCTBS: return (omnetpp::intval_t)(pp->getFCTBS());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBTxCredMsg' as cValue -- field index out of range?", field);
    }
}

void IBTxCredMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBTxCredMsg *pp = omnetpp::fromAnyPtr<IBTxCredMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: pp->setVL(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_FCCL: pp->setFCCL(omnetpp::checked_int_cast<long>(value.intValue())); break;
        case FIELD_FCTBS: pp->setFCTBS(omnetpp::checked_int_cast<long>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBTxCredMsg'", field);
    }
}

const char *IBTxCredMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBTxCredMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBTxCredMsg *pp = omnetpp::fromAnyPtr<IBTxCredMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBTxCredMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBTxCredMsg *pp = omnetpp::fromAnyPtr<IBTxCredMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBTxCredMsg'", field);
    }
}

Register_Class(IBRxCredMsg)

IBRxCredMsg::IBRxCredMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

IBRxCredMsg::IBRxCredMsg(const IBRxCredMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

IBRxCredMsg::~IBRxCredMsg()
{
}

IBRxCredMsg& IBRxCredMsg::operator=(const IBRxCredMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void IBRxCredMsg::copy(const IBRxCredMsg& other)
{
    this->VL = other.VL;
    this->FCCL = other.FCCL;
}

void IBRxCredMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->VL);
    doParsimPacking(b,this->FCCL);
}

void IBRxCredMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->VL);
    doParsimUnpacking(b,this->FCCL);
}

int IBRxCredMsg::getVL() const
{
    return this->VL;
}

void IBRxCredMsg::setVL(int VL)
{
    this->VL = VL;
}

long IBRxCredMsg::getFCCL() const
{
    return this->FCCL;
}

void IBRxCredMsg::setFCCL(long FCCL)
{
    this->FCCL = FCCL;
}

class IBRxCredMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_VL,
        FIELD_FCCL,
    };
  public:
    IBRxCredMsgDescriptor();
    virtual ~IBRxCredMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBRxCredMsgDescriptor)

IBRxCredMsgDescriptor::IBRxCredMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBRxCredMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

IBRxCredMsgDescriptor::~IBRxCredMsgDescriptor()
{
    delete[] propertyNames;
}

bool IBRxCredMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBRxCredMsg *>(obj)!=nullptr;
}

const char **IBRxCredMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBRxCredMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBRxCredMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int IBRxCredMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_VL
        FD_ISEDITABLE,    // FIELD_FCCL
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *IBRxCredMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "VL",
        "FCCL",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int IBRxCredMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "VL") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "FCCL") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *IBRxCredMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_VL
        "long",    // FIELD_FCCL
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **IBRxCredMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBRxCredMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBRxCredMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBRxCredMsg *pp = omnetpp::fromAnyPtr<IBRxCredMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBRxCredMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBRxCredMsg *pp = omnetpp::fromAnyPtr<IBRxCredMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBRxCredMsg'", field);
    }
}

const char *IBRxCredMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBRxCredMsg *pp = omnetpp::fromAnyPtr<IBRxCredMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBRxCredMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBRxCredMsg *pp = omnetpp::fromAnyPtr<IBRxCredMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: return long2string(pp->getVL());
        case FIELD_FCCL: return long2string(pp->getFCCL());
        default: return "";
    }
}

void IBRxCredMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBRxCredMsg *pp = omnetpp::fromAnyPtr<IBRxCredMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: pp->setVL(string2long(value)); break;
        case FIELD_FCCL: pp->setFCCL(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBRxCredMsg'", field);
    }
}

omnetpp::cValue IBRxCredMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBRxCredMsg *pp = omnetpp::fromAnyPtr<IBRxCredMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: return pp->getVL();
        case FIELD_FCCL: return (omnetpp::intval_t)(pp->getFCCL());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBRxCredMsg' as cValue -- field index out of range?", field);
    }
}

void IBRxCredMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBRxCredMsg *pp = omnetpp::fromAnyPtr<IBRxCredMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: pp->setVL(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_FCCL: pp->setFCCL(omnetpp::checked_int_cast<long>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBRxCredMsg'", field);
    }
}

const char *IBRxCredMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBRxCredMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBRxCredMsg *pp = omnetpp::fromAnyPtr<IBRxCredMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBRxCredMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBRxCredMsg *pp = omnetpp::fromAnyPtr<IBRxCredMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBRxCredMsg'", field);
    }
}

Register_Class(IBSentMsg)

IBSentMsg::IBSentMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

IBSentMsg::IBSentMsg(const IBSentMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

IBSentMsg::~IBSentMsg()
{
}

IBSentMsg& IBSentMsg::operator=(const IBSentMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void IBSentMsg::copy(const IBSentMsg& other)
{
    this->VL = other.VL;
    this->usedStatic = other.usedStatic;
    this->wasLast = other.wasLast;
}

void IBSentMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->VL);
    doParsimPacking(b,this->usedStatic);
    doParsimPacking(b,this->wasLast);
}

void IBSentMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->VL);
    doParsimUnpacking(b,this->usedStatic);
    doParsimUnpacking(b,this->wasLast);
}

short IBSentMsg::getVL() const
{
    return this->VL;
}

void IBSentMsg::setVL(short VL)
{
    this->VL = VL;
}

short IBSentMsg::getUsedStatic() const
{
    return this->usedStatic;
}

void IBSentMsg::setUsedStatic(short usedStatic)
{
    this->usedStatic = usedStatic;
}

short IBSentMsg::getWasLast() const
{
    return this->wasLast;
}

void IBSentMsg::setWasLast(short wasLast)
{
    this->wasLast = wasLast;
}

class IBSentMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_VL,
        FIELD_usedStatic,
        FIELD_wasLast,
    };
  public:
    IBSentMsgDescriptor();
    virtual ~IBSentMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBSentMsgDescriptor)

IBSentMsgDescriptor::IBSentMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBSentMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

IBSentMsgDescriptor::~IBSentMsgDescriptor()
{
    delete[] propertyNames;
}

bool IBSentMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBSentMsg *>(obj)!=nullptr;
}

const char **IBSentMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBSentMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBSentMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int IBSentMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_VL
        FD_ISEDITABLE,    // FIELD_usedStatic
        FD_ISEDITABLE,    // FIELD_wasLast
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *IBSentMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "VL",
        "usedStatic",
        "wasLast",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int IBSentMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "VL") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "usedStatic") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "wasLast") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *IBSentMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_VL
        "short",    // FIELD_usedStatic
        "short",    // FIELD_wasLast
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **IBSentMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBSentMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBSentMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBSentMsg *pp = omnetpp::fromAnyPtr<IBSentMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBSentMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBSentMsg *pp = omnetpp::fromAnyPtr<IBSentMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBSentMsg'", field);
    }
}

const char *IBSentMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBSentMsg *pp = omnetpp::fromAnyPtr<IBSentMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBSentMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBSentMsg *pp = omnetpp::fromAnyPtr<IBSentMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: return long2string(pp->getVL());
        case FIELD_usedStatic: return long2string(pp->getUsedStatic());
        case FIELD_wasLast: return long2string(pp->getWasLast());
        default: return "";
    }
}

void IBSentMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBSentMsg *pp = omnetpp::fromAnyPtr<IBSentMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: pp->setVL(string2long(value)); break;
        case FIELD_usedStatic: pp->setUsedStatic(string2long(value)); break;
        case FIELD_wasLast: pp->setWasLast(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBSentMsg'", field);
    }
}

omnetpp::cValue IBSentMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBSentMsg *pp = omnetpp::fromAnyPtr<IBSentMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: return pp->getVL();
        case FIELD_usedStatic: return pp->getUsedStatic();
        case FIELD_wasLast: return pp->getWasLast();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBSentMsg' as cValue -- field index out of range?", field);
    }
}

void IBSentMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBSentMsg *pp = omnetpp::fromAnyPtr<IBSentMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: pp->setVL(omnetpp::checked_int_cast<short>(value.intValue())); break;
        case FIELD_usedStatic: pp->setUsedStatic(omnetpp::checked_int_cast<short>(value.intValue())); break;
        case FIELD_wasLast: pp->setWasLast(omnetpp::checked_int_cast<short>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBSentMsg'", field);
    }
}

const char *IBSentMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBSentMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBSentMsg *pp = omnetpp::fromAnyPtr<IBSentMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBSentMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBSentMsg *pp = omnetpp::fromAnyPtr<IBSentMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBSentMsg'", field);
    }
}

Register_Class(IBFreeMsg)

IBFreeMsg::IBFreeMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

IBFreeMsg::IBFreeMsg(const IBFreeMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

IBFreeMsg::~IBFreeMsg()
{
}

IBFreeMsg& IBFreeMsg::operator=(const IBFreeMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void IBFreeMsg::copy(const IBFreeMsg& other)
{
    this->VL = other.VL;
}

void IBFreeMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->VL);
}

void IBFreeMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->VL);
}

short IBFreeMsg::getVL() const
{
    return this->VL;
}

void IBFreeMsg::setVL(short VL)
{
    this->VL = VL;
}

class IBFreeMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_VL,
    };
  public:
    IBFreeMsgDescriptor();
    virtual ~IBFreeMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBFreeMsgDescriptor)

IBFreeMsgDescriptor::IBFreeMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBFreeMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

IBFreeMsgDescriptor::~IBFreeMsgDescriptor()
{
    delete[] propertyNames;
}

bool IBFreeMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBFreeMsg *>(obj)!=nullptr;
}

const char **IBFreeMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBFreeMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBFreeMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int IBFreeMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_VL
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *IBFreeMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "VL",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int IBFreeMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "VL") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *IBFreeMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_VL
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **IBFreeMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBFreeMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBFreeMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBFreeMsg *pp = omnetpp::fromAnyPtr<IBFreeMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBFreeMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBFreeMsg *pp = omnetpp::fromAnyPtr<IBFreeMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBFreeMsg'", field);
    }
}

const char *IBFreeMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBFreeMsg *pp = omnetpp::fromAnyPtr<IBFreeMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBFreeMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBFreeMsg *pp = omnetpp::fromAnyPtr<IBFreeMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: return long2string(pp->getVL());
        default: return "";
    }
}

void IBFreeMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBFreeMsg *pp = omnetpp::fromAnyPtr<IBFreeMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: pp->setVL(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBFreeMsg'", field);
    }
}

omnetpp::cValue IBFreeMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBFreeMsg *pp = omnetpp::fromAnyPtr<IBFreeMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: return pp->getVL();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBFreeMsg' as cValue -- field index out of range?", field);
    }
}

void IBFreeMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBFreeMsg *pp = omnetpp::fromAnyPtr<IBFreeMsg>(object); (void)pp;
    switch (field) {
        case FIELD_VL: pp->setVL(omnetpp::checked_int_cast<short>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBFreeMsg'", field);
    }
}

const char *IBFreeMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBFreeMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBFreeMsg *pp = omnetpp::fromAnyPtr<IBFreeMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBFreeMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBFreeMsg *pp = omnetpp::fromAnyPtr<IBFreeMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBFreeMsg'", field);
    }
}

Register_Class(IBDoneMsg)

IBDoneMsg::IBDoneMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

IBDoneMsg::IBDoneMsg(const IBDoneMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

IBDoneMsg::~IBDoneMsg()
{
}

IBDoneMsg& IBDoneMsg::operator=(const IBDoneMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void IBDoneMsg::copy(const IBDoneMsg& other)
{
    this->appIdx = other.appIdx;
    this->VL = other.VL;
}

void IBDoneMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->appIdx);
    doParsimPacking(b,this->VL);
}

void IBDoneMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->appIdx);
    doParsimUnpacking(b,this->VL);
}

int IBDoneMsg::getAppIdx() const
{
    return this->appIdx;
}

void IBDoneMsg::setAppIdx(int appIdx)
{
    this->appIdx = appIdx;
}

short IBDoneMsg::getVL() const
{
    return this->VL;
}

void IBDoneMsg::setVL(short VL)
{
    this->VL = VL;
}

class IBDoneMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_appIdx,
        FIELD_VL,
    };
  public:
    IBDoneMsgDescriptor();
    virtual ~IBDoneMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBDoneMsgDescriptor)

IBDoneMsgDescriptor::IBDoneMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBDoneMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

IBDoneMsgDescriptor::~IBDoneMsgDescriptor()
{
    delete[] propertyNames;
}

bool IBDoneMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBDoneMsg *>(obj)!=nullptr;
}

const char **IBDoneMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBDoneMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBDoneMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int IBDoneMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_appIdx
        FD_ISEDITABLE,    // FIELD_VL
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *IBDoneMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "appIdx",
        "VL",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int IBDoneMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "appIdx") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "VL") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *IBDoneMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_appIdx
        "short",    // FIELD_VL
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **IBDoneMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBDoneMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBDoneMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBDoneMsg *pp = omnetpp::fromAnyPtr<IBDoneMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBDoneMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBDoneMsg *pp = omnetpp::fromAnyPtr<IBDoneMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBDoneMsg'", field);
    }
}

const char *IBDoneMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBDoneMsg *pp = omnetpp::fromAnyPtr<IBDoneMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBDoneMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBDoneMsg *pp = omnetpp::fromAnyPtr<IBDoneMsg>(object); (void)pp;
    switch (field) {
        case FIELD_appIdx: return long2string(pp->getAppIdx());
        case FIELD_VL: return long2string(pp->getVL());
        default: return "";
    }
}

void IBDoneMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBDoneMsg *pp = omnetpp::fromAnyPtr<IBDoneMsg>(object); (void)pp;
    switch (field) {
        case FIELD_appIdx: pp->setAppIdx(string2long(value)); break;
        case FIELD_VL: pp->setVL(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBDoneMsg'", field);
    }
}

omnetpp::cValue IBDoneMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBDoneMsg *pp = omnetpp::fromAnyPtr<IBDoneMsg>(object); (void)pp;
    switch (field) {
        case FIELD_appIdx: return pp->getAppIdx();
        case FIELD_VL: return pp->getVL();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBDoneMsg' as cValue -- field index out of range?", field);
    }
}

void IBDoneMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBDoneMsg *pp = omnetpp::fromAnyPtr<IBDoneMsg>(object); (void)pp;
    switch (field) {
        case FIELD_appIdx: pp->setAppIdx(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_VL: pp->setVL(omnetpp::checked_int_cast<short>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBDoneMsg'", field);
    }
}

const char *IBDoneMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBDoneMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBDoneMsg *pp = omnetpp::fromAnyPtr<IBDoneMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBDoneMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBDoneMsg *pp = omnetpp::fromAnyPtr<IBDoneMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBDoneMsg'", field);
    }
}

Register_Class(IBAppMsg)

IBAppMsg::IBAppMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

IBAppMsg::IBAppMsg(const IBAppMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

IBAppMsg::~IBAppMsg()
{
}

IBAppMsg& IBAppMsg::operator=(const IBAppMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void IBAppMsg::copy(const IBAppMsg& other)
{
    this->appIdx = other.appIdx;
    this->msgIdx = other.msgIdx;
    this->SQ = other.SQ;
    this->lenBytes = other.lenBytes;
    this->lenPkts = other.lenPkts;
    this->dstLid = other.dstLid;
    this->mtuBytes = other.mtuBytes;
    this->pktLenFlits = other.pktLenFlits;
    this->pktLenBytes = other.pktLenBytes;
    this->pktIdx = other.pktIdx;
    this->flitIdx = other.flitIdx;
    this->VL = other.VL;
}

void IBAppMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->appIdx);
    doParsimPacking(b,this->msgIdx);
    doParsimPacking(b,this->SQ);
    doParsimPacking(b,this->lenBytes);
    doParsimPacking(b,this->lenPkts);
    doParsimPacking(b,this->dstLid);
    doParsimPacking(b,this->mtuBytes);
    doParsimPacking(b,this->pktLenFlits);
    doParsimPacking(b,this->pktLenBytes);
    doParsimPacking(b,this->pktIdx);
    doParsimPacking(b,this->flitIdx);
    doParsimPacking(b,this->VL);
}

void IBAppMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->appIdx);
    doParsimUnpacking(b,this->msgIdx);
    doParsimUnpacking(b,this->SQ);
    doParsimUnpacking(b,this->lenBytes);
    doParsimUnpacking(b,this->lenPkts);
    doParsimUnpacking(b,this->dstLid);
    doParsimUnpacking(b,this->mtuBytes);
    doParsimUnpacking(b,this->pktLenFlits);
    doParsimUnpacking(b,this->pktLenBytes);
    doParsimUnpacking(b,this->pktIdx);
    doParsimUnpacking(b,this->flitIdx);
    doParsimUnpacking(b,this->VL);
}

unsigned int IBAppMsg::getAppIdx() const
{
    return this->appIdx;
}

void IBAppMsg::setAppIdx(unsigned int appIdx)
{
    this->appIdx = appIdx;
}

unsigned int IBAppMsg::getMsgIdx() const
{
    return this->msgIdx;
}

void IBAppMsg::setMsgIdx(unsigned int msgIdx)
{
    this->msgIdx = msgIdx;
}

unsigned int IBAppMsg::getSQ() const
{
    return this->SQ;
}

void IBAppMsg::setSQ(unsigned int SQ)
{
    this->SQ = SQ;
}

unsigned int IBAppMsg::getLenBytes() const
{
    return this->lenBytes;
}

void IBAppMsg::setLenBytes(unsigned int lenBytes)
{
    this->lenBytes = lenBytes;
}

unsigned int IBAppMsg::getLenPkts() const
{
    return this->lenPkts;
}

void IBAppMsg::setLenPkts(unsigned int lenPkts)
{
    this->lenPkts = lenPkts;
}

unsigned int IBAppMsg::getDstLid() const
{
    return this->dstLid;
}

void IBAppMsg::setDstLid(unsigned int dstLid)
{
    this->dstLid = dstLid;
}

unsigned int IBAppMsg::getMtuBytes() const
{
    return this->mtuBytes;
}

void IBAppMsg::setMtuBytes(unsigned int mtuBytes)
{
    this->mtuBytes = mtuBytes;
}

unsigned int IBAppMsg::getPktLenFlits() const
{
    return this->pktLenFlits;
}

void IBAppMsg::setPktLenFlits(unsigned int pktLenFlits)
{
    this->pktLenFlits = pktLenFlits;
}

unsigned int IBAppMsg::getPktLenBytes() const
{
    return this->pktLenBytes;
}

void IBAppMsg::setPktLenBytes(unsigned int pktLenBytes)
{
    this->pktLenBytes = pktLenBytes;
}

unsigned int IBAppMsg::getPktIdx() const
{
    return this->pktIdx;
}

void IBAppMsg::setPktIdx(unsigned int pktIdx)
{
    this->pktIdx = pktIdx;
}

unsigned int IBAppMsg::getFlitIdx() const
{
    return this->flitIdx;
}

void IBAppMsg::setFlitIdx(unsigned int flitIdx)
{
    this->flitIdx = flitIdx;
}

unsigned int IBAppMsg::getVL() const
{
    return this->VL;
}

void IBAppMsg::setVL(unsigned int VL)
{
    this->VL = VL;
}

class IBAppMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_appIdx,
        FIELD_msgIdx,
        FIELD_SQ,
        FIELD_lenBytes,
        FIELD_lenPkts,
        FIELD_dstLid,
        FIELD_mtuBytes,
        FIELD_pktLenFlits,
        FIELD_pktLenBytes,
        FIELD_pktIdx,
        FIELD_flitIdx,
        FIELD_VL,
    };
  public:
    IBAppMsgDescriptor();
    virtual ~IBAppMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBAppMsgDescriptor)

IBAppMsgDescriptor::IBAppMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBAppMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

IBAppMsgDescriptor::~IBAppMsgDescriptor()
{
    delete[] propertyNames;
}

bool IBAppMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBAppMsg *>(obj)!=nullptr;
}

const char **IBAppMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBAppMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBAppMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 12+base->getFieldCount() : 12;
}

unsigned int IBAppMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_appIdx
        FD_ISEDITABLE,    // FIELD_msgIdx
        FD_ISEDITABLE,    // FIELD_SQ
        FD_ISEDITABLE,    // FIELD_lenBytes
        FD_ISEDITABLE,    // FIELD_lenPkts
        FD_ISEDITABLE,    // FIELD_dstLid
        FD_ISEDITABLE,    // FIELD_mtuBytes
        FD_ISEDITABLE,    // FIELD_pktLenFlits
        FD_ISEDITABLE,    // FIELD_pktLenBytes
        FD_ISEDITABLE,    // FIELD_pktIdx
        FD_ISEDITABLE,    // FIELD_flitIdx
        FD_ISEDITABLE,    // FIELD_VL
    };
    return (field >= 0 && field < 12) ? fieldTypeFlags[field] : 0;
}

const char *IBAppMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "appIdx",
        "msgIdx",
        "SQ",
        "lenBytes",
        "lenPkts",
        "dstLid",
        "mtuBytes",
        "pktLenFlits",
        "pktLenBytes",
        "pktIdx",
        "flitIdx",
        "VL",
    };
    return (field >= 0 && field < 12) ? fieldNames[field] : nullptr;
}

int IBAppMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "appIdx") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "msgIdx") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "SQ") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "lenBytes") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "lenPkts") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "dstLid") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "mtuBytes") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "pktLenFlits") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "pktLenBytes") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "pktIdx") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "flitIdx") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "VL") == 0) return baseIndex + 11;
    return base ? base->findField(fieldName) : -1;
}

const char *IBAppMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_appIdx
        "unsigned int",    // FIELD_msgIdx
        "unsigned int",    // FIELD_SQ
        "unsigned int",    // FIELD_lenBytes
        "unsigned int",    // FIELD_lenPkts
        "unsigned int",    // FIELD_dstLid
        "unsigned int",    // FIELD_mtuBytes
        "unsigned int",    // FIELD_pktLenFlits
        "unsigned int",    // FIELD_pktLenBytes
        "unsigned int",    // FIELD_pktIdx
        "unsigned int",    // FIELD_flitIdx
        "unsigned int",    // FIELD_VL
    };
    return (field >= 0 && field < 12) ? fieldTypeStrings[field] : nullptr;
}

const char **IBAppMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBAppMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBAppMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBAppMsg *pp = omnetpp::fromAnyPtr<IBAppMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBAppMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBAppMsg *pp = omnetpp::fromAnyPtr<IBAppMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBAppMsg'", field);
    }
}

const char *IBAppMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBAppMsg *pp = omnetpp::fromAnyPtr<IBAppMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBAppMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBAppMsg *pp = omnetpp::fromAnyPtr<IBAppMsg>(object); (void)pp;
    switch (field) {
        case FIELD_appIdx: return ulong2string(pp->getAppIdx());
        case FIELD_msgIdx: return ulong2string(pp->getMsgIdx());
        case FIELD_SQ: return ulong2string(pp->getSQ());
        case FIELD_lenBytes: return ulong2string(pp->getLenBytes());
        case FIELD_lenPkts: return ulong2string(pp->getLenPkts());
        case FIELD_dstLid: return ulong2string(pp->getDstLid());
        case FIELD_mtuBytes: return ulong2string(pp->getMtuBytes());
        case FIELD_pktLenFlits: return ulong2string(pp->getPktLenFlits());
        case FIELD_pktLenBytes: return ulong2string(pp->getPktLenBytes());
        case FIELD_pktIdx: return ulong2string(pp->getPktIdx());
        case FIELD_flitIdx: return ulong2string(pp->getFlitIdx());
        case FIELD_VL: return ulong2string(pp->getVL());
        default: return "";
    }
}

void IBAppMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBAppMsg *pp = omnetpp::fromAnyPtr<IBAppMsg>(object); (void)pp;
    switch (field) {
        case FIELD_appIdx: pp->setAppIdx(string2ulong(value)); break;
        case FIELD_msgIdx: pp->setMsgIdx(string2ulong(value)); break;
        case FIELD_SQ: pp->setSQ(string2ulong(value)); break;
        case FIELD_lenBytes: pp->setLenBytes(string2ulong(value)); break;
        case FIELD_lenPkts: pp->setLenPkts(string2ulong(value)); break;
        case FIELD_dstLid: pp->setDstLid(string2ulong(value)); break;
        case FIELD_mtuBytes: pp->setMtuBytes(string2ulong(value)); break;
        case FIELD_pktLenFlits: pp->setPktLenFlits(string2ulong(value)); break;
        case FIELD_pktLenBytes: pp->setPktLenBytes(string2ulong(value)); break;
        case FIELD_pktIdx: pp->setPktIdx(string2ulong(value)); break;
        case FIELD_flitIdx: pp->setFlitIdx(string2ulong(value)); break;
        case FIELD_VL: pp->setVL(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBAppMsg'", field);
    }
}

omnetpp::cValue IBAppMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBAppMsg *pp = omnetpp::fromAnyPtr<IBAppMsg>(object); (void)pp;
    switch (field) {
        case FIELD_appIdx: return (omnetpp::intval_t)(pp->getAppIdx());
        case FIELD_msgIdx: return (omnetpp::intval_t)(pp->getMsgIdx());
        case FIELD_SQ: return (omnetpp::intval_t)(pp->getSQ());
        case FIELD_lenBytes: return (omnetpp::intval_t)(pp->getLenBytes());
        case FIELD_lenPkts: return (omnetpp::intval_t)(pp->getLenPkts());
        case FIELD_dstLid: return (omnetpp::intval_t)(pp->getDstLid());
        case FIELD_mtuBytes: return (omnetpp::intval_t)(pp->getMtuBytes());
        case FIELD_pktLenFlits: return (omnetpp::intval_t)(pp->getPktLenFlits());
        case FIELD_pktLenBytes: return (omnetpp::intval_t)(pp->getPktLenBytes());
        case FIELD_pktIdx: return (omnetpp::intval_t)(pp->getPktIdx());
        case FIELD_flitIdx: return (omnetpp::intval_t)(pp->getFlitIdx());
        case FIELD_VL: return (omnetpp::intval_t)(pp->getVL());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBAppMsg' as cValue -- field index out of range?", field);
    }
}

void IBAppMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBAppMsg *pp = omnetpp::fromAnyPtr<IBAppMsg>(object); (void)pp;
    switch (field) {
        case FIELD_appIdx: pp->setAppIdx(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_msgIdx: pp->setMsgIdx(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_SQ: pp->setSQ(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_lenBytes: pp->setLenBytes(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_lenPkts: pp->setLenPkts(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_dstLid: pp->setDstLid(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_mtuBytes: pp->setMtuBytes(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_pktLenFlits: pp->setPktLenFlits(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_pktLenBytes: pp->setPktLenBytes(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_pktIdx: pp->setPktIdx(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_flitIdx: pp->setFlitIdx(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_VL: pp->setVL(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBAppMsg'", field);
    }
}

const char *IBAppMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBAppMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBAppMsg *pp = omnetpp::fromAnyPtr<IBAppMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBAppMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBAppMsg *pp = omnetpp::fromAnyPtr<IBAppMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBAppMsg'", field);
    }
}

Register_Class(IBPushFECNMsg)

IBPushFECNMsg::IBPushFECNMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

IBPushFECNMsg::IBPushFECNMsg(const IBPushFECNMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

IBPushFECNMsg::~IBPushFECNMsg()
{
}

IBPushFECNMsg& IBPushFECNMsg::operator=(const IBPushFECNMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void IBPushFECNMsg::copy(const IBPushFECNMsg& other)
{
    this->srcLid = other.srcLid;
    this->dstLid = other.dstLid;
    this->SL = other.SL;
    this->msgIdx = other.msgIdx;
    this->appIdx = other.appIdx;
    this->RecvRate = other.RecvRate;
    this->BECNValue = other.BECNValue;
}

void IBPushFECNMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->srcLid);
    doParsimPacking(b,this->dstLid);
    doParsimPacking(b,this->SL);
    doParsimPacking(b,this->msgIdx);
    doParsimPacking(b,this->appIdx);
    doParsimPacking(b,this->RecvRate);
    doParsimPacking(b,this->BECNValue);
}

void IBPushFECNMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->srcLid);
    doParsimUnpacking(b,this->dstLid);
    doParsimUnpacking(b,this->SL);
    doParsimUnpacking(b,this->msgIdx);
    doParsimUnpacking(b,this->appIdx);
    doParsimUnpacking(b,this->RecvRate);
    doParsimUnpacking(b,this->BECNValue);
}

int IBPushFECNMsg::getSrcLid() const
{
    return this->srcLid;
}

void IBPushFECNMsg::setSrcLid(int srcLid)
{
    this->srcLid = srcLid;
}

int IBPushFECNMsg::getDstLid() const
{
    return this->dstLid;
}

void IBPushFECNMsg::setDstLid(int dstLid)
{
    this->dstLid = dstLid;
}

int IBPushFECNMsg::getSL() const
{
    return this->SL;
}

void IBPushFECNMsg::setSL(int SL)
{
    this->SL = SL;
}

int IBPushFECNMsg::getMsgIdx() const
{
    return this->msgIdx;
}

void IBPushFECNMsg::setMsgIdx(int msgIdx)
{
    this->msgIdx = msgIdx;
}

int IBPushFECNMsg::getAppIdx() const
{
    return this->appIdx;
}

void IBPushFECNMsg::setAppIdx(int appIdx)
{
    this->appIdx = appIdx;
}

double IBPushFECNMsg::getRecvRate() const
{
    return this->RecvRate;
}

void IBPushFECNMsg::setRecvRate(double RecvRate)
{
    this->RecvRate = RecvRate;
}

int IBPushFECNMsg::getBECNValue() const
{
    return this->BECNValue;
}

void IBPushFECNMsg::setBECNValue(int BECNValue)
{
    this->BECNValue = BECNValue;
}

class IBPushFECNMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcLid,
        FIELD_dstLid,
        FIELD_SL,
        FIELD_msgIdx,
        FIELD_appIdx,
        FIELD_RecvRate,
        FIELD_BECNValue,
    };
  public:
    IBPushFECNMsgDescriptor();
    virtual ~IBPushFECNMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBPushFECNMsgDescriptor)

IBPushFECNMsgDescriptor::IBPushFECNMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBPushFECNMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

IBPushFECNMsgDescriptor::~IBPushFECNMsgDescriptor()
{
    delete[] propertyNames;
}

bool IBPushFECNMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBPushFECNMsg *>(obj)!=nullptr;
}

const char **IBPushFECNMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBPushFECNMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBPushFECNMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int IBPushFECNMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srcLid
        FD_ISEDITABLE,    // FIELD_dstLid
        FD_ISEDITABLE,    // FIELD_SL
        FD_ISEDITABLE,    // FIELD_msgIdx
        FD_ISEDITABLE,    // FIELD_appIdx
        FD_ISEDITABLE,    // FIELD_RecvRate
        FD_ISEDITABLE,    // FIELD_BECNValue
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *IBPushFECNMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcLid",
        "dstLid",
        "SL",
        "msgIdx",
        "appIdx",
        "RecvRate",
        "BECNValue",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int IBPushFECNMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcLid") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "dstLid") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "SL") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "msgIdx") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "appIdx") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "RecvRate") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "BECNValue") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *IBPushFECNMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_srcLid
        "int",    // FIELD_dstLid
        "int",    // FIELD_SL
        "int",    // FIELD_msgIdx
        "int",    // FIELD_appIdx
        "double",    // FIELD_RecvRate
        "int",    // FIELD_BECNValue
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **IBPushFECNMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBPushFECNMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBPushFECNMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBPushFECNMsg *pp = omnetpp::fromAnyPtr<IBPushFECNMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBPushFECNMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBPushFECNMsg *pp = omnetpp::fromAnyPtr<IBPushFECNMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBPushFECNMsg'", field);
    }
}

const char *IBPushFECNMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBPushFECNMsg *pp = omnetpp::fromAnyPtr<IBPushFECNMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBPushFECNMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBPushFECNMsg *pp = omnetpp::fromAnyPtr<IBPushFECNMsg>(object); (void)pp;
    switch (field) {
        case FIELD_srcLid: return long2string(pp->getSrcLid());
        case FIELD_dstLid: return long2string(pp->getDstLid());
        case FIELD_SL: return long2string(pp->getSL());
        case FIELD_msgIdx: return long2string(pp->getMsgIdx());
        case FIELD_appIdx: return long2string(pp->getAppIdx());
        case FIELD_RecvRate: return double2string(pp->getRecvRate());
        case FIELD_BECNValue: return long2string(pp->getBECNValue());
        default: return "";
    }
}

void IBPushFECNMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBPushFECNMsg *pp = omnetpp::fromAnyPtr<IBPushFECNMsg>(object); (void)pp;
    switch (field) {
        case FIELD_srcLid: pp->setSrcLid(string2long(value)); break;
        case FIELD_dstLid: pp->setDstLid(string2long(value)); break;
        case FIELD_SL: pp->setSL(string2long(value)); break;
        case FIELD_msgIdx: pp->setMsgIdx(string2long(value)); break;
        case FIELD_appIdx: pp->setAppIdx(string2long(value)); break;
        case FIELD_RecvRate: pp->setRecvRate(string2double(value)); break;
        case FIELD_BECNValue: pp->setBECNValue(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBPushFECNMsg'", field);
    }
}

omnetpp::cValue IBPushFECNMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBPushFECNMsg *pp = omnetpp::fromAnyPtr<IBPushFECNMsg>(object); (void)pp;
    switch (field) {
        case FIELD_srcLid: return pp->getSrcLid();
        case FIELD_dstLid: return pp->getDstLid();
        case FIELD_SL: return pp->getSL();
        case FIELD_msgIdx: return pp->getMsgIdx();
        case FIELD_appIdx: return pp->getAppIdx();
        case FIELD_RecvRate: return pp->getRecvRate();
        case FIELD_BECNValue: return pp->getBECNValue();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBPushFECNMsg' as cValue -- field index out of range?", field);
    }
}

void IBPushFECNMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBPushFECNMsg *pp = omnetpp::fromAnyPtr<IBPushFECNMsg>(object); (void)pp;
    switch (field) {
        case FIELD_srcLid: pp->setSrcLid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dstLid: pp->setDstLid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_SL: pp->setSL(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_msgIdx: pp->setMsgIdx(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_appIdx: pp->setAppIdx(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_RecvRate: pp->setRecvRate(value.doubleValue()); break;
        case FIELD_BECNValue: pp->setBECNValue(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBPushFECNMsg'", field);
    }
}

const char *IBPushFECNMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBPushFECNMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBPushFECNMsg *pp = omnetpp::fromAnyPtr<IBPushFECNMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBPushFECNMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBPushFECNMsg *pp = omnetpp::fromAnyPtr<IBPushFECNMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBPushFECNMsg'", field);
    }
}

Register_Class(IBPushBECNMsg)

IBPushBECNMsg::IBPushBECNMsg(const char *name, short kind) : ::IBWireMsg(name, kind)
{
}

IBPushBECNMsg::IBPushBECNMsg(const IBPushBECNMsg& other) : ::IBWireMsg(other)
{
    copy(other);
}

IBPushBECNMsg::~IBPushBECNMsg()
{
}

IBPushBECNMsg& IBPushBECNMsg::operator=(const IBPushBECNMsg& other)
{
    if (this == &other) return *this;
    ::IBWireMsg::operator=(other);
    copy(other);
    return *this;
}

void IBPushBECNMsg::copy(const IBPushBECNMsg& other)
{
    this->BECNValue = other.BECNValue;
    this->srcLid = other.srcLid;
    this->dstLid = other.dstLid;
    this->SL = other.SL;
    this->msgIdx = other.msgIdx;
    this->appIdx = other.appIdx;
    this->RecvRate = other.RecvRate;
}

void IBPushBECNMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::IBWireMsg::parsimPack(b);
    doParsimPacking(b,this->BECNValue);
    doParsimPacking(b,this->srcLid);
    doParsimPacking(b,this->dstLid);
    doParsimPacking(b,this->SL);
    doParsimPacking(b,this->msgIdx);
    doParsimPacking(b,this->appIdx);
    doParsimPacking(b,this->RecvRate);
}

void IBPushBECNMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::IBWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->BECNValue);
    doParsimUnpacking(b,this->srcLid);
    doParsimUnpacking(b,this->dstLid);
    doParsimUnpacking(b,this->SL);
    doParsimUnpacking(b,this->msgIdx);
    doParsimUnpacking(b,this->appIdx);
    doParsimUnpacking(b,this->RecvRate);
}

int IBPushBECNMsg::getBECNValue() const
{
    return this->BECNValue;
}

void IBPushBECNMsg::setBECNValue(int BECNValue)
{
    this->BECNValue = BECNValue;
}

int IBPushBECNMsg::getSrcLid() const
{
    return this->srcLid;
}

void IBPushBECNMsg::setSrcLid(int srcLid)
{
    this->srcLid = srcLid;
}

int IBPushBECNMsg::getDstLid() const
{
    return this->dstLid;
}

void IBPushBECNMsg::setDstLid(int dstLid)
{
    this->dstLid = dstLid;
}

int IBPushBECNMsg::getSL() const
{
    return this->SL;
}

void IBPushBECNMsg::setSL(int SL)
{
    this->SL = SL;
}

int IBPushBECNMsg::getMsgIdx() const
{
    return this->msgIdx;
}

void IBPushBECNMsg::setMsgIdx(int msgIdx)
{
    this->msgIdx = msgIdx;
}

int IBPushBECNMsg::getAppIdx() const
{
    return this->appIdx;
}

void IBPushBECNMsg::setAppIdx(int appIdx)
{
    this->appIdx = appIdx;
}

double IBPushBECNMsg::getRecvRate() const
{
    return this->RecvRate;
}

void IBPushBECNMsg::setRecvRate(double RecvRate)
{
    this->RecvRate = RecvRate;
}

class IBPushBECNMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_BECNValue,
        FIELD_srcLid,
        FIELD_dstLid,
        FIELD_SL,
        FIELD_msgIdx,
        FIELD_appIdx,
        FIELD_RecvRate,
    };
  public:
    IBPushBECNMsgDescriptor();
    virtual ~IBPushBECNMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(IBPushBECNMsgDescriptor)

IBPushBECNMsgDescriptor::IBPushBECNMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(IBPushBECNMsg)), "IBWireMsg")
{
    propertyNames = nullptr;
}

IBPushBECNMsgDescriptor::~IBPushBECNMsgDescriptor()
{
    delete[] propertyNames;
}

bool IBPushBECNMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IBPushBECNMsg *>(obj)!=nullptr;
}

const char **IBPushBECNMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IBPushBECNMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IBPushBECNMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int IBPushBECNMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_BECNValue
        FD_ISEDITABLE,    // FIELD_srcLid
        FD_ISEDITABLE,    // FIELD_dstLid
        FD_ISEDITABLE,    // FIELD_SL
        FD_ISEDITABLE,    // FIELD_msgIdx
        FD_ISEDITABLE,    // FIELD_appIdx
        FD_ISEDITABLE,    // FIELD_RecvRate
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *IBPushBECNMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "BECNValue",
        "srcLid",
        "dstLid",
        "SL",
        "msgIdx",
        "appIdx",
        "RecvRate",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int IBPushBECNMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "BECNValue") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "srcLid") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "dstLid") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "SL") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "msgIdx") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "appIdx") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "RecvRate") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *IBPushBECNMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_BECNValue
        "int",    // FIELD_srcLid
        "int",    // FIELD_dstLid
        "int",    // FIELD_SL
        "int",    // FIELD_msgIdx
        "int",    // FIELD_appIdx
        "double",    // FIELD_RecvRate
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **IBPushBECNMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IBPushBECNMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IBPushBECNMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IBPushBECNMsg *pp = omnetpp::fromAnyPtr<IBPushBECNMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IBPushBECNMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IBPushBECNMsg *pp = omnetpp::fromAnyPtr<IBPushBECNMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IBPushBECNMsg'", field);
    }
}

const char *IBPushBECNMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IBPushBECNMsg *pp = omnetpp::fromAnyPtr<IBPushBECNMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IBPushBECNMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IBPushBECNMsg *pp = omnetpp::fromAnyPtr<IBPushBECNMsg>(object); (void)pp;
    switch (field) {
        case FIELD_BECNValue: return long2string(pp->getBECNValue());
        case FIELD_srcLid: return long2string(pp->getSrcLid());
        case FIELD_dstLid: return long2string(pp->getDstLid());
        case FIELD_SL: return long2string(pp->getSL());
        case FIELD_msgIdx: return long2string(pp->getMsgIdx());
        case FIELD_appIdx: return long2string(pp->getAppIdx());
        case FIELD_RecvRate: return double2string(pp->getRecvRate());
        default: return "";
    }
}

void IBPushBECNMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBPushBECNMsg *pp = omnetpp::fromAnyPtr<IBPushBECNMsg>(object); (void)pp;
    switch (field) {
        case FIELD_BECNValue: pp->setBECNValue(string2long(value)); break;
        case FIELD_srcLid: pp->setSrcLid(string2long(value)); break;
        case FIELD_dstLid: pp->setDstLid(string2long(value)); break;
        case FIELD_SL: pp->setSL(string2long(value)); break;
        case FIELD_msgIdx: pp->setMsgIdx(string2long(value)); break;
        case FIELD_appIdx: pp->setAppIdx(string2long(value)); break;
        case FIELD_RecvRate: pp->setRecvRate(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBPushBECNMsg'", field);
    }
}

omnetpp::cValue IBPushBECNMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IBPushBECNMsg *pp = omnetpp::fromAnyPtr<IBPushBECNMsg>(object); (void)pp;
    switch (field) {
        case FIELD_BECNValue: return pp->getBECNValue();
        case FIELD_srcLid: return pp->getSrcLid();
        case FIELD_dstLid: return pp->getDstLid();
        case FIELD_SL: return pp->getSL();
        case FIELD_msgIdx: return pp->getMsgIdx();
        case FIELD_appIdx: return pp->getAppIdx();
        case FIELD_RecvRate: return pp->getRecvRate();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IBPushBECNMsg' as cValue -- field index out of range?", field);
    }
}

void IBPushBECNMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IBPushBECNMsg *pp = omnetpp::fromAnyPtr<IBPushBECNMsg>(object); (void)pp;
    switch (field) {
        case FIELD_BECNValue: pp->setBECNValue(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_srcLid: pp->setSrcLid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dstLid: pp->setDstLid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_SL: pp->setSL(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_msgIdx: pp->setMsgIdx(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_appIdx: pp->setAppIdx(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_RecvRate: pp->setRecvRate(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBPushBECNMsg'", field);
    }
}

const char *IBPushBECNMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr IBPushBECNMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IBPushBECNMsg *pp = omnetpp::fromAnyPtr<IBPushBECNMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IBPushBECNMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IBPushBECNMsg *pp = omnetpp::fromAnyPtr<IBPushBECNMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IBPushBECNMsg'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

