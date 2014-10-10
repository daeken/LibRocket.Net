#pragma once

#include "LibRocketNet.h"



namespace LibRocketNet {

	ref class Element;

	namespace Util {
		
		template < class T, class U >
		Boolean IsInstance(U u) {
			return dynamic_cast< T >(u) != nullptr;
		}


		String^ ToNetString(const Rocket::Core::String& const s);
		Rocket::Core::String ToRocketString(const String^ const s);

		gcroot<Element^>* GetGcRoot(RocketElement* elem, const char *attribName);
		void SetGcRoot(RocketElement* elem, gcroot<Element^>* r, const char *attribName);
	}

}