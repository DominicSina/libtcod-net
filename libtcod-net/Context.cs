using System;
using System.Runtime.InteropServices;

namespace libtcod
{
	public class Context
	{
		// TODO should return TCOD_ERROR
		[DllImport(Constants.LibraryName)]
		public extern static IntPtr TCOD_context_present(IntPtr context, IntPtr console, IntPtr viewport);
		 
	}
}