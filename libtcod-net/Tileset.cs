using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace libtcod
{
    public class Tileset
    {
        //struct TCOD_Tileset
        //{
        //    int tile_width;
        //    int tile_height;
        //    int tile_length;
        //    int tiles_capacity;
        //    int tiles_count;
        //    IntPtr pixels;
        //    int character_map_length;
        //    int* __restrict character_map;
        //    IntPtr observer_list;
        //    int virtual_columns;
        //    volatile int ref_count;
        //};


        //TCOD_Tileset* TCOD_tileset_load(
        //    const char* filename, int columns, int rows, int n, const int* __restrict charmap);
        [DllImport(Constants.LibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr TCOD_tileset_load(
            [MarshalAs(UnmanagedType.LPStr)] string filename, 
            int columns, 
            int rows, 
            int n,
            [In, Out] int[] charmap);


        //TCODLIB_CAPI void TCOD_set_default_tileset(TCOD_Tileset* tileset);
        [DllImport(Constants.LibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void TCOD_set_default_tileset(IntPtr tileset);
    }
}
