#include "ArenaTitansHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/COnstructorHelpers.h"

AArenaTitansHUD::AArenaTitansHUD()
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> PointerTexObj(TEXT("/Game/StarterContent/Textures/T_Spark_Core"));
	PointerTex = PointerTexObj.Object;
}

void AArenaTitansHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D PointerDrawPosition((Center.X),
		(Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem(PointerDrawPosition, PointerTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}
