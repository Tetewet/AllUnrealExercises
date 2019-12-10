// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HPPlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALEXERCISES_API UHPPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly)
		class AUnrealExercisesCharacter* Player;
};
