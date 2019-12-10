// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Cubemon.h"
#include "UnrealExercisesCharacter.h"
#include "EnnemyHp.generated.h"

/**
 * 
 */
UCLASS()
class UNREALEXERCISES_API UEnnemyHp : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadWrite)
		ACubemon* Cubemon;
	
	UPROPERTY(BlueprintReadWrite)
		AUnrealExercisesCharacter* Player;
};
