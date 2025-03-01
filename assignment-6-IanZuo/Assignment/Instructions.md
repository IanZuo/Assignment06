# Assignment_06

This assignment is divided into two parts. It is recommended to read through both parts beforehand to understand the overall objective. If you are comfortable with abstraction and C++, you may choose to combine both parts and directly implement the final result. However, for most students, completing Part 1 before Part 2 is advised and what I would recommend.

Since this assignment involves multiple abstractions and modifications, it is easy to lose track of changes. To avoid introducing numerous errors at once, compile your code frequently as you make small changes. Making multiple changes before compiling can lead to an overwhelming number of errors that may be difficult to debug. Make a change, check for errors, and continue.

To assist with the refactoring process, two SAMPLE GUIDELINE UMLs are provided. These are not mandatory but serve as helpful references if needed.

***Part 1: Abstracting a GameEntity Class from the Sprite Class***

A sprite is a moveable texture. That's all it's supposed to be. Currently, our Sprite class is handling too much functionality, making it difficult to differentiate behavior for the player and enemies. To address this, we will create a GameEntity class that abstracts shared functionality from our Sprite.

***Game Entity Class***
This class will own a Sprite, and handle Input, Update, and Render.
* Your functions should be virtual so they can be overridden later.
* Input() will take deltaTime (for a later purpose).
* Update() will now handle all of the movement that the Sprite was previously handling.
* Render() will simply call the Sprite's render function.
* This class will also hold xPositiveDirection, whatever you were storing the Sprite's overall movement, and speed.

***Application***
Your application class will need some revamping too depending on how you've implemented things.
* In your StartUp(), you'll need to make sure you're creating unique pointers for both enemies and the main character.
* std::unique_ptr<Type> unique_ptr = std::make_unique<Type>();
* Also keep in mind, you'll now be working with pointers, so there may be other areas in your code that need a little refactoring.
* You'll also want to make sure you update your member variables to reflect this.

***Part 2: Abtracting a Player and Enemy Class from our GameEntity***

With Input/Update/Render now abstracted into GameEntity, we can define specialized behaviors for the Player and Enemy classes. Each will inherit from GameEntity and override necessary functions.

**Enemy Class**
This class will need to store the xPositiveDirection, whatever you were storing the GameEntity's overall movement, and speed.
* This class should only need to override the Update function from the GameEntity and will have all the same previous functionality, namely, moving left and right.
* You can use Enemy::Enemy(Sprite sprite) : GameEntity(sprite) to call the GameEntity constructor.

**Player Class**
This class will need to just store a speed.
* This class should only need to override the Input function from the GameEntity.
* The Input() function will need to utilize SDL_GetKeyboardState().
* Your implementation should move the main character left or right depending on whether (either A/D or left_arrow/right_arrow) were pressed.
* You should also be updating your application to call your mainCharacter's Input function.

**Requirements**

Copy over your files from the previous assignment into the Assignment directory of this assignment. 

**Additional Tips**<br>
* Take the requirements one at a time, and one step at a time.
* Keep your changes modular to make debugging easier.
* Regularly compile and test functionality as you implement changes.
* The UML diagrams are provided as guidelines — modifications and refinements are encouraged, but please don't stray too far away from the guidelines.

**How to compile and run your program**

Your code may compile with different commands based on your architecture, but a sample compilation command may look like: g++ -std=c++20 ./src/*.cpp `pkg-config --cflags --libs sdl2` -o prog.

**Submission/Deliverables**

Submission

Commit all of your files to github, including any additional files you create.
Do not commit any binary files unless told to do so.
Do not commit any 'data' files generated when executing a binary.
Submit your GitHub link on Canvas.

Found a bug?

If you found a mistake (big or small, including spelling mistakes) in this lab, kindly send me an e-mail. It is not seen as nitpicky, but appreciated! (Or rather, future generations of students will appreciate it!)

**Goal** Your output doesn't have to be exactly as seen in the below video, but it should be pretty close.

![](../Media/Module06_Goal.mov)

