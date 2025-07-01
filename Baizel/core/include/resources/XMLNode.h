#ifndef BAIZEL_XMLNODE_H
#define BAIZEL_XMLNODE_H

#include <string>
#include <list>

namespace baizel
{
	class cXMLElement;
	class cXMLNode;

	using tNodeList = std::list<cXMLNode*>;
	using tNodeListIt = tNodeList::const_iterator;

	class cXMLNode
	{
	public:
		cXMLNode(cXMLNode* apParent);
		~cXMLNode();

		void SetParent(cXMLNode* apParent);
		cXMLNode* GetParent() const;

		void AddChild(cXMLNode* apChild);
		void RemoveChild(cXMLNode* apChild);
		void RemoveChildren();

		void SetValueString(const std::string& asValue);
		void SetValueInt(int alValue);
		void SetValueFloat(float afValue);
		void SetValueDouble(double afValue);
		void SetValueBool(bool abValue);

		const std::string& GetValueString() const;
		int GetValueInt() const;
		float GetValueFloat() const;
		double GetValueDouble() const;
		bool GetValueBool() const;

		const tNodeList& GetChildren() const;
		cXMLNode* GetFirstChild() const;
		cXMLNode* GetLastChild() const;

		cXMLElement* ToElement();

	protected:
		void SetValue(const std::string& asValue);
		const std::string& GetValue() const;

	protected:
		cXMLNode* mpParent = nullptr;
		tNodeList mlstChildren = tNodeList();

		std::string msValue = "";
	};
}

#endif // BAIZEL_XMLNODE_H