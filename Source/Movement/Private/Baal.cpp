// Fill out your copyright notice in the Description page of Project Settings.


#include "Baal.h"

#include "Math/Vector.h"
#include "Math/Rotator.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"

ABaal::ABaal()
{
	PrimaryActorTick.bCanEverTick = true;

	BaalMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(BaalMeshComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(BaalMeshComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void ABaal::BeginPlay()
{
	Super::BeginPlay();

	UNiagaraFunctionLibrary::SpawnSystemAttached(
		NS_Trail, //
		BaalMeshComponent, //
		SocketName, //
		FVector::ZeroVector, //
		FRotator::ZeroRotator, //
		EAttachLocation::SnapToTarget, //
		true);
}

void ABaal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaal::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ABaal::Jump);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABaal::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ABaal::MoveRight);
}

void ABaal::Jump()
{
	UE_LOG(LogTemp, Error, TEXT("Jump"));
	BaalMeshComponent->AddImpulse(FVector(0,0,100), FName("None"), false);
}

void ABaal::MoveForward(float Value)
{
    if (!FMath::IsNearlyZero(Value))
    {
    	UE_LOG(LogTemp, Warning, TEXT("%f"), Value * MovementSpeed);
    	BaalMeshComponent->AddAngularImpulseInDegrees(FVector(0,0,10000), FName("None"), false);
    }
}

void ABaal::MoveRight(float Value)
{
    if (!FMath::IsNearlyZero(Value))
    {
    	UE_LOG(LogTemp, Warning, TEXT("%f"), Value * MovementSpeed);
    	BaalMeshComponent->AddAngularImpulseInDegrees(FVector(0,10000,0), FName("None"), false);
    }
}
