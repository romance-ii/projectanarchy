/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

inline const hkVector4& hkContactPoint::getPosition() const
{ 
	return m_position; 
}

inline const hkVector4& hkContactPoint::getNormal() const
{ 
	return m_separatingNormal; 
}

inline hkVector4& hkContactPoint::getPosition()
{ 
	return m_position; 
}

inline void hkContactPoint::setPosition( const hkVector4& position )
{	
	m_position = position; 
}


inline const hkVector4& hkContactPoint::getSeparatingNormal() const
{ 
	return m_separatingNormal; 
}

inline hkVector4& hkContactPoint::getSeparatingNormal()
{ 
	return m_separatingNormal; 
}


inline void hkContactPoint::setSeparatingNormal( const hkVector4& normal, hkReal dist )
{
	m_separatingNormal = normal;
	m_separatingNormal(3) = dist;
}

inline void hkContactPoint::setSeparatingNormal( hkVector4Parameter normal, hkSimdRealParameter dist )
{
	m_separatingNormal.setXYZ_W(normal,dist);
}

inline void hkContactPoint::setSeparatingNormal( const hkVector4& separatingNormal )
{
	m_separatingNormal = separatingNormal;
}


inline hkReal hkContactPoint::getDistance() const
{
	return m_separatingNormal(3); 
}

inline hkSimdReal hkContactPoint::getDistanceSimdReal() const
{
	return m_separatingNormal.getComponent<3>(); 
}

inline void hkContactPoint::setDistance( hkReal d )
{ 
	m_separatingNormal(3) = d; 
}

//
//	Set the distance

inline void hkContactPoint::setDistanceSimdReal(hkSimdRealParameter newValue)
{
	m_separatingNormal.setW(newValue);
}

inline void hkContactPoint::set( const hkVector4& position, const hkVector4& normal, hkReal dist )
{ 
	m_position = position; 
	m_separatingNormal = normal;
	m_separatingNormal(3) = dist; 
}

//
//	Set the position, normal and distance

inline void hkContactPoint::setPositionNormalAndDistance(hkVector4Parameter position, hkVector4Parameter normal, hkSimdRealParameter dist)
{
	m_position = position; 
	m_separatingNormal.setXYZ_W(normal, dist);
}

inline void hkContactPoint::setNormalOnly( const hkVector4& normal )
{ 
	m_separatingNormal.setXYZ( normal );
}

inline void hkContactPoint::setFlipped( const hkContactPoint& point )
{
	hkVector4 dist; dist.setBroadcast<3>( point.m_separatingNormal ); 
	m_position.setAddMul( point.m_position, point.m_separatingNormal, dist );
	m_separatingNormal.setNeg<3>( point.m_separatingNormal );
}

inline void hkContactPoint::flip()
{
	setFlipped(*this);
}

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
