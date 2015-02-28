// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently
//
// see `file_header_text.txt` for licensing & contact info.


#ifndef STDAFX_INCLUDED
#define STDAFX_INCLUDED
#else
#error ass
#endif

#pragma once

#define _HAS_EXCEPTIONS 0


#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#endif

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
//#ifndef WINVER				// Allow use of features specific to Windows 95 and Windows NT 4 or later.
//#define WINVER 0x0400		// Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
//#endif

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows NT 4 or later.
#define _WIN32_WINNT 0x0602	// Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#else
static_assert( _WIN32_WINNT >= 0x0600, "" );
//static_assert( _WIN32_WINNT >= 0x0601, "" );
//static_assert( _WIN32_WINNT >= 0x0602, "" );
#endif						

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0602
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 4.0 or later.
#define _WIN32_IE 0x0800	// Change this to the appropriate value to target IE 5.0 or later.
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#define _ATL_ALL_WARNINGS

//From helpmap.h
#define IDH_Treemap 1003

#ifdef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 
#error
#else
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#endif


#define _ATL_ENABLE_PTM_WARNING

//Things that I will eventually get rid of/add to program, but can't safely do so as of yet.

//Debugging defs
//#define DUMP_MEMUSAGE
//#define GRAPH_LAYOUT_DEBUG
//#define EXTENSION_LIST_DEBUG
//#define COLOR_DEBUGGING
//#define SIMD_ACCESS_DEBUGGING
//#define WDS_STRING_ALLOC_DEBUGGING
#define DISPLAY_FINAL_CITEMBRANCH_SIZE
//#define WDS_OWNERDRAWNLISTITEM_DESTRUCTOR_DEBUG
//#define WDS_SCOPE_GUARD_DEBUGGING

#ifndef DEBUG
#define DISPLAY_FINAL_CITEMBRANCH_SIZE
#endif

#ifdef WDS_STRING_ALLOC_DEBUGGING
#ifndef DEBUG
#error incompatible!
#endif
#endif

#ifdef GRAPH_LAYOUT_DEBUG
#ifndef DEBUG
#error incompatible!
#endif
#endif


//#pragma warning(disable:4265) //'class' : class has virtual functions, but destructor is not virtual
//#pragma warning(disable:4987) //nonstandard extension used: 'throw (...)'
//#pragma warning(disable:4548) //expression before comma has no effect; expected expression with side-effect
//#pragma warning(disable:4625) //A copy constructor was not accessible in a base class, therefore not generated for a derived class. Any attempt to copy an object of this type will cause a compiler error. warn!
//#pragma warning(disable:4626) //An assignment operator was not accessible in a base class and was therefore not generated for a derived class. Any attempt to assign objects of this type will cause a compiler error.
//#pragma warning(disable:4189) //A variable is declared and initialized but not used.
//#pragma warning(disable:4755) //Conversion rules for arithmetic operations in the comparison mean that one branch cannot be executed in an inlined function. Cast '(nBaseTypeCharLen + ...)' to 'ULONG64' (or similar type of 8 bytes).
//#pragma warning(disable:4280) //'operator �>' was self recursive through type 'type'. Your code incorrectly allows operator�> to call itself.
//#pragma warning(disable:4127) //The controlling expression of an if statement or while loop evaluates to a constant.
//#pragma warning(disable:4365) //'action' : conversion from 'type_1' to 'type_2', signed/unsigned mismatch
//#pragma warning(disable:4710) //The given function was selected for inline expansion, but the compiler did not perform the inlining.


//these are all in MFC message maps.
#pragma warning(disable:4191) //'operator/operation' : unsafe conversion from 'type of expression' to 'type required'

#ifndef DUMP_MEMUSAGE
#pragma warning(disable:4820) //'bytes' bytes padding added after construct 'member_name'. The type and order of elements caused the compiler to add padding to the end of a struct
#endif

#pragma warning(disable:4917) //'declarator' : a GUID can only be associated with a class, interface or namespace. A user-defined structure other than class, interface, or namespace cannot have a GUID.
#pragma warning(disable:4264) //'virtual_function' : no override available for virtual member function from base 'class'; function is hidden
#pragma warning(disable:4263) //A class function definition has the same name as a virtual function in a base class but not the same number or type of arguments. This effectively hides the virtual function in the base class.


//Comment this out for insanely slow compilation!
#pragma warning(disable:4514) //'function' : unreferenced inline function has been removed
#pragma warning(disable:4711) //function 'function' selected for inline expansion. The compiler performed inlining on the given function, although it was not marked for inlining.

