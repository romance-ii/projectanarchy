/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2014 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */
#ifndef HKANIMATION_MAPPER_HKSKELETONMAPPERDATA_H
#define HKANIMATION_MAPPER_HKSKELETONMAPPERDATA_H


extern const class hkClass hkaSkeletonMapperDataChainMappingClass;

extern const class hkClass hkaSkeletonMapperDataSimpleMappingClass;

class hkaSkeleton;

extern const hkClass hkaSkeletonMapperDataClass;

	/// hkaSkeletonMapperData is the data used at run-time by an hkaSkeletonMapper. It consists of a set of
	/// both simple (one-to-one) and chain (m-to-n) mappings.
	/// The information in this class can easily be generated by the utility class hkaSkeletonMapperUtils
class hkaSkeletonMapperData 
{
	//+version(2)
	public:

		HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR( HK_MEMORY_CLASS_ANIM_RIG, hkaSkeletonMapperData );
		HK_DECLARE_REFLECTION();

		enum MappingType
		{
				/// Ragdoll mapping
			HK_RAGDOLL_MAPPING = 0,

				/// Animation retargeting mapping
			HK_RETARGETING_MAPPING = 1
		};

			/// Defines a 1-1 mapping between a single bone of A and a single bone of B.
		struct SimpleMapping
		{
			HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR( HK_MEMORY_CLASS_ANIMATION, hkaSkeletonMapperData::SimpleMapping );
			HK_DECLARE_REFLECTION();
			HK_DECLARE_POD_TYPE();

				/// Default constructor
			SimpleMapping()
			{
				m_boneA = 0;
				m_boneB = 0;
				m_aFromBTransform.setIdentity();
			}
			
				/// The bone of A
			hkInt16 m_boneA;
			
				/// The bone of B
			hkInt16 m_boneB;
			
				/// The transformation from B to A
			hkQsTransform m_aFromBTransform;
		};
		
			/// Defines a n-to-m mapping between a chain of bones of A and a chain of bones of B.
		struct ChainMapping
		{
			HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR( HK_MEMORY_CLASS_ANIMATION, hkaSkeletonMapperData::ChainMapping );
			HK_DECLARE_REFLECTION();
			HK_DECLARE_POD_TYPE();

				/// Default constructor
			ChainMapping()
			{
				m_startBoneA = 0;
				m_endBoneA = 0;
				m_startBoneB = 0;
				m_endBoneB = 0;
				m_startAFromBTransform.setIdentity();
				m_endAFromBTransform.setIdentity();
			}
			
				/// The start bone of the chain in A
			hkInt16 m_startBoneA;
			
				/// The end bone of the chain in A
			hkInt16 m_endBoneA;
			
				/// The start bone of the chain in B
			hkInt16 m_startBoneB;
			
				/// The end bone of the chain in B
			hkInt16 m_endBoneB;
			
				/// The transformation from the start bone in B to the start bone in A
			hkQsTransform m_startAFromBTransform;
			
				/// The transformation from the end bone in B to the start bone in A
			hkQsTransform m_endAFromBTransform;
		};
		
			/// Defines mapping between the partition and simple/chain mappings
		struct PartitionMappingRange
		{
			HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR( HK_MEMORY_CLASS_ANIMATION, hkaSkeletonMapperData::PartitionMappingRange );
			HK_DECLARE_REFLECTION();
			HK_DECLARE_POD_TYPE();

				/// Start index of SimpleMapping/ChainMapping for a partition
			int m_startMappingIndex;
				
				/// The number of mappings for a partition
			int m_numMappings;
		};

			/// Default constructor
		hkaSkeletonMapperData();
		hkaSkeletonMapperData( hkFinishLoadedObjectFlag f );
		~hkaSkeletonMapperData();

		//
		// Members
		//
		
			/// The first skeleton
		hkRefPtr<const hkaSkeleton> m_skeletonA;
		
			/// The second skeleton
		hkRefPtr<const hkaSkeleton> m_skeletonB;
		
			/// The mappings between partitions in A and B
		hkArray<hkInt16> m_partitionMap;

			/// The mapping between partitions in A to simple mappings
		hkArray<struct PartitionMappingRange> m_simpleMappingPartitionRanges;

			/// The mapping between partitions in A to chain mappings
		hkArray<struct PartitionMappingRange> m_chainMappingPartitionRanges;

			/// All the simple mappings between A and B
		hkArray<struct SimpleMapping> m_simpleMappings;
		
			/// All the chain mappings between A and B
		hkArray<struct ChainMapping> m_chainMappings;
		
			/// Bones that are not driven by the input pose
		hkArray<hkInt16> m_unmappedBones;

			/// Local space mappings need extracted motion mappings
		hkQsTransform m_extractedMotionMapping;
		
			/// If true, the local pose will be kept for the unmapped bones; if false, the world
			/// pose will be kept instead
		hkBool m_keepUnmappedLocal;
		
			/// The mapper supports different kinds of mapping.
			/// Model space mapping is used for ragdolls.
			/// Local space mapping is used for animations
		hkEnum< hkaSkeletonMapperData::MappingType, hkInt32 > m_mappingType;  //+default(0)
};

#endif // HKANIMATION_MAPPER_HKSKELETONMAPPERDATA_H

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
