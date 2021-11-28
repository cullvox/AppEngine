// License
//		AppEngine is licenced under the MIT Licence
//		Read the license to learn more

// Tabs vs Spaces
//		Always use tabs when you need to indent
//		Spaces are for spacing out information not to indent

// Comments
//		Always have a space after "//" when there is text directly after it (this line does not fall under this rule)
//		Never use /* or */
//		Comments are a 
//		Comments usually never have periods
//		I would set the "Render Whitespace" preference to "boundary" in VSCode to make this easier to see

// Includes
//		Add includes at the very top
//		When including always add the full path even if they technically are in the same directory
#include "Types.h" 
#include "Graphics/GraphicsDevice.h"

// Namespaces
namespace AE // Since this project is called AppEngine we use the namespace AE in every file
{

// Naming Conventions
// Most naming conventions are inspired by the Epic Games Coding Standard
//
//		Classes
//			Capitalize every word in a class or struct name (PascalCase)
//			Use G to describe any general public class in the AE namespace, other prefixes will override this one most times
//			Use W to describe game objects in a world
//			Use D to describe structs and data types
//			Use T to describe templated types
//			Use I to describe interfaces and abstract classes 
//			Use E to describe an enum
//			Use F to describe final
//		
//		Values
//			The first letter of the first word in a value definition is lowercase (camelCase)
//			Use a lowercase 'b' before defining boolean values
//
//		Functions
//			The first letter of every word is capitalized (PascalCase)
//			If a function is returning a boolean value the name should be a question (for example, isWindowOpen() or isTrueFalse())

// Classes
//		You usually want a class with the same name as the file in the file
class GCodeStyle
{

//		Protection
//			Use public: for functions and [con,de]structors
//			Use protected: for variables that may be inherited
//			Use private: when the values will not be inherited
public:

//		Constructors
//			Always have a default constructor
//			Always have a default destructor
//			Always have a copy constructor except when the class inherits from GNonCopyable
//			Active constructors are optional
	GCodeStyle(); // Always have a default constructor
	GCodeStyle(const GCodeStyle& other); // You usually want a copy constructor unless it inherits NotCopyable
	GCodeStyle(const SString& name, float foo, int var); // This is an active constructor, its active because it does things
	~GCodeStyle();

public:
	virtual GCodeStyle& operator=(const GCodeStyle& other); // Copy assignment required when a copy constructor is available

public:
	void DoSomething();
//		Templates
//			Use templates to your advantage when ever you need to
//			Place the template tag above the declaration/definition when possible
	template <typename T> 
	void DoSomethingTemplated(const T& value);
	void DoSomethingElse();

	void IsFooNormalized();

//		Variables
//			Most variables in a class should be private and accessable through functions
private:
	SString name;
	bool bFooNormalized;
		// This white space after a class is defined is vital


// Class Ordering
//
//		Constructors/Destructors
//		Virtual Constructors
//		Operator Overloads
//		Functions
//		Variables
//		Friends
//	Every member ordered in these grops are also subordered from public, protected to private

};

// Structs
//		Structs are for data and not much should go in them except data and constructors
struct SCodeStyleInfo
{
//	Constructors
//		Defining constructors is allowed inside of a struct
	SCodeStyleInfo(bool _bSomeValue, float _anotherValue, int _anInteger)
		: bSomeValue(_bSomeValue), anotherValue(_anotherValue), anInteger(_anInteger)
	{
	}

	bool bSomeValue;
	float anotherValue;
	int anInteger;
}

// The AE namespace does not require a comment after it
}