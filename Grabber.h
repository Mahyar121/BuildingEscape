// Mahyar Babaie

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	// Find (assumed) attached physics handle
	void FindPhysicsHandleComponent();
	// Setup (assumed) attached input component
	void SetupInputComponent();
	// Ray-cast and grab what's in reach
	void Grab();
	// Called when grab is released
	void Release();
	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
	// Returns FVector variable for the line start
	FVector GetReachLineStart();
	// Returns FVector variable for the line end
	FVector GetReachLineEnd();

private:
	// How far ahead of the player can we reach in cm
	float Reach = 100.f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	
		
	
};
