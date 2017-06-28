/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_CONFIGURATIONS_FEATURES_FINAL_HH
#define AEIOU_HEADER_CONFIGURATIONS_FEATURES_FINAL_HH
#include <Aeiou/Configurations/Basic-Values.hh>

#include <Aeiou/Configurations/Compiler.hh>
#include <Aeiou/Configurations/Features/Constexpr.hh>

#define AEIOU_NON_INHERITABLE(name) AEIOU_NON_INHERITABLE_DESTRUCTOR(name, ;)
#define AEIOU_NON_INHERITABLE_CONSTEXPR(name)						\
AEIOU_NON_INHERITABLE_DESTRUCTOR_CONSTEXPR(name, ;)

#if AEIOU_CONFIG_SUPPORTED_CONSTEXPR == AEIOU_CONFIG_YES
#define AEIOU_NON_INHERITABLE_DESTRUCTOR_CONSTEXPR(name, body)		\
public:																\
	constexpr void Destructor() {}
#else
#define AEIOU_NON_INHERITABLE_DESTRUCTOR_CONSTEXPR(name, body)		\
AEIOU_NON_INHERITABLE_DESTRUCTOR(name, body)
#endif

#if AEIOU_CONFIG_SUPPORTED_FINAL == AEIOU_CONFIG_YES
#define AEIOU_FINAL final
#define AEIOU_NON_INHERITABLE_DESTRUCTOR(name, body)				\
public:																\
	~name()															\
	body															\
																	\
public:																\
	void Destructor()												\
	{																\
		this->~name();												\
	}

#else
#define AEIOU_FINAL
#define AEIOU_NON_INHERITABLE_DESTRUCTOR(name, body)				\
private:															\
	~name()															\
	body															\
																	\
public:																\
	void Destructor()												\
	{																\
		this->~name();												\
	}
#endif

#endif