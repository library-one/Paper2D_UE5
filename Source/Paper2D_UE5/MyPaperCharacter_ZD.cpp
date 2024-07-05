// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPaperCharacter_ZD.h"

#include "Camera/CameraComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "MyPlayerController.h"

#include "PaperFlipbookComponent.h"
#include "PaperZDAnimationComponent.h"



AMyPaperCharacter_ZD::AMyPaperCharacter_ZD()
{

    AnimationComponent = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("Animation"));

    if (AnimationComponent)
    {
        AddInstanceComponent(AnimationComponent.Get());
        AnimationComponent.Get()->RegisterComponent();
    }

    //카메라, 스프링암 컴퍼넌트를 값 세팅
    // Spring Arm Component
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 300.0f;
    SpringArm->SetRelativeRotation(FRotator(-10.0f, -90.0f, 0.0f)); //횡스크롤 화면 
    //SpringArm->SetWorldRotation(FRotator(0.0f, 0.0f, -90.0f));
    SpringArm->bDoCollisionTest = false;
    SpringArm->bInheritPitch = false;
    SpringArm->bInheritYaw = false;
    SpringArm->bInheritRoll = false;

    // Camera Component
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

    //점프관련 수치 초기화
        // Configure character movement
    GetCharacterMovement()->GravityScale = 2.0f;
    GetCharacterMovement()->AirControl = 0.80f;
    GetCharacterMovement()->JumpZVelocity = 1000.f;
    GetCharacterMovement()->GroundFriction = 3.0f;
    GetCharacterMovement()->MaxWalkSpeed = 600.0f;
    GetCharacterMovement()->MaxFlySpeed = 600.0f;


    bIsAttacking = false;
    PrimaryActorTick.bCanEverTick = true;

}


void AMyPaperCharacter_ZD::BeginPlay()
{
    Super::BeginPlay();

}



void AMyPaperCharacter_ZD::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}


void AMyPaperCharacter_ZD::Move(float Value)
{
    AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);    
    TurnRight(Value);
    //UE_LOG(LogTemp, Warning, TEXT("Move!"));
}


void AMyPaperCharacter_ZD::Walk(float Value)
{
    UE_LOG(LogTemp, Warning, TEXT("Walk!"));
}


void AMyPaperCharacter_ZD::Jump()
{
    Super::Jump();
    
    UE_LOG(LogTemp, Warning, TEXT("Jump!"));
}


void AMyPaperCharacter_ZD::StopJumping()
{
    Super::StopJumping();
    UE_LOG(LogTemp, Warning, TEXT("StopJumping!"));
}



void AMyPaperCharacter_ZD::Attack()
{
    // 공격 로직을 여기에 구현
    //if (!bIsAttacking)
    //{
    //    bIsAttacking = true;
    //    /*GetSprite()->SetFlipbook(FB_Char_Attack01);
    //    GetSprite()->SetLooping(false);
    //    GetSprite()->PlayFromStart();*/
    //}
}



void AMyPaperCharacter_ZD::TurnRight(float value)
{
    float TravelDirection = value;

    if (TravelDirection < 0.0f)
    {
        GetController()->SetControlRotation(FRotator(0.0, 180.0f, 0.0f));

        //UE_LOG(LogTemp, Warning, TEXT("SetControlRotation!"));
    }
    else if (TravelDirection > 0.0f)
    {
        GetController()->SetControlRotation(FRotator(0.0f, 0.0f, 0.0f));

        //UE_LOG(LogTemp, Warning, TEXT("SetControlRotation!"));
    }
}

