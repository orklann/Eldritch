#include "core.h"
#include "sdpeldworld.h"
#include "irenderer.h"
#include "mesh.h"
#include "view.h"
#include "eldritchframework.h"
#include "eldritchgame.h"
#include "vector4.h"

SDPEldWorld::SDPEldWorld()
{
}

SDPEldWorld::~SDPEldWorld()
{
}

/*virtual*/ void SDPEldWorld::SetShaderParameters( IRenderer* const pRenderer, Mesh* const pMesh, const View& View ) const
{
	SDPBase::SetShaderParameters( pRenderer, pMesh, View );

	EldritchFramework* const	pFramework		= EldritchFramework::GetInstance();
	EldritchGame* const			pGame			= pFramework->GetGame();
	const Vector4				FogParams		= pGame->GetFogParams();
	const Vector4				FogPosition		= View.m_Location;

	STATIC_HASHED_STRING( FogParams );
	pRenderer->SetPixelShaderFloat4( sFogParams,		FogParams.GetArray(),	1 );

	STATIC_HASHED_STRING( FogViewPosition );
	pRenderer->SetPixelShaderFloat4( sFogViewPosition,	FogPosition.GetArray(),	1 );
}