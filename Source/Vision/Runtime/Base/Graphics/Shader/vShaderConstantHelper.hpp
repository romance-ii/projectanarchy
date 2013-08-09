/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

/// \file vShaderConstantHelper.hpp

#ifndef VSHADERCONSTANTHELPER_HPP_INCLUDED
#define VSHADERCONSTANTHELPER_HPP_INCLUDED

/// \brief 
///   converts a pass type into a string representation
///
/// \param ePassType
///   The pass type to convert
VBASE_IMPEXP const char * VPassTypeToString(VPassType_e ePassType);

/// \brief
///  Maps the pre-2013.1 PassType to the 2013.1 PassType
VBASE_IMPEXP VPassType_e MapOldToNewPassType(VPassType_e ePassType);

#endif

/*
 * Havok SDK - Base file, BUILD(#20130723)
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
