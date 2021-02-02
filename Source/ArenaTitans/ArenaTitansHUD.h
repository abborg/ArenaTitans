#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ArenaTitansHUD.generated.h"

UCLASS()
class AArenaTitansHUD : public AHUD
{
	GENERATED_BODY()

public:
	AArenaTitansHUD();

	virtual void DrawHUD() override;

private:
	class UTexture2D* PointerTex;
};