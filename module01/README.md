## Module01

## Allocation on stack or heap

```
TheClass Hohoho; // on the stack
TheClass *Hohoho = new TheClass(); // on the heap
```

Instances created on the stack will be destroyed automaticly when leaving the scope.
To destroy the instances created on the heap:
```
delete Hohoho;
```
As simple as that :D

## ex00
