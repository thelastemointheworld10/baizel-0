#ifndef BAIZEL_XMLELEMENTTINYXML_H
#define BAIZEL_XMLELEMENTTINYXML_H

#include <system/XMLElement.h>
#include <impl/system/XMLDocumentTinyXML.h>

#include <impl/system/ErrorHandlerTinyXML.h>

using namespace tinyxml2;

namespace baizel
{
    class cXMLElementTinyXML final : public iXMLElement
    {
    public:
        cXMLElementTinyXML(iXMLDocument* apDocument);
        ~cXMLElementTinyXML();

        void SetValue(const std::string& asValue) const override;
        void SetValue(int alValue) const override;
        void SetValue(unsigned int alValue) const override;
        void SetValue(int64_t alValue) const override;
        void SetValue(uint64_t alValue) const override;
        void SetValue(float afValue) const override;
        void SetValue(double afValue) const override;
        void SetValue(bool abValue) const override;

        std::string GetStrValue() override;
        int GetIntValue() override;
        unsigned int GetUintValue() override;
        int64_t GetInt64Value() override;
        uint64_t GetUint64Value() override;
        float GetFloatValue() override;
        double GetDoubleValue() override;
        bool GetBoolValue() override;

        void SetAttribute(const std::string& asName, const std::string& asValue) const override;
        void SetAttribute(const std::string& asName, int alValue) const override;
        void SetAttribute(const std::string& asName, unsigned int alValue) const override;
        void SetAttribute(const std::string& asName, int64_t alValue) const override;
        void SetAttribute(const std::string& asName, uint64_t alValue) const override;
        void SetAttribute(const std::string& asName, float afValue) const override;
        void SetAttribute(const std::string& asName, double afValue) const override;
        void SetAttribute(const std::string& asName, bool abValue) const override;

        std::string GetStrAttribute(const std::string& asName) override;
        int GetIntAttribute(const std::string& asName) override;
        unsigned int GetUintAttribute(const std::string& asName) override;
        int64_t GetInt64Attribute(const std::string& asName) override;
        uint64_t GetUint64Attribute(const std::string& asName) override;
        float GetFloatAttribute(const std::string& asName) override;
        double GetDoubleAttribute(const std::string& asName) override;
        bool GetBoolAttribute(const std::string& asName) override;

        void InsertFirst(iXMLElement* apElement) const override;
        void InsertEnd(iXMLElement* apElement) const override;

        void Find(const std::string& asName) override;

        void SetName(const std::string& asName) override;
        XMLElement* GetElement();

    protected:
        void FindRoot() override;

    private:
        tinyxml2::XMLDocument* mpDocument = nullptr;
        XMLElement* mpElement = nullptr;
        XMLNode* mpRoot = nullptr;
    };
}

#endif // BAIZEL_XMLELEMENTTINYXML_H