# Shapes Blackboard
## Purpose of work
Gain practical skills in implementing systems using polymorphism and inheritance principles in
mind. The goal of this task is to design and implement a set of common expandable interfaces for
objects.

## Task
Develop a console-based application which will represent a shapes board with the ability to draw
different types of shapes on it. The main idea is that the user has an empty blackboard and can
interact with it in a few ways: show the blackboard, place or remove some shape within the
blackboard or clear it completely. Additionally, the user should be able to save and load the state
of the blackboard from the file.

## Constrains
There are some constraints and preferences related to that task.
1. Shapes are drawn as frames.
2. Shapes can overlap. In that case, shapes should be correctly drawn.
3. Shapes cannot be placed outside of the board.
4. Shapes bigger than the board cannot be placed on the board.
5. Shapes that are partially outside of the board can be placed, but they are cropped.
6. Figures with the same type and parameters cannot be placed on the same spot.
7. There is no limit to the shape count on the board.
8. Empty boards should also be correctly saved and loaded.
9. A file with an invalid board should not be loadable.
10. There must be shapes with different parameter count (radius, width\height, height\angle).

## Task milestones
1. Design your system on paper or by using some online tools, please use squares and
arrows to draw classes and their relations, no specific notation is needed in this task.
2. Implement the blackboard drawing part of the system.
3. Implement the single shape\figure class and try to draw it with the board.
4. Try to add more shapes. At that stage, you can evaluate the interface of the shape\figure
class and re-design it. Take a note, of what played what, and what did not.
5. Try to add a CLI interface for the developed application and related logic.
6. Thinks how parameters should be passed to the shapes with different parameter count.
7. Test the solution, and develop your input data files

## Control questions
1. What is inheritance?
2. What is polymorphism? How can it be achieved?
3. What is operator overloading?
4. Which types of constructors do you know?
5. What does the virtual keyword mean?
6. What does the override keyword mean?
7. What does the final keyword mean? In which contexts it can be used?
8. What does the pure method mean?
9. When do we need virtual functions?
10. What is dynamic_cast and how is it implemented under the hood?
11. Explain the difference between unique_ptr and shared_ptr.
12. Explain the difference between shared_ptr and weak_ptr.
13. RAII idiom.

## Evaluation
- Usage of inheritance and polymorphism principles - **4**
- The shape interface is uniform and strictly defined - **2**
- The draw interface is the same for figures of all shapes and parameter count - **2**
- There are 4 or more shapes available to the user (e.g. triangle, rectangle,
circle, line) - **1**
- All constraints are satisfied - **1**
  
**Total:** 10
