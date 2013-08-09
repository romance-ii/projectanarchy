/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef HKVPLATFORMDEFINESDX11_H
#define HKVPLATFORMDEFINESDX11_H

  // Note that there are additional defines set in here
  #include "hkvPlatformWin32.h"

  #if defined(_WINRT)
    #define VERSION_TYPE "WINRT DIRECTX11.1"
  #elif defined (_WIN64)
    #define VERSION_TYPE "WIN64 DIRECTX11"
  #else
    #define VERSION_TYPE "WIN32 DIRECTX11"
  #endif

  #define MAX_NUM_RENDERTARGETS 8
  #define MAX_TEXTURE_UNIT_COUNT     16
  #define MAX_VS_TEXTURE_UNIT_COUNT 16
  #define MAX_UAV_COUNT              4 /*D3D11_PS_CS_UAV_REGISTER_COUNT*/
  #define SUPPORTS_MEMEXPORT_SKINNING         
  #define SUPPORTS_HARDWARESPANNING           
  #define USE_MESHBUFFER_DESC_VERTEX_SETUP
  #define SUPPORTS_VS_SAMPLERS
  #define SUPPORTS_GS_SAMPLERS
  #define SUPPORTS_CS_SAMPLERS
  #define SUPPORTS_HS_SAMPLERS
  #define SUPPORTS_DS_SAMPLERS
  #define SUPPORTS_SHADER_CONSTANT_BUFFERS
  #define SUPPORTS_GPU_RESOURCE_VIEWS
  #define SUPPORTS_GPU_DATA_UPLOAD

  #define SUPPORTS_2D_TEXTURE_ARRAYS
  #define SUPPORTS_GEOMETRY_SHADER
  #define SUPPORTS_COMPUTE_SHADER
  #define SUPPORTS_TESSELATION_SHADER
  #define SUPPORTS_SELECTIVE_BLENDING
  #define SUPPORTS_CLOUD_LAYER
  
  #define VERTEX_RGBA8_ATTRIB_SWIZZLE_MODE SWIZZLE_VERTEX_RGBA8_TO_BGRA8

  #if defined(_DEBUG) || defined(PROFILING)
    #define SET_RESOURCE_DEBUG_NAME(pRes, szName) if (pRes){const char* s=szName; (pRes)->SetPrivateData(WKPDID_D3DDebugObjectName, (UINT)strlen(s), s ); }
  #endif

  #define Direct3D     void
  
#ifndef _VISION_WINRT
  #define D3DDevice ID3D11Device
  #define D3DDeviceContext ID3D11DeviceContext
  #define D3DSwapChain IDXGISwapChain
  #define D3DSwapChainDesc DXGI_SWAP_CHAIN_DESC
#else
  #define D3DDevice ID3D11Device1
  #define D3DDeviceContext ID3D11DeviceContext1
  #define D3DSwapChain IDXGISwapChain1
  #define D3DSwapChainDesc DXGI_SWAP_CHAIN_DESC1

  typedef DWORD D3DCOLOR;
