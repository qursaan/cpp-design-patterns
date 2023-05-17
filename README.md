# Design Patterns Samples Using C++

## Creational Patterns

### Families Objects

1. [AbstractFactory](/creational/object/AbstractFactory.cpp)
    The Abstract Factory Pattern provides an interface for creating families of related or dependent objects without specifying their concrete classes.
    *Example:*
    Create three shapes: Circle, Square and Rectangle with different colors: Red, Green and Yellow. Then create a factory to create the shapes objects. The client then can create the shapes with the colors based on the chosen factory.

## Structural Patterns

### Composite Objects

1. [Composite](/structural/object/compsoite/ObjectTree.cpp)
    Create a tree structure of objects. Each object can have a list of objects. The client can then iterate over the tree structure and print the objects.
    *Example:*
    An order might comprise various products, packaged in boxes, which are packaged in bigger boxes and so on. The whole structure looks like an upside down tree.

