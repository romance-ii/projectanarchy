/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2014 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef HKCD_CONVEX_CELLS_TREE_2D_H
#define HKCD_CONVEX_CELLS_TREE_2D_H

#include <Geometry/Collide/DataStructures/Planar/ConvexCellsTree/hkcdConvexCellsTree.h>

/// A binary tree of convex polygons. The root node is generally
/// a rectangle (typically initialized to an AABB larger than the object). Child cells are generated by cutting parent cells with a plane.
class hkcdConvexCellsTree2D : public hkcdConvexCellsTree<hkcdPlanarEntity::Polygon, hkcdPlanarEntity::PolygonId, hkcdPlanarGeometry>
{
	public:

		HK_DECLARE_CLASS_ALLOCATOR(HK_MEMORY_CLASS_GEOMETRY);

		// Types
		typedef PolygonId	CellId;

	public:

		/// Constructor
		hkcdConvexCellsTree2D(hkcdPlanarGeometry* geom, PlaneId supportPlaneId);

	public:

		/// Creates a box cell that encloses the entire "known" space
		CellId createBoundaryCell();

		/// Build a convex cell tree out of a solid bsp  tree
		void buildFromSolid(hkcdPlanarSolid* planes);

		/// Split a cell returning inside and outside polys ids
		HK_FORCE_INLINE void splitCell(hkcdPlanarSolid* solid, CellId cellId, PlaneId splitPlaneId, CellId& insideCellIdOut, CellId& outsideCellIdOut);

		/// Gets / sets the support plane
		HK_FORCE_INLINE PlaneId getSupportPlaneId() const;
		HK_FORCE_INLINE void setSupportPlaneId(PlaneId supportId);

	protected:

		PlaneId m_supportPlaneId;	///< The support plane
};

#include <Geometry/Collide/DataStructures/Planar/ConvexCellsTree/hkcdConvexCellsTree2D.inl>

#endif	// HKCD_CONVEX_CELLS_TREE_2D_H

/*
 * Havok SDK - Base file, BUILD(#20140327)
 * 
 * Confidential Information of Havok.  (C) Copyright 1999-2014
 * Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
 * Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
 * rights, and intellectual property rights in the Havok software remain in
 * Havok and/or its suppliers.
 * 
 * Use of this software for evaluation purposes is subject to and indicates
 * acceptance of the End User licence Agreement for this product. A copy of
 * the license is included with this software and is also available from salesteam@havok.com.
 * 
 */