#ifndef _DEBUG
#pragma warning(disable:4555) //expression has no effect; expected expression with side-effect //Happens alot with AfxCheckMemory in release builds.
#endif

//#pragma comment(lib, "d2d1")
//#pragma comment(lib, "Dwrite")

#pragma warning(push, 3)

#ifdef DUMP_MEMUSAGE
#pragma warning(disable:4820) //'bytes' bytes padding added after construct 'member_name'. The type and order of elements caused the compiler to add padding to the end of a struct
#endif



#pragma warning(disable:4530)//C++ exception handler used, but unwind semantics are not enabled.
#pragma warning(disable:4555) //expression has no effect; expected expression with side-effect //Happens alot in WTL.

#pragma warning(disable:4302)//'type cast' : truncation from 'LPCTSTR' to 'WORD'


//These are ALL in STL
#pragma warning(disable:4350) //An rvalue cannot be bound to a non-const reference. In previous versions of Visual C++, it was possible to bind an rvalue to a non-const reference in a direct initialization. This code now gives a warning.

#pragma warning(disable:4061) //enumerator 'identifier' in switch of enum 'enumeration' is not explicitly handled by a case label. The enumerate has no associated handler in a switch statement.
#pragma warning(disable:4062) //The enumerate has no associated handler in a switch statement, and there is no default label.




#include <afxwin.h>         // MFC Core //MUST BE INCLUDED FIRST!!!!!!!!!!!!!

// Add support for ATL/WTL
//#define _WTL_FORWARD_DECLARE_CSTRING
#define _WTL_NO_AUTOMATIC_NAMESPACE
//_ATL_NO_AUTOMATIC_NAMESPACE

#include <atlbase.h>        // base ATL classes

#ifdef _AFX
#ifndef _WTL_NO_CSTRING
#define _WTL_NO_CSTRING 1
#endif // _WTL_NO_CSTRING
#define _CSTRING_NS
#endif // _AFX

#pragma warning(disable:4265) //'class' : class has virtual functions, but destructor is not virtual
#include <atlapp.h>         // base WTL classes
extern WTL::CAppModule _Module;

#include <atlwin.h>         // ATL GUI  classes
//#include <atlframe.h>       // WTL frame window classes
//#include <atlsplit.h>
#include <atlctrls.h>

#pragma warning(disable:4640) //construction of local static object is not thread-safe	

#include <atlctrlx.h>
#include <atlmisc.h>        // ATL utility classes (i.e. CString)
#include <atlcrack.h>       // WTL message map macros
#include <atldlgs.h>
#include <atlddx.h>         //For DDX support


#pragma warning(disable:4702)//unreachable code

#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <future>
#include <map>
#include <unordered_map>
#include <numeric>
#include <cstdint>
//#include <stdexcept>
#include <type_traits>
#include <utility>
#include <atomic>
#include <tuple>
//#include <iterator>
//#include <PathCch.h>
//#pragma comment(lib, "Pathcch")

#include <afxext.h>         // MFC Extensions
#include <afxdlgs.h>
//#include <afxdtctl.h>		// MFC IE 4
#include <afxdisp.h>
#include <afxcmn.h>			// MFC Common Controls
//#include <afxtempl.h>		// MFC Container classes
//#include <afxmt.h>		// MFC Multithreading


#include <cvt/wstring>		//for wstring_convert

#include <windowsx.h>

#ifdef _DEBUG
//#define _CRTDBG_MAP_ALLOC
#endif
#include <stdlib.h>


//#define _WIN32_WINNT 0x0602	// Change this to the appropriate value to target Windows 98 and Windows 2000 or later.


#include <math.h>			// floor(), fmod(), sqrt() etc.
#include <psapi.h>			// PROCESS_MEMORY_INFO
#include <processthreadsapi.h>// SetProcessMitigationPolicy 


//#include <lmcons.h>		// UNLEN
#include <float.h>			// DBL_MAX


#include <strsafe.h>
//#include <intsafe.h>


#include <iso646.h>
#include <wctype.h>
#include <concurrent_vector.h>


#pragma warning(pop)

#pragma warning(disable:4710) //The given function was selected for inline expansion, but the compiler did not perform the inlining.

// Headers placed in the common directory (used by windirstat and by setup)
#include "../common/version.h"

#ifndef _INC_STDARG
#include <stdarg.h>
#endif


#ifndef countof
#define countof(arr) (sizeof(arr)/sizeof((arr)[0]))
#else
#error already defiend!
#endif

#define pi2 1.5707963267948966192
#define RAM_USAGE_UPDATE_INTERVAL 100
#define TREELISTCOLORCOUNT size_t( 8 )

