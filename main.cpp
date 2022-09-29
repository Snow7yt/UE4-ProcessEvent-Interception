/*
This allows you to access cretain classes that might be harder to access and allows you to block function calls in a UE4 game.
The only prequisits are to have a working/functioning SDK and to have a process event hook.
*/

//In this example we will be jumping to access ALionfishLion_Character_BP_C and block functions from that class too.

//Have a struct so you can store access to that certain area that you are trying to access, if you are blocking then you dont need this
struct{
  (ALionfishLion_Character_BP_C*) LionFish; //Create a refrence to ALionfishLion_Character_BP_C class in your sdk, it could also be CG:ALionfishLion_Character_BP_C
}pEventSaves;

__forceinline void Hooks::ProcessEvent(UObject* pObject, UFunction* pFunction, void* params)
{
  //Start off by logging the names and #'s
  for (int i = 0; i < pObject->GetGlobalObjects().Num(); i++)
  {
    print("%s - %i\n", pObject->GetGlobalObjects().GetByIndex(i)->GetFullName().c_str(), i);
  }
  
  //                                 Func name here
  if (pFunction->GetFullname().find("ALionfishLion.ReceiveTick").c_str()) != std::string::npos)
  {
    LionFish = (ALionfishLion_Character_BP_C*)pObject;
    
    //if you want to block this function, (it would need to be the name of the function above where RecieveTick is, just return here
    // return;
  }
  
  //This is for if you want to 'access' the class, if you just want to block it this isnt needed, only the return above is.
  if (LionFish)
  {
    LionFish->Server_Request_Jump();
  }
  
  return oProcessEvent(pObject, pFunction, params);
}
