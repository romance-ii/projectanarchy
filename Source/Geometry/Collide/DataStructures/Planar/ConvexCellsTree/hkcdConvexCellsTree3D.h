/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef HKCD_CONVEX_CELLS_TREE_3D_H
#define HKCD_CONVEX_CELLS_TREE_3D_H

#include <Geometry/Collide/DataStructures/Planar/ConvexCellsTree/hkcdConvexCellsTree.h>

/// A binary tree of convex cells. The root node is generally
/// a box (typically initialized to an AABB larger than the object). Child cells are generated by cutting parent cells with a plane.
class hkcdConvexCellsTree3D : public hkcdConvexCellsTree<hkcdConvexCellsCollection::Cell, hkcdConvexCellsCollection::CellId, hkcdConvexCellsCollection>
{
	public:

		HK_DECLARE_CLASS_ALLOCATOR(HK_MEMORY_CLASS_GEOMETRY);

		// Types
		typedef hkcdConvexCellsCollection::Labels		CellLabel;

	public:

		/// Types of surfaces used to infer cell labels
		enum PolygonSurfaceType
		{
			POLY_SURFACE_OPEN			= 0,
			POLY_SURFACE_DIRECT			= 0x01,
			POLY_SURFACE_INDIRECT		= 0x02,
			POLY_SURFACE_WATERTIGHT		= POLY_SURFACE_DIRECT | POLY_SURFACE_INDIRECT,			
			POLY_SURFACE_INVALID		= 0x04,

			POLY_VISITED_FLAG			= 0x10,
		};

	public:

		/// Constructor for compatibility with previous approach using geom
		hkcdConvexCellsTree3D(hkcdPlanarGeometry* geom, bool withConnectivity = false);

		/// Constructor from data pointers (connectivity and boundary polys will be copied from the other)
		hkcdConvexCellsTree3D(hkcdConvexCellsCollection* cells, hkcdPlanarGeometry* geom, const hkcdConvexCellsTree3D& other);

		/// Copy constructor. The geometry will not be shared!
		hkcdConvexCellsTree3D(const hkcdConvexCellsTree3D& other);

		/// Destructor
		virtual ~hkcdConvexCellsTree3D();

	public:

		/// Build a convex cell tree out of a solid bsp  tree
		void buildFromSolid(hkcdPlanarSolid* planes);

		/// Splits the given cell by the given plane. Updates all adjacency information
		void splitCell(hkcdPlanarSolid* solid, CellId cellId, PlaneId splitPlaneId, CellId& insideCellIdOut, CellId& outsideCellIdOut);

		/// Creates a box cell that encloses the entire "known" space
		CellId createBoundaryCell();

		/// Collects all the leaf cells
		void collectLeafCells(hkArray<CellId>& cellIdsOut) const;

		/// Collects all the cells marked as solid
		void collectSolidCells(hkArray<CellId>& cellIdsOut) const;

		/// Converts the given cell to geometry
		void extractCellGeometry(CellId cellId, hkGeometry& cellGeomOut) const;

		/// Converts the boundary connections to geometry
		void debugPrint() const;

		/// Computes the approximate position of the vertices of the given convex cell (floating point precision)
		void computeCellVertices(CellId cellId, hkArray<hkVector4>& verticesPos, bool useFastConversion = false) const;

		/// Removes all cells not marked as cellLabel
		void removeCellsOfType(CellLabel cellLabel);

		/// Extracts a solid planar geometry from a subset of selected cells
		hkcdPlanarSolid* buildSolidFromSubsetOfCells(const hkArray<CellId>& cellIdsIn);

		/// Compute and creates boundary polygons for a given set of cells. Requires connectivity
		void extractBoundaryPolygonsFromCellIds(const hkArray<CellId>& cellIdsIn, hkcdPlanarGeometry& geomOut, hkArray<PolygonId>& boundaryPolygonIdsOut);

		/// Returns a list of unique polygon ids from a set of cells
		void getUniquePolygonIdsFromCellIds(const hkArray<CellId>& cellIdsIn, hkArray<PolygonId>& polygonIdsOut);

		/// Returns a set of cell ids representing disconnected islands of solid regions
		void computeSolidRegionIslands(hkArray< hkArray<CellId> >& islands);

		/// Updates the state of each cell by copying the label of the node of the provided solid planar geometry
		void relabelCellsFromSolid(const hkcdPlanarSolid* solid);

		/// Re-assigns the labels of a bsp tree using the label store in the convex cell tree
		void reassignSolidGeomLabels(const hkcdPlanarGeometry& originalGeom, hkcdPlanarSolid* solid, const hkArray<PolygonId>& originalBoundaryPolygonIds, hkcdPlanarEntityDebugger* debugger = HK_NULL);

		/// Collects all the plane Ids used by the convex cells
		void collectUsedPlaneIds(hkBitField& usedPlaneIdsOut, bool resetBitField) const;

		/// Enables / disables the collection of connectivity information during the building of the tree.
		HK_FORCE_INLINE void enableConnectivityCollection(bool doEnable);

		/// Returns whether the tree has been built with connectivity information.
		HK_FORCE_INLINE bool hasManifoldCells() const;

		/// Returns the cell with the given Id
		HK_FORCE_INLINE const Cell& getCell(CellId cellId) const;
		HK_FORCE_INLINE Cell& accessCell(CellId cellId);

		/// Computes the number of boundary planes
		HK_FORCE_INLINE int getNumBoundaryPlanes(CellId cellId) const;

		/// Creates a polygon for the given splitting plane
		HK_FORCE_INLINE void createSplittingPolygon(PlaneId splitPlaneId, PlaneId* boundsOut) const;

	protected:

		/// Adds a closing polygon cap created from the given splitting plane
		HK_FORCE_INLINE PolygonId addClosingCap(const PlaneId* cellPlaneIds, int numPlanes, PlaneId splitPlaneId);

		/// Check if the direction cell to polygon is valid
		HK_FORCE_INLINE bool canGoFromCellThroughPoly(CellId fromCellId, PolygonId throughPolygonId, bool fromOutside);

		/// Infers in/out labels by flood filling thanks to the boundary properties computed on each polygon of each cell
		void inferCellsLabels(hkcdPlanarEntityDebugger* debugger = HK_NULL);

		/// From a set of polygons of the original geometry, mark all the boundary of all the cells with an intersection test
		void markBoundaryCells(const hkcdPlanarGeometry& originalGeom, const hkArray<PolygonId>& originalBoundaryPolygonIds, hkcdPlanarEntityDebugger* debugger = HK_NULL);

		/// Updates the connectivity information for a given polygon after a split
		void updateConnectivity(hkcdPlanarSolid* solid, CellId cellId, PolygonId splitPolygonId, PolygonId insidePolyId, PolygonId outsidePolyId, PlaneId splitPlaneId);

		/// Finds an empty cell
		CellId findOutputCell();

	protected:

		/// Bounding polygons
		PolygonId m_boundingPolys[PlanesCollection::NUM_BOUNDS];

		/// Whether the tree is kept manifold and conectivity computed between cells
		bool m_buildCellConnectivity;
};

#include <Geometry/Collide/DataStructures/Planar/ConvexCellsTree/hkcdConvexCellsTree3D.inl>

#endif	// HKCD_CONVEX_CELLS_TREE_3D_H

/*
 * Havok SDK - Base file, BUILD(#20131019)
 * 
 * Confidential Information of Havok.  (C) Copyright 1999-2013
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