#define PALETTE_BRIGHTNESS DOUBLE( 0.6 )
#define INDICATORS_NUMBER size_t( 2 )

#define COLORFLAG_DARKER  DWORD( 0x01000000 )
#define COLORFLAG_LIGHTER DWORD( 0x02000000 )
#define COLORFLAG_MASK    DWORD( 0x03000000 )

#define GRIPPER_RADIUS INT( 8 )

#define ITEM_ROW_HEIGHT 20
static_assert( ITEM_ROW_HEIGHT > -1, "Rows need to be a positive size!" );

//static UINT _N_ID_EXTENSION_LIST_CONTROL = 4711;
#define _N_ID_EXTENSION_LIST_CONTROL UINT( 4711 )

//const UINT CXySlider::XY_SETPOS = WM_USER + 100;
//const UINT CXySlider::XY_GETPOS = WM_USER + 101;
#define XY_SETPOS UINT( WM_USER + 100 )
#define XY_GETPOS UINT( WM_USER + 101 )

#define XYSLIDER_CHANGED 0x88 // this is a value, I hope, that is nowhere used as notification code.


#define CPageTreemap_maxHeight INT( 200 )

#ifndef WDS_WRITES_TO_STACK
#define WDS_WRITES_TO_STACK( strSize, chars_written ) _Out_writes_z_( strSize ) _Pre_writable_size_( strSize ) _Post_readable_size_( chars_written ) _Pre_satisfies_( strSize >= chars_written ) _Post_satisfies_( _Old_( chars_written ) <= chars_written )
#else
#error already defined!
#endif

#ifndef WDS_SCOPEGUARD_INSTANCE
#define WDS_SCOPEGUARD_INSTANCE( func ) scopeGuard( (func), __FILE__, __FUNCSIG__, __LINE__ )
#else
#error already defined!!
#endif

#ifndef WDS_ASSERT_NEVER_REACHED
//this line of code should NEVER be reached. ASSERT( false ) on reaching in Debug build.
#define WDS_ASSERT_NEVER_REACHED( ) ASSERT( false )
#else
#error already defined??!?
#endif

#ifndef WDS_ASSERT_EXPECTED_STRING_FORMAT_FAILURE_HRESULT

//I don't think anything in strsafe actually ever returns STRSAFE_E_END_OF_FILE,
//so I use this after I've handled the other error conditions (STRSAFE_E_INSUFFICIENT_BUFFER, STRSAFE_E_INVALID_PARAMETER),
//to catch unexpected errors. NOTE that these are still handled by the calling function via SUCCESSS( ),
//but this macro helps catch the issue closer to the function that returned the unexpected value;
#define WDS_ASSERT_EXPECTED_STRING_FORMAT_FAILURE_HRESULT( res ) {                                                \
	static_assert( SUCCEEDED( S_OK ), "This macro depends on SUCCEEDED( S_OK ) returning true" );                 \
	static_assert( std::is_same<decltype( res ), const HRESULT>::value, "This macro depends on an HRESULT res" ); \
	ASSERT( ( res ) != STRSAFE_E_END_OF_FILE );                                                                   \
	ASSERT( FAILED( res ) );                                                                                      \
	ASSERT( !SUCCEEDED( res ) );                                                                                  \
	}

#else
#error already defined!
#endif

#ifndef WDS_STRSAFE_E_INVALID_PARAMETER_HANDLER
//std::terminate( )s if ( res == STRSAFE_E_INVALID_PARAMETER ), as this is usually an issue with an incorrect compile-time constant.
//Is a macro and not an inline function because of the use of file name, function signature, and line number.
#define WDS_STRSAFE_E_INVALID_PARAMETER_HANDLER( res, strsafe_func_name )                                             \
	if ( ( res ) == STRSAFE_E_INVALID_PARAMETER ) {                                                                   \
		static_assert( std::is_same<decltype( res ), const HRESULT>::value, "This macro depends on an HRESULT res" ); \
		unexpected_strsafe_invalid_parameter_handler( ( strsafe_func_name ), __FILE__, __FUNCSIG__, __LINE__ );       \
		}
#else
#error already defined!!
#endif

#ifdef DEBUG
#define new DEBUG_NEW
#endif



#ifndef DEBUG
//#pragma warning(3:4710) //The given function was selected for inline expansion, but the compiler did not perform the inlining.
#endif

//some generic structures!
#include "datastructures.h"

//WDS headers (infrequently modified)
#include "Resource.h"



#pragma warning(3:4711)