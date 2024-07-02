
// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPaperCharacter.h"


#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"

#include "PaperFlipbookComponent.h"
#include "PaperZDAnimationComponent.h"

#include "MyPlayerController.h"



AMyPaperCharacter::AMyPaperCharacter()
{

    AnimationComponent = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("Animation"));

    if (AnimationComponent)
    {
        AddInstanceComponent(AnimationComponent.Get());
        AnimationComponent.Get()->RegisterComponent();
    }

    //AnimationComponent = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("Animation"));
    //AnimationComponent->InitRenderComponent(GetSprite());


	
    //ī�޶�, �������� ���۳�Ʈ�� �� ����
    // Spring Arm Component
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 300.0f;
    SpringArm->SetRelativeRotation(FRotator(-10.0f, -90.0f, 0.0f)); //Ⱦ��ũ�� ȭ�� 
    //SpringArm->SetWorldRotation(FRotator(0.0f, 0.0f, -90.0f));
    SpringArm->bDoCollisionTest = false;
    SpringArm->bInheritPitch = false;
    SpringArm->bInheritYaw = false;
    SpringArm->bInheritRoll = false;

    // Camera Component
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

    //�������� ��ġ �ʱ�ȭ
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



void AMyPaperCharacter::BeginPlay()
{
	Super::BeginPlay();

    bIsAttacking = false;    

    if (GetSprite() != nullptr)
    {
        GetSprite()->SetFlipbook(FB_Char_Idle);
        //GetSprite �̺�Ʈ �Լ� ���
        GetSprite()->OnFinishedPlaying.AddDynamic(this, &AMyPaperCharacter::OnAttackFinished);

        UE_LOG(LogTemp, Warning, TEXT("OnFinishedPlaying.AddDynamic"));
    }
}


void AMyPaperCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //�߰� �����ϸ� ��.
    UpdateCharacter();

}




void AMyPaperCharacter::Walk(const FInputActionValue& Value)
{
    UE_LOG(LogTemp, Warning, TEXT("Walk!"));
}


void AMyPaperCharacter::Jump()
{
    Super::Jump();

    GetSprite()->SetFlipbook(FB_Char_Attack01);
    UE_LOG(LogTemp, Warning, TEXT("Jump!"));
}


void AMyPaperCharacter::StopJumping()
{
    Super::Jump();

    GetSprite()->SetFlipbook(FB_Char_Attack01);
    UE_LOG(LogTemp, Warning, TEXT("StopJumping!"));
}

void AMyPaperCharacter::Move(float Value)
{   
    AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
}

void AMyPaperCharacter::Attack()
{
    // ���� ������ ���⿡ ����
    if (!bIsAttacking)
    {
        bIsAttacking = true;
        GetSprite()->SetFlipbook(FB_Char_Attack01);
        GetSprite()->SetLooping(false);        
        GetSprite()->PlayFromStart();
    }
}


void AMyPaperCharacter::OnAttackFinished()
{
    UE_LOG(LogTemp, Warning, TEXT("OnAttackFinished!"));

    bIsAttacking = false;
    GetSprite()->SetLooping(true);
    GetSprite()->Play();
    UpdateAnimation();

}




void AMyPaperCharacter::UpdateCharacter()
{
    // Update animation to match the motion
    UpdateAnimation();


    if (!bIsAttacking)
    {
        UE_LOG(LogTemp, Warning, TEXT("UpdateCharacter!"));


        const FVector PlayerVelocity = GetActorForwardVector();
        float TravelDirection = PlayerVelocity.X;

        if (Controller != nullptr)
        {

            AMyPlayerController* MyController = Cast<AMyPlayerController>(Controller);

            if (MyController != nullptr)
            {
                if (TravelDirection < 0.0f)
                {
                    MyController->SetControlRotation(FRotator(0.0, 180.0f, 0.0f));

                    UE_LOG(LogTemp, Warning, TEXT("SetControlRotation!"));
                }
                else if (TravelDirection > 0.0f)
                {
                    MyController->SetControlRotation(FRotator(0.0f, 0.0f, 0.0f));

                    UE_LOG(LogTemp, Warning, TEXT("SetControlRotation!"));
                }

            }

        }
    }
}



void AMyPaperCharacter::UpdateAnimation()
{
    if (!bIsAttacking)
    {
        const FVector PlayerVelocity = GetVelocity();
        const float PlayerSpeedSqr = PlayerVelocity.SizeSquared();

        // Are we moving or standing still?
        UPaperFlipbook* DesiredAnimation = (PlayerSpeedSqr > 0.0f) ? FB_Char_Run : FB_Char_Idle;
        if (GetSprite()->GetFlipbook() != DesiredAnimation)
        {
            GetSprite()->SetFlipbook(DesiredAnimation);
        }

    }
    
}
