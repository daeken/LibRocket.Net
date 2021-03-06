#pragma once

#include <gcroot.h>
#include "LibRocketNet.h"

using namespace System;

namespace LibRocketNet {

	ref class Element;

	namespace Util {
		
		template < class T, class U >
		Boolean IsInstance(U u) {
			return dynamic_cast< T >(u) != nullptr;
		}


		String^ ToNetString(const Rocket::Core::String& s);
		Rocket::Core::String ToRocketString(String^ s);

		gcroot<Element^>* GetGcRoot(Rocket::Core::Element* elem, const char *attribName);
		void SetGcRoot(Rocket::Core::Element* elem, gcroot<Element^>* r, const char *attribName);
	}

}