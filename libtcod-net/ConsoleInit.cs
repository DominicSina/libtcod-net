using System;
using System.Runtime.InteropServices;

namespace libtcod
{
	public class ConsoleInit
	{

		//TODO model Context/Console struct

		[DllImport(Constants.LibraryName)]
		public extern static IntPtr TCOD_sys_get_internal_context();

		[DllImport(Constants.LibraryName)]
		public extern static IntPtr TCOD_sys_get_internal_console();
	}
}