#endif

  #define D3DResource  ID3D11Resource
  #define D3DShaderResourceView ID3D11ShaderResourceView
  #define D3DUnorderedAccessView ID3D11UnorderedAccessView
  #define D3DTexture1D ID3D11Texture1D
  #define D3DTexture2D ID3D11Texture2D
  #define D3DTexture3D ID3D11Texture3D
  #define D3DPixelShader ID3D11PixelShader
  #define D3DVertexShader ID3D11VertexShader
  #define D3DGeometryShader ID3D11GeometryShader
  #define D3DHullShader ID3D11HullShader
  #define D3DDomainShader ID3D11DomainShader
  #define D3DComputeShader ID3D11ComputeShader
  #define D3DBlendState ID3D11BlendState
  #define D3DRasterizerState ID3D11RasterizerState
  #define D3DSamplerState ID3D11SamplerState
  #define D3DDepthStencilState ID3D11DepthStencilState
  #define D3DBuffer ID3D11Buffer
  #define D3DView ID3D11View
  #define D3DInputLayout ID3D11InputLayout
  #define D3DQuery ID3D11Query
  #define D3DRenderTargetView ID3D11RenderTargetView
  #define D3DDepthStencilView ID3D11DepthStencilView
  #define D3DVertexBuffer ID3D11Buffer
  #define D3DIndexBuffer ID3D11Buffer

  #define D3D_BLEND_DESC D3D11_BLEND_DESC
  #define D3D_BLEND D3D11_BLEND
  #define D3D_BLEND_OP D3D11_BLEND_OP

  #define D3D_DEPTH_STENCIL_DESC D3D11_DEPTH_STENCIL_DESC
  #define D3D_STENCIL_OP D3D11_STENCIL_OP
  #define D3D_COMPARISON_FUNC D3D11_COMPARISON_FUNC

  #define D3D_RASTERIZER_DESC D3D11_RASTERIZER_DESC 
  #define D3D_FILL_MODE D3D11_FILL_MODE
  #define D3D_CULL_MODE D3D11_CULL_MODE

  #define D3D_SAMPLER_DESC D3D11_SAMPLER_DESC
  #define D3D_FILTER D3D11_FILTER
  #define D3D_TEXTURE_ADDRESS_MODE D3D11_TEXTURE_ADDRESS_MODE

  #define D3D_PRIMITIVE_TOPOLOGY            D3D11_PRIMITIVE_TOPOLOGY
  #define D3D_PRIMITIVE_TOPOLOGY_UNDEFINED  D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED
  #define D3D_PRIMITIVE_TOPOLOGY_POINTLIST  D3D11_PRIMITIVE_TOPOLOGY_POINTLIST
  #define D3D_PRIMITIVE_TOPOLOGY_LINELIST   D3D11_PRIMITIVE_TOPOLOGY_LINELIST
  #define D3D_PRIMITIVE_TOPOLOGY_LINESTRIP  D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP
  #define D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST   D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST
  #define D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP  D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP
  #define D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ   D3D11_PRIMITIVE_TOPOLOGY_LINELIST_ADJ
  #define D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ  D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ
  #define D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ   D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ
  #define D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ  D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ
  
  #define D3D_INPUT_ELEMENT_DESC            D3D11_INPUT_ELEMENT_DESC
  #define D3D_INPUT_PER_VERTEX_DATA         D3D11_INPUT_PER_VERTEX_DATA
  #define D3D_INPUT_PER_INSTANCE_DATA       D3D11_INPUT_PER_INSTANCE_DATA

  #define D3D_CLEAR_DEPTH     D3D11_CLEAR_DEPTH
  #define D3D_CLEAR_STENCIL   D3D11_CLEAR_STENCIL

  #define D3D_VIEWPORT        D3D11_VIEWPORT
  #define D3D_RECT            D3D11_RECT

  #define D3D_CPU_ACCESS_WRITE    D3D11_CPU_ACCESS_WRITE
  #define D3D_CPU_ACCESS_READ     D3D11_CPU_ACCESS_READ

  #define D3D_BUFFER_DESC       D3D11_BUFFER_DESC
  #define D3D_SUBRESOURCE_DATA  D3D11_SUBRESOURCE_DATA

  #define D3D_BIND_VERTEX_BUFFER    D3D11_BIND_VERTEX_BUFFER
  #define D3D_BIND_INDEX_BUFFER     D3D11_BIND_INDEX_BUFFER
  #define D3D_BIND_CONSTANT_BUFFER  D3D11_BIND_CONSTANT_BUFFER
  #define D3D_BIND_SHADER_RESOURCE  D3D11_BIND_SHADER_RESOURCE
  #define D3D_BIND_STREAM_OUTPUT    D3D11_BIND_STREAM_OUTPUT
  #define D3D_BIND_RENDER_TARGET    D3D11_BIND_RENDER_TARGET
  #define D3D_BIND_DEPTH_STENCIL    D3D11_BIND_DEPTH_STENCIL
  #define D3D_BIND_UNORDERED_ACCESS D3D11_BIND_UNORDERED_ACCESS

  #define D3D_MAP         D3D11_MAP
  #define D3D_MAP_READ    D3D11_MAP_READ
  #define D3D_MAP_WRITE   D3D11_MAP_WRITE
  #define D3D_MAP_READ_WRITE    D3D11_MAP_READ_WRITE
  #define D3D_MAP_WRITE_DISCARD D3D11_MAP_WRITE_DISCARD
  #define D3D_MAP_WRITE_NO_OVERWRITE D3D11_MAP_WRITE_NO_OVERWRITE

  #define D3D_USAGE     D3D11_USAGE
  #define D3D_BOX       D3D11_BOX

  #define D3D_TEXTURE2D_DESC          D3D11_TEXTURE2D_DESC
  #define D3D_TEXTURE3D_DESC          D3D11_TEXTURE3D_DESC
  #define D3D_BIND_SHADER_RESOURCE    D3D11_BIND_SHADER_RESOURCE
  #define D3D_BIND_RENDER_TARGET      D3D11_BIND_RENDER_TARGET
  #define D3D_BIND_DEPTH_STENCIL      D3D11_BIND_DEPTH_STENCIL
  #define D3D_RESOURCE_MISC_GENERATE_MIPS     D3D11_RESOURCE_MISC_GENERATE_MIPS
  #define D3D_RESOURCE_MISC_TEXTURECUBE       D3D11_RESOURCE_MISC_TEXTURECUBE
  #define D3D_RENDER_TARGET_VIEW_DESC         D3D11_RENDER_TARGET_VIEW_DESC
  #define D3D_DEPTH_STENCIL_VIEW_DESC         D3D11_DEPTH_STENCIL_VIEW_DESC
  #define D3D_SHADER_RESOURCE_VIEW_DESC       D3D11_SHADER_RESOURCE_VIEW_DESC
  #define D3D_UNORDERED_ACCESS_VIEW_DESC      D3D11_UNORDERED_ACCESS_VIEW_DESC
  #define D3D_RTV_DIMENSION_TEXTURE2DARRAY    D3D11_RTV_DIMENSION_TEXTURE2DARRAY
  #define D3D_RTV_DIMENSION_TEXTURE2D         D3D11_RTV_DIMENSION_TEXTURE2D
  #define D3D_RTV_DIMENSION_TEXTURE3D         D3D11_RTV_DIMENSION_TEXTURE2DARRAY
  #define D3D_RTV_DIMENSION_TEXTURE2DMS       D3D11_RTV_DIMENSION_TEXTURE2DMS
  #define D3D_RTV_DIMENSION_TEXTURE2DMSARRAY  D3D11_RTV_DIMENSION_TEXTURE2DMSARRAY
  #define D3D_DSV_DIMENSION_TEXTURE2DARRAY    D3D11_DSV_DIMENSION_TEXTURE2DARRAY
  #define D3D_DSV_DIMENSION_TEXTURE2D         D3D11_DSV_DIMENSION_TEXTURE2D
  #define D3D_DSV_DIMENSION_TEXTURE2DMS       D3D11_DSV_DIMENSION_TEXTURE2DMS
  #define D3D_DSV_DIMENSION_TEXTURE2DMSARRAY  D3D11_DSV_DIMENSION_TEXTURE2DMSARRAY

  #define D3D_QUERY_DESC        D3D11_QUERY_DESC
  #define D3D_QUERY_EVENT       D3D11_QUERY_EVENT
  #define D3D_QUERY_OCCLUSION   D3D11_QUERY_OCCLUSION
  #define D3D_QUERY_TIMESTAMP   D3D11_QUERY_TIMESTAMP
  #define D3D_QUERY_TIMESTAMP_DISJOINT      D3D11_QUERY_TIMESTAMP_DISJOINT
  #define D3D_QUERY_PIPELINE_STATISTICS     D3D11_QUERY_PIPELINE_STATISTICS
  #define D3D_QUERY_OCCLUSION_PREDICATE     D3D11_QUERY_OCCLUSION_PREDICATE
  #define D3D_QUERY_SO_STATISTICS           D3D11_QUERY_SO_STATISTICS
  #define D3D_QUERY_SO_OVERFLOW_PREDICATE   D3D11_QUERY_SO_OVERFLOW_PREDICATE

  #define D3D_USAGE_DYNAMIC         D3D11_USAGE_DYNAMIC
  #define D3D_USAGE_DEFAULT         D3D11_USAGE_DEFAULT
  #define D3D_USAGE_IMMUTABLE       D3D11_USAGE_IMMUTABLE
  #define D3D_USAGE_STAGING         D3D11_USAGE_STAGING

  #define D3D_SO_DECLARATION_ENTRY  D3D11_SO_DECLARATION_ENTRY

  #define D3DCounter ID3D11Counter

  #define D3D_INCLUDE_TYPE          D3D10_INCLUDE_TYPE
  #define D3D_INCLUDE_LOCAL         D3D10_INCLUDE_LOCAL
  #define D3D_INCLUDE_SYSTEM        D3D10_INCLUDE_SYSTEM

  #define D3D_CREATE_DEVICE_DEBUG   D3D11_CREATE_DEVICE_DEBUG

  #define D3DCalcSubresource    D3D11CalcSubresource

  #define D3D_SHADER_TYPE_DESC  D3D11_SHADER_TYPE_DESC
  #define D3D_SVT_BOOL  D3D11_SVT_BOOL
  #define D3D_SVC_SCALAR  D3D11_SVC_SCALAR
  #define D3D_SVC_VECTOR  D3D11_SVC_VECTOR
  #define D3D_SVC_MATRIX_ROWS  D3D11_SVC_MATRIX_ROWS
  #define D3D_SVC_MATRIX_COLUMNS  D3D11_SVC_MATRIX_COLUMNS
  #define D3D_SVT_INT  D3D11_SVT_INT
  #define D3D_SVT_FLOAT  D3D11_SVT_FLOAT
  #define D3D_SVT_STRING  D3D11_SVT_STRING
  #define D3D_SVT_SAMPLER  D3D11_SVT_SAMPLER
  #define D3D_SVT_TEXTURE  D3D11_SVT_TEXTURE
  #define D3D_SVT_TEXTURE1D  D3D11_SVT_TEXTURE1D
  #define D3D_SVT_TEXTURE2D  D3D11_SVT_TEXTURE2D
  #define D3D_SVT_TEXTURE1DARRAY  D3D11_SVT_TEXTURE1DARRAY
  #define D3D_SVT_TEXTURE2DARRAY  D3D11_SVT_TEXTURE2DARRAY
  #define D3D_SVT_TEXTURE3D  D3D11_SVT_TEXTURE3D
  #define D3D_SVT_TEXTURECUBE  D3D11_SVT_TEXTURECUBE

  #define D3D_SRV_DIMENSION D3D11_SRV_DIMENSION
  #define D3D_SRV_DIMENSION_BUFFER       D3D11_SRV_DIMENSION_BUFFER
  #define D3D_SRV_DIMENSION_TEXTURE1D       D3D11_SRV_DIMENSION_TEXTURE1D
  #define D3D_SRV_DIMENSION_TEXTURE2D       D3D11_SRV_DIMENSION_TEXTURE2D
  #define D3D_SRV_DIMENSION_TEXTURE2DMS       D3D11_SRV_DIMENSION_TEXTURE2DMS
  #define D3D_SRV_DIMENSION_TEXTURE1DARRAY       D3D11_SRV_DIMENSION_TEXTURE1DARRAY
  #define D3D_SRV_DIMENSION_TEXTURE2DARRAY       D3D11_SRV_DIMENSION_TEXTURE2DARRAY
  #define D3D_SRV_DIMENSION_TEXTURE2DMSARRAY       D3D11_SRV_DIMENSION_TEXTURE2DMSARRAY
  #define D3D_SRV_DIMENSION_TEXTURE3D       D3D11_SRV_DIMENSION_TEXTURE3D
  #define D3D_SRV_DIMENSION_TEXTURECUBE       D3D11_SRV_DIMENSION_TEXTURECUBE

  #define D3D_UAV_DIMENSION D3D11_UAV_DIMENSION
  #define D3D_UAV_DIMENSION_BUFFER       D3D11_UAV_DIMENSION_BUFFER
  #define D3D_UAV_DIMENSION_TEXTURE1D       D3D11_UAV_DIMENSION_TEXTURE1D
  #define D3D_UAV_DIMENSION_TEXTURE2D       D3D11_UAV_DIMENSION_TEXTURE2D
  #define D3D_UAV_DIMENSION_TEXTURE2DMS       D3D11_UAV_DIMENSION_TEXTURE2DMS
  #define D3D_UAV_DIMENSION_TEXTURE1DARRAY       D3D11_UAV_DIMENSION_TEXTURE1DARRAY
  #define D3D_UAV_DIMENSION_TEXTURE2DARRAY       D3D11_UAV_DIMENSION_TEXTURE2DARRAY
  #define D3D_UAV_DIMENSION_TEXTURE2DMSARRAY       D3D11_UAV_DIMENSION_TEXTURE2DMSARRAY
  #define D3D_UAV_DIMENSION_TEXTURE3D       D3D11_UAV_DIMENSION_TEXTURE3D
  #define D3D_UAV_DIMENSION_TEXTURECUBE       D3D11_UAV_DIMENSION_TEXTURECUBE

  #define D3D_DEPTH_WRITE_MASK_ALL  D3D11_DEPTH_WRITE_MASK_ALL
  #define D3D_DEPTH_WRITE_MASK_ZERO  D3D11_DEPTH_WRITE_MASK_ZERO

  #define D3D_MAPPED_TEXTURE2D  D3D11_MAPPED_SUBRESOURCE
  #define D3D_MAPPED_TEXTURE3D  D3D11_MAPPED_SUBRESOURCE
  #define D3D_SIGNATURE_PARAMETER_DESC D3D11_SIGNATURE_PARAMETER_DESC


  #define V_DEVICE_MAX_TEXTURE_SIZE 16384


#endif // HKVPLATFORMDEFINESDX11_H

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
