#include <resources/XMLNode.h>
#include <resources/XMLElement.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cXMLNode::cXMLNode(cXMLNode* apParent)
	{
		mpParent = apParent;
	}

	cXMLNode::~cXMLNode()
	{
		mlstChildren.clear();
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	void cXMLNode::SetParent(cXMLNode* apParent)
	{
		mpParent = apParent;
	}

	cXMLNode* cXMLNode::GetParent() const
	{
		return mpParent;
	}

	void cXMLNode::AddChild(cXMLNode* apChild)
	{
		mlstChildren.push_back(apChild);
	}
	
	void cXMLNode::RemoveChild(cXMLNode* apChild)
	{
		tNodeListIt it = std::find(mlstChildren.begin(), mlstChildren.end(), apChild);
		mlstChildren.erase(it);
	}

	void cXMLNode::RemoveChildren()
	{
		mlstChildren.clear();
	}

	void cXMLNode::SetValueString(const std::string& asValue)
	{
		SetValue(asValue);
	}

	void cXMLNode::SetValueInt(int alValue)
	{
		std::string sValue = std::to_string(alValue);
		SetValue(sValue);
	}

	void cXMLNode::SetValueFloat(float afValue)
	{
		std::string sValue = std::to_string(afValue);
		SetValue(sValue);
	}

	void cXMLNode::SetValueDouble(double afValue)
	{
		std::string sValue = std::to_string(afValue);
		SetValue(sValue);
	}

	void cXMLNode::SetValueBool(bool abValue)
	{
		std::string sValue = abValue ? "true" : "false";
		SetValue(sValue);
	}

	const std::string& cXMLNode::GetValueString() const
	{
		return GetValue();
	}

	int cXMLNode::GetValueInt() const
	{
		return std::stoi(GetValue());
	}

	float cXMLNode::GetValueFloat() const
	{
		return std::stof(GetValue());
	}

	double cXMLNode::GetValueDouble() const
	{
		return std::stod(GetValue());
	}

	bool cXMLNode::GetValueBool() const
	{
		return GetValue() == "true";
	}

	const tNodeList& cXMLNode::GetChildren() const
	{
		return mlstChildren;
	}

	cXMLNode* cXMLNode::GetFirstChild() const
	{
		return mlstChildren.front();
	}

	cXMLNode* cXMLNode::GetLastChild() const
	{
		return mlstChildren.back();
	}

	int cXMLNode::GetChildCount() const
	{
		return mlstChildren.size();
	}

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	cXMLElement* cXMLNode::ToElement()
	{
		return static_cast<cXMLElement*>(this);
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PROTECTED METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	void cXMLNode::SetValue(const std::string& asValue)
	{
		msValue = asValue;
	}

	const std::string& cXMLNode::GetValue() const
	{
		return msValue;
	}

	// -----------------------------------------------------------------------
}