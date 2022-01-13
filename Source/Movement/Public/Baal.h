// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Baal.generated.h"

class UNiagaraSystem;
class UNiagaraComponent;

UCLASS()
class MOVEMENT_API ABaal : public APawn
{
	GENERATED_BODY()

public:
	ABaal();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Trail")
	UNiagaraSystem* NS_Trail;

	UPROPERTY(EditAnywhere, Category = "Trail")
	FName SocketName = FName("TrailStart");
	
	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* BaalMeshComponent;

	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* CameraComponent;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed = 500.0f;
	
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Jump();

public:
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
