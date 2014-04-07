/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2014 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef HKB_MOVE_CHARACTER_MODIFIER_UTILS_H
#define HKB_MOVE_CHARACTER_MODIFIER_UTILS_H

class hkbMoveCharacterModifier;
class hkbGeneratorOutput;

	/// Used internally by the hkbMoveCharacterModifier.
class hkbMoveCharacterModifierUtils
{
	public:

			/// The core code for performing modify() on an hkbMoveCharacterModifier.
		static void HK_CALL modifyInternal(	hkbMoveCharacterModifier& mod, hkbGeneratorOutput& inOut, hkReal timeOffset );

};

#endif

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
