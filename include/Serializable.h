#pragma once
#include "SerializationFileWriterBuilder.h"
#include "SerializationFileReaderBuilder.h"
#include "Defines.h"
#define NVP(name) #name<<"="<<name<<'\n'
#define ADDITIONAL_KEY(name) #name<<"."
#define GET_NVP_VALUE_BY_ADDITIONAL_KEY(additionalKey,name) getNVPValueByAdditionalKey(#additionalKey,#name)
#define GET_NVP(name) getNVP(#name)

EXPORT_API std::string getNVPValueByAdditionalKey(const char* additionalKey,const char* name)
{
    std::stringstream ss;
    ss << additionalKey << "." << name;
    return ss.str();
}
EXPORT_API std::string getNVP(const char* name)
{
    std::stringstream ss;
    ss<< name << "=";
    return ss.str();
}
class Serializable
{
public:
    EXPORT_API virtual void save(SerializationFileWriterBuilder& stream) = 0;
    EXPORT_API virtual void load(SerializationFileReaderBuilder& stream) = 0;

};
EXPORT_API SerializationFileWriterBuilder& operator<<(SerializationFileWriterBuilder& stream, Serializable* serializable)
{
    serializable->save(stream);
    return stream;
}

EXPORT_API SerializationFileReaderBuilder& operator >>(SerializationFileReaderBuilder& stream,Serializable* serialazable)
{
    serialazable->load(stream);
    return stream;
}

