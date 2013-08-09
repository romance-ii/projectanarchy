/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef HK_VISION_MESH_INDEX_BUFFER_H
#define HK_VISION_MESH_INDEX_BUFFER_H

#include <Common/GeometryUtilities/Mesh/hkMeshVertexBuffer.h>

	/// Index buffer wrapper around Trinigy VisMeshBuffer_cl objects
class hkVisionMeshIndexBuffer : public hkReferencedObject
{
	public:

		HK_DECLARE_CLASS_ALLOCATOR(HK_MEMORY_CLASS_SCENE_DATA);

	public:

			/// Constructor
		hkVisionMeshIndexBuffer(class VGScene* visionScene, int meshIndex);

			/// Locks the index buffer (READ_ONLY)
		void* lock();

			/// Unlocks the index buffer
		void unlock();

		int getNumIndices( int sectionIndex );

	protected:

			/// Vision scene
		class VGScene* m_visionScene;

		hkArray<hkUint32> m_indices;

			/// Pointer to the locked index buffer if any
		hkUint8* m_indexBufferPtr;

			/// Mesh index
		int m_meshIndex;

			/// Lock count
		int m_numLocks;
};

#endif	//	HK_VISION_MESH_INDEX_BUFFER_H

/*
 * Havok SDK - Base file, BUILD(#20130717)
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
