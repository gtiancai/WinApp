// ATLProj-app.cpp : Implementation of WinMain


#include "stdafx.h"
#include "resource.h"
#include "ATLProjapp_i.h"


using namespace ATL;


class CATLProjappModule : public ATL::CAtlExeModuleT< CATLProjappModule >
{
public :
	DECLARE_LIBID(LIBID_ATLProjappLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLPROJAPP, "{C1B89204-C5A6-4861-BC1B-D9C245D9D1A8}")
	};

CATLProjappModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

