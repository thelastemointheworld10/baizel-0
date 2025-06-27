#ifndef BAIZEL_XMLELEMENT_H
#define BAIZEL_XMLELEMENT_H

#include <string>
#include <cstdint>

#include <system/XMLDocument.h>

namespace baizel
{
    class iXMLElement
    {
    public:
        virtual ~iXMLElement() = default;

        virtual void SetValue(const std::string& asValue) const = 0;
        virtual void SetValue(int alValue) const = 0;
        virtual void SetValue(unsigned int alValue) const = 0;
        virtual void SetValue(int64_t alValue) const = 0;
        virtual void SetValue(uint64_t alValue) const = 0;
        virtual void SetValue(float afValue) const = 0;
        virtual void SetValue(double afValue) const = 0;
        virtual void SetValue(bool abValue) const = 0;

        virtual std::string GetStrValue() = 0;
        virtual int GetIntValue() = 0;
        virtual unsigned int GetUintValue() = 0;
        virtual int64_t GetInt64Value() = 0;
        virtual uint64_t GetUint64Value() = 0;
        virtual float GetFloatValue() = 0;
        virtual double GetDoubleValue() = 0;
        virtual bool GetBoolValue() = 0;

        virtual void SetAttribute(const std::string& asName, const std::string& asValue) const = 0;
        virtual void SetAttribute(const std::string& asName, int alValue) const = 0;
        virtual void SetAttribute(const std::string& asName, unsigned int alValue) const = 0;
        virtual void SetAttribute(const std::string& asName, int64_t alValue) const = 0;
        virtual void SetAttribute(const std::string& asName, uint64_t alValue) const = 0;
        virtual void SetAttribute(const std::string& asName, float afValue) const = 0;
        virtual void SetAttribute(const std::string& asName, double afValue) const = 0;
        virtual void SetAttribute(const std::string& asName, bool abValue) const = 0;

        virtual std::string GetStrAttribute(const std::string& asName) = 0;
        virtual int GetIntAttribute(const std::string& asName) = 0;
        virtual unsigned int GetUintAttribute(const std::string& asName) = 0;
        virtual int64_t GetInt64Attribute(const std::string& asName) = 0;
        virtual uint64_t GetUint64Attribute(const std::string& asName) = 0;
        virtual float GetFloatAttribute(const std::string& asName) = 0;
        virtual double GetDoubleAttribute(const std::string& asName) = 0;
        virtual bool GetBoolAttribute(const std::string& asName) = 0;

        virtual void InsertFirst(iXMLElement* apElement) const = 0;
        virtual void InsertEnd(iXMLElement* apElement) const = 0;

        virtual void Find(const std::string& asName) = 0;

        virtual void SetName(const std::string& asName) = 0;

    protected:
        virtual void FindRoot() = 0;
    };
}

#endif // BAIZEL_XMLELEMENT_H