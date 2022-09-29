UE4 Process Event Intereception

"Intercept" and hook / access functions and classes that you might not normally be able or easily be able to in a UE4 game through process event.
Allows you to adjust values and call functions that might not be easily accessabile in classes that have weird heirarchy/parents. It also allows you to block function calls if that is something you are interested in and werent able to figure out.

Example: 
UObject -> AActor -> AEmitter -> APrimalEmitterSpawnable -> etc... (I will not be using this path in the code example)

The case here is that you can access AActor but AEmitter isnt as easily accesable and doesnt have a dirrect offset to call into AEmitter so this
allows you to access AEmitter straight up and jump over UObject and AActor if that makes sense.
