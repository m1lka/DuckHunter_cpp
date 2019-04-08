#ifndef _RENDEREGION_HPP_
#define _RENDEREGION_HPP_

struct t_RenderRegion
{
	int Width;
	int Height;
	
	t_RenderRegion(int width, int height):
		Width(width),
		Height(height) {}
};

using RenderRegion = struct t_RenderRegion;

#endif // _RENDEREGION_HPP_
