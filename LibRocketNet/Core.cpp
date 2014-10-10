#include "stdafx.h"

#include "Rocket/Core.h"
#include "Rocket/Core/String.h"

#include "Core.h"
#include "Util.h"
#include "SystemInterface.h"
#include "RenderInterface.h"
#include "FileInterface.h"
#include "Context.h"



namespace LibRocketNet{

	bool Core::Initialize() {
		_contexts = gcnew Dictionary<IntPtr,Context^>();
		return Rocket::Core::Initialise();
	}

	void Core::Shutdown() {
		Rocket::Core::Shutdown();
		_contexts->Clear();
		_contexts = nullptr;

	}

	String^ Core::Version::get(){
		auto v = Rocket::Core::GetVersion();
		return Util::ToNetString(v);
	}

	SystemInterface^ Core::SystemInterface::get(){
		return _systemInterface;
	} 

	void Core::SystemInterface::set(LibRocketNet::SystemInterface^ s) {
		_systemInterface = s;
	}


	RenderInterface^ Core::RenderInterface::get() {
		return _renderInterface;
	}

	void Core::RenderInterface::set(LibRocketNet::RenderInterface^ r) {
		_renderInterface = r;
	}

	FileInterface^ Core::FileInterface::get() {
		return _fileInterface;
	}

	void Core::FileInterface::set(LibRocketNet::FileInterface^ f) {
		FileInterface = f;
	}

	Context^ Core::CreateContext(String^ name, Vector2i dimensions, LibRocketNet::RenderInterface^ renderInterface) {

		Rocket::Core::RenderInterface * rPtr = _renderInterface == nullptr ? NULL : (_renderInterface->Interface.ToPointer);
		IntPtr ctxPtr = IntPtr(Rocket::Core::CreateContext(Util::ToRocketString(name), Rocket::Core::Vector2i(dimensions.X, dimensions.Y), rPtr));
		auto ctx = gcnew Context(ctxPtr.ToPointer);
		_contexts[ctxPtr] = ctx;
		return ctx;
	}

	Context^ Core::CreateContext(String^ name, Vector2i dimensions) { return CreateContext(name, dimensions, nullptr); }

	Context^ Core::GetContext(String^ name) {
		auto ptr = Rocket::Core::GetContext(Util::ToRocketString(name));
		if (!ptr) return nullptr;
		return _contexts[IntPtr(ptr)];
	}


	Context^ Core::GetContext(int index) {
		auto ptr = Rocket::Core::GetContext(index);
		if (!ptr) return nullptr;
		return _contexts[IntPtr(ptr)];
	}

	int Core::NumContexts::get(){
		return Rocket::Core::GetNumContexts();
	}

	void Core::ReleaseCompiledGeometries() {
		Rocket::Core::ReleaseCompiledGeometries();
	}
	void Core::ReleaseTextures() {
		Rocket::Core::ReleaseTextures();
	}

